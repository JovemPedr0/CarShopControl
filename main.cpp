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
            vcl = new Carro();
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

void exibeMenu(){
    cout << "------------------------------------------------------------------------------------------------" << endl;
        cout << "   1 - Cadastrar Veí­culo" << 
              "\n   2 - Visualizar Estoque de Veí­culos" << 
              "\n   3 - Adicionar Veículo ao Estoque" << 
              "\n   4 - Remover Veí­culo do Estoque" << 
              "\n   5 - Sair" << endl;
}

void AdicionarEstoque(){
    int codigo, quantidade, escolha;

    while(1){
        
        cout << "Digite o código do veí­culo a adicionar no estoque: " << endl;
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

                cout << "Escolha em qual loja será vendido o veí­culo: " << veiculos[i]->getModeloDoVeiculo()
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
    int opcao = 0, estoqueEscolhido;

    lojas[0] = Concessionaria("Loja Matriz", Endereco("10102300", "Avenida Nego", 99));
    lojas[1] = Concessionaria("Loja Filial", Endereco("59871234", "Avenida Tirandentes", 45));
   
    while (opcao != 5){
        system("cls");
        exibeMenu();
        cin >> opcao;

        switch(opcao){
            case 1:
                system("cls");
                CadastroVeiculo();
                break;

            case 2:
                system("cls");
                cout << "Digite qual estoque deseja ver: ('1 - para a loja Matriz e 2 - para a Filial')" << endl;
                cin >> estoqueEscolhido;
         
                if(estoqueEscolhido == 0){
                    lojas[0].exibirEstoque();
                    system("pause");
                }else{
                    lojas[1].exibirEstoque();
                    system("pause");
                }   
                break;

            case 3:
                system("cls");
                AdicionarEstoque();
                break;

            case 4:
                system("cls");
                DiminuirEstoque();
                break;
            
            case 5:
                system("cls");
                printf("Você pediu para sair, fechando programa\n");
                printf("Obrigado por usar nosso sistema!");
                for(int a = 0; a < 3; a++){
                    printf("=");
                    printf("D");
                    printf(" ");
                    Sleep(300);
                }
                exit(0);
                break;
        }

    }
    
    return 0;
}
