#include "./headers/Functions.h"

int main (int argc, char **argv) {

    map<string, Instrucao> tab_inst;    // Map tabela de instruções
    map<string,Diretiva> tab_diret;   // Map tabela de diretivas
    map<string, Simbolo> tab_simbol;  // Map tabela de simbolos
    Enunciado enunc;


    list<int> diretivas_final;
    list<string> bff_for_errors;
    bool forma_linha[2] = {false, false};
    bool forma_op[2] = {false, false};

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

    Functions::ler_tab_instr(tab_inst);     // Tabela de instruções
    Functions::ler_tab_diret(tab_diret);   // Tabela de diretivas

    ifstream arq_cod1 (argv[2]);

    ofstream arq_saida (argv[3]);
    if (! arq_saida) { 
        cout << "Arquivo saida.txt nao pode ser aberto" << endl;
        abort();
    }
    
    char c, b_space;
    string lexema;
    int line_count = 1;
    int pos_count = 0, ign_coment = 0, estado = 0, op_count = 0, last_inst = 0;
    
    vector<string> linha;
    int begin_line = 0;

    if (arq_cod1.is_open()){
        for (int passagem = 0; passagem <= 0; passagem++) {
            
            arq_cod1.close();
            ifstream arq_cod1 (argv[2]);

            Instrucao inst;
            Diretiva diret;
            string rot = "";
            bool line_analise = true;
            int pos_inst = -2;

            while(arq_cod1.good()){
                arq_cod1.get(c);

                
                
                Functions::Analise_rot_instr(arq_cod1, c, lexema, tab_inst, tab_diret, line_count, forma_linha, linha, rot, begin_line, line_analise, pos_inst);

                
                

                if (c == '\n') {
                    begin_line = arq_cod1.tellg();
                    line_analise = true;
                    cout << "=================== Linha: ";
                    for (int i = 0; i < linha.size(); i++) {
                        cout << linha[i] << " ";
                    }
                    cout << endl;

                    //cout << "\n\n Fim da linha: "<< line_count << " Rotulo[" << forma_linha[0] << "] | Instrução[" << forma_linha[1] << "]" << endl;
                    if (forma_linha[0] && !forma_linha[1]) {
                        forma_linha[0] = true;
                    } else if (forma_linha[0] && forma_linha[1]) {
                        linha.clear();
                        forma_linha[0] = false;
                    } else if (!forma_linha[0] && forma_linha[1]) {
                        linha.clear();
                    } else if (!forma_linha[0] && !forma_linha[1]) {
                        linha.clear();
                        
                    }
                    forma_linha[1] = false;
                    line_count++;
                }

                
            
            }
            cout << "Linha: ";
            for (int i = 0; i < linha.size(); i++) {
                cout << linha[i] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Arquivo inexistente" << endl;
    }

    return 0;
}