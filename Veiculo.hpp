#ifndef VEICULO_HPP
#define VEICULO_HPP
#include <string>

class Veiculo{
    protected:
        std::string nomeDoVeiculo;
        int codigoVeiculo;
        std::string marcaDoVeiculo;
        std::string modeloDoVeiculo;
        std::string corDoVeiculo;
        int anoDeFabricacao;
        double preco;
        int quantidade;


    public:
        Veiculo();
        ~Veiculo();

        virtual void lerAtributos() = 0;
        virtual void exibeAtributos() = 0;

        int getCodigoDoVeiculo();
        std::string getCorDoVeiculo();
        std::string getNomeDoVeiculo();
        std::string getMarcaDoVeiculo();
        std::string getModeloDoVeiculo();
        int getAnoDeFabricacao();
        double getValor();
        int getQuantidade();

        void setCodigoDoVeiculo(int codigoVeiculo);
        void setCorDoVeiculo(std::string corDoVeiculo);
        void setNomeDoVeiculo(std::string nomeDoVeiculo);
        void setMarcaDoVeiculo(std::string marcaDoVeiculo);
        void setModeloDoVeiculo(std::string modeloDoVeiculo);
        void setAnoDeFabricacao(int anoDeFabricacao);
        void setValor(double preco);
        void setQuantidade(int qtde);

};

#endif // VEICULO_HPP
