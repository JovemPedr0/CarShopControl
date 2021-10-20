#ifndef ENDERECO_HPP
#define ENDERECO_HPP
#include <string>


class Endereco{
    protected:
        std::string numeroDoCEP;
        std::string logradouro;
        int numeroDaLocalidade;

    public:
        Endereco();
        Endereco(std::string numeroDoCEP, std::string logradouro, int numeroDaLocalidade);
        ~Endereco();

        std::string getCEP();
        std::string getLogradouro();
        int getNumeroDaLocalidade();

        void setCEP(std::string numeroDoCEP);
        void setLogradouro(std::string logradouro);
        void setNumeroDaLocalidade(int numeroDaLocalidade);
};

#endif //Endereco.hpp