#ifndef CONCESSIONARIA_HPP
#define CONCESSIONARIA_HPP
#include <string>
#include "Endereco.hpp"
#include <vector>
#include "Veiculo.hpp"
#include <fstream>
#include "Carro.hpp"
#include "Moto.hpp"

class Concessionaria{
    protected:
        std::string nomeDaConcessionaria;
        Endereco localizacao;
        std::vector <Veiculo*> estoque;

    public:
        Concessionaria();
        Concessionaria(std::string nomeDaConcessionaria, Endereco localizacao);
        ~Concessionaria();

        std::string getNomeConcessionaria();

        void setNome(std::string nomeDaConcessionaria);
        void setVeiculo(Veiculo* vcl);
        void adicionarEstoque(int qtde, int cod);
        void diminuirEstoque(int cod);
        void exibirEstoque();

        void exibeConcessionaria();
        void salvarConcessionaria(std::ofstream &output);
        void lerEstoque(std::ifstream &input);

};



#endif //Concessionaria.hpp
