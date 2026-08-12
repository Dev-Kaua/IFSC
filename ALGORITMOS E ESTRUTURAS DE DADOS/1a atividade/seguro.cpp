#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <mutex>

using namespace std;
struct No {
string dado;
No* proximo;
No(string d) : dado(d), proximo(nullptr) {}
};

class ListaSegura {
private:
No* inicio = nullptr;
int tamanho = 0;
mutex trava; // 2. o cadeado
public:
void inserir(string dado) {
No* novo = new No(dado); // fora: cada thread tem o seu
lock_guard<mutex> lock(trava); // 3. tranca aqui
No* antigoInicio = inicio;
this_thread::yield(); // a MESMA janela de antes
novo->proximo = antigoInicio;
inicio = novo;
tamanho++;
} // destranca sozinho ao sair
int getTamanho() { lock_guard<mutex> lock(trava); return tamanho; }
int contarDeVerdade() {
lock_guard<mutex> lock(trava);
int c = 0; No* a = inicio;
while (a != nullptr) { c++; a = a->proximo; }
return c;
}
};

int main() {
    const int THREADS = 4, INSERCOES = 2000;
    ListaSegura lista;
    vector<thread> ts;
    for (int i = 0; i < THREADS; i++) {
        ts.push_back(thread([&lista, i, INSERCOES]() {
        for (int j = 0; j < INSERCOES; j++)

        lista.inserir("T" + to_string(i) + "-" + to_string(j));
        }));
    }
    for (auto& t : ts) t.join(); // espera todas terminarem
    int esperado = THREADS * INSERCOES;
    cout << "Esperado : " << esperado << endl;
    cout << "Contador tamanho : " << lista.getTamanho() << endl;
    cout << "Contando os nos : " << lista.contarDeVerdade() << endl;
    cout << "Nos PERDIDOS : " << (esperado - lista.contarDeVerdade()) << endl;
    return 0;
}