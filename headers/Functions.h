#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "../headers/Includes.h"

class Functions {

    public:
        static void ler_tab_instr (map<string, Instrucao>& tab_inst);

        static void ler_tab_diret (map<string,Diretiva>& tab_diret);

        static void ler_tab_extend (map<string, DiretivaExtend>& tab_extend);

        static void print_inst_por_key (map<string, Instrucao> tab_inst, string key);

        static void print_diret_por_key (map<string,Diretiva> tab_diret, string key);

        static void print_inst (map<string, Instrucao> tab_inst);

        static void print_diret (map<string,Diretiva> tab_diret);

        static void print_extend (map<string, DiretivaExtend> tab_extend);

        static void insere_tab_simbol (map<string,Simbolo>& tab_simbol, string key, int pos, int line);

        static void print_tab_simbol (map<string,Simbolo> tab_simbol);

        static int retur_tam_inst (map<string,Instrucao> tab_inst, string key);

        static int retur_op_inst (map<string,Instrucao> tab_inst, string key);

        static Instrucao retur_inst (map<string,Instrucao> tab_inst, string key);

        static int retur_tam_diret (map<string,Diretiva> tab_diret, string key);

        static int retur_op_diret (map<string,Diretiva> tab_diret, string key);

        static Diretiva retur_diret (map<string,Diretiva> tab_diret, string key);

        static void extern_simbol (map<string,Simbolo>& tab_simbol, string key);

        static void public_simbol (map<string, Simbolo>& tab_simbol, map<string, Definicao>& tab_def);

        static int busca_tab_simbol (map<string,Simbolo> tab_simbol, string key);

        static Enunciado update_enunc(Enunciado enunc, int line_count);

        static bool busca_1(map<string,Instrucao> tab_inst, string key);

        static bool busca_2(map<string,Diretiva> tab_diret, string key);

        static bool busca_extend (map<string,DiretivaExtend> tab_extend, string key);

        static bool busca_instrucao(map<string,Instrucao> tab_inst, map<string,Diretiva> tab_diret, string key);

        static void print_errors(string lexema, int cod, int line_count);

        static bool val_caracts(char l);
        
        static bool rot_valido(string lexema, int cod);

        static void Analise_rot_instr(ifstream& arq_entrada, char& c, string& lexema, map<string, Instrucao>& tab_inst,
            map<string, Diretiva>& tab_diret, map<string, DiretivaExtend>& tab_extend, int& line_count, string* forma_linha, vector<string>& linha,
            int& begin_line, bool& line_analise, int& estado, pair<int,int>& virgula, int& flag_v,
            bool* section_t, bool* section_d, int& flag_sec_t, int& flag_sec_d, int& flag_erros, bool& flag_ligador);

        static bool duplicate_vector(vector<string> v, string key);

        static pair<int, int> has_line_instruction(ifstream& arq_entrada, map<string, Instrucao>& tab_inst, map<string, Diretiva>& tab_diret, map<string, DiretivaExtend>& tab_extend, int begin_line, int cod);

        static pair<bool, string> section_test(ifstream& arq_entrada, int begin_line);

        static void val_sections(int& flag_section, ifstream& arq_entrada, int& begin_line, string& msg, string& passagem_2);

        static string up_file(char *argv);

        static void update_diretivas(map<string, string>& map_diret, map<string, Diretiva>& tab_diret, string& diret, int& flag_ign);

        static string GetNameFile(string src, int cod);

        static void passagem1(map<string, Definicao>& tab_def, map<string, Simbolo>& tab_simbol, map<string,Instrucao>& tab_inst, map<string,Diretiva>& tab_diret,
            vector<string>& linha, int& cont_posicao, int& line_count, int& flag_erros, map<string, Plus>& tab_plus);

        static void passagem2(string& cod_obj, map<string, Simbolo>& tab_simbol, map<string,Instrucao>& tab_inst, map<string,Diretiva>& tab_diret,
            string& passagem2, int& cont_posicao, int& line_count, map<string, DiretivaExtend>& tab_extend, map<string, Uso>& tab_uso, map<string, Plus>& tab_plus,
            int& flag_erros);

        static bool isAllDigit(string dig);

        static void insere_tab_def (map<string, Definicao>& tab_def, string key, int pos, int line);

        static void print_tab_def (map<string, Definicao> tab_def);

        static Simbolo return_simbol (map<string,Simbolo> tab_simbol, string key);

        static void insere_tab_uso(map<string, Uso>& tab_uso, string key, int pos, int line);

        static void print_tab_uso (map<string, Uso> tab_uso);

        static void insere_tab_plus (map<string, Plus>& tab_plus, string key, int pos);

        static void print_tab_plus (map<string, Plus> tab_plus);

        static Plus return_plus (map<string,Plus> tab_plus, string key);

};

#endif