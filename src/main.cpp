#include <iostream>
#include "Musica.hpp"

int main() {
    // Vamos testar com as nossas regras
    Musica m1(1, "Swim", "BTS", "Korean Single", 174);
    Musica m2(2, "Born to Die", "Lana Del Rey", "Born to Die", 286);
    Musica m3(3, "Video Games", "Lana Del Rey", "Born to Die", 282);

    // Testando a ordem lógica do operator<
    std::cout << "--- Teste de Ordenacao da Etapa 1 ---" << std::endl;
    
    if (m1 < m2) {
        std::cout << "[OK] " << m1.getArtista() << " vem antes de " << m2.getArtista() << std::endl;
    }

    if (m2 < m3) {
        std::cout << "[OK] No mesmo album, " << m2.getTitulo() << " vem antes de " << m3.getTitulo() << std::endl;
    }

    return 0;
}