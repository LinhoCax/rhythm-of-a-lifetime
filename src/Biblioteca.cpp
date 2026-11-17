#include "Biblioteca.hpp"
#include <vector>
#include <algorithm>
#include <iostream>

Biblioteca::Biblioteca() : proximoId(1) {}

bool Biblioteca::cadastrar(std::string titulo, std::string artista, std::string album, int duracao) {
    for (const auto& par : acervo) {
        if (par.second.getTitulo() == titulo && par.second.getArtista() == artista) {
            return false;
        }
    }
    Musica novaMusica(proximoId, titulo, artista, album, duracao);
    acervo.insert({proximoId, novaMusica});
    proximoId++;
    return true;
}

int Biblioteca::getTamanho() const {
    return acervo.size();
}

void Biblioteca::listar() const {
    if (acervo.empty()) {
        std::cout << "A biblioteca esta vazia." << std::endl;
        return;
    }
    
    std::vector<Musica> listaOrdenada;
    for (const auto& par : acervo) {
        listaOrdenada.push_back(par.second);
    }
    
    std::sort(listaOrdenada.begin(), listaOrdenada.end());

    std::cout << "\n=== Biblioteca de Musicas ===" << std::endl;
    for (const auto& m : listaOrdenada) {
        std::cout << "[" << m.getId() << "] " 
                  << m.getArtista() << " - " 
                  << m.getAlbum() << " - " 
                  << m.getTitulo() << " (" 
                  << m.getDuracao() << "s)" << std::endl;
    }
    std::cout << "=============================\n" << std::endl;
}