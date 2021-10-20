#include "Concessionaria.hpp"

Concessionaria::Concessionaria(){
    nomeDaConcessionaria = "-";
    localizacao.setCEP("-");
    localizacao.setLogradouro("-");
    localizacao.setNumeroDaLocalidade(0);
}

Concessionaria::Concessionaria(std::string nomeDaConcessionaria, Endereco localizacao){
    this->nomeDaConcessionaria = nomeDaConcessionaria;
    this->localizacao = localizacao;
}

Concessionaria::~Concessionaria(){
    //DESTRUTOR
}

std::string Concessionaria::getNome(){
    return nomeDaConcessionaria;
}

void Concessionaria::setNome(std::string nomeDaConcessionaria){
    this->nomeDaConcessionaria = nomeDaConcessionaria;
}

void Concessionaria::setVeiculo(Veiculo* vcl){
    estoque.push_back(vcl);
}

void Concessionaria::adicionarEstoque(int qtde, int cod){
    int quantAtual;

    for(unsigned int i = 0; i < estoque.size(); i++){

        if(cod == estoque[i]->getCodigoDoVeiculo()){

            quantAtual = estoque[i]->getQuantidade() + qtde;
            estoque[i]->setQuantidade(quantAtual);
        }
    }
}

void Concessionaria::diminuirEstoque(int cod){
    int quantAtual;

    for(unsigned int i = 0; i < estoque.size(); i++){

        if(cod == estoque[i]->getCodigoDoVeiculo()){
            quantAtual = estoque[i]->getQuantidade() - 1;
            estoque[i]->setQuantidade(quantAtual);
        }
    }
}
