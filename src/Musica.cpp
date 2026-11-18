#include "Musica.hpp"

Musica::Musica(int id, std::string titulo, std::string artista, std::string album, int duracao)
    : id(id), titulo(titulo), artista(artista), album(album), duracao(duracao) {}

int Musica::getId() const { return id; }
std::string Musica::getTitulo() const { return titulo; }
std::string Musica::getArtista() const { return artista; }
std::string Musica::getAlbum() const { return album; }
int Musica::getDuracao() const { return duracao; }

bool Musica::operator<(const Musica &outra) const
{
    if (artista != outra.artista)
    {
        return artista < outra.artista;
    }
    if (album != outra.album)
    {
        return album < outra.album;
    }
    return titulo < outra.titulo;
}