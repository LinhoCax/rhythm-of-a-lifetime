#include "Biblioteca.hpp"
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>

Biblioteca::Biblioteca() : proximoId(1) {}

bool Biblioteca::cadastrar(std::string titulo, std::string artista, std::string album, int duracao)
{
    for (const auto &par : acervo)
    {
        if (par.second.getTitulo() == titulo && par.second.getArtista() == artista)
        {
            return false;
        }
    }
    Musica novaMusica(proximoId, titulo, artista, album, duracao);
    acervo.insert({proximoId, novaMusica});
    proximoId++;
    return true;
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

void Biblioteca::salvar() const
{
    std::ofstream arquivo("biblioteca.txt");

    if (!arquivo.is_open())
    {
        std::cout << "Erro ao tentar salvar o arquivo!" << std::endl;
        return;
    }

    for (const auto &par : acervo)
    {
        arquivo << par.second.getId() << ";"
                << par.second.getTitulo() << ";"
                << par.second.getArtista() << ";"
                << par.second.getAlbum() << ";"
                << par.second.getDuracao() << "\n";
    }
    arquivo.close();
}

void Biblioteca::carregar()
{
    std::ifstream arquivo("biblioteca.txt");

    if (!arquivo.is_open())
        return;

    std::string id_str, titulo, artista, album, duracao_str;
    int maiorId = 0;

    while (std::getline(arquivo, id_str, ';') &&
           std::getline(arquivo, titulo, ';') &&
           std::getline(arquivo, artista, ';') &&
           std::getline(arquivo, album, ';') &&
           std::getline(arquivo, duracao_str))
    {

        int id = std::stoi(id_str);
        int duracao = std::stoi(duracao_str);

        Musica m(id, titulo, artista, album, duracao);
        acervo.insert({id, m});

        if (id > maiorId)
        {
            maiorId = id;
        }
    }

    proximoId = maiorId + 1;
    arquivo.close();
}