#include "../../headers/estados/Q100.h"
#include "../../headers/Functions.h"


void Q100::Caso(map<string, Instrucao>& tab_inst, map<string, Diretiva>& tab_diret, map<string, Simbolo>& tab_simbol,
            Enunciado& enunc, list<int>& diretivas_final, list<string>& bff_for_errors, int* forma_linha, char& c, char& b_space,
                std::string& lexema, int& line_count, int& pos_count, int& ign_coment, int& estado, int& op_count, int& last_inst,
                    class Instrucao inst, class Diretiva diret, int& ender_simbol, ofstream& arq_saida, int& passagem) {

    cout << "ESTADO Q100: " << endl;
}                       