#include "Fila.hpp"

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
        std::cout << "A fila ja esta vazia." << std::endl;
        return;
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