#include "./headers/Functions.h"

int main (int argc, char **argv) {

    int NUM_PASS;
    string mont_mod = string(argv[1]);
    if (mont_mod == "-p") {
        NUM_PASS = 1;
    }
    else if (mont_mod == "-o") {
        NUM_PASS = 3;
    } else {
        NUM_PASS = -1;
    }

    vector<string> linha;
    string passagem_2;

    int begin_line = 0;
    int line_count = 1;
    int estado = 0;
    int cont_posicao = 0;
    string lexema, file_string;
    string name_file;

    char* arq_in = argv[2];
    char* arq_out = argv[3];
    char c, b_space;

    string forma_linha[2] = {"nil", "nil"};
    // nil -> Não Checado
    // ckeck -> Checado:Sem
    // rot/inst -> Checado:OK 
    // Rotulo/Instrucao -> Checado:Erro
    map<string, Instrucao> tab_inst;    // Map tabela de instruções
    map<string,Diretiva> tab_diret;   // Map tabela de diretivas
    map<string, Simbolo> tab_simbol;  // Map tabela de simbolos
    map<string, DiretivaExtend> tab_extend;  // Map tabela extendida de diretivas

    int flag_erros = 0;
    bool flag_ligador = false;

    map<string, Definicao> tab_def;  // Map tabela de definicao
    map<string, Uso> tab_uso;  // Map tabela de uso

    map<string, Plus> tab_plus;  // Tabela de Soma

    Functions::ler_tab_instr(tab_inst);     // Tabela de instruções
    Functions::ler_tab_diret(tab_diret);   // Tabela de diretivas
    Functions::ler_tab_extend(tab_extend);   // Tabela de extendida
   
    name_file = Functions::GetNameFile(string(arq_in), 0);
    
    file_string =  Functions::up_file(arq_in);

    if(!file_string.empty() && NUM_PASS > 0) {
        for (int passagem = 0; passagem < NUM_PASS; passagem++) {
            if (passagem == 0) {
                cout << "PASSAGEM 0 ===================================================================\n" << endl;
                char b;
                string diret;
                string pre_file_string;
                int flag_ign = 0;
                int ign_coment = 0;
                map<string, string> map_diret;

                for (int i=0; i<file_string.size(); i++) {
                    if (file_string[i] == ';') {
                        ign_coment = 1;
                    }
                    else if (file_string[i] == '\n') {
                        ign_coment = 0;
                    }
                    if (ign_coment == 0) {
                        if (file_string[i] == '\n' || file_string[i] == '\t') {
                            //cout << "diret: " << diret << endl;
                            Functions::update_diretivas(map_diret, tab_diret, diret, flag_ign);
                            
                            pre_file_string += diret;

                            diret.clear();
                        } else {
                            diret += file_string[i];
                        }
                    }
                }
                map_diret.clear();
                ofstream arq_pre ("files/pre_processado/pre_" + name_file);
                arq_pre << pre_file_string;
                arq_pre.close();
            }
            else if (passagem == 1) {
                cout << "PASSAGEM 1 ===================================================================\n" << endl;
                Instrucao inst;
                Diretiva diret;
                string rot = "";
                bool line_analise = true;
                int estado = 0;
                pair<int,int> virg;
                int flag_v = 0;

                int flag_section = 0;
                int flag_data = 0;
                
                string msg = "";
                int flag_sec_t = 0;
                int flag_sec_d = 0;

                bool section_t[2] = {false, false};
                bool section_d[2] = {false, false};
                
                ifstream arq_entrada ("files/pre_processado/pre_" + name_file);
                
                while(arq_entrada.good()){

                    arq_entrada.get(c);
                    Functions::Analise_rot_instr(arq_entrada, c, lexema, tab_inst, tab_diret, tab_extend, line_count, forma_linha, linha, begin_line, line_analise, estado, virg, flag_v,
                                                    section_t, section_d, flag_sec_t, flag_sec_d, flag_erros, flag_ligador);
            
                    if (c == '\n') {
                        begin_line = arq_entrada.tellg();
                        line_analise = true;
                        
                        if (forma_linha[0] != "nil" && forma_linha[1] != "nil") {

                            Functions::passagem1(tab_def, tab_simbol, tab_inst, tab_diret, linha, cont_posicao, line_count, flag_erros, tab_plus);

                            for (int i = 0; i < linha.size(); i++) {
                                passagem_2 += linha[i] + " ";
                            }
                            passagem_2 += "\n";
                            linha.clear();
                            forma_linha[0] = "nil";
                            forma_linha[1] = "nil";
                        }
                        line_count++;
                    }
                }
                line_count = 1;
                cont_posicao = 0;
                arq_entrada.close();
                Functions::public_simbol(tab_simbol, tab_def);
                cout << endl;
                cout << "Tabela de Símbolos : " << endl;
                Functions::print_tab_simbol(tab_simbol);
                cout << endl;
                
                if (flag_ligador) {
                    cout << "Tabela de Definições : " << endl;
                    Functions::print_tab_def(tab_def);
                    cout << endl;
                }
            } 
            else if (passagem == 2) {
                cout << "PASSAGEM 2 ===================================================================\n" << endl;
                string cod_obj;
                Functions::passagem2(cod_obj, tab_simbol, tab_inst, tab_diret, passagem_2, cont_posicao, line_count, tab_extend, tab_uso, tab_plus, flag_erros);

                if (flag_erros == 0) {
                    if (flag_ligador) {
                        cout << "Tabela de Uso : " << endl;
                        Functions::print_tab_uso(tab_uso);
                        cout << endl;
                        cout << "Tabela de Definições : " << endl;
                        Functions::print_tab_def(tab_def);
                        cout << endl;
                        cout << cod_obj << endl;

                        string name_saida = Functions::GetNameFile(string(arq_out), 1);  
                        ofstream arq_saida(name_saida + "_" + name_file);
                        arq_saida << "TABELA USO" << endl;
                        for (auto u : tab_uso) {
                            arq_saida << u.second.GetRotulo() + " " + to_string(u.second.SetEndereco()) + "\n";
                        }
                        arq_saida << endl;
                        arq_saida << "TABELA DEF" << endl;
                        for (auto d : tab_def) {
                            arq_saida << d.second.GetRotulo() + " " + to_string(d.second.SetEndereco()) + "\n";
                        }
                        arq_saida << endl;
                        arq_saida << cod_obj;
                        arq_saida.close();
                    } else {
                        cout << cod_obj << endl;
                        ofstream arq_saida (arq_out);
                        arq_saida << cod_obj;
                        arq_saida.close();
                    }
                } else {
                    cout << "O Codigo Objeto Não Foi Gerado. Corrija os Erros e Tente Novamente!" << endl;
                    cout << "FORAM ENCONTRADOS [" << flag_erros << "] ERROS ESPECIFICADOS ACIMA." << endl << endl;
                }
            }
        }
    } else {
        Functions::print_errors("", 11, -1);
        if(file_string.empty()) {
            Functions::print_errors(arq_in, 12, -1);
        }
        if (NUM_PASS < 1) {
            Functions::print_errors(mont_mod, 13, -1);
        }
        Functions::print_errors("", 14, -1);
    }
    return 0;
}