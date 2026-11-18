#ifndef MUSICA_HPP
#define MUSICA_HPP

#include <string>

class Musica
{
private:
    int id;
    std::string titulo;
    std::string artista;
    std::string album;
    int duracao;

public:
    Musica(int id, std::string titulo, std::string artista, std::string album, int duracao);

    int getId() const;
    std::string getTitulo() const;
    std::string getArtista() const;
    std::string getAlbum() const;
    int getDuracao() const;

    bool operator<(const Musica &outra) const;
};

#endif