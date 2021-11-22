#ifndef CODIGOEXCEPTION_HPP
#define CODIGOEXCEPTION_HPP

#include <exception>
#include <string>

class CodigoException : public std::exception
{
    public:
        CodigoException(int i);
        std::string getMensagem();

    protected:
        int cod_erro;

    private:
};

#endif // CODIGOEXCEPTION_HPP