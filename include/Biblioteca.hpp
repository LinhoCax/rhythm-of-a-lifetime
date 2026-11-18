#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include <map>
#include <string>
#include <vector>
#include "Musica.hpp"

class Biblioteca
{
private:
    std::map<int, Musica> acervo;
    int proximoId;

public:
    Biblioteca();

    bool cadastrar(std::string titulo, std::string artista, std::string album, int duracao);
    int getTamanho() const;
    void listar() const;
    bool existeMusica(int id) const;
    void salvar() const;
    void carregar();
};

#endif