#include "Fila.hpp"
#include <stdexcept>

void Fila::adicionarNoFim(int id)
{
    musicasIds.push_back(id);
}

void Fila::adicionarNoInicio(int id)
{
    musicasIds.push_front(id);
}

void Fila::pularMusica()
{
    if (musicasIds.empty())
    {
        throw std::runtime_error("A fila esta vazia. Nao ha musica para pular.");
    }
    musicasIds.pop_front();
}

void Fila::mostrarFila() const
{
    if (musicasIds.empty())
    {
        std::cout << "A fila esta vazia no momento." << std::endl;
        return;
    }

    std::cout << "Fila atual (IDs): ";
    for (int id : musicasIds)
    {
        std::cout << "[" << id << "] ";
    }
    std::cout << std::endl;
}