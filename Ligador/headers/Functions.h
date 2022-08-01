#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "../headers/Includes.h"

class Functions {

    public:
        static void ler_tab_instr (map<string, Instrucao>& tab_inst);
        static void insere_tab_def (map<string, Definicao>& tab_def, string key, int pos, int line);
        static void insere_tab_uso(map<string, Uso>& tab_uso, string key, int pos, int line);
        static void print_tab_def (map<string, Definicao> tab_def);
        static void print_tab_uso (map<string, Uso> tab_uso);

        static int retur_op_inst_cod(map<string,Instrucao> tab_inst, int key);
        static string up_file(char *argv);
        static string GetNameFile(string src, int cod);
        static bool isAllDigit(string dig);

        static void tabs_ligador(map<string, Definicao>& tab_def, map<string, Uso>& tab_uso, string& linha, int& flag_uso, int& flag_def,
            int flag_cod, vector<int>& cod_obj);

        static void ler_arquivos(char* arq_a, char* arq_b, map<string, Definicao>& tab_def_a, map<string, Uso>& tab_uso_a, vector<int>& cod_obj_a,
            map<string, Definicao>& tab_def_b, map<string, Uso>& tab_uso_b, vector<int>& cod_obj_b);
};

#endif