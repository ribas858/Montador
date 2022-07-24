#include "../../headers/estados/Q9.h"
#include "../../headers/Functions.h"


void Q9::Caso(map<string, Instrucao>& tab_inst, map<string, Diretiva>& tab_diret, map<string, Simbolo>& tab_simbol,
            Enunciado& enunc, list<int>& diretivas_final, list<string>& bff_for_errors, int* forma_linha, char& c, char& b_space,
                std::string& lexema, int& line_count, int& pos_count, int& ign_coment, int& estado, int& op_count, int& last_inst,
                    class Instrucao inst, class Diretiva diret, int& ender_simbol, ofstream& arq_saida, int& passagem) {

        cout << "ESTADO Q9: ";

    if (isdigit(c)) { // Se é Número DPS de letra
        lexema += c;
        estado = 9;
    } else if ( c == ' ') {
        b_space = c;
        lexema = "";
        estado = 0;
    } else if (c == '\n') {
        b_space = c;
        lexema = "";
        estado = 0;
    } else if (c != ':') {
        lexema += c;
        estado = 9;
    } else {
        if (passagem == 1) {
            cout << "ERRO LÉXICO -- Linha: " << line_count << " | Formato do Rótulo '" << lexema << "' Inválido" << endl;
                            }
        b_space = c;
        lexema = "";
        estado = 0; // erro
                        }

    cout << "É um numero: '" << c << "'" << " Passagem: " << passagem << endl;
}                       