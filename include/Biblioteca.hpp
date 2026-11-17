#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include <map>
#include <string>
#include "Musica.hpp"

class Biblioteca {
private:
    std::map<int, Musica> acervo;
    int proximoId; // Controla o gerador de IDs automáticos

public:
    Biblioteca();

    // Retorna true se cadastrou com sucesso, ou false se a música já existir
    bool cadastrar(std::string titulo, std::string artista, std::string album, int duracao);
    
    // Método provisório para testarmos o tamanho do acervo
    int getTamanho() const;
};

#endif