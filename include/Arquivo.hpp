#ifndef ARQUIVO_HPP
#define ARQUIVO_HPP

#include <string>
#include "Biblioteca.hpp"

class Arquivo
{
public:
    void salvar(const Biblioteca &bib, const std::string &nomeArquivo) const;
    void carregar(Biblioteca &bib, const std::string &nomeArquivo) const;
};

#endif