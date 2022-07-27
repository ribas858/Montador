#include "../headers/Functions.h"

void Functions::ler_tab_instr (map<string, Instrucao>& tab_inst) {
    Instrucao inst;    // Item tabela de instruções 
    ifstream arq_tab_inst ("files/default/tabela_de_instrucoes.txt");

    if (!arq_tab_inst) {
        cout << endl << "Arquivo TXT de dados da tabela de instruções esta faltando." 
            << endl << "Verifique o local do arquivos e tente novamentes!!" << "\n\n";
        abort();
    }

    while (arq_tab_inst >> inst.SetInstrucao() >> inst.SetOperando() >> inst.SetCodigo() >> inst.SetTamanho() ) {
        tab_inst.insert(pair<string, Instrucao> (inst.GetInstrucao(), inst));
    }
}

void Functions::ler_tab_diret (map<string,Diretiva>& tab_diret) {
        
    Diretiva diret;   // Item tabela de diretivas
    ifstream arq_tab_diret ("files/default/diretivas.txt");
    
    if (!arq_tab_diret) {
        cout << endl << "Arquivo TXT de dados da tabela de diretivas esta faltando." 
            << endl << "Verifique o local do arquivos e tente novamentes!!" << "\n\n";
        abort();
    }

    while (arq_tab_diret >> diret.SetInstrucao() >> diret.SetOperando() >> diret.SetTamanho() ) {
        tab_diret.insert(pair<string, Diretiva> (diret.GetInstrucao(), diret));
    }
    //tab_inst.erase("ADD");
    //tab_inst.erase(tab_inst.find("ADD"), tab_inst.find("STOP"));
}

void Functions::print_inst_por_key (map<string, Instrucao> tab_inst, string key) {

    map<string,  Instrucao>::iterator it_tab_inst;

    it_tab_inst = tab_inst.find(key);
    if ( it_tab_inst != tab_inst.end()) {
        cout << "Key: " << it_tab_inst->first << " -> " << it_tab_inst->second.GetInstrucao() << " " << it_tab_inst->second.GetOperando() << " " <<  it_tab_inst->second.GetCodigo() << " " <<  it_tab_inst->second.GetTamanho() << endl; 
    }
}

void Functions::print_diret_por_key (map<string,Diretiva> tab_diret, string key) {

    map<string, Diretiva>::iterator it_tab_diret;

    it_tab_diret = tab_diret.find(key);
    if ( it_tab_diret != tab_diret.end()) {
        cout << "Key: " << it_tab_diret->first << " -> " << it_tab_diret->second.GetInstrucao() << " " << it_tab_diret->second.GetOperando() << " " <<  it_tab_diret->second.GetTamanho() << endl; 
    }
}

void Functions::print_inst (map<string, Instrucao> tab_inst) {
    for (auto i : tab_inst) {
        cout << "Key: " << i.first << " -> " << i.second.GetInstrucao() << " " << i.second.GetOperando() << " " <<  i.second.GetCodigo() << " " <<  i.second.GetTamanho() << endl;
    }
}

void Functions::print_diret (map<string,Diretiva> tab_diret) {
    for (auto d : tab_diret) {
        cout << "Key: " << d.first << " -> " << d.second.GetInstrucao() << " " << d.second.GetOperando()  << " " <<  d.second.GetTamanho() << endl;
    }
}

void Functions::insere_tab_simbol (map<string,Simbolo>& tab_simbol, string key, int pos, int line) {

    Simbolo simbol;
    map<string, Simbolo>::iterator it_tab_simbol;
    
    
    it_tab_simbol = tab_simbol.find(key);
    if ( it_tab_simbol == tab_simbol.end()) {
        
        simbol.SetRotulo() = key;
        simbol.SetEndereco() = pos;
        cout << "entrouuuuu " << simbol.GetRotulo() << " -- " << simbol.GetEndereco() << endl;
        tab_simbol.insert(pair<string, Simbolo> (key, simbol));
    } else {
        cout << "ERRO SEMÂNTICO -- Linha: " << line << " | Rótulo '" << key << "' Já Declarado Anteriormente" << endl;
    }
}

void Functions::print_tab_simbol (map<string,Simbolo> tab_simbol) {
    for (auto d : tab_simbol) {
        cout << "Key: " << d.first << " -> " << d.second.GetRotulo() << " " << d.second.GetEndereco() << endl;
    }
}

int Functions::retur_tam_inst (map<string,Instrucao> tab_inst, string key) {

    map<string, Instrucao>::iterator it_tab_inst;

    it_tab_inst = tab_inst.find(key);
    if ( it_tab_inst != tab_inst.end()) {
        return it_tab_inst->second.GetTamanho();
    } else {
        return -1;
    }
}

int Functions::retur_op_inst (map<string,Instrucao> tab_inst, string key) {

    map<string, Instrucao>::iterator it_tab_inst;

    it_tab_inst = tab_inst.find(key);
    if ( it_tab_inst != tab_inst.end()) {
        return it_tab_inst->second.GetOperando();
    } else {
        return -1;
    }
}

Instrucao Functions::retur_inst (map<string,Instrucao> tab_inst, string key) {
    map<string, Instrucao>::iterator it_tab_inst;
    Instrucao ret;

    it_tab_inst = tab_inst.find(key);
    if ( it_tab_inst != tab_inst.end()) {
        return it_tab_inst->second;
    } else {
        return ret;
    }
}

int Functions::retur_tam_diret (map<string,Diretiva> tab_diret, string key) {

    map<string, Diretiva>::iterator it_tab_diret;

    it_tab_diret = tab_diret.find(key);
    if ( it_tab_diret != tab_diret.end()) {
        return it_tab_diret->second.GetTamanho();
    } else {
        return -1;
    }
}

int Functions::retur_op_diret (map<string,Diretiva> tab_diret, string key) {

    map<string, Diretiva>::iterator it_tab_diret;

    it_tab_diret = tab_diret.find(key);
    if ( it_tab_diret != tab_diret.end()) {
        return it_tab_diret->second.GetOperando();
    } else {
        return -1;
    }
}

Diretiva Functions::retur_diret (map<string,Diretiva> tab_diret, string key) {
    map<string, Diretiva>::iterator it_tab_diret;
    Diretiva ret;
    it_tab_diret = tab_diret.find(key);
    if ( it_tab_diret != tab_diret.end()) {
        return it_tab_diret->second;
    } else {
        return ret;
    }
}

int Functions::busca_tab_simbol (map<string,Simbolo> tab_simbol, string key) {

    map<string, Simbolo>::iterator it_tab_simbol;

    it_tab_simbol = tab_simbol.find(key);
    if ( it_tab_simbol != tab_simbol.end()) {
        return it_tab_simbol->second.GetEndereco();
    } else {
        return -1;
    }
}

Enunciado Functions::update_enunc(Enunciado enunc, int line_count) {
    int forma_linha[2] = { enunc.GetForm()[0], enunc.GetForm()[1] };
    int op_count = enunc.GetOpc();
    cout << "OP Count antes: " << op_count << endl;
    cout << "Forma_linha[0]: " << forma_linha[0] << " -- ";
    cout << "Forma_linha[1]: " << forma_linha[1] << endl;
    if (forma_linha[1] != -1) {
        if (op_count == forma_linha[1]){
            forma_linha[0] = -1;
            forma_linha[1] = -1;
            op_count = 0;
        }
        else if (op_count > forma_linha[1]) {
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
    enunc.GetForm()[0] = forma_linha[0];
    enunc.GetForm()[1] = forma_linha[1];
    enunc.SetOpc() = op_count;
    return enunc;
}

bool Functions::busca_1 (map<string,Instrucao> tab_inst, string key) {
    map<string, Instrucao>::iterator it_tab_inst;
    it_tab_inst = tab_inst.find(key);
    if ( it_tab_inst != tab_inst.end()) {
        return true;
    } else {
        return false;
    }
}

bool Functions::busca_2 (map<string,Diretiva> tab_diret, string key) {
    map<string, Diretiva>::iterator it_tab_diret;
    
    it_tab_diret = tab_diret.find(key);
    if ( it_tab_diret != tab_diret.end()) {
        return true;
    } else {
        return false;
    }
}

bool Functions::busca_instrucao(map<string,Instrucao> tab_inst, map<string,Diretiva> tab_diret, string key) {
    if(busca_1(tab_inst, key) || busca_2(tab_diret, key)) {
        return true;
    } else {
        return false;
    }
}

void Functions::print_errors(string lexema, int cod, int line_count) {
    switch (cod)
    {
    case 1:
        cout << "Erro LÉXICO::Declaração de Rótulo Inválida -- (Esperado \"[LABEL][:]\" - Mas foi encontrado \"[" << lexema << "]\" ) Erro::Linha: " << line_count << endl;
        break;
    case 2:
        cout << "Erro LÉXICO/SINTÁTICO::Tentativa de Dupla Declaração de Rótulo -- (Esperado \"[LABEL][:]\" - Mas foi encontrado \"[" << lexema << "]\" ) Erro::Linha: " << line_count << endl;
        break;
    case 3:
        cout << "Erro SEMÂNTICO::Dupla Declaração | Linha de Instrução Já Possui Rótulo -- (Esperado \"Instrução\" - Mas foi encontrado \"[" << lexema << "]\" ) Erro::Linha: " << line_count << endl;
        break;
    case 4:
        cout << "Erro SINTÁTICO::Instrução Indefinida -- (Esperado \"[INSTRUCTION]\" - Mas foi encontrado \"[" << lexema << "]\" ) Erro::Linha: " << line_count << endl;
        break;
    case 5:
        cout << "Erro SEMÂNTICO::Dupla Declaração | Linha de Instrução Já Possui Rótulo -- (Esperado \"Operando\" - Mas foi encontrado \"[" << lexema << "]\" ) Erro::Linha: " << line_count << endl;
        break;
    case 6:
        cout << "Erro LÉXICO::TOKEN Inválido | -- (Esperado \"[OP]\" - Mas foi encontrado \"[" << lexema << "]\" ) Erro::Linha: " << line_count << endl;
        break;
    case 7:
        cout << "Erro LÉXICO::TOKEN ROTULO Inválido | --> \"[" << lexema << "]\" ) Erro::Linha: " << line_count << endl;
        break;
    case 8:
        cout << "Erro LÉXICO::TOKEN +99 Caracteres | --> Erro::Linha: " << line_count << endl;
        break;
    case 9:
        cout << "Erro SINTÁTICO::Falta Secao Texto | -- (Esperado \"[SECAO TEXTO]\" - Mas foi encontrado \"[" << lexema << "]\" ) Erro::Linha: " << line_count << endl;
        break;
    case 10:
        cout << "Erro SINTÁTICO::Falta Secao Dados | -- (Esperado \"[SECAO DADOS]\" - Mas foi encontrado \"[" << lexema << "]\" ) Erro::Linha: " << line_count << endl;
        break;
    default:
        cout << "Erro não encontrado!!" << endl;
        break;
    }
}

bool Functions::val_caracts(char l) {
   
    if ( (int(l) >= 65 && int(l) <= 90) || (int(l) >= 97 && int(l) <= 122) || (int(l) >= 48 && int(l) <= 58) || int(l) == 44 || int(l) == 95) {
        return true;
    } else {
        return false;
    }
}

bool Functions::rot_valido(string lexema, int cod) {
    int flag = 0;
    if (cod == 1) {
        if (isdigit(lexema[0])) {
            return false;
        } else {
            for (int i = 0; i < lexema.size(); i++) {
                if (!val_caracts(lexema[i])) {
                    cout << int(lexema[i]) << endl;
                    flag = 1;
                }
            }
            if (flag == 0) {
                return true;
            } else {
                return false;
            }
        }   
    }
    else if (cod == 2) {
        // cout << lexema << " func" << endl;
        if ( (isdigit(lexema[0]) || lexema[0] == ',' || lexema[0] == ':' || lexema[lexema.size()-1] == ':') && lexema.size() > 1 ) {
            return false;
        } else {
            for (int i = 0; i < lexema.size(); i++) {
                if (!val_caracts(lexema[i])) {
                    cout << int(lexema[i]) << endl;
                    flag = 1;
                }
                if (lexema[i] == ':' || lexema[i] == ',') {
                    if (i != lexema.size()-1 ) {
                        flag = 1;
                    } 
                    // else if (lexema.size() == 1) {
                    //     flag = 1;
                    // } 
                }
            }
            if (flag == 0) {
                return true;
            } else {
                return false;
            }
        }
    }
    else if (cod == 3) {
        // cout << lexema << " func" << endl;
        if ( (isdigit(lexema[0]) || lexema[0] == ',' || lexema[0] == ':' || lexema[lexema.size()-1] == ':' || lexema[lexema.size()-1] == ',') && lexema.size() > 1 ) {
            return false;
        } else {
            for (int i = 0; i < lexema.size(); i++) {
                if (!val_caracts(lexema[i])) {
                    cout << int(lexema[i]) << endl;
                    flag = 1;
                }
                if (lexema[i] == ':' || lexema[i] == ',') {
                    if (i != lexema.size()-1 ) {
                        flag = 1;
                    } 
                    // else if (lexema.size() == 1) {
                    //     flag = 1;
                    // } 
                }
            }
            if (flag == 0) {
                return true;
            } else {
                return false;
            }
        }
    }
    return false;
}

void Functions::Analise_rot_instr(ifstream& arq_entrada, char& c, string& lexema, map<string, Instrucao>& tab_inst,
    map<string, Diretiva>& tab_diret, int& line_count, string* forma_linha, vector<string>& linha, string& rot,
        int& begin_line, bool& line_analise, int& estado, pair<int,int>& v, int& flag_v) {
    
    if (c == ' ' || c == '\n' || c == '\t') {
        int size = lexema.size();
        
        if (size > 0) {
            if (busca_instrucao(tab_inst, tab_diret, lexema)) {
                
                //arq_entrada.seekg(-(size+1), ios::cur);
                estado = 2;
            } else {
                // cout << -(size+1) << endl;
                //arq_entrada.seekg(-(size+1), ios::cur);
                if (forma_linha[0] == "nil") {
                    estado = 1;
                } else {
                    estado = 3;
                }
            }
            
            switch (estado) {
                case 0:
                    // cout << "Estado 0" << endl;
                    
                    lexema.clear();
                    break;
                case 1:
                    // cout << "Estado 1" << endl;
                    
                    if (lexema[size-1] == ':') {
                        if(rot_valido(lexema, 1) && size <= 99+1) {
                            forma_linha[0] = "rot";
                            linha.push_back(lexema);
                        } else {
                            forma_linha[0] = "erro";
                            linha.push_back("[rotulo]");
                            if (size > 99+1) {
                                Functions::print_errors(lexema, 8, line_count);
                            } else {
                                Functions::print_errors(lexema, 1, line_count);
                                Functions::print_errors(lexema, 7, line_count);
                            }
                        }
                        
                    } else {
                        if (forma_linha[0] == "nil") {
                            forma_linha[0] = "erro";
                            linha.push_back("[rotulo]");
                            Functions::print_errors(lexema, 1, line_count);
                        }
                    }
                    // cout << lexema << endl;

                    //cout << "Rotulo[" << forma_linha[0] << "] | Instrução[" << forma_linha[1] << "]" << endl;
                    lexema.clear();
                    break;

                case 2:
                    // cout << "Estado 2" << endl;
                    
                    if (forma_linha[0] == "nil") {
                        forma_linha[0] = "check";
                    }
                    forma_linha[1] = "inst";
                    linha.push_back(lexema);
                    // cout << lexema << endl;
                    
                    //cout << "Rotulo[" << forma_linha[0] << "] | Instrução[" << forma_linha[1] << "]" << endl;
                    lexema.clear();
                    break;
                
                case 3:
                    // cout << "Estado 3" << endl;
                    
                    
                    if (forma_linha[1] == "nil" && has_line_instruction(arq_entrada, tab_inst, tab_diret, begin_line, 1).first == -1) {
                            forma_linha[1] = "erro";
                            linha.push_back("[inst]");
                            cout << lexema << endl;
                            Functions::print_errors(lexema, 4, line_count);
                            
                        
                    } else {
                        if (forma_linha[1] == "nil") {
                            if (lexema[size-1] == ':' ){
                                // linha.push_back(lexema);
                                if (size == 1) {
                                    Functions::print_errors(lexema, 2, line_count);
                                } else {
                                    Functions::print_errors(lexema, 3, line_count);
                                }
                            } else {
                                linha.push_back("[rotulo]");
                                Functions::print_errors(lexema, 1, line_count);
                                if (forma_linha[0] == "erro" || forma_linha[0] == "rot") {
                                    
                                    Functions::print_errors(lexema, 2, line_count);
                                }
                                forma_linha[0] = "erro";
                            }
                        } else {
                            if (lexema[size-1] == ':' ){
                                linha.push_back(lexema);
                                Functions::print_errors(lexema, 5, line_count);
                            } else {
                                
                                if (line_analise) {
                                    v = has_line_instruction(arq_entrada, tab_inst, tab_diret, begin_line, 2);
                                    line_analise = false;
                                }

                                if (v.first > 0) {
                                    // cout << "flag_v: " << flag_v << endl;
                                    if (v.first > 1) {
                                        flag_v = 1;
                                        v.first--;
                                        if (rot_valido(lexema, 2) && size <= 99+1) {
                                            // cout << "Rot valido" << endl;
                                        } else {
                                            // cout << "erro Rot" << endl;
                                            if (size > 99+1) {
                                                Functions::print_errors(lexema, 8, line_count);
                                            } else {
                                                Functions::print_errors(lexema, 6, line_count);
                                            }
                                        }
                                        if (v.second == 1) {
                                            linha.push_back(lexema+" ");
                                        } else {
                                            linha.push_back(lexema);
                                        }
                                    } else {
                                        
                                        if (v.first < 2 && flag_v == 1) {
                                            flag_v = 0;
                                            if (rot_valido(lexema, 3) && size <= 99+1) {
                                                // cout << "Rot valido" << endl;
                                            } else {
                                                // cout << "erro Rot" << endl;
                                                if (size > 99+1) {
                                                    Functions::print_errors(lexema, 8, line_count);
                                                } else {
                                                    Functions::print_errors(lexema, 6, line_count);
                                                }
                                            }
                                        } else {
                                            //cout << "-------l: " << lexema[size-1] << endl;
                                            if (rot_valido(lexema, 2) && (c != '\n' || lexema[size-1] != ',') && size <= 99+1) {
                                                // cout << "Rot valido" << endl;
                                            } else {
                                                // cout << "erro Rot" << endl;
                                                if (size > 99+1) {
                                                    Functions::print_errors(lexema, 8, line_count);
                                                } else {
                                                    Functions::print_errors(lexema, 6, line_count);
                                                }
                                            }
                                        }
                                        if (v.second == 1) {
                                            linha.push_back(lexema+" ");
                                        } else {
                                            linha.push_back(lexema);
                                        }
                                    }
                                } else {
                                    if (rot_valido(lexema, 3) && size <= 99+1) {
                                        // cout << "Rot valido" << endl;
                                    } else {
                                        // cout << "erro Rot" << endl;
                                        if (size > 99+1) {
                                            Functions::print_errors(lexema, 8, line_count);
                                        } else {
                                            Functions::print_errors(lexema, 6, line_count);
                                        }
                                    }
                                    linha.push_back(lexema);
                                }
                                
                            }
                        }
                    }
                    
                    // cout << "Rotulo[" << forma_linha[0] << "] | Instrução[" << forma_linha[1] << "]" << endl;
                    lexema.clear();
                    break;
                
                default:
                    break;
            }
        }
        
    } else {
        lexema += c;
    }
}

bool Functions::duplicate_vector(vector<string> v, string key) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == key) {
            return true;
        }
    }
    return false;

}

pair<int, int> Functions::has_line_instruction(ifstream& arq_entrada, map<string, Instrucao>& tab_inst, map<string, Diretiva>& tab_diret, int begin_line, int cod) {
    if (cod == 1) {
        char b;
        string word;
        int atual_pos_file = arq_entrada.tellg();
        
        int has_inst = 0;
        int inst_pos = -1;
        int pos = 0;
        int dois_pt = 0;
        vector<string> line;

        // cout << "pos atual: " << atual_pos_file << endl;
        
        int i = 0;
        while (b != '\n') {
            arq_entrada.seekg(begin_line + i);
            arq_entrada.get(b);
            if (b == ' ' || b == '\t' || b == '\n') {
                if (word.size() > 0) {
                    if (busca_instrucao(tab_inst, tab_diret, word)) {
                        has_inst++;
                    } else {
                        if (has_inst == 0) {
                            pos++;
                        }
                    }
                }
                line.push_back(word);
                word = "";
            } else {
                
                word += b;
            }
            i++;
        }
        
        
        arq_entrada.seekg(atual_pos_file);

        if (has_inst > 0) {
            inst_pos = pos;
        } 
        // else {
        //     // for (int i = 0; i < line.size(); i++) {
        //     //     cout << line[i] << " ";
        //     // }
        //     // cout << endl;
        //     // cout << line[0];
        //     if (line.size() > 2) {
        //         inst_pos = -2;
        //     }
        // }
        
        // cout << "dois pt: " << dois_pt << " has inst: " << has_inst <<  " word: " << word << " inst_pos: " << inst_pos << " pos: " << pos << endl;

        return make_pair(inst_pos, -1);
    }
    else if (cod == 2) {
        char b;
        int virg = 0;
        int atual_pos_file = arq_entrada.tellg();
        string word;

        int i = 0;
        while (b != '\n') {
            arq_entrada.seekg(begin_line + i);
            arq_entrada.get(b);
            
            if (b == ',') {
                virg++;
            } else {
                if (virg > 0) {
                    word += b;
                }
            }
            i++;
        }

        arq_entrada.seekg(atual_pos_file);
        int cont_space = 0;
        for (int i=0; i<word.size(); i++) {
            
                if (word[i] == ' ') {
                    cont_space++;
                } else {
                    // cout << "word[i]: " << word[i] << endl;
                    if (int(word[i]) == 10) {
                        cont_space = 0;
                    }
                    break;
                }
            
        }
        // cout << "Virgula: " << virg << " word: " << word << " =====> cont_s: " << cont_space << endl;
        
        if (virg == 0) {
            return make_pair(-1,-1);
        } else {
            return make_pair(virg, cont_space);
        }
        
    }
    return make_pair(-3,-3);
}

pair<bool, string> Functions::section_test(ifstream& arq_entrada, int begin_line) {
    char b;
    int atual_pos_file = arq_entrada.tellg();
    // arq_entrada.seekg(atual_pos_file);
    string line;

    int i = 0;
    while (b != '\n') {
            arq_entrada.seekg(begin_line + i);
            arq_entrada.get(b);
            if (b != '\n') {
                line += b;
            }
            i++;
    }
    // cout << "atual_pos_file: " << atual_pos_file << endl;

    arq_entrada.seekg(atual_pos_file);

    // cout << "Line size " << line << endl;
    if (line == "SECAO TEXTO" || line == "SECAO DADOS") {
        cout << "Line:: " << line << endl;
        return make_pair(true, line);
    } else {
        return make_pair(false, line);
    }
}

void Functions::val_sections(int& flag_section, ifstream& arq_entrada, int& begin_line, int& flag_data, string& lexema, int line_count, string& msg, int cod) {
    if (cod == 1) {
        if (flag_section == 0) {
            auto aux = Functions::section_test(arq_entrada, begin_line);
            if(aux.first) {
                flag_section = 1;
                arq_entrada.seekg(aux.second.size(), ios::cur);
                flag_data = 1;
            } else {
                msg = aux.second;
                
                arq_entrada.seekg(aux.second.size(), ios::cur);
                flag_data = 1;
            }
        }

    } 
    else if (cod == 2) {
        if (lexema == "SECAO" && flag_data == 1) {
            lexema.clear();
            flag_data = 0;
            auto aux = Functions::section_test(arq_entrada, begin_line);
            if (!aux.first) {
                // cout << "Falta secao dados" << endl;
                arq_entrada.seekg(aux.second.size()-4, ios::cur);
                Functions::print_errors(aux.second, 10, line_count);
            } else {
                arq_entrada.seekg(aux.second.size()-4, ios::cur);
            }
        }
    }
}

void Functions::up_file(char *arq_in) {
    char c;
    string file;
    ifstream arq_entrada(arq_in);

    if (arq_entrada.is_open()){
        while(arq_entrada.good()){
            arq_entrada.get(c);
		    file += c;
        }
    } else {
        cout << "Arquivo inexistente" << endl;
    }
    arq_entrada.close();
    
    file.pop_back();
    for(int i=0; i<file.size(); i++) {
        file[i] = toupper(file[i]);
    }

    ofstream arq_cod2(arq_in);
    if (arq_cod2.is_open()){
        arq_cod2 << file;
    } else {
        cout << "Arquivo inexistente" << endl;
    }
    arq_cod2.close();
}

string Functions::limpa_coment(ifstream& arq_entrada) {
    char b;
    string file;
    int ign_coment = 0;
    while(arq_entrada.good()){
        arq_entrada.get(b);
        if (b == ';') {
            ign_coment = 1;
        } else if (b == '\n') {
            ign_coment = 0;
        }
        if (ign_coment == 0) {
            file += b;
        }
    }
    return file;
}

void Functions::update_diretivas(map<string, string>& map_diret, map<string, Diretiva>& tab_diret, string& diret, string& key) {
    char b;
    string word;
    int size;
    int flag_qu = 0;
    int flag_if = 0;
    int flag_ign = 0;
    // cout << diret << endl;
    for (int i=0; i<diret.size(); i++) {
        
        if (diret[i] == ' ' || int(diret[i]) == 10) {
            if (flag_ign == 0) {
                size = word.size();
                if (size > 0) {
                    if (word[size-1] == ':') {
                        word.pop_back();
                        key = word;
                        auto it_diret = map_diret.find(word);
                        if ( it_diret == map_diret.end()) {
                            map_diret.insert(make_pair(word, "not"));    
                        }
                    }
                    else if (busca_2(tab_diret, word)) {
                        if (word == "EQU") {
                            auto it_diret = map_diret.find(key);
                            if ( it_diret != map_diret.end()) {
                                flag_qu = 1;
                            }
                        }
                        else if (word == "IF") {
                            flag_if = 1;
                            cout << "key: " << key << endl;
                        }
                        
                    }
                    
                    
                }
            }
            word.clear();
        } else {
            
            word += diret[i];
        }
    }
    if (flag_qu == 1) {
        auto it_diret = map_diret.find(key);
        if ( it_diret != map_diret.end()) {
            it_diret->second = word;
        }
    }
    if (flag_if == 1) {
        auto it_diret = map_diret.find(word);
        if ( it_diret != map_diret.end()) {
            cout << "s: " << it_diret->second << endl;
            if (int(stoi(it_diret->second)) == 0) {

            } 
        }
        cout << "w: "<< word << endl;
    }
    // cout << word << endl;
    
}