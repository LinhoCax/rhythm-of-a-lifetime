#include <iostream>
#include <stdexcept>
#include <string>
#include "Biblioteca.hpp"
#include "Fila.hpp"
#include "Arquivo.hpp"

int main()
{
    Biblioteca bib;
    Fila fila;
    Arquivo arq;

    try
    {
        arq.carregar(bib, "biblioteca.txt");
    }
    catch (const std::exception &e)
    {
        std::cout << "Aviso ao carregar dados: " << e.what() << std::endl;
    }

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

        std::string entradaOpcao;
        if (!std::getline(std::cin, entradaOpcao))
        {
            break;
        }

        try
        {
            opcao = std::stoi(entradaOpcao);
        }
        catch (const std::exception &)
        {
            std::cout << "Entrada invalida! Por favor, digite um numero." << std::endl;
            continue;
        }

        if (opcao == 1)
        {
            std::string titulo, artista, album, entradaDuracao;

            std::cout << "Artista: ";
            std::getline(std::cin, artista);
            std::cout << "Album: ";
            std::getline(std::cin, album);
            std::cout << "Titulo: ";
            std::getline(std::cin, titulo);
            std::cout << "Duracao (ex: 4:24 ou 4.24): ";
            std::getline(std::cin, entradaDuracao);

            try
            {
                size_t pos = entradaDuracao.find(':');
                if (pos == std::string::npos)
                {
                    pos = entradaDuracao.find('.');
                }
                if (pos == std::string::npos)
                {
                    throw std::invalid_argument("Formato de duracao invalido! Use MM:SS.");
                }

                int min = std::stoi(entradaDuracao.substr(0, pos));
                int seg = std::stoi(entradaDuracao.substr(pos + 1));

                if (min < 0 || seg < 0 || seg >= 60)
                {
                    throw std::invalid_argument("Minutos ou segundos fora do intervalo valido.");
                }

                int duracao = (min * 60) + seg;
                bib.cadastrar(titulo, artista, album, duracao);
                std::cout << "Musica cadastrada com sucesso!" << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cout << "Erro: " << e.what() << std::endl;
            }
        }
        else if (opcao == 2)
        {
            bib.listar();
        }
        else if (opcao == 3 || opcao == 4)
        {
            std::string entradaId;
            std::cout << "Digite o ID da musica: ";
            std::getline(std::cin, entradaId);

            try
            {
                int id = std::stoi(entradaId);
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
            catch (const std::exception &)
            {
                std::cout << "Erro: ID invalido! Digite um numero inteiro." << std::endl;
            }
        }
        else if (opcao == 5)
        {
            try
            {
                fila.pularMusica();
                std::cout << "Musica pulada!" << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cout << "Erro: " << e.what() << std::endl;
            }
        }
        else if (opcao == 6)
        {
            fila.mostrarFila();
        }
        else if (opcao == 0)
        {
            try
            {
                std::cout << "Salvando a biblioteca..." << std::endl;
                arq.salvar(bib, "biblioteca.txt");
                std::cout << "Ate logo!" << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cout << "Erro ao salvar: " << e.what() << std::endl;
            }
        }
        else
        {
            std::cout << "Opcao inexistente." << std::endl;
        }
    }

    return 0;
}