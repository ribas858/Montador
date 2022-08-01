#ifndef INSTRUCAO_H
#define INSTRUCAO_H

#include <iostream>

class Instrucao {

    public:
        const std::string& GetInstrucao() const {
            return instrucao;
        }

        const int& GetOperando() const {
            return operando;
        }

        const int& GetCodigo() const {
            return codigo;
        }

        const int& GetTamanho() const {
            return tamanho;
        }

        std::string& SetInstrucao() {
            return instrucao;
        }

        int& SetOperando() {
            return operando;
        }

        int& SetCodigo() {
            return codigo;
        }

        int& SetTamanho() {
            return tamanho;
        }

    private:
        std::string instrucao;
        int operando;
        int codigo;
        int tamanho;
};


// class Foo
// {
// private:
//     X x_;

// public:
//     X&       x()        { return x_; }
//     const X& x() const  { return x_; }
// };

#endif