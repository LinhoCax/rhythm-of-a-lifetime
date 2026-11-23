#include "Biblioteca.hpp"
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <stdexcept>

Biblioteca::Biblioteca() : proximoId(1) {}

void Biblioteca::cadastrar(std::string titulo, std::string artista, std::string album, int duracao)
{
    if (titulo.empty() || artista.empty() || album.empty())
    {
        throw std::invalid_argument("Titulo, artista e album nao podem ser vazios.");
    }

    if (duracao <= 0)
    {
        throw std::invalid_argument("A duracao deve ser maior que zero.");
    }

    for (const auto &par : acervo)
    {
        if (par.second.getTitulo() == titulo &&
            par.second.getArtista() == artista &&
            par.second.getAlbum() == album)
        {
            throw std::invalid_argument("Essa musica ja existe na biblioteca.");
        }
    }

    Musica nova(proximoId, titulo, artista, album, duracao);
    acervo.insert({proximoId, nova});
    proximoId++;
}

int Biblioteca::getTamanho() const
{
    return acervo.size();
}

bool Biblioteca::existeMusica(int id) const
{
    return acervo.find(id) != acervo.end();
}

void Biblioteca::listar() const
{
    if (acervo.empty())
    {
        std::cout << "A biblioteca esta vazia." << std::endl;
        return;
    }

    std::vector<Musica> listaOrdenada;
    for (const auto &par : acervo)
    {
        listaOrdenada.push_back(par.second);
    }

    std::sort(listaOrdenada.begin(), listaOrdenada.end());

    std::cout << "\n=== Biblioteca de Musicas ===" << std::endl;
    for (const auto &m : listaOrdenada)
    {
        std::cout << "[" << m.getId() << "] "
                  << m.getArtista() << " - "
                  << m.getAlbum() << " - "
                  << m.getTitulo() << " ("
                  << m.getDuracao() << "s)" << std::endl;
    }
    std::cout << "=============================\n"
              << std::endl;
}

const std::map<int, Musica> &Biblioteca::getAcervo() const
{
    return acervo;
}

void Biblioteca::inserirCarregada(const Musica &m)
{
    acervo.insert({m.getId(), m});
    if (m.getId() >= proximoId)
    {
        proximoId = m.getId() + 1;
    }
}