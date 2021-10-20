#include "Includes.hpp"

using namespace std;

int a, b, L, L2; // DeclaraÃ§Ã£o das vÃ¡riaveis das setas
int co, L3, L4; // Novas declaraÃ§Ãµes do menu

void gotoxy(int x,int y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

int main() {
    /* MENU */
    int opcao;
    setlocale(LC_ALL, "Portuguese"); // Definindo portuguÃªs como linguagem padrÃ£o
    int numVeiculos = 0;
    Concessionaria lojas[2];
    vector <Veiculo*> veiculos;
    do{
        inicio:
        opcao = 0;
        L = 2;
        L2 = 2;
        b = 2;
        system("cls"); // Limpar a tela dos comandos anteriores
        system("color 1F"); // Definindo a cor do fundo e a letra no cmd
        printf("Dica: Precione a tecla ESQ a qualquer momento para voltar para o menu principal!");


        /*modificando o valor de co muda a coluna de inicio do menu que pose ser de zero ate 63*/
        /*modificando o valor de L muda a linha de inicio do menu que pode ser de zero ate 20*/
        opcao = 0;
        co = 0;/*co Ã© a coluna onde colocar a seta*/
        L = 3;/*L Ã© a linha onde fica as opÃ§Ãµes, mudando as opÃ§Ãµes p/baixo mude o valor de L igual*/
        L2 = L;    /*L2 Ã© onde estava a seta */
        L3 = L + 4;  /*L3 Ã© a linha final do menu*/
        L4 = L;    /*L4 Ã© a linha de inicio do menu*/
        //system("color 4F"); /*// Definindo a cor do fundo e a letra no cmd*/

        gotoxy(co + 5,L);     // co Ã© a coluna de inicio do menu e L Ã© a linha de inico do menu
        printf("1 - CADASTRAR VEÍCULO");
        gotoxy(co + 5,L + 1);
        printf("2 - VISUALIZAR ESTOQUE DE VEÍCULOS");
        gotoxy(co + 5,L + 2);
        printf("3 - COMPRAR VEÍCULO");
        gotoxy(co + 5,L + 3);
        printf("4 - VENDER VEÍCULO");
        gotoxy(co + 5,L + 4);
        printf("5 - SAIR\n");

        do{                       /*loop para movimentar a seta*/
            gotoxy(co + 2,L);       /*gotoxy posiciona o cursor, o co Ã© a coluna e L Ã© a linha onde imprimir a seta*/
            printf("-%c",16);     /*imprime a seta*/
            gotoxy(0,23);         /*posiciona o cursor fora da tela para ele nÃ£o ficar piscando*/
            if(kbhit){
                a = getch();
            } /*se alguma tecla foi pressionada a igual a tecla*/
            if(a == 80){          /*80 Ã© valor do cactere seta p/baixo do teclado*/
                L2 = L;             /*L2 Ã© posiÃ§Ã£o onde estava a seta para apagar senao fica duas setas*/
                L++;              /*L aponta para a nova posiÃ§Ã£o da seta*/
                if(L > L3){
                    L = L4;
                }   /*L vai de 2 ate 5 pois Ã© onde estÃ£o as 4 opÃ§Ãµes, mudando mude tambem os valores*/
            }                     /*a seta estando no 4 e for movida p/baixo ela vai para a primeira opÃ§Ã£o*/
            if(a == 72){          /*72 Ã© valor do cactere seta p/cima do teclado*/
                L2 = L;             /*L2 Ã© onde estava a seta para apagar*/
                L--;              /*L aponta para a nova posiÃ§Ã£o da seta*/
                if(L < L4){
                    L = L3;
                }   /*a seta estando no 1 e for movida p/cima ela vai para a ultima opÃ§Ã£o*/
            }
            if(L!=L2){            /*se a seta for movida */
                gotoxy(co + 2,L2);  /*posicione o cursor onde estava a seta*/
                printf("  ");     /*imprime espaÃ§os em branco(que sao pretos) em cima da seta para apaga-la*/
                L2 = L;             /*L2 igual a nova posiÃ§Ã£o da seta*/
            }
            if(a == 13){          /*se a tecla enter for pressionada*/
                opcao = L - (L4 - 1);        /*opcao igual a linha onde esta a opÃ§Ã£o menos um, pois a primeira opÃ§Ã£o */
                                  /*esta na linha 2*/
            }
        }while(opcao == 0);       /*repete enquanto opcao igual a zero*/

    switch (opcao) {
        case 1:
            system("cls");
            printf("Cadastre seu Veículo!\n");
             int tipo;
    
                cout << "Qual tipo de veículo deseja cadastrar? (1 para MOTO e 2 para CARRO): ";
                cin >> tipo;

                if(tipo == 1){
                    veiculos.push_back(new Moto());
                
                }else if(tipo == 2){
                    veiculos.push_back(new Carro());
                
                }else{
                    cout << "Digite uma opção válida(1 para MOTO e 2 para CARRO): ";
                    cin >> tipo;
                }

                veiculos[numVeiculos]->lerAtributos();
                numVeiculos++;
            /*do{
                if(kbhit){
                    a = getch();
                }
            }while(a != 27);*/
            break;
        case 2:
            system("cls");
            printf("Visualizar Estoque de Veículos!\n");
            do{
                if(kbhit){
                    a = getch();
                }
            }while(a != 27);
            break;
        case 3:
            system("cls");
            printf("Comprar Veí­culo\n");
            do{
                if(kbhit){
                    a = getch();
                }
            }while(a != 27);
            break;
        case 4:
            system("cls");
            printf("Vender Veículo\n");
            do{
                if(kbhit){
                    a = getch();
                }
            }while(a != 27);
            break;
        case 5:
            system("cls");
            printf("Você pediu para sair, fechando programa");
            for(a = 0; a < 3; a++){
                printf(".");
                Sleep(300);
            }
            //printf("!\n\n");
            exit(0);
        default:
            system("cls");
            printf("Você deve escolher uma opção válida\n");
            printf("Precione qualquer tecla para voltar ao menu\n");
            system("pause");
            goto inicio;
        }
    }while(opcao != 5);
}