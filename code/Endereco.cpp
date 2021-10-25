#include "Endereco.hpp"

Endereco::Endereco(){
    numeroDoCEP = "-";
    logradouro = "-";
    numeroDaLocalidade = 0;
}

Endereco::Endereco(std::string numeroDoCEP, std::string logradouro, int numeroDaLocalidade){
    this->numeroDoCEP = numeroDoCEP;
    this->logradouro = logradouro;
    this->numeroDaLocalidade = numeroDaLocalidade;
}

Endereco::~Endereco(){
    //DESTRUTOR
}

std::string Endereco::getCEP(){
    return numeroDoCEP;
}

std::string Endereco::getLogradouro(){
    return logradouro;
}

int Endereco::getNumeroDaLocalidade(){
    return numeroDaLocalidade;
}

void Endereco::setCEP(std::string numeroDoCEP){
    this->numeroDoCEP = numeroDoCEP;
}

void Endereco::setLogradouro(std::string logradouro){
    this->logradouro = logradouro;
}

void Endereco::setNumeroDaLocalidade(int numeroDaLocalidade){
    this->numeroDaLocalidade = numeroDaLocalidade;
}
