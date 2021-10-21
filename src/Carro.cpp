#include "Carro.hpp"
#include <iostream>

Carro::Carro(){
    tipoDeCarro = "-";
    numeroDePortas = 0;
    tipoDeMotor = "-";
}

Carro::~Carro(){
    //DESTRUTOR
}

std::string Carro::getTipoDeCarro(){
    return tipoDeCarro;
}

int Carro::getNumeroDePortas(){
    return numeroDePortas;
}

std::string Carro::getTipoDeMotor(){
    return tipoDeMotor;
}

void Carro::setTipoDeCarro(std::string tipoDeCarro){
    this->tipoDeCarro = tipoDeCarro;
}

void Carro::setNumeroDePortas(int numeroDePortas){
    if(numeroDePortas > 0){
        this->numeroDePortas = numeroDePortas;
    }else{
        numeroDePortas = 0;
    }
}

void Carro::setTipoDeMotor(std::string tipoDeMotor){
    this->tipoDeMotor = tipoDeMotor;
}

void Carro::lerAtributos(){
    std::string marcaRecebida, modeloRecebido, corRecebida, tipoDeCarroRecebido, tipoDeMotorRecebido;
    int anoRecebido, numeroDePortasRecebido, codigoVeiculoRecebido;
    double precoRecebido;

    setNomeDoVeiculo("Carro");

    std::cout << "Digite o codigo do Carro: " << std::endl;
    do{
        std::cin >> codigoVeiculoRecebido;
        if(codigoVeiculoRecebido < 0){
            std::cout << "Código Inválido, insira novamente!" << std::endl;
        }
    }while(codigoVeiculoRecebido < 0);
    setCodigoDoVeiculo(codigoVeiculoRecebido);
    std::cin.ignore();

    std::cout << "Insira a marca do carro: " << std::endl;
    getline(std::cin, marcaRecebida);
    setMarcaDoVeiculo(marcaRecebida);

    std::cout << "Insira o modelo do carro: " << std::endl;
    getline(std::cin, modeloRecebido);
    setModeloDoVeiculo(modeloRecebido);

    std::cout << "Insira o ano em que o carro foi fabricado: " << std::endl;
    do{
        std::cin >> anoRecebido;
        if(anoRecebido < 0){
            std::cout << "Ano de Fabricação Inválido, insira novamente!" << std::endl;
        }
    }while(anoRecebido < 0);
    setAnoDeFabricacao(anoRecebido);

    std::cout << "Insira valor do carro: "  << std::endl;
    do{
        std::cin >> precoRecebido;
        if(precoRecebido < 0){
            std::cout << "Preço Inválido, insira novamente!" << std::endl;
        }
    }while(precoRecebido < 0);
    setValor(precoRecebido);
    std::cin.ignore();

    std::cout << "Insira o tipo do carro (sedan, popular, esportivo): "  << std::endl;
    getline(std::cin, tipoDeCarroRecebido);
    setTipoDeCarro(tipoDeCarroRecebido);

    std::cout << "Insira a quantidade de portas: " << std::endl;
    do{
        std::cin >> numeroDePortasRecebido;
        if(numeroDePortasRecebido < 0){
            std::cout << "Número de Portas Inválido, insira novamente!" << std::endl;
        }
    }while(numeroDePortasRecebido < 0);
    setNumeroDePortas(numeroDePortasRecebido);
    std::cin.ignore();

    std::cout << "Insira a cor do carro: " << std::endl;
    getline(std::cin, corRecebida);
    setCorDoVeiculo(corRecebida);

    std::cout << "Insira caracteristicas sobre o motor: " << std::endl;
    getline(std::cin, tipoDeMotorRecebido);
    setTipoDeMotor(tipoDeMotorRecebido);
}

void Carro::exibeAtributos(){
    std::cout << getNomeDoVeiculo() << " - " << getCodigoDoVeiculo() << ". " << getMarcaDoVeiculo() << " " << getModeloDoVeiculo() << " - "
    << getAnoDeFabricacao() << "( "  << getTipoDeCarro() << ", "<< getTipoDeMotor() << ", " << getCorDoVeiculo() << ", " << getNumeroDePortas() << " )" << std::endl;

    std::cout << "Por apenas R$ " << getValor() << " à vista" << "\n" << " ou em 24x de R$ " << getValor() / 24 << std::endl;
}
