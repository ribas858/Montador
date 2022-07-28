#include "./headers/Functions.h"

int main (int argc, char **argv) {

    vector<string> linha;
    int begin_line = 0;
    int line_count = 1;
    int estado = 0;
    string lexema;

    char* mont_mod = argv[1];
    char* arq_in = argv[2];
    char* arq_out = argv[3];
    char c, b_space;
    Enunciado enunc;

    string forma_linha[2] = {"nil", "nil"};
    // nil -> Não Checado
    // ckeck -> Checado:Sem
    // rot/inst -> Checado:OK 
    // Rotulo/Instrucao -> Checado:Erro
    map<string, Instrucao> tab_inst;    // Map tabela de instruções
    map<string,Diretiva> tab_diret;   // Map tabela de diretivas
    map<string, Simbolo> tab_simbol;  // Map tabela de simbolos

    Functions::ler_tab_instr(tab_inst);     // Tabela de instruções
    Functions::ler_tab_diret(tab_diret);   // Tabela de diretivas
    Functions::up_file(arq_in);
    ifstream arq_entrada (arq_in);
    ofstream arq_saida (arq_out);

    if (!arq_saida) {
        cout << "Arquivo saida.txt nao pode ser aberto" << endl;
        abort();
    }

    if (arq_entrada.is_open()){

        for (int passagem = 0; passagem < 1; passagem++) {
            arq_entrada.close();

            if (passagem == 0) {
                cout << "Passagem 0" << endl;
                int flag_ign = 0;
                // string key;
                string diret, file;
                string line2;
                map<string, string> map_diret;

                ifstream arq_entrada (arq_in);
                file = Functions::limpa_coment(arq_entrada);
                
                for (int i=0; i<file.size(); i++) {

                    if (file[i] == '\n' || file[i] == '\t') {
                        // cout << "diret: " << diret << endl;
                        Functions::update_diretivas(map_diret, tab_diret, diret, flag_ign);

                        if(diret.empty()) {
                            // cout << "Vazio meu bom" << endl;
                            line2 += diret;
                        } else {
                            line2 += diret + '\n';
                        }

                        diret.clear();
                    } else {
                        diret += file[i];
                    }

                }

                // for (auto itr = map_diret.begin(); itr != map_diret.end(); ++itr) {
                //     cout << itr->first
                //          << '\t' << itr->second << '\n';
                // }
                
                cout << "\nLine2:\n" << line2 << endl;


            }
            else if (passagem == 1) {
                ifstream arq_entrada (arq_in);

                Instrucao inst;
                Diretiva diret;
                string rot = "";
                bool line_analise = true;
                int estado = 0;
                pair<int,int> v;
                int flag_v = 0;

                int flag_section = 0;
                int flag_data = 0;
                string msg = "";
                

                while(arq_entrada.good()){
                    
                    Functions::val_sections(flag_section, arq_entrada, begin_line, flag_data, lexema, line_count, msg, 1);

                    Functions::val_sections(flag_section, arq_entrada, begin_line, flag_data, lexema, line_count, msg, 2);

                    arq_entrada.get(c);

                    if (flag_section == 1) {
                        Functions::Analise_rot_instr(arq_entrada, c, lexema, tab_inst, tab_diret, line_count, forma_linha, linha, rot, begin_line, line_analise, estado, v, flag_v);
                    } else {
                        flag_section = 1;
                        Functions::print_errors(msg, 9, line_count);
                    }

                    if (c == '\n') {
                        begin_line = arq_entrada.tellg();
                        line_analise = true;
                        if (forma_linha[0] != "nil" && forma_linha[1] != "nil" ) {
                            
                            cout << "=================== Linha: ";
                            for (int i = 0; i < linha.size(); i++) {
                                cout << linha[i] << " ";
                            }
                            cout << endl;

                            //cout << "\nFim da linha: "<< line_count << " Rotulo[" << forma_linha[0] << "] | Instrução[" << forma_linha[1] << "]" << endl;

                            linha.clear();
                            forma_linha[0] = "nil";
                            forma_linha[1] = "nil";
                        }
                        line_count++;
                    }
                }
            }
        }
    } else {
        cout << "Arquivo inexistente" << endl;
    }

    return 0;
}