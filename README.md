# Nome do sistema

Atividade da Unidade 2 de Linguagem de Programação I. Leia `ENUNCIADO.md`
antes de começar.

Uma frase dizendo o que o sistema faz. A descrição completa está em
`DESCRICAO.md`.

É um gerenciador em modo texto para catalogar músicas na biblioteca e controlar uma fila de reprodução em tempo real.

## Arquivos

```text
.
├── AGENTS.md       regras que a IA lê antes de cada pedido
├── DESCRICAO.md    a descrição do sistema, escrita por você
├── ENUNCIADO.md    a atividade
├── PLANO.md        o plano feito com a IA (criado na etapa 3)
├── README.md       este arquivo
├── exemplos/       arquivos de entrada para testar
├── include/        um .hpp por classe
└── src/            um .cpp por classe, mais a interface
```

## Compilar e executar

```bash
g++ -std=c++11 -Wall -Wextra src/*.cpp -Iinclude -o sistema
./sistema.exe
```

```PowerShell
g++ -std=c++11 -Wall -Wextra src/main.cpp src/Musica.cpp src/Biblioteca.cpp src/Fila.cpp -Iinclude -o sistema
```

Se o comando mudar, atualize esta seção. Na correção eu vou usar o que
estiver escrito aqui.

## Onde uso a STL

Neste projeto, utilizei três estruturas diferentes da STLs, cada uma escolhida para resolver um problema específico:

1. **`std::map` (na Biblioteca):** Usei o map para guardar todas as músicas cadastradas (`acervo`). A chave é o ID (um número inteiro) e o valor é o objeto `Musica`. Escolhi o map porque ele funciona como um dicionário: quando o usuário digita um ID para adicionar na fila, o sistema usa o `.find()` para checar quase instantaneamente se a música existe, sem precisar fazer um laço de repetição (`for`) passando por todas as faixas.

2. **`std::vector` e `std::sort` (na Listagem):** Como o map organiza os itens automaticamente pela chave (ID numérico), eu não conseguiria imprimir as músicas em ordem alfabética direto dele. A solução foi criar um método que copia as músicas para um `std::vector` temporário e usa a função `std::sort` da biblioteca `<algorithm>`. Para o sort saber como ordenar, criei um `operator<` na classe Musica que compara primeiro o Artista, depois o Álbum e por último o Título.

3. **`std::list` (na Fila de Reprodução):** Para a fila, o importante não é buscar elementos no meio, mas sim adicionar e remover coisas rapidamente das pontas. Usei a lista duplamente encadeada (`list`) porque ela é muito mais eficiente que um vector para remover a música atual (`pop_front`), colocar a próxima música no final (`push_back`) ou furar a fila colocando uma música para tocar agora (`push_front`).

## Como usei a IA

Utilizei a inteligência artificial (Gemini) como um tutor auxiliar durante o desenvolvimento, focando em estruturar o projeto e resolver problemas de compilação:

* **Planejamento:** No início, usei a IA para entender as regras da atividade e dividir o sistema nas três classes principais (`Musica`, `Biblioteca` e `Fila`), criando o arquivo PLANO.md antes de escrever o código.

* **Resolução de Bugs:** Pedi ajuda para entender e corrigir um erro de *"undefined reference"* na hora de compilar no terminal (ajustando os comandos do `g++`) e para resolver um loop infinito causado pelo buffer do       `std::cin` na leitura do menu.

* **Testes:** A IA me orientou a criar um script automatizado de testes (o arquivo `entradas.txt` dentro da pasta `exemplos`) e a rodá-lo usando redirecionamento no PowerShell, acelerando muito a validação das regras de negócio.
