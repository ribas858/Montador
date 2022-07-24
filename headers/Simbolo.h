#ifndef SIMBOLO_H
#define SIMBOLO_H

#include <iostream>

class Simbolo {

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
