#include "includes.h"

typedef struct  {
    string rotulo;
    int endereco;
} tsb; // Tabela de Simbolos

typedef struct  {
    string instrucao;
    int operando;
    int codigo;
    int tamanho;
} ti; // Tabela de instruções 

typedef struct  {
    string instrucao;
    int operando;
    int tamanho;
} td; // Tabela de diretivas

typedef struct {
    int form[2];
    int op_c;
} enunciado; // Enunciado

map<string,ti> tab_inst;    // Map tabela de instruções
map<string,td> tab_diret;   // Map tabela de diretivas
map<string,tsb> tab_simbol;  // Map tabela de simbolos
enunciado enunc;


list<int> diretivas_final;
list<string> bff_for_errors;
int forma_linha[2] = {-1, -1};

// for (int i=0; i<2; i++){
//     cout << forma_linha[i] << " ";
// }
// cout << endl;

// tsb simbol;
// simbol.rotulo = "ADD";
//     simbol.endereco = 200;
    
//     tab_simbol.insert(pair<string, tsb> ("ADD", simbol));
// arq_cod1.seekg(-1, ios::cur); -- VOLTA UMA POSIÇÃO NO ARQUIVO

// ESTADOS
char Q1 = 'A', Q2 = 'D', Q3 = 'D',                                      // ADD
    Q5 = 'C', Q6 = 'O', Q7 = 'P', Q8 = 'Y',                             // COPY
    Q10 = 'C', Q11 = 'O', Q12 = 'N', Q13 = 'S', Q14 = 'T',              // CONST
    Q16 = 'D', Q17 = 'I', Q18 = 'V',                                    // DIV
    Q20 = 'I', Q21 = 'N', Q22 = 'P', Q23 = 'U', Q24 = 'T',              // INPUT
    Q26 = 'I', Q27 = 'F',                                               // IF
    Q29 = 'J', Q30 = 'M', Q31 = 'P',                                    // JMP
    Q33 = 'J', Q34 = 'M', Q35 = 'P', Q36 = 'N',                         // JMPN
    Q38 = 'J', Q39 = 'M', Q40 = 'P', Q41 = 'P',                         // JMPP
    Q43 = 'J', Q44 = 'M', Q45 = 'P', Q46 = 'Z',                         // JMPZ
    Q48 = 'L', Q49 = 'O', Q50 = 'A', Q51 = 'D',                         // LOAD
    Q53 = 'M', Q54 = 'U', Q55 = 'L', Q56 = 'T',                         // MULT
    Q58 = 'M', Q59 = 'A', Q60 = 'C', Q61 = 'R', Q62 = 'O',              // MACRO
    Q64 = 'O', Q65 = 'U', Q66 = 'T', Q67 = 'P', Q68 = 'U', Q69 = 'T',   // OUTPUT
    Q71 = 'S', Q72 = 'T', Q73 = 'O', Q74 = 'P',                         // STOP
    Q76 = 'S', Q77 = 'T', Q78 = 'O', Q79 = 'R', Q80 = 'E',              // STORE
    Q82 = 'S', Q83 = 'U', Q84 = 'B',                                    // SUB
    Q86 = 'S', Q87 = 'P', Q88 = 'A', Q89 = 'C', Q90 = 'E',              // SPACE
    Q92 = 'E', Q93 = 'N', Q94 = 'D', Q95 = 'M', Q96 = 'A',Q97 = 'C',    //
        Q98 = 'R', Q99 = 'O',                                           // ENDMACRO
    Q101 = 'E', Q102 = 'Q', Q103 = 'U';                                 // EQU

tab_inst = ler_tab_instr(tab_inst);     // Tabela de instruções
tab_diret = ler_tab_diret(tab_diret);   // Tabela de diretivas

ifstream arq_cod1 (argv[2]);

// cout << "argv 0: " << argv[0] << endl;
// cout << "argv 1: " << argv[1] << endl;
// cout << "argv 2: " << argv[2] << endl;
// cout << "argv 3: " << argv[3] << endl;

ofstream arq_saida (argv[3]);
if (! arq_saida) { 
    cout << "Arquivo saida.txt nao pode ser aberto" << endl;
    abort();
}

char c, b_space;
string lexema;
int line_count = 0, pos_count = 0, ign_coment = 0, estado = 0, op_count = 0, last_inst = 0;