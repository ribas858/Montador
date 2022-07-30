#ifndef DIRETIVAEXTEND_H
#define DIRETIVAEXTEND_H

#include <iostream>

class DiretivaExtend {

    public:
        const std::string& GetInstrucao() const {
            return instrucao;
        }

        const int& GetOperando() const {
            return operando;
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

        int& SetTamanho() {
            return tamanho;
        }

    private:
        std::string instrucao;
        int operando;
        int tamanho;

};

#endif