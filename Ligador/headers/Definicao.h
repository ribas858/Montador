#ifndef DEFINICAO_H
#define DEFINICAO_H

#include <iostream>

class Definicao {

    public:
        const std::string& GetRotulo() const {
            return rotulo;
        }

        const int& GetEndereco() const {
            return endereco;
        }

        std::string& SetRotulo() {
            return rotulo;
        }

        int& SetEndereco() {
            return endereco;
        }

    private:
        std::string rotulo;
        int endereco;
};

#endif
