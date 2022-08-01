#ifndef PLUS_H
#define PLUS_H

#include <iostream>

class Plus {

    public:
        const std::string& GetRotulo() const {
            return rotulo;
        }

        const int& GetEndereco() const {
            return endereco;
        }

        const bool& GetExiste() const {
            return existe;
        }

        std::string& SetRotulo() {
            return rotulo;
        }

        int& SetEndereco() {
            return endereco;
        }

        bool& SetExiste() {
            return existe;
        }

    private:
        std::string rotulo;
        int endereco;
        bool existe = true;
};

#endif
