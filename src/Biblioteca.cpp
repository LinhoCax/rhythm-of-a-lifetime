#include "Biblioteca.hpp"

// O construtor inicia o gerador de IDs no 1
Biblioteca::Biblioteca() : proximoId(1) {}

bool Biblioteca::cadastrar(std::string titulo, std::string artista, std::string album, int duracao) {
    // 1. Verifica se a música já existe (mesmo título e mesmo artista)
    // O 'auto' deduz automaticamente que 'par' contém um ID e uma Musica
    for (const auto& par : acervo) {
        if (par.second.getTitulo() == titulo && par.second.getArtista() == artista) {
            return false; // A música já existe, bloqueia o cadastro
        }
    }

    // 2. Se não existe, cria a música com o ID atual
    Musica novaMusica(proximoId, titulo, artista, album, duracao);
    
    // 3. Insere no map (a chave é o ID, o valor é a música)
    acervo.insert({proximoId, novaMusica});
    
    // 4. Prepara o ID para a próxima música que for cadastrada
    proximoId++;
    
    return true;
}

int Biblioteca::getTamanho() const {
    return acervo.size();
}