#include "../../headers/estados/Q18.h"
#include "../../headers/Functions.h"


void Q18::Caso(map<string, Instrucao>& tab_inst, map<string, Diretiva>& tab_diret, map<string, Simbolo>& tab_simbol,
            Enunciado& enunc, list<int>& diretivas_final, list<string>& bff_for_errors, int* forma_linha, char& c, char& b_space,
                std::string& lexema, int& line_count, int& pos_count, int& ign_coment, int& estado, int& op_count, int& last_inst,
                    class Instrucao inst, class Diretiva diret, int& ender_simbol, ofstream& arq_saida, int& passagem) {

      cout << "ESTADO Q18: ";

    lexema += c;
    if (c == ' ' || c == '\n'){
        b_space = c;
        if ( c == '\n' ) {
                                line_count++;
                            }
                            lexema.pop_back();
        cout << "Lexema " << lexema.length() << " - " << lexema << "a" << endl;
                            
        int achou = Functions::retur_tam_inst(tab_inst, lexema);
        if (achou != -1) {
            pos_count += achou;
            if (forma_linha[1] == -1 ){
                forma_linha[1] = Functions::retur_op_inst(tab_inst, lexema);
            } else {
                cout << "ERRO SINTÁTICO -- Linha: " << line_count << " | Duas(ou mais) Instruções Na Mesma Linha '" << lexema << "'" << endl;
                                }
            cout << "Forma_linha[1]: " << forma_linha[1] << endl;
            if (passagem == 2) {
                inst = Functions::retur_inst(tab_inst, lexema);
                arq_saida << inst.GetCodigo() << " ";
                                }
        } else {
            achou = Functions::retur_tam_diret(tab_diret, lexema);
            if (achou != -1) {
                pos_count += achou;
                if (forma_linha[1] == -1 ){
                    forma_linha[1] = Functions::retur_op_diret(tab_diret, lexema);
                } else {
                    cout << "ERRO SINTÁTICO -- Linha: " << line_count << " | Duas(ou mais) Diretivas Na Mesma Linha '" << lexema << "'" << endl;
                                    }
                cout << "Forma_linha[1]: " << forma_linha[1] << endl;
                                    
                if (passagem == 2) {
                    diret = Functions::retur_diret(tab_diret, lexema);
                    if (diret.GetInstrucao() == "SPACE") {
                                            diretivas_final.push_back(0);
                    } else if (diret.GetInstrucao() == "CONST") {
                        cout << "COnstt\n";
                                        }
                                    }
            } else {
                cout << "ERRO SINTÁTICO -- Linha: " << line_count << " | Instrução '" << lexema << "' Indefinida" << endl;
                                }
                            }
                            
        if (c == '\n'){
            cout << "OP Count antes: " << op_count << endl;
            cout << "Forma_linha[0]: " << forma_linha[0] << " -- ";
            cout << "Forma_linha[1]: " << forma_linha[1] << endl;
            if (forma_linha[1] != -1) {
                if (op_count == forma_linha[1]){
                    forma_linha[0] = -1;
                    forma_linha[1] = -1;
                    op_count = 0;
                } else if (op_count > forma_linha[1]) {
                    cout << "ERRO SINTÁTICO -- Linha: " << line_count << " | Número de Operandos Incorreto Para a Instrução Definida -- Instrução Pede: "
                    << forma_linha[1] << " Operandos | " << "Encontrado: " << op_count << " Operandos" << endl;
                    forma_linha[0] = -1;
                    forma_linha[1] = -1;
                    op_count = 0;
                                    }
                                }
        cout << "OP Count dps: " << op_count << endl;
        cout << "Forma_linha[0]: " << forma_linha[0] << " -- ";
            cout << "Forma_linha[1]: " << forma_linha[1] << endl;
                            }

        cout << "Contador de Posicao: " << pos_count << endl;
        last_inst = 1;
        b_space = c;
        lexema = "";
        estado = 0; // fecha na tabela e volta pro zero
    } else if (isalpha(c)) { // Se é Letra
        estado = 4;
    } else if (isdigit(c)) { // Se é Número DPS de letra
        estado = 4;
    } else if(c == '_') {   
        estado = 4;
    } else {
        estado = 0; // erro
                        }
}                       