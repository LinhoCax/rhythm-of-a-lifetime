#include "Arquivo.hpp"
#include <fstream>
#include <iostream>
#include <string>

void Arquivo::salvar(const Biblioteca& bib, const std::string& nomeArquivo) const {
    std::ofstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cout << "Erro ao tentar salvar o arquivo!" << std::endl;
        return;
    }

    for (const auto& par : bib.getAcervo()) {
        arquivo << par.second.getId() << ";"
                << par.second.getTitulo() << ";"
                << par.second.getArtista() << ";"
                << par.second.getAlbum() << ";"
                << par.second.getDuracao() << "\n";
    }
    arquivo.close();
}

void Arquivo::carregar(Biblioteca& bib, const std::string& nomeArquivo) const {
    std::ifstream arquivo(nomeArquivo);

    // Se o arquivo ainda nao existe, o sistema comeca vazio
    if (!arquivo.is_open()) {
        return;
    }

    std::string id_str, titulo, artista, album, duracao_str;

    while (std::getline(arquivo, id_str, ';') &&
           std::getline(arquivo, titulo, ';') &&
           std::getline(arquivo, artista, ';') &&
           std::getline(arquivo, album, ';') &&
           std::getline(arquivo, duracao_str)) {

        int id = std::stoi(id_str);
        int duracao = std::stoi(duracao_str);

        Musica m(id, titulo, artista, album, duracao);
        bib.inserirCarregada(m);
    }

    arquivo.close();
}