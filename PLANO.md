# Plano de Implementação: Rhythm of a Lifetime

## 1. As Classes e a STL

### Classe `Musica`
* **Responsabilidade:** Guardar os dados de uma única faixa (ID, Título, Artista, Álbum, Duração em segundos).
* **STL:** Vai implementar o `operator<` (operador de menor). Isso vai ensinar ao C++ como comparar duas músicas para sabermos qual vem primeiro na ordem alfabética (desempatando por Artista -> Álbum -> Título).

### Classe `Biblioteca`
* **Responsabilidade:** Armazenar todo o acervo, gerar IDs automáticos para novas músicas e listar o catálogo ordenado.
* **STL 1: `std::map<int, Musica>`** 
  * **Por quê:** O `map` funciona como um dicionário. Usaremos o ID da música como chave (o `int`) e a `Musica` como valor. Isso permite que o sistema encontre os dados de uma música instantaneamente quando o usuário digitar o ID no menu, sem precisar varrer uma lista inteira.
* **STL 2: `std::vector<Musica>` e `std::sort`**
  * **Por quê:** O `map` não guarda as coisas em ordem alfabética, ele guarda pela chave (ID). Quando o usuário pedir para listar a biblioteca, copiaremos as músicas para um `vector` temporário e usaremos o algoritmo `std::sort` (que vai usar o nosso `operator<` da classe `Musica`) para exibir tudo organizadinho na tela.

### Classe `Fila`
* **Responsabilidade:** Controlar o que vai tocar a seguir.
* **STL: `std::list<int>`**
  * **Por quê:** A `list` é duplamente encadeada. Para uma fila de reprodução onde queremos adicionar músicas tanto no *início* (para tocar logo em seguida) quanto no *fim*, e pular a faixa atual (removendo do início), a `list` é extremamente rápida e eficiente, diferentemente do `vector`, que é lento para mexer no começo. Ela guardará apenas os IDs das músicas.

---

## 2. Etapas de Implementação

**Etapa 1: Estrutura Básica da Música**
* Criar `Musica.hpp` e `Musica.cpp`.
* Fazer construtor, getters (métodos para ler os dados) e definir o `operator<`.
* **Teste:** No `main.cpp`, criar duas músicas na mão e usar um `if (musica1 < musica2)` para ver se a ordenação lógica está funcionando.

**Etapa 2: A Biblioteca (Adicionar e Buscar)**
* Criar `Biblioteca.hpp` e `Biblioteca.cpp`.
* Implementar o `map` e o método de cadastrar (gerando ID numérico sequencial) validando se já existe.
* **Teste:** No `main.cpp`, chamar o cadastro passando dados fictícios e tentar cadastrar a mesma música duas vezes para ver se ele barra.

**Etapa 3: A Biblioteca (Listagem Ordenada)**
* Adicionar o método de listar na `Biblioteca`, que usa o `std::sort`.
* **Teste:** Cadastrar três músicas fora de ordem no `main.cpp` e chamar o método de listar para ver se saem na ordem alfabética certa.

**Etapa 4: A Fila de Reprodução**
* Criar `Fila.hpp` e `Fila.cpp`.
* Implementar a `std::list` e os métodos de adicionar no início, adicionar no fim, e pular música (removendo o primeiro ID da lista).
* **Teste:** No `main.cpp`, simular a adição de alguns IDs de músicas, pular uma e mandar imprimir a fila restante.

**Etapa 5: O Menu e a Interface Textual**
* Limpar os testes do `main.cpp` e criar o loop infinito do menu principal.
* Fazer a leitura de dados com `std::getline` (tratando espaços) e a leitura de números limpando o buffer corretamente.
* Ligar as opções do menu às chamadas das classes `Biblioteca` e `Fila`.