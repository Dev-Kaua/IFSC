let notas = [];
let notaAtualId = null;

document.addEventListener('DOMContentLoaded', () => {
  carregarNotasDoStorage();
  renderizarLista();
});

// requisito: Salvar no localStorage em formato de json
function carregarNotasDoStorage() {
  const dados = localStorage.getItem('notasApp');
  if (dados) {
    notas = JSON.parse(dados);
  }
}

function salvarNoStorage() {
  localStorage.setItem('notasApp', JSON.stringify(notas));
}

function novaNota() {
  document.getElementById('nota-titulo').value = '';
  document.getElementById('nota-conteudo').value = '';
  notaAtualId = null;
  document.getElementById('nota-titulo').focus();
}


function salvarNota() {
    const titulo = document.getElementById('nota-titulo').value;
    const conteudo = document.getElementById('nota-conteudo').value;

    if (!titulo && !conteudo) {
      alert("A nota precisa ter conteúdo!");
      return;
    }

    if (notaAtualId !== null) {
      const nota = notas.find(n => n.id === notaAtualId);
      if (nota) {
        nota.titulo = titulo;
        nota.conteudo = conteudo;
      }
    }else {
      const novaNotaObj = {
        id: Date.now(),
        titulo: titulo || "Sem Título",
        conteudo: conteudo
      };
      notas.push(novaNotaObj);
      notaAtualId = novaNotaObj.id;
    }

    salvarNoStorage();
    renderizarLista();
    alert("Nota salva!");
}

function renderizarLista() {
  const listaElemento = document.getElementById('lista-notas');
  listaElemento.innerHTML = '';

  notas.forEach(nota => {
    const div = document.createElement('div');
    div.className = 'item-nota';
    if (nota.id === notaAtualId) div.classList.add('selecionada');
    
    div.onclick = () => carregarNota(nota.id);

    div.innerHTML = `
      <h3>${nota.titulo}</h3>
      <p>${nota.conteudo.substring(0, 30)}...</p>
    `;

    listaElemento.appendChild(div);
  });
}

// requisito: clicar sobre a nota deve abrir ela
function carregarNota(id) {
  const nota = notas.find(n => n.id === id);
  if (nota) {
    document.getElementById('nota-titulo').value = nota.titulo;
    document.getElementById('nota-conteudo').value = nota.conteudo;
    notaAtualId = nota.id;
    renderizarLista();
  }
}

// requisito: excluir a nota com confirmação
function excluirNota() {
  if (notaAtualId === null) {
    alert("Nenhuma nota selecionada para excluir.");
    return;
  }

  const confirmacao = confirm("Tem certeza que deseja excluir esta nota?");
  
  if (confirmacao) {
    notas = notas.filter(n => n.id !== notaAtualId);
    salvarNoStorage();
    novaNota();
    renderizarLista();
  }
}