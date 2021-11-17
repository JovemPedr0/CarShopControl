#include "Concessionaria.hpp"
#include <iostream>

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

std::string Concessionaria::getNomeConcessionaria(){
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

            if(estoque[i]->getQuantidade() == 0){
                std::cout << "Nao existe estoque para o modelo selecionado." << std::endl;

            }else{
                quantAtual = estoque[i]->getQuantidade() - 1;
                estoque[i]->setQuantidade(quantAtual);
            }
        }
    }
}

void Concessionaria::exibirEstoque(){
    std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
        std::cout << getNomeConcessionaria() << std::endl;
        for (unsigned int i = 0; i < estoque.size(); i++){
            std::cout << estoque[i]->getNomeDoVeiculo() << " de codigo: " << estoque[i]->getCodigoDoVeiculo() << " com a quantidade : " << estoque[i]->getQuantidade()
            << " " << estoque[i]->getMarcaDoVeiculo() << " - " << estoque[i]->getModeloDoVeiculo() << " ( "<< estoque[i]->getAnoDeFabricacao() << ", " <<
            estoque[i]->getCorDoVeiculo() << ", R$ " << estoque[i]->getValor() << " ) " << std::endl;
        }
    std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
}

void Concessionaria::exibeConcessionaria(){
    std::cout << getNomeConcessionaria() << " - " << localizacao.getLogradouro() << ", " << localizacao.getNumeroDaLocalidade() << " - " << localizacao.getCEP() << std::endl;
}

void Concessionaria::salvarConcessionaria(std::ofstream &output){
    for(unsigned int i = 0; i < estoque.size(); i++){
        output << estoque[i]->getNomeDoVeiculo() << "," << estoque[i]->getCodigoDoVeiculo() << "," << estoque[i]->getQuantidade()
            << " " << estoque[i]->getMarcaDoVeiculo() << "," << estoque[i]->getModeloDoVeiculo() << ","<< estoque[i]->getAnoDeFabricacao() << ", " <<
            estoque[i]->getCorDoVeiculo() << "," << estoque[i]->getValor() << std::endl;
    }
}

void Concessionaria::lerEstoque(std::ifstream &input){
    
    while(!input.fail() && !input.bad() && !input.eof() && input.good()) {
        std::cout << "Abrindo" << std::endl;
        int i = 0, codigo, quant, ano;
        std::string nome, marca, modelo, cor;
        double preco;
        Veiculo *vcl;

        std::cin.ignore();
        input >> nome;

        if(input.fail() && input.bad() && input.eof() && !input.good()){
            break;
        }

        if(nome == "Moto"){
            vcl = new Moto();
        }else{
            vcl = new Carro();
        }

        vcl->setNomeDoVeiculo(nome);

        input >> codigo;
        vcl->setCodigoDoVeiculo(codigo);

        input >> quant;
        vcl->setQuantidade(quant);

        std::cin.ignore();
        getline(input, marca);
        vcl->setMarcaDoVeiculo(marca);

        std::cin.ignore();
        getline(input, modelo);
        vcl->setModeloDoVeiculo(modelo);

        input >> ano;
        vcl->setAnoDeFabricacao(ano);

        std::cin.ignore();
        getline(input, cor);
        vcl->setCorDoVeiculo(cor);

        input >> preco;
        vcl->setValor(preco);

        setVeiculo(vcl);
    }

    std::cout << "Ribamar" << std::endl;
}
