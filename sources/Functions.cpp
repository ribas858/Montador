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
    enunc.GetForm()[0] = forma_linha[0];
    enunc.GetForm()[1] = forma_linha[1];
    enunc.SetOpc() = op_count;
    return enunc;
}

bool Functions::busca_inst (map<string,Instrucao> tab_inst, string key) {
    map<string, Instrucao>::iterator it_tab_inst;
    it_tab_inst = tab_inst.find(key);
    if ( it_tab_inst != tab_inst.end()) {
        return true;
    } else {
        return false;
    }
}

bool Functions::busca_diret (map<string,Diretiva> tab_diret, string key) {
    map<string, Diretiva>::iterator it_tab_diret;
    
    it_tab_diret = tab_diret.find(key);
    if ( it_tab_diret != tab_diret.end()) {
        return true;
    } else {
        return false;
    }
}

void Functions::print_errors(string lexema, int cod, int line_count) {
    switch (cod)
    {
    case 1:
        cout << "Erro LÉXICO::Declaração de Rótulo Inválida -- (Esperado \":\" - Mas foi encontrado \"" << lexema << "\" ) Erro::Linha: " << line_count << endl;
        break;
    case 2:
        cout << "Erro SEMÂNTICO::Linha de Instrução Já Possui Rótulo -- (Esperado \"Instrução\" - Mas foi encontrado \"" << lexema << "\" ) Erro::Linha: " << line_count << endl;
        break;
    case 3:
        cout << "Erro SINTÁTICO::Instrução Indefinida -- (Esperado \"Instrução Válida\" - Mas foi encontrado \"" << lexema << "\" ) Erro::Linha: " << line_count << endl;
        break;
    default:
        cout << "Erro não encontrado!!" << endl;
        break;
    }
}

bool Functions::val_caracts(char l) {
   
    if ( (int(l) >= 65 && int(l) <= 90) || (int(l) >= 97 && int(l) <= 122) || (int(l) >= 48 && int(l) <= 58) ) {
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
    } else if (cod == 2) {
        cout << lexema << " func" << endl;
        if (isdigit(lexema[0]) || (lexema[0] == ':' && lexema.size() > 1) ) {
            return false;
        } else {
            for (int i = 0; i < lexema.size(); i++) {
                if (!val_caracts(lexema[i])) {
                    cout << int(lexema[i]) << endl;
                    flag = 1;
                }
                if (lexema[i] == ':') {
                    if (i != lexema.size()-1 ) {
                        flag = 1;
                    } else if (lexema.size() == 1) {
                        flag = 1;
                    } 
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

void Functions::Analise_rot_instr(ifstream& arq_cod1, char& c, string& lexema, map<string, Instrucao>& tab_inst,
    map<string, Diretiva>& tab_diret, int& line_count, bool* forma_linha, vector<string>& linha, string& rot, int& begin_line, bool& line_analise, int& pos_inst) {

    int flag = 0;
    // string rot = "";
    string aux1, aux2;
    vector<string> flag_error;
    
    

    if (c == ' ' || c == '\n' || c == '\t') {
        if (lexema.size() > 0) {

            if (line_analise) {
                line_analise = false;
                pos_inst = has_line_instruction(arq_cod1, tab_inst, tab_diret, begin_line);
                cout << "Pos Instrucao: " << pos_inst << endl;
            }

            if (Functions::busca_inst(tab_inst, lexema) || Functions::busca_diret(tab_diret, lexema)) {
                // cout << "rot0: " << rot << endl;
                // cout << "Caso 0: Achou na tabela de inst -> " << lexema << endl;
                if (!rot.empty()) {
                    cout << "vamooooooooo" << endl;
                    Functions::print_errors(lexema, 1, line_count);
                    flag_error.push_back(lexema);
                    linha.push_back("Error");
                    rot = "";
                }
                forma_linha[1] = true;
                linha.push_back(lexema);
                
            } else {
                cout << "Nao achou na tabela de inst. Size: -> " << lexema << endl;
                if (pos_inst != -1) {

                    if ( !forma_linha[1] && !forma_linha[0] ) {
                        //cout << "Nao existe instrucao e nem rotulo na linha atual -> " << lexema << endl;

                        if( Functions::rot_valido(lexema, 1) ) {
                            //cout << "1 caso: Checa se existe caracteres expeciais e digitos dentre o rotulo -> " << lexema << endl;

                            if (lexema[lexema.size()-1] != ':') {
                                //cout << "2 caso: Ultimo caracter do lexema é DIFERENTE de dois pontos :  -> " << lexema << endl;

                                if(lexema[0] != ':') {
                                    //cout << "3 caso: Primeiro caracter do lexema é DIFERENTE de dois pontos :  -> " << lexema << endl;
                                    
                                    int pos = -1;
                                    for (int i=0; i<lexema.size(); i++) {
                                        if (lexema[i] == ':') {
                                            pos = i;
                                        }
                                    }
                                    if (pos != -1){
                                        aux1 = lexema.substr(pos+1, lexema.size());
                                        aux2 = lexema.substr(0, pos+1);

                                        if (Functions::busca_inst(tab_inst, aux1) || Functions::busca_diret(tab_diret, aux1)) {
                                            linha.push_back(aux2);
                                            linha.push_back(aux1);
                                            forma_linha[0] = true;
                                            forma_linha[1] = true;
                                            flag = 1;
                                        } else {
                                            Functions::print_errors(lexema.substr(pos, lexema.size()), 1, line_count);
                                            flag_error.push_back(lexema);
                                        }
                                    } else {
                                        
                                        if (rot.empty()) {
                                            rot = lexema;
                                        } else {
                                            
                                            

                                            cout << "Aquiii pohhaaaa " << endl;
                                            Functions::print_errors(lexema, 1, line_count);
                                            flag_error.push_back(lexema);
                                            rot = "";
                                        }
                                    }
                                    
                                } else {
                                    //cout << "4 caso: Primeiro caracter do lexema é IGUAL a dois pontos :  -> " << lexema << endl;
                                    if (lexema.size() > 1 ) {
                                        
                                        string aux = lexema.substr(1, lexema.size());

                                        if (Functions::busca_inst(tab_inst, aux) || Functions::busca_diret(tab_diret, aux)) {
                                            lexema = rot + lexema[0];
                                            linha.push_back(lexema);
                                            linha.push_back(aux);
                                            rot = "";
                                            forma_linha[0] = true;
                                            forma_linha[1] = true;
                                        } else {
                                            Functions::print_errors(lexema, 1, line_count); 
                                            flag_error.push_back(lexema);
                                        }
                                    
                                        
                                    } else {
                                        lexema = rot + lexema;
                                        linha.push_back(lexema);
                                        rot = "";
                                        forma_linha[0] = true;
                                    }
                                }
                            } else {
                                //cout << "5 caso: Ultimo caracter do lexema é IGUAL a dois pontos :  -> " << lexema << endl;
                                //cout << "rot: " << rot << endl;
                                if (rot.empty()) {
                                    lexema = rot + lexema;
                                    linha.push_back(lexema);
                                    rot = "";
                                    forma_linha[0] = true;
                                } else {
                                    if (lexema.size() > 1) {
                                        // cout << "deu ruim" << endl;
                                        Functions::print_errors(lexema, 1, line_count);
                                        flag_error.push_back(lexema);
                                    } else {
                                        
                                        lexema = rot + lexema;
                                        linha.push_back(lexema);
                                        rot = "";
                                        forma_linha[0] = true;
                                    }
                                }
                            }
                        } else {
                            
                        }
                    } else {
                        if (forma_linha[0] && !forma_linha[1]) {
                            //cout << "lexema rot: " << lexema << endl;
                            if (Functions::rot_valido(lexema, 2)) {
                                // cout << "Rotulo válido" << endl;
                                Functions::print_errors(lexema, 2, line_count);
                                flag_error.push_back(lexema);
                            } else {
                                Functions::print_errors(lexema, 1, line_count);
                                Functions::print_errors(lexema, 2, line_count);
                                flag_error.push_back(lexema);
                            }
                        }
                    }
                } else {
                    cout << "Erraoooo man" << endl;
                    Functions::print_errors(lexema, 3, line_count);
                    flag_error.push_back(lexema);
                }
            }
            if (flag == 1) {
                //cout << " lexema final: aux1 e aux2 -> |" << aux1 << "| e |" << aux2 << "| ";
                //cout << " L: "<< line_count << " R[" << forma_linha[0] << "] | I[" << forma_linha[1] << "]" << endl;
                flag = 0;
            } else {
                
                cout << " lexema final: |" << lexema << "| ";
                cout << " L: "<< line_count << " R[" << forma_linha[0] << "] | I[" << forma_linha[1] << "]" << endl;
                if (!forma_linha[0] && !forma_linha[1] && linha.size() == 0 && rot.empty()) {
                    linha.push_back("Error");
                    if (!duplicate_vector(flag_error, lexema)) {
                        Functions::print_errors(lexema, 3, line_count);
                    }
                    
                } else {
                    cout << "rot mul " << rot << " lexema: " << lexema << "|" << endl;
                    if (!duplicate_vector(linha, lexema) && lexema[lexema.size()-1] == ':') {
                        linha.push_back(lexema);
                    } else {
                        if (!duplicate_vector(linha, lexema) && forma_linha[1]) {
                            linha.push_back(lexema);
                        } else if (!duplicate_vector(linha, lexema) && pos_inst == -1) {
                            linha.push_back(lexema);
                        }
                    }
                }
            }
            flag_error.clear();
            lexema = "";
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

int Functions::has_line_instruction(ifstream& arq_cod1, map<string, Instrucao>& tab_inst, map<string, Diretiva>& tab_diret, int begin_line) {
    char b;
    string word;
    int atual_pos_file = arq_cod1.tellg();
    
    int has_inst = 0;
    int inst_pos = -1;
    int pos = 0;
    int dois_pt = 0;
    vector<string> line;

    // cout << "pos atual: " << atual_pos_file << endl;
    
    int i = 0;
    while (b != '\n') {
        arq_cod1.seekg(begin_line + i);
        arq_cod1.get(b);
        if (b == ' ' || b == '\t' || b == '\n') {
            if (word.size() > 0) {
                if (Functions::busca_inst(tab_inst, word) || Functions::busca_diret(tab_diret, word)) {
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
    
    
    arq_cod1.seekg(atual_pos_file);

    if (has_inst > 0) {
        inst_pos = pos;
    } else {
        // for (int i = 0; i < line.size(); i++) {
        //     cout << line[i] << " ";
        // }
        // cout << endl;
        // cout << line[0];
        if (line.size() > 2) {
            inst_pos = -2;
        }
    }
    
    cout << "dois pt: " << dois_pt << " has inst: " << has_inst <<  " word: " << word << " inst_pos: " << inst_pos << " pos: " << pos << endl;

    return inst_pos;
}