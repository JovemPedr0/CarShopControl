#ifndef MOTO_HPP
#define MOTO_HPP

#include <string>

#include "Veiculo.hpp"

class Moto: public Veiculo{
    protected:
        int numeroDeCilindradas;

    public:
        Moto();
        ~Moto();

        int getNumeroDeCilindradas();

        void setNumeroDeCilindradas(int numeroDeCilindradas);

        void lerAtributos();
        void exibeAtributos();


};

#endif // CARRO_HPP
