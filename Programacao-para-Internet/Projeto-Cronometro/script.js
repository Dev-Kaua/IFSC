let intervalo;
let tempoDecorrido = 0;
let estaRodando = false;

function formatarTempo(ms) {
  const data = new Date(ms);
  const minutos = String(data.getUTCMinutes()).padStart(2, '0');
  const segundos = String(data.getUTCSeconds()).padStart(2, '0');
  const milissegundos = String(Math.floor(data.getUTCMilliseconds() / 10)).padStart(2, '0');
  
  return `${minutos}:${segundos}:${milissegundos}`;
}

function atualizarDisplay() {
    const display = document.getElementById('tempo');
    display.innerText = formatarTempo(tempoDecorrido);
}

function iniciar() {
  if (!estaRodando) {
    // REQUISITO: Usar Date para calcular o tempo real do sistema
    const tempoInicial = Date.now() - tempoDecorrido;
    
    // REQUISITO: Usar setInterval para atualizar a interface
    intervalo = setInterval(() => {
      tempoDecorrido = Date.now() - tempoInicial;
      atualizarDisplay();
    }, 10);
    
    estaRodando = true;
  }
}

function pausar() {
  if (estaRodando) {
    clearInterval(intervalo);
    estaRodando = false;
    
    // REQUISITO: Registrar a pausa na lista
    registrarNaLista();
  }
}

function zerar() {
  clearInterval(intervalo);
  tempoDecorrido = 0;
  estaRodando = false;
  atualizarDisplay();
  // Limpa a lista de paradas visualmente
  document.getElementById('lista-paradas').innerHTML = '';
}

function registrarNaLista() {
    const lista = document.getElementById('lista-paradas');
    const item = document.createElement('li');
    item.innerText = formatarTempo(tempoDecorrido);
    lista.appendChild(item);
}


//Atalhos de teclado
document.addEventListener('keydown', function(event) {
  const tecla = event.key.toLowerCase();
  
  if (tecla === 'i') {
    iniciar();
  } else if (tecla === 'p') {
    pausar();
  } else if (tecla === 'escape') {
    zerar();
  }
});