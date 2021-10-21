#ifndef CARRO_HPP
#define CARRO_HPP
#include <string>
#include "Veiculo.hpp"

class Carro: public Veiculo{
    protected:
        std::string tipoDeCarro;
        int numeroDePortas;
        std::string tipoDeMotor;

    public:
        Carro();
        ~Carro();

        std::string getTipoDeCarro();
        int getNumeroDePortas();
        std::string getTipoDeMotor();

        void setTipoDeCarro(std::string tipoDeCarro);
        void setNumeroDePortas(int numeroDePortas);
        void setTipoDeMotor(std::string tipoDeMotor);

        void lerAtributos();
        void exibeAtributos();


};

#endif // CARRO_HPP