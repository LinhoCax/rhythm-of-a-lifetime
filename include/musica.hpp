#ifndef MUSICA_HPP
#define MUSICA_HPP

#include <string>

class Musica {
private:
    int id;
    std::string titulo;
    std::string artista;
    std::string album;
    int duracao; // em segundos totais

public:
    // Construtor
    Musica(int id, std::string titulo, std::string artista, std::string album, int duracao);

    // Getters para lermos os dados depois
    int getId() const;
    std::string getTitulo() const;
    std::string getArtista() const;
    std::string getAlbum() const;
    int getDuracao() const;

    // Operador necessário para a STL ordenar
    bool operator<(const Musica& outra) const;
};

#endif