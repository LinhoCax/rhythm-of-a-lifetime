#ifndef FILA_HPP
#define FILA_HPP

#include <list>
#include <iostream>

class Fila {
private:
    std::list<int> musicasIds; // Guarda apenas os IDs (números)

public:
    void adicionarNoFim(int id);
    void adicionarNoInicio(int id);
    void pularMusica();
    void mostrarFila() const;
};

#endif