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

        const bool& GetExterno() const {
            return externo;
        }

        const bool& GetPublico() const {
            return publico;
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

        bool& SetExterno() {
            return externo;
        }
        
        bool& SetPublico() {
            return publico;
        }

        bool& SetExiste() {
            return existe;
        }

    private:
        std::string rotulo;
        int endereco;
        bool externo;
        bool publico;
        bool existe = true;

};

#endif
