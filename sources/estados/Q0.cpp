#include "../../headers/estados/Q0.h"
#include "../../headers/Functions.h"


void Q0::Caso(map<string, Instrucao>& tab_inst, map<string, Diretiva>& tab_diret, map<string, Simbolo>& tab_simbol,
            Enunciado& enunc, list<int>& diretivas_final, list<string>& bff_for_errors, int* forma_linha, char& c, char& b_space,
                std::string& lexema, int& line_count, int& pos_count, int& ign_coment, int& estado, int& op_count, int& last_inst,
                    class Instrucao inst, class Diretiva diret, int& ender_simbol, ofstream& arq_saida, int& passagem) {

    if (c == '\n'){
        cout << "ESTADO Q0: " << "C == barra N" << " -- ";
    } else {
        cout << "ESTADO Q0: " << "C == " << c << " -- ";
    }

    cout << "lexema: " << lexema << " -- " << "ign coment: " << ign_coment << " -- Op_count: " 
    << op_count << " last_inst: " << last_inst << " f_l[0]: " << forma_linha[0] << " f_l[1]: " << forma_linha[1] << endl;
    if (ign_coment == 0 ) {
        
        if (c == ';') {
            if (last_inst == 0 && b_space != ' ' && forma_linha[1] != -1 && (Functions::retur_op_inst(tab_inst, lexema) == -1 && Functions::retur_op_diret(tab_diret, lexema) == -1) )  {
                op_count++;
            } else if (last_inst == 1){
                last_inst = 0;
            }
            if (forma_linha[0] == -1 && forma_linha[1] == -1 && lexema != "") {
                bff_for_errors.push_back(lexema);
                cout << "f_l[0]: " << forma_linha[0] << " f_l[1]: " << forma_linha[1] << " lexema: " << lexema << endl;
                forma_linha[0] = 1;
            }
            ign_coment = 1;
            estado = 0;
        }
        //if (c != ' ' && c != '\n' && c != ';') lexema += c; 
        if (c == 'A'){
            if (last_inst == 1 && b_space == ' ') {
                last_inst = 0;
            }
            cout << "B_Space Antes: " << b_space << endl;
            if (b_space != ' ' || lexema.length() == 0) {
                lexema += c;
                b_space = c;
            } else if (b_space == ' ' && lexema.length() > 0){
                if (forma_linha[0] == 1 && forma_linha[1] == -1){
                    cout << "ERRO SINTÁTICO -- Linha: " << line_count << " | Instrução '" << lexema << "' Indefinida" << endl;
                } else if (forma_linha[0] == -1){
                    forma_linha[0] = 1;
                }
                b_space = c;
                cout << "B_Space Depois: " << b_space << endl;
                lexema = "";
                lexema += c;
                estado = 0;
            }
            b_space = c;
            cout << "B_Space Depois: " << b_space << endl;
            estado = 1;
        } else if (c == 'C') {
            if (last_inst == 1 && b_space == ' ') {
                last_inst = 0;
            }
            cout << "B_Space Antes: " << b_space << " Lexema: " << lexema << endl;
            if (b_space != ' ' || lexema.length() == 0) {
                lexema += c;
                b_space = c;
            } else if (b_space == ' ' && lexema.length() > 0){
                if (forma_linha[0] == 1 && forma_linha[1] == -1){
                    cout << "ERRO SINTÁTICO -- Linha: " << line_count << " | Instrução '" << lexema << "' Indefinida" << endl;
                } else if (forma_linha[0] == -1){
                    forma_linha[0] = 1;
                }
                b_space = c;
                cout << "B_Space Depois: " << b_space << endl;
                lexema = "";
                lexema += c;
                estado = 0;
            }
            b_space = c;
            cout << "B_Space Depois: " << b_space << endl;
            estado = 5;
        } else if (c == 'D') {
            if (last_inst == 1 && b_space == ' ') {
                last_inst = 0;
            }
            cout << "B_Space Antes: " << b_space << endl;
            if (b_space != ' ' || lexema.length() == 0) {
                lexema += c;
                b_space = c;
            } else if (b_space == ' ' && lexema.length() > 0){
                if (forma_linha[0] == 1 && forma_linha[1] == -1){
                    cout << "ERRO SINTÁTICO -- Linha: " << line_count << " | Instrução '" << lexema << "' Indefinida" << endl;
                } else if (forma_linha[0] == -1){
                    forma_linha[0] = 1;
                }
                b_space = c;
                cout << "B_Space Depois: " << b_space << endl;
                lexema = "";
                lexema += c;
                estado = 0;
            }
            b_space = c;
            cout << "B_Space Depois: " << b_space << endl;
            estado = 16;
        } else if (c == 'I') {
            if (last_inst == 1 && b_space == ' ') {
                last_inst = 0;
            }
            cout << "B_Space Antes: " << b_space << " lexema lenght: " << lexema.length() << endl;
            if (b_space != ' ' || lexema.length() == 0) {
                lexema += c;
                b_space = c;
            } else if (b_space == ' ' && lexema.length() > 0){
                if (forma_linha[0] == 1 && forma_linha[1] == -1){
                    cout << "ERRO SINTÁTICO -- Linha: " << line_count << " | Instrução '" << lexema << "' Indefinida" << endl;
                } else if (forma_linha[0] == -1){
                    forma_linha[0] = 1;
                }
                b_space = c;
                cout << "B_Space Depois: " << b_space << endl;
                lexema = "";
                lexema += c;
                estado = 0;
            }
            b_space = c;
            cout << "B_Space Depois: " << b_space << endl;
            estado = 20;
        } else if (c == 'J') {
            if (last_inst == 1 && b_space == ' ') {
                last_inst = 0;
            }
            cout << "B_Space Antes: " << b_space << endl;
            if (b_space != ' ' || lexema.length() == 0) {
                lexema += c;
                b_space = c;
            } else if (b_space == ' ' && lexema.length() > 0){
                if (forma_linha[0] == 1 && forma_linha[1] == -1){
                    cout << "ERRO SINTÁTICO -- Linha: " << line_count << " | Instrução '" << lexema << "' Indefinida" << endl;
                } else if (forma_linha[0] == -1){
                    forma_linha[0] = 1;
                }
                b_space = c;
                cout << "B_Space Depois: " << b_space << endl;
                lexema = "";
                lexema += c;
                estado = 0;
            }
            b_space = c;
            cout << "B_Space Depois: " << b_space << endl;
            estado = 29;
        } else if (c == 'L') {
            if (last_inst == 1 && b_space == ' ') {
                last_inst = 0;
            }
            cout << "B_Space Antes: " << b_space << endl;
            if (b_space != ' ' || lexema.length() == 0) {
                lexema += c;
                b_space = c;
            } else if (b_space == ' ' && lexema.length() > 0){
                if (forma_linha[0] == 1 && forma_linha[1] == -1){
                    cout << "ERRO SINTÁTICO -- Linha: " << line_count << " | Instrução '" << lexema << "' Indefinida" << endl;
                } else if (forma_linha[0] == -1){
                    forma_linha[0] = 1;
                }
                b_space = c;
                cout << "B_Space Depois: " << b_space << endl;
                lexema = "";
                lexema += c;
                estado = 0;
            }
            b_space = c;
            cout << "B_Space Depois: " << b_space << endl;
            estado = 48;
        } else if (c == 'M') {
            if (last_inst == 1 && b_space == ' ') {
                last_inst = 0;
            }
            cout << "B_Space Antes: " << b_space << endl;
            if (b_space != ' ' || lexema.length() == 0) {
                lexema += c;
                b_space = c;
            } else if (b_space == ' ' && lexema.length() > 0){
                if (forma_linha[0] == 1 && forma_linha[1] == -1){
                    cout << "ERRO SINTÁTICO -- Linha: " << line_count << " | Instrução '" << lexema << "' Indefinida" << endl;
                } else if (forma_linha[0] == -1){
                    forma_linha[0] = 1;
                }
                b_space = c;
                cout << "B_Space Depois: " << b_space << endl;
                lexema = "";
                lexema += c;
                estado = 0;
            }
            b_space = c;
            cout << "B_Space Depois: " << b_space << endl;
            estado = 53;
        } else if (c == 'O') {
            if (last_inst == 1 && b_space == ' ') {
                last_inst = 0;
            }
            cout << "B_Space Antes: " << b_space << endl;
            if (b_space != ' ' || lexema.length() == 0) {
                lexema += c;
                b_space = c;
            } else if (b_space == ' ' && lexema.length() > 0){
                if (forma_linha[0] == 1 && forma_linha[1] == -1){
                    cout << "ERRO SINTÁTICO -- Linha: " << line_count << " | Instrução '" << lexema << "' Indefinida" << endl;
                } else if (forma_linha[0] == -1){
                    forma_linha[0] = 1;
                }
                b_space = c;
                cout << "B_Space Depois: " << b_space << endl;
                lexema = "";
                lexema += c;
                estado = 0;
            }
            b_space = c;
            cout << "B_Space Depois: " << b_space << endl;
            estado = 64;
        } else if (c == 'S') {
            if (last_inst == 1 && b_space == ' ') {
                last_inst = 0;
            }
            cout << "B_Space Antes: " << b_space << endl;
            if (b_space != ' ' || lexema.length() == 0) {
                lexema += c;
                b_space = c;
            } else if (b_space == ' ' && lexema.length() > 0){
                if (forma_linha[0] == 1 && forma_linha[1] == -1){
                    cout << "ERRO SINTÁTICO -- Linha: " << line_count << " | Instrução '" << lexema << "' Indefinida" << endl;
                } else if (forma_linha[0] == -1){
                    forma_linha[0] = 1;
                }
                b_space = c;
                cout << "B_Space Depois: " << b_space << endl;
                lexema = "";
                lexema += c;
                estado = 0;
            }
            b_space = c;
            cout << "B_Space Depois: " << b_space << " -- Op_count: " << op_count << endl;
            estado = 71;
        } else if (c == 'E') {
            if (last_inst == 1 && b_space == ' ') {
                last_inst = 0;
            }
            cout << "B_Space Antes: " << b_space << endl;
            if (b_space != ' ' || lexema.length() == 0) {
                lexema += c;
                b_space = c;
            } else if (b_space == ' ' && lexema.length() > 0){
                if (forma_linha[0] == 1 && forma_linha[1] == -1){
                    cout << "ERRO SINTÁTICO -- Linha: " << line_count << " | Instrução '" << lexema << "' Indefinida" << endl;
                } else if (forma_linha[0] == -1){
                    forma_linha[0] = 1;
                }
                b_space = c;
                cout << "B_Space Depois: " << b_space << endl;
                lexema = "";
                lexema += c;
                estado = 0;
            }
            b_space = c;
            cout << "B_Space Depois: " << b_space << endl;
            estado = 92;
        } else if (isalpha(c)) { // Se é Letra
            if (forma_linha[0] == 1 && forma_linha[1] == -1) {
                cout << "ERRO SINTÁTICO -- Linha: " << line_count << " | Declaração de Rótulo '" << lexema 
                << "' Incorreta | Esperado -> ':' | Encontrado -> '" << c << "'" << endl;
            }
            if (last_inst == 1 && b_space == ' ') {
                last_inst = 0;
            }
            cout << "B_Space Antes: " << b_space << endl;
            if (b_space != ' ' || lexema.length() == 0) {
                lexema += c;
                b_space = c;
            } else if (b_space == ' ' && lexema.length() > 0){
                if (forma_linha[0] == 1 && forma_linha[1] == -1){
                    cout << "ERRO SINTÁTICO -- Linha: " << line_count << " | Instrução '" << lexema << "' Indefinida" << endl;
                } else if (forma_linha[0] == -1){
                    forma_linha[0] = 1;
                }
                b_space = c;
                cout << "B_Space Depois: " << b_space << endl;
                lexema = "";
                lexema += c;
                estado = 0;
            }
            b_space = c;
            cout << "B_Space Depois: " << b_space << endl;
            estado = 4; // Estado dos rotulos
        } else if (isdigit(c)) { // Se é Número
            if (last_inst == 1 && b_space == ' ') {
                last_inst = 0;
            }
            cout << "B_Space Antes: " << b_space << endl;
            if (b_space != ' ' || lexema.length() == 0) {
                lexema += c;
                b_space = c;
            } else if (b_space == ' ' && lexema.length() > 0){
                if (forma_linha[0] == 1 && forma_linha[1] == -1){
                    cout << "ERRO SINTÁTICO -- Linha: " << line_count << " | Instrução '" << lexema << "' Indefinida" << endl;
                } else if (forma_linha[0] == -1){
                    forma_linha[0] = 1;
                }
                b_space = c;
                cout << "B_Space Depois: " << b_space << endl;
                lexema = "";
                lexema += c;
                estado = 0;
            }
            b_space = c;
            cout << "B_Space Depois: " << b_space << " -- Op_count: " << op_count << endl;
            estado = 9; // Estado dos numeros
        } else if(c == ' ') {
            if ( last_inst == 0 && b_space != ' ' && forma_linha[1] != -1 && (Functions::retur_op_inst(tab_inst, lexema) == -1 && Functions::retur_op_diret(tab_diret, lexema) == -1) ) {
                op_count++;
            } else if (last_inst == 1) {
                last_inst = 0;
            }
            
            if (forma_linha[0] == -1 && forma_linha[1] == -1 && lexema != "") {
                bff_for_errors.push_back(lexema);
                cout << "f_l[0]: " << forma_linha[0] << " f_l[1]: " << forma_linha[1] << " lexema: " << lexema << endl;
                forma_linha[0] = 1;
            }
        
            enunc.GetForm()[0] = forma_linha[0];
            enunc.GetForm()[1] = forma_linha[1];
            enunc.SetOpc() = op_count;
            enunc = Functions::update_enunc(enunc, line_count);
            forma_linha[0] = enunc.GetForm()[0];
            forma_linha[1] = enunc.GetForm()[1];
            op_count = enunc.GetOpc();

            
            cout << "b_space - c == espaço -> " << b_space << endl;
            b_space = c;
            estado = 0;
        } else if(c == ':') {
            if (last_inst == 1 && b_space == ' ') {
                last_inst = 0;
            }
            if (passagem == 1){
                cout << "DEUUU DOIS PONTOSSS " << lexema << " -- Op_count: " << op_count << endl;
                int tam_tab_aux = tab_simbol.size();
                Functions::insere_tab_simbol(tab_simbol, lexema, pos_count, line_count);
                if ( tab_simbol.size() > tam_tab_aux) {
                    cout << "=========================== " << tam_tab_aux << endl;
                    if(forma_linha[0] == -1){
                        forma_linha[0] = 1;
                    } else {
                        cout << "bff_for_erros: [";
                        for (auto i : bff_for_errors) {
                            cout << i << ", ";
                        }
                        cout <<"]" << endl;
                        cout << "ERRO LÉXICO -- Linha: " << line_count << " | Formato do Rótulo '" << bff_for_errors.back() << " " << lexema << "' Inválido" << endl;
                    }
                }
                b_space = c;
                lexema = "";
                estado = 0;
            } else if (passagem == 2){
                b_space = c;
                lexema = "";
                estado = 0;
            }
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
            // if (passagem == 1) {
            //     if (Functions::busca_tab_simbol(tab_simbol, lexema) !=)
            //     cout << "ERRO LÉXICO -- Token inválido -- Linha: " << line_count << endl;
            // }
            if (passagem == 2 && lexema != "") {
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
        } else if(c == '_') {
            estado = 4;
        } else if(c == '\n') {
            line_count++;
            if (forma_linha[0] == -1 && forma_linha[1] == -1 && lexema != "") {
                bff_for_errors.push_back(lexema);
                cout << "f_l[0]: " << forma_linha[0] << " f_l[1]: " << forma_linha[1] << " lexema: " << lexema << endl;
                forma_linha[0] = 1;
            }
            cout << "bff_for_erros: [";
                        for (auto i : bff_for_errors) {
                            cout << i << ", ";
                        }
                        cout <<"]" << endl;
            if (passagem == 2 && lexema != "") {
                ender_simbol = Functions::busca_tab_simbol(tab_simbol, lexema);
                if (ender_simbol != -1){
                    arq_saida << ender_simbol << " ";
                } else {
                    cout << "Sibolo não definido " << "estadoddd: " << estado << " linha: " << line_count << endl;
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
    } else if(c == '\n') {
        line_count++;
        if (forma_linha[0] == -1 && forma_linha[1] == -1 && lexema != "") {
            bff_for_errors.push_back(lexema);
            cout << "f_l[0]: " << forma_linha[0] << " f_l[1]: " << forma_linha[1] << " lexema: " << lexema << endl;
            forma_linha[0] = 1;
        }
        enunc.GetForm()[0] = forma_linha[0];
        enunc.GetForm()[1] = forma_linha[1];
        enunc.SetOpc() = op_count;
        enunc = Functions::update_enunc(enunc, line_count);
        forma_linha[0] = enunc.GetForm()[0];
        forma_linha[1] = enunc.GetForm()[1];
        op_count = enunc.GetOpc();

        cout << "IGNORA COMENTARIOSSSSSSSSSSSSSSSSSSSSSSSSSSSS\n";

        b_space = c;
        lexema = "";
        ign_coment = 0;
        estado = 0;
    }
}                       