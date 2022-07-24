#include "../../headers/estados/Q95.h"
#include "../../headers/Functions.h"


void Q95::Caso(map<string, Instrucao>& tab_inst, map<string, Diretiva>& tab_diret, map<string, Simbolo>& tab_simbol,
            Enunciado& enunc, list<int>& diretivas_final, list<string>& bff_for_errors, int* forma_linha, char& c, char& b_space,
                std::string& lexema, int& line_count, int& pos_count, int& ign_coment, int& estado, int& op_count, int& last_inst,
                    class Instrucao inst, class Diretiva diret, int& ender_simbol, ofstream& arq_saida, int& passagem) {

      cout << "ESTADO Q95: " << endl;

    lexema += c;
    if (c == 'A'){
        estado = 96;
    } else if (isalpha(c)) { // Se é Letra
        estado = 4;
    } else if (isdigit(c)) { // Se é Número DPS de letra
        estado = 4;
    }  else if(c == ' ') {
        if (last_inst == 0 && b_space != ' ' && forma_linha[1] != -1 && (Functions::retur_op_inst(tab_inst, lexema) == -1 && Functions::retur_op_diret(tab_diret, lexema) == -1) ) {
                                    op_count++;
            } else if (last_inst == 1) {
                last_inst = 0;
                                }
        if (forma_linha[0] == -1 && forma_linha[1] == -1 && lexema != "") {
                                bff_for_errors.push_back(lexema);
            cout << "f_l[0]: " << forma_linha[0] << " f_l[1]: " << forma_linha[1] << " lexema: " << lexema << endl;
            forma_linha[0] = 1;
        }    
        cout << "b_space - c == espaço -> " << b_space << endl;
                            
        enunc.GetForm()[0] = forma_linha[0];
        enunc.GetForm()[1] = forma_linha[1];
        enunc.SetOpc() = op_count;
        enunc = Functions::update_enunc(enunc, line_count);
        forma_linha[0] = enunc.GetForm()[0];
        forma_linha[1] = enunc.GetForm()[1];
        op_count = enunc.GetOpc();

        b_space = c;
        estado = 0; // volta pro zero
    } else if(c == ':') {
        if ( passagem == 1) {
            int tam_tab_aux = tab_simbol.size();
            Functions::insere_tab_simbol(tab_simbol, lexema, pos_count, line_count);
            if ( tab_simbol.size() > tam_tab_aux) {
                    // cout << "=========================== " << tam_tab_aux << endl;
                    if(forma_linha[0] == -1){
                        forma_linha[0] = 1;
                    } else {
                        cout << "ERRO LÉXICO -- Linha: " << line_count << " | Formato do Rótulo '" << lexema << "' Inválido" << endl;
                                        }
                                    }
        } else if (passagem == 2 && lexema != "") {
            ender_simbol = Functions::busca_tab_simbol(tab_simbol, lexema);
            if (ender_simbol != -1){
                arq_saida << ender_simbol << " ";
            } else {
                cout << "Sibolo não definido " << "estado: " << estado << " linha: " << line_count << endl;
                                }
                            }
        b_space = c;
        lexema = "";
        estado = 0;
    } else if(c == ',') {
        if (last_inst == 0 && b_space != ' ' && forma_linha[1] != -1 && (Functions::retur_op_inst(tab_inst, lexema) == -1 && Functions::retur_op_diret(tab_diret, lexema) == -1) ) {
                                op_count++;
        } else if (last_inst == 1){
            last_inst = 0;
                            }
        if (forma_linha[0] == -1 && forma_linha[1] == -1 && lexema != "") {
                                    bff_for_errors.push_back(lexema);
                cout << "f_l[0]: " << forma_linha[0] << " f_l[1]: " << forma_linha[1] << " lexema: " << lexema << endl;
                forma_linha[0] = 1;
                                }
        if (passagem == 2) {
            ender_simbol = Functions::busca_tab_simbol(tab_simbol, lexema);
            if (ender_simbol != -1){
                arq_saida << ender_simbol << " ";
            } else {
                cout << "Sibolo não definido " << "estado: " << estado << " linha: " << line_count << endl;
                                }
                            }
        b_space = c;
        lexema = "";
        estado = 0; // é operando
    } else if(c == '_') {
        estado = 4;
    } else if(c == '\n') {
                            line_count++;
        if (forma_linha[0] == -1 && forma_linha[1] == -1 && lexema != "") {
                                bff_for_errors.push_back(lexema);
            cout << "f_l[0]: " << forma_linha[0] << " f_l[1]: " << forma_linha[1] << " lexema: " << lexema;
                forma_linha[0] = 1;
                                }

        if (passagem == 2) {
            ender_simbol = Functions::busca_tab_simbol(tab_simbol, lexema);
            if (ender_simbol != -1){
                arq_saida << ender_simbol << " ";
            } else {
                cout << "Sibolo não definido " << "estado: " << estado << " linha: " << line_count << endl;
                                }
                            }

        if (last_inst == 0 && b_space != ' ' && forma_linha[1] != -1 && (Functions::retur_op_inst(tab_inst, lexema) == -1 && Functions::retur_op_diret(tab_diret, lexema) == -1) ) {
                                op_count++;
        } else if (last_inst == 1){
            last_inst = 0;
                            }
                            
        enunc.GetForm()[0] = forma_linha[0];
        enunc.GetForm()[1] = forma_linha[1];
        enunc.SetOpc() = op_count;
        enunc = Functions::update_enunc(enunc, line_count);
        forma_linha[0] = enunc.GetForm()[0];
        forma_linha[1] = enunc.GetForm()[1];
        op_count = enunc.GetOpc();

                            
        b_space = c;
        lexema = "";
        estado = 0;
    } else {
        estado = 0; // erro
                        }
}                       