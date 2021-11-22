#include "CodigoException.hpp"

CodigoException::CodigoException(int i)
{
    cod_erro = i;
}

std::string CodigoException::getMensagem(){
    std::string mensagem;

    switch(cod_erro){
        case 1:
            mensagem = "Erro 001: Nao existe estoque para o modelo selecionado.\n";
            break;

        case 2:
            mensagem = "Erro 002: Codigo nao encontrado no estoque.\n";
            break;

        case 3:
            mensagem = "Erro 003: Codigo ja cadastrado no estoque. Cadastre novamente!\n";
    }

    return mensagem;
}