#include <iostream>
#include <string>
#include "Biblioteca.hpp"
#include "Fila.hpp"
#include "Arquivo.hpp"

void limparBuffer()
{
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}

int main()
{
    Biblioteca bib;
    Fila fila;
    Arquivo arq;
    arq.carregar(bib, "biblioteca.txt");

    int opcao = -1;

    while (opcao != 0)
    {
        std::cout << "\n=== Rhythm of a Lifetime ===" << std::endl;
        std::cout << "1. Cadastrar Musica" << std::endl;
        std::cout << "2. Mostrar Biblioteca" << std::endl;
        std::cout << "3. Adicionar na Fila (fim)" << std::endl;
        std::cout << "4. Adicionar na Fila (inicio)" << std::endl;
        std::cout << "5. Pular Musica" << std::endl;
        std::cout << "6. Mostrar Fila" << std::endl;
        std::cout << "0. Sair" << std::endl;
        std::cout << "Escolha uma opcao: ";

        if (!(std::cin >> opcao))
        {
            std::cout << "Entrada invalida! Por favor, digite um numero." << std::endl;
            limparBuffer();
            continue;
        }

        limparBuffer();

        if (opcao == 1)
        {
            std::string titulo, artista, album;
            int min, seg, duracao;
            char separador;

            std::cout << "Artista: ";
            std::getline(std::cin, artista);
            std::cout << "Album: ";
            std::getline(std::cin, album);
            std::cout << "Titulo: ";
            std::getline(std::cin, titulo);

            std::cout << "Duracao (ex: 4:24 ou 4.24): ";

            if (!(std::cin >> min >> separador >> seg) || min < 0 || seg < 0 || seg >= 60)
            {
                std::cout << "Duracao invalida! Use o formato MM:SS." << std::endl;
                limparBuffer();
                continue;
            }

            duracao = (min * 60) + seg;
            limparBuffer();

            if (bib.cadastrar(titulo, artista, album, duracao))
            {
                std::cout << "Musica cadastrada com sucesso!" << std::endl;
            }
            else
            {
                std::cout << "Erro: Essa musica ja existe na biblioteca!" << std::endl;
            }
        }
        else if (opcao == 2)
        {
            bib.listar();
        }
        else if (opcao == 3 || opcao == 4)
        {
            int id;
            std::cout << "Digite o ID da musica: ";
            if (std::cin >> id)
            {
                if (bib.existeMusica(id))
                {
                    if (opcao == 3)
                        fila.adicionarNoFim(id);
                    else
                        fila.adicionarNoInicio(id);
                    std::cout << "Musica adicionada a fila!" << std::endl;
                }
                else
                {
                    std::cout << "Erro: Musica nao encontrada na biblioteca." << std::endl;
                }
            }
            else
            {
                std::cout << "ID invalido." << std::endl;
                limparBuffer();
            }
        }
        else if (opcao == 5)
        {
            fila.pularMusica();
        }
        else if (opcao == 6)
        {
            fila.mostrarFila();
        }
        else if (opcao == 0)
        {
            std::cout << "Salvando a biblioteca..." << std::endl;
            arq.salvar(bib, "biblioteca.txt");
            std::cout << "Ate logo!" << std::endl;
        }
        else
        {
            std::cout << "Opcao inexistente." << std::endl;
        }
    }

    return 0;
}