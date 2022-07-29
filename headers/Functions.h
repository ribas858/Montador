#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "../headers/Includes.h"

class Functions {

    public:
        static void ler_tab_instr (map<string, Instrucao>& tab_inst);

        static void ler_tab_diret (map<string,Diretiva>& tab_diret);

        static void print_inst_por_key (map<string, Instrucao> tab_inst, string key);

        static void print_diret_por_key (map<string,Diretiva> tab_diret, string key);

        static void print_inst (map<string, Instrucao> tab_inst);

        static void print_diret (map<string,Diretiva> tab_diret);

        static void insere_tab_simbol (map<string,Simbolo>& tab_simbol, string key, int pos, int line);

        static void print_tab_simbol (map<string,Simbolo> tab_simbol);

        static int retur_tam_inst (map<string,Instrucao> tab_inst, string key);

        static int retur_op_inst (map<string,Instrucao> tab_inst, string key);

        static Instrucao retur_inst (map<string,Instrucao> tab_inst, string key);

        static int retur_tam_diret (map<string,Diretiva> tab_diret, string key);

        static int retur_op_diret (map<string,Diretiva> tab_diret, string key);

        static Diretiva retur_diret (map<string,Diretiva> tab_diret, string key);

        static int busca_tab_simbol (map<string,Simbolo> tab_simbol, string key);

        static Enunciado update_enunc(Enunciado enunc, int line_count);

        static bool busca_1(map<string,Instrucao> tab_inst, string key);

        static bool busca_2(map<string,Diretiva> tab_diret, string key);

        static bool busca_instrucao(map<string,Instrucao> tab_inst, map<string,Diretiva> tab_diret, string key);

        static void print_errors(string lexema, int cod, int line_count);

        static bool val_caracts(char l);
        
        static bool rot_valido(string lexema, int cod);

        static void Analise_rot_instr(ifstream& arq_entrada, char& c, string& lexema, map<string, Instrucao>& tab_inst,
            map<string, Diretiva>& tab_diret, int& line_count, string* forma_linha, vector<string>& linha,
            int& begin_line, bool& line_analise, int& estado, pair<int,int>& virgula, int& flag_v, int& flag_test_sec);

        static bool duplicate_vector(vector<string> v, string key);

        static pair<int, int> has_line_instruction(ifstream& arq_entrada, map<string, Instrucao>& tab_inst, map<string, Diretiva>& tab_diret, int begin_line, int cod);

        static pair<bool, string> section_test(ifstream& arq_entrada, int begin_line);

        static void val_sections(int& flag_section, ifstream& arq_entrada, int& begin_line, string& msg, string& passagem_2);

        static string up_file(char *argv);

        static void update_diretivas(map<string, string>& map_diret, map<string, Diretiva>& tab_diret, string& diret, int& flag_ign);

        static string GetNameFile(string src);

        static void passagem1(map<string, Simbolo>& tab_simbol, map<string,Instrucao>& tab_inst, map<string,Diretiva>& tab_diret,
            vector<string>& linha, int& cont_posicao, int& line_count);

        static void passagem2(char* arq_out, map<string, Simbolo>& tab_simbol, map<string,Instrucao>& tab_inst, map<string,Diretiva>& tab_diret,
            string& passagem2, int& cont_posicao, int& line_count);

        static bool isAllDigit(string dig);

};

#endif