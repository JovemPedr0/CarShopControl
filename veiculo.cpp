#include "Veiculo.hpp"

Veiculo::Veiculo(){
    codigoVeiculo = 0;
    corDoVeiculo = "-";
    marcaDoVeiculo = "-";
    modeloDoVeiculo = "-";
    anoDeFabricacao = 0;
    preco = 0;
    quantidade = 0;
}

Veiculo::~Veiculo(){

    //DESTRUTOR

}

int Veiculo::getCodigoDoVeiculo(){
    return codigoVeiculo;
}

std::string Veiculo::getCorDoVeiculo(){
    return corDoVeiculo;
}

std::string Veiculo::getNomeDoVeiculo(){
    return nomeDoVeiculo;
}

std::string Veiculo::getMarcaDoVeiculo(){
    return marcaDoVeiculo;
}

std::string Veiculo::getModeloDoVeiculo(){
    return modeloDoVeiculo;
}

int Veiculo::getAnoDeFabricacao(){
    return anoDeFabricacao;
}

double Veiculo::getValor(){
    return preco;
}

void Veiculo::setCodigoDoVeiculo(int codigoVeiculo){
    this->codigoVeiculo = codigoVeiculo;
}

void Veiculo::setCorDoVeiculo(std::string corDoVeiculo){
    this->corDoVeiculo = corDoVeiculo;
}

void Veiculo::setNomeDoVeiculo(std::string nomeDoVeiculo){
    this->nomeDoVeiculo = nomeDoVeiculo;
}

void Veiculo::setMarcaDoVeiculo(std::string marcaDoVeiculo){
    this->marcaDoVeiculo = marcaDoVeiculo;
}

void Veiculo::setModeloDoVeiculo(std::string modeloDoVeiculo){
    this->modeloDoVeiculo = modeloDoVeiculo;
}

void Veiculo::setAnoDeFabricacao(int anoDeFabricacao){
    if(anoDeFabricacao > 0){
        this->anoDeFabricacao = anoDeFabricacao;
    }else{
        anoDeFabricacao = 0;
    }
}

void Veiculo::setValor(double preco){
    if(preco > 0){
        this->preco = preco;
    }else{
        preco= 0;
    }
}

void Veiculo::setQuantidade(int qtde){
    quantidade = qtde;
}

int Veiculo::getQuantidade(){
    return quantidade;
}
