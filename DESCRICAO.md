# Descrição do sistema

Escreva este arquivo sem IA, antes de qualquer código. Apague as instruções
em itálico quando preencher.

## Nome e ideia

O sistema se chama Rhythm of a Lifetime.  É um gerenciador em modo texto para catalogar músicas na biblioteca e controlar uma fila de reprodução em tempo real.

## O que o sistema guarda

Música: guarda o título, o artista (ex: Lana Del Rey, BTS), o álbum e a duração.

Biblioteca: guarda todas as músicas cadastradas no sistema.

Fila de Reprodução: guarda a ordem das músicas que vão tocar.

## O que dá para fazer

Cadastrar nova música.

Listar todas as músicas da biblioteca (ordenadas por artista).

Adicionar uma música no início ou no fim da fila.

Pular para a próxima música da fila.

Mostrar as músicas que estão na fila.

## Regras

Não é permitido cadastrar duas músicas com o mesmo título e o mesmo artista.

A duração da música deve ser maior que zero.

A biblioteca deve ordenar as músicas em ordem alfabética automaticamente.

## Quando algo dá errado

Se tentar adicionar na fila uma música que não está na biblioteca: (ex: erro "Música não encontrada").

Se tentar pular de música com a fila vazia: (ex: erro "A fila já está vazia").

Se o usuário digitar uma letra onde o menu espera um número (opção do menu): exibe aviso de entrada inválida.

## Classes que eu imagino

Musica: representa os dados de uma única faixa.

Biblioteca: gerencia o acervo total e faz as buscas.

Fila: controla o que vai tocar a seguir, permitindo adicionar no início ou no fim.

## Exemplo de uso

Menu:
1. Cadastrar Música
2. Mostrar Biblioteca
...
Opção: 1
Digite o artista: BTS
Digite a música: Swim
...
Música cadastrada com sucesso!