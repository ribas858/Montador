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
};

#endif