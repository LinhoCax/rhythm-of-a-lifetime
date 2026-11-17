#include <iostream>
#include "Biblioteca.hpp"

int main() {
    Biblioteca minhaBib;

    std::cout << "--- Teste da Etapa 2: A Biblioteca ---" << std::endl;

    // 1. Cadastrar uma música nova
    if (minhaBib.cadastrar("Video Games", "Lana Del Rey", "Born to Die", 282)) {
        std::cout << "[OK] Primeira musica cadastrada com sucesso!" << std::endl;
    }

    // 2. Tentar cadastrar a MESMA música (deve falhar)
    if (!minhaBib.cadastrar("Video Games", "Lana Del Rey", "Outro Album", 282)) {
        std::cout << "[OK] O sistema bloqueou a duplicata corretamente!" << std::endl;
    }

    // 3. Cadastrar uma música diferente
    if (minhaBib.cadastrar("A Sky Full of Stars", "Coldplay", "Ghost Stories", 268)) {
        std::cout << "[OK] Segunda musica cadastrada com sucesso!" << std::endl;
    }

    std::cout << "Total de musicas no acervo: " << minhaBib.getTamanho() << std::endl;

    return 0;
}