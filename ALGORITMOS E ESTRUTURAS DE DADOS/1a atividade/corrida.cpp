#include <iostream>
#include <thread>
#include <vector>
#include <string>
using namespace std;
struct No {
string dado;
No* proximo;
No(string d) : dado(d), proximo(nullptr) {}
};
class ListaInsegura {
    private:
    No* inicio = nullptr;
    int tamanho = 0;
    public:
    void inserir(string dado) {
        No* novo = new No(dado);
        No* antigoInicio = inicio; // 1. LE o inicio atual
        this_thread::yield(); // 2. janela (explicada adiante)
        novo->proximo = antigoInicio;
        inicio = novo; // 3. ESCREVE o novo inicio
        tamanho++; // 4. conta
    }

    int getTamanho() { return tamanho; }
    int contarDeVerdade() {
        int c = 0; No* a = inicio;
        while (a != nullptr) { c++; a = a->proximo; }
        return c;
    }
};

int main() {
    const int THREADS = 4, INSERCOES = 2000;
    ListaInsegura lista;
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