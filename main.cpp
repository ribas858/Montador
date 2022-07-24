#include "./headers/Functions.h"
#include "./headers/Estados.h"

int main (int argc, char **argv) {

    map<string, Instrucao> tab_inst;    // Map tabela de instruções
    map<string,Diretiva> tab_diret;   // Map tabela de diretivas
    map<string, Simbolo> tab_simbol;  // Map tabela de simbolos
    Enunciado enunc;


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
    int line_count = 0, pos_count = 0, ign_coment = 0, estado = 0, op_count = 0, last_inst = 0;

    // Functions::insere_tab_simbol(tab_simbol, "", 1, 1);

    if (arq_cod1.is_open()){
        for (int passagem = 1; passagem <= 2; passagem++) {
            estado = 0;
            pos_count = 0;
            arq_cod1.close();
            Instrucao inst;
            Diretiva diret;
            int ender_simbol;
            line_count = 1;
            ifstream arq_cod1 (argv[2]);
            b_space = 'a';
            while(arq_cod1.good()){
                arq_cod1.get(c);
                c = (char)toupper(c);

                switch (estado) {
                    case 0:
                        Q0::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 1:
                        Q1::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 2:
                        Q2::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 3:
                        Q3::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 4:
                        Q4::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 5:
                        Q5::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 6:
                        Q6::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem, arq_cod1);
                        break;

                    case 7:
                        Q7::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 8:
                        Q8::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 9:
                        Q9::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 10:
                        Q10::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                    case 11:
                        Q11::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 12:
                        Q12::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 13:
                        Q13::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 14:
                        Q14::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 15:
                        Q15::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 16:
                        Q16::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 17:
                        Q17::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 18:
                        Q18::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 19:
                        Q19::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 20:
                        Q20::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem, arq_cod1);
                        break;
                    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    
                    case 21:
                        Q21::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 22:
                        Q22::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 23:
                        Q23::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 24:
                        Q24::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 25:
                        Q25::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 26:
                        Q26::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 27:
                        Q27::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 28:
                        Q28::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 29:
                        Q29::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 30:
                        Q30::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    
                    case 31:
                        Q31::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem, arq_cod1);
                        break;

                    case 32:
                        Q32::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 33:
                        Q33::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 34:
                        Q34::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 35:
                        Q35::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 36:
                        Q36::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 37:
                        Q37::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 38:
                        Q38::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 39:
                        Q39::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 40:
                        Q40::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    
                    case 41:
                        Q41::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 42:
                        Q42::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 43:
                        Q43::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 44:
                        Q44::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 45:
                        Q45::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 46:
                        Q46::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 47:
                        Q47::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 48:
                        Q48::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 49:
                        Q49::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 50:
                        Q50::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    
                    case 51:
                        Q51::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;

                    case 52:
                        Q52::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 53:
                        Q53::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem, arq_cod1);
                        break;
                    
                    case 54:
                        Q54::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 55:
                        Q55::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 56:
                        Q56::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 57:
                        Q57::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 58:
                        Q58::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 59:
                        Q59::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 60:
                        Q60::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    
                    case 61:
                        Q61::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 62:
                        Q62::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 63:
                        Q63::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 64:
                        Q64::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 65:
                        Q65::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 66:
                        Q66::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 67:
                        Q67::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 68:
                        Q68::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 69:
                        Q69::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 70:
                        Q70::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    
                    case 71:
                        Q71::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem, arq_cod1);
                        break;
                    
                    case 72:
                        Q72::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 73:
                        Q73::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem, arq_cod1);
                        break;
                    
                    case 74:
                        Q74::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 75:
                        Q75::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 76:
                        Q76::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem, arq_cod1);
                        break;
                    
                    case 77:
                        Q77::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 78:
                        Q78::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 79:
                        Q79::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 80:
                        Q80::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    
                    case 81:
                        Q81::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 82:
                        Q82::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem, arq_cod1);
                        break;
                    
                    case 83:
                        Q83::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 84:
                        Q84::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 85:
                        Q85::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 86:
                        Q86::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 87:
                        Q87::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 88:
                        Q88::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 89:
                        Q89::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 90:
                        Q90::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    
                    case 91:
                        Q91::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 92:
                        Q92::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem, arq_cod1);
                        break;
                    
                    case 93:
                        Q93::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 94:
                        Q94::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 95:
                        Q95::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 96:
                        Q96::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 97:
                        Q97::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 98:
                        Q98::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 99:
                        Q99::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 100:
                        Q100::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    
                    case 101:
                        Q101::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 102:
                        Q102::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    
                    case 103:
                        Q103::Caso(tab_inst, tab_diret, tab_simbol, enunc, diretivas_final, bff_for_errors, forma_linha, c, b_space, lexema,
                                        line_count, pos_count, ign_coment, estado, op_count, last_inst, inst, diret, ender_simbol,
                                        arq_saida, passagem);
                        break;
                    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                    
                    default:
                        cout << "Error!\n";
                        break;
                }
            }
            
            cout << "FIMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM DO FORRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR\n";
            Functions::print_tab_simbol(tab_simbol);
        }
    } else {
        cout << "Arquivo inexistente" << endl;
    }

    for (auto i : diretivas_final) {
        arq_saida << i << " ";
    }
    arq_saida.close();

    return 0;
}