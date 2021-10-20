#include "Includes.hpp"

using namespace std;

Concessionaria lojas[2];
vector <Veiculo*> veiculos;
int numVeiculos = 0;

void CadastroVeiculo(){
    int tipo;
    Veiculo *vcl;

    cout << "Qual tipo de veículo deseja cadastrar? (1 para MOTO e 2 para CARRO): ";
    cin >> tipo;

    switch(tipo){
        case 1:
            vcl = new Moto();
            break;
        case 2:
            vcl = new Moto();
            break;

        default:
            cout << "Valor Inválido" << endl;
    }

    vcl->lerAtributos();
    numVeiculos++;

    lojas[0].setVeiculo(vcl);
    lojas[1].setVeiculo(vcl);
    veiculos.push_back(vcl);
}

void VisualizarEstoque(){

}

void AdicionarEstoque(){
    int codigo, quantidade, escolha;

    while(1){
        cout << "Digite o código do veículo a adicionar no estoque: " << endl;
        cin >> codigo;

        for(unsigned int i = 0; i < veiculos.size(); i++){

            if(codigo == veiculos[i]->getCodigoDoVeiculo()){
                cout << "Digite a quantidade a ser adicionada:" << endl;
                cin >> quantidade;

                cout << "Escolha em qual loja será adicionada a quantidade de " << quantidade << " veículos: " << veiculos[i]->getModeloDoVeiculo()
                << "(LOJA MATRIZ = 1 / FILIAL = 2)" << endl;
                cin >> escolha;

                switch(escolha){
                    case 1:
                        lojas[0].adicionarEstoque(quantidade, codigo);
                        return;

                    case 2:
                        lojas[1].adicionarEstoque(quantidade, codigo);
                        return;

                        default:
                        cout << "Loja inválida" << endl;
                    }

            }else{
                cout << "Código Inválido" << endl;
            }
        }
    }
}

void DiminuirEstoque(){
    int codigo, escolha;

    while(1){
        cout << "Digite o código do veículo a retirar no estoque: " << endl;
        cin >> codigo;

        for(unsigned int i = 0; i < veiculos.size(); i++){

            if(codigo == veiculos[i]->getCodigoDoVeiculo()){

                cout << "Escolha em qual loja será vendido o veículo: " << veiculos[i]->getModeloDoVeiculo()
                << "(LOJA MATRIZ = 1 / FILIAL = 2)" << endl;
                cin >> escolha;

                switch(escolha){
                    case 1:
                        lojas[0].diminuirEstoque(codigo);
                        return;

                    case 2:
                        lojas[1].diminuirEstoque(codigo);
                        return;

                        default:
                        cout << "Loja inválida" << endl;
                    }

            }else{
                cout << "Código Inválido" << endl;
            }
        }
    }
}

int main(){
    int opcao = 0;

    lojas[0] = Concessionaria("Loja Matriz", Endereco("10102300", "Avenida Nego", 99));
    lojas[1] = Concessionaria("Loja Filial", Endereco("59871234", "Avenida Tirandentes", 45));

    while (opcao != 5){

        cout << "1 - Cadastrar Veículo" << "\n2 - Visualizar Estoque de Veículos" << "\n3 - Adicionar Veículo ao Estoque" << "\n4 - Remover Veículo do Estoque" << "\n5 - Sair" << endl;
        cin >> opcao;

        switch(opcao){
            case 1:
                CadastroVeiculo();

                break;

            case 2:

                break;
            case 3:
                AdicionarEstoque();
                break;

            case 4:
                DiminuirEstoque();
                break;

            case 5:

                break;
        }

    }

    return 0;
}
