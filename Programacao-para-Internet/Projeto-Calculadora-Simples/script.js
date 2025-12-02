function insert(num) {
    var numero = document.getElementById('resultado').value;
    document.getElementById('resultado').value = numero + num;
}

function clean() {
    document.getElementById('resultado').value = "";
}

function calcular() {
    var resultado = document.getElementById('resultado').value;

    if (resultado) {
        // REQUISITO DE SEGURANÇA 
        // Expressão Regular (Regex). Permite apenas números e operadores matemáticos
        // Isso impede que alguém injete código JS malicioso no eval
        const caracteresValidos = /^[0-9+\-*/().\s]*$/;

        if (caracteresValidos.test(resultado)) {
            try {
                // REQUISITO: Uso da função eval() 
                document.getElementById('resultado').value = eval(resultado);
            } catch (e) {
                alert("Erro na expressão!");
                clean();
            }
        } else {
            alert("Entrada inválida! Apenas números e operações são permitidos.");
            clean();
        }
    } else {
        document.getElementById('resultado').value = "Nada...";
    }
}