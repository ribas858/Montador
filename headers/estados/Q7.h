#ifndef Q7_H
#define Q7_H

#include <iostream>
#include <list>
#include <map>

using namespace std;

class Q7 {

    public:
        static void Caso(map<std::string, class Instrucao>& tab_inst, map<std::string, class Diretiva>& tab_diret, map<std::string, class Simbolo>& tab_simbol,
            class Enunciado& enunc, list<int>& diretivas_final, list<std::string>& bff_for_errors, int* forma_linha, char& c, char& b_space,
                std::string& lexema, int& line_count, int& pos_count, int& ign_coment, int& estado, int& op_count, int& last_inst,
                    class Instrucao inst, class Diretiva diret, int& ender_simbol, ofstream& arq_saida, int& passagem);

};

#endif

 