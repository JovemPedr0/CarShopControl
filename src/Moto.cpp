#include "Moto.hpp"

#include <iostream>

Moto::Moto(){
    numeroDeCilindradas = 0;
}

Moto::~Moto(){
    //DESTRUTOR
}

int Moto::getNumeroDeCilindradas(){
    return numeroDeCilindradas;
}

void Moto::setNumeroDeCilindradas(int numeroDeCilindradas){
    if(numeroDeCilindradas > 0){
        this->numeroDeCilindradas = numeroDeCilindradas;
    }else{
        numeroDeCilindradas = 0;
    }
}

void Moto::lerAtributos(){
    std::string marcaRecebida, modeloRecebido, corRecebida;
    int anoRecebido, numeroDeCilindradasRecebido, codigoVeiculoRecebido;
    double precoRecebido;

    setNomeDoVeiculo("Moto");

    std::cout << "Digite o codigo da moto: " << std::endl;
    do{
        std::cin >> codigoVeiculoRecebido;
        if(codigoVeiculoRecebido < 0){
            std::cout << "Código Inválido, insira novamente!" << std::endl;
        }
    }while(codigoVeiculoRecebido > 0);
    setCodigoDoVeiculo(codigoVeiculoRecebido);
    std::cin.ignore();

    std::cout << "Insira a marca da moto: " << std::endl;
    getline(std::cin, marcaRecebida);
    setMarcaDoVeiculo(marcaRecebida);

    std::cout << "Insira o modelo da moto: " << std::endl;
    getline(std::cin, modeloRecebido);
    setModeloDoVeiculo(modeloRecebido);

    std::cout << "Insira o ano em que a moto foi fabricada: " << std::endl;
    do{
        std::cin >> anoRecebido;
        if(anoRecebido < 0){
            std::cout << "Ano de Fabricação Inválido, insira novamente!" << std::endl;
        }
    }while(anoRecebido < 0);
    setAnoDeFabricacao(anoRecebido);

    std::cout << "Insira valor da moto: "  << std::endl;
    do{
        std::cin >> precoRecebido;
        if(precoRecebido < 0){
            std::cout << "Preço Inválido, insira novamente!" << std::endl;
        }
    }while(precoRecebido < 0);    
    setValor(precoRecebido);

    std::cout << "Insira a quantidade de cilindradas: " << std::endl;
    do{
        std::cin >> numeroDeCilindradasRecebido;
        if(numeroDeCilindradasRecebido < 0){
            std::cout << "Número de Cilindradas Inválido, insira novamente!" << std::endl;
        }
    }while(numeroDeCilindradasRecebido < 0);
    setNumeroDeCilindradas(numeroDeCilindradasRecebido);
    std::cin.ignore();

    std::cout << "Insira a cor da Moto: " << std::endl;
    getline(std::cin, corRecebida);
    setCorDoVeiculo(corRecebida);
}

void Moto::exibeAtributos(){
    std::cout << getNomeDoVeiculo() << " - " << getCodigoDoVeiculo() << ". " << getMarcaDoVeiculo() << " " << getModeloDoVeiculo() << " - " << getAnoDeFabricacao() << "( " << getNumeroDeCilindradas() << ", " << getCorDoVeiculo() << " )" << std::endl;

    std::cout << "Por apenas R$ " << getValor() << " à vista" << "\n" << "ou em 24x de R$ " << getValor() / 24 << std::endl;

}
