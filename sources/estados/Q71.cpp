#include "../../headers/estados/Q71.h"
#include "../../headers/Functions.h"


void Q71::Caso(map<string, Instrucao>& tab_inst, map<string, Diretiva>& tab_diret, map<string, Simbolo>& tab_simbol,
            Enunciado& enunc, list<int>& diretivas_final, list<string>& bff_for_errors, int* forma_linha, char& c, char& b_space,
                std::string& lexema, int& line_count, int& pos_count, int& ign_coment, int& estado, int& op_count, int& last_inst,
                    class Instrucao inst, class Diretiva diret, int& ender_simbol, ofstream& arq_saida, int& passagem, ifstream& arq_cod1) {

      cout << "ESTADO Q71: ";

    lexema += c;
    if (c == 'T'){
        estado = 72;
    } else if ( c == 'U') { // Se é Letra
        lexema = lexema[0];
        cout << "LExema Zera: " << lexema << endl;
        arq_cod1.seekg(-1, ios::cur);
        estado = 82;

    } else if ( c == 'P') { // Se é Letra

        lexema = lexema[0];
        cout << "LExema Zera: " << lexema << " indo pro 86" << endl;
        arq_cod1.seekg(-1, ios::cur);
        estado = 86;
                            
    } else if ( c == 'Z') { // Se é Letra

        lexema = lexema[0];
        cout << "LExema Zera: " << lexema << endl;
        arq_cod1.seekg(-3, ios::cur);
        estado = 43;
                            
    } else if (isalpha(c)) { // Se é Letra
        cout << endl;
        estado = 4;
    } else if (isdigit(c)) { // Se é Número DPS de letra
        estado = 4;
    } else if(c == '_') {   
        estado = 4;
    } else {
        estado = 0; // erro
                        }
}                       