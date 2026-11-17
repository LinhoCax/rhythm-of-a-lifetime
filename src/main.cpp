#include <iostream>
#include "Biblioteca.hpp"

int main() {
    Biblioteca minhaBib;

    std::cout << "--- Teste da Etapa 3: Listagem Ordenada ---" << std::endl;

    minhaBib.cadastrar("Video Games", "Lana Del Rey", "Born to Die", 282);
    minhaBib.cadastrar("A Sky Full of Stars", "Coldplay", "Ghost Stories", 268);
    minhaBib.cadastrar("Born to Die", "Lana Del Rey", "Born to Die", 286);
    minhaBib.cadastrar("Swim", "BTS", "Japanese Single", 174);
    minhaBib.cadastrar("Yellow", "Coldplay", "Parachutes", 269);

    minhaBib.listar();

    return 0;
}