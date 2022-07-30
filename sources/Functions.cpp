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

void Functions::ler_tab_extend (map<string, DiretivaExtend>& tab_extend) {
        
    DiretivaExtend extend;   // Item tabela de diretivas
    ifstream arq_tab_extend ("files/default/diretivas_extend.txt");
    // cout << "lendo" << endl;
    
    if (!arq_tab_extend) {
        cout << endl << "Arquivo TXT de dados da tabela Extendida de diretivas esta faltando." 
            << endl << "Verifique o local do arquivos e tente novamentes!!" << "\n\n";
        abort();
    }

    while (arq_tab_extend >> extend.SetInstrucao() >> extend.SetOperando() >> extend.SetTamanho() ) {
        tab_extend.insert(pair<string, DiretivaExtend> (extend.GetInstrucao(), extend));
    }
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

void Functions::print_extend (map<string, DiretivaExtend> tab_extend) {
    for (auto d : tab_extend) {
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
        simbol.SetExterno() = false;
        simbol.SetPublico() = false;
        // cout << "entrouuuuu " << simbol.GetRotulo() << " -- " << simbol.GetEndereco() << endl;
        tab_simbol.insert(pair<string, Simbolo> (key, simbol));
    } else {
        cout << "ERRO SEMÂNTICO -- Linha: " << line << " | Rótulo '" << key << "' Já Declarado Anteriormente" << endl;
    }
}

void Functions::insere_tab_def (map<string, Definicao>& tab_def, string key, int pos, int line) {

    Definicao def;
    map<string, Definicao>::iterator it_tab_def;
    
    
    it_tab_def = tab_def.find(key);
    if ( it_tab_def == tab_def.end()) {
        
        def.SetRotulo() = key;
        def.SetEndereco() = pos;
        tab_def.insert(pair<string, Definicao> (key, def));
    } else {
        cout << "ERRO SEMÂNTICO -- Linha: " << line << " | Rótulo '" << key << "' Já Declarado Anteriormente" << endl;
    }
}

void Functions::insere_tab_uso (map<string, Uso>& tab_uso, string key, int pos, int line) {

    Uso uso;
    uso.SetRotulo() = key;
    uso.SetEndereco() = pos;
    tab_uso.insert(pair<string, Uso> (to_string(pos), uso));
}

void Functions::insere_tab_plus (map<string, Plus>& tab_plus, string key, int pos) {
    Plus p;
    p.SetRotulo() = to_string(pos);
    p.SetEndereco() = stoi(key);
    tab_plus.insert(pair<string, Plus> (key, p));
}

void Functions::print_tab_def (map<string, Definicao> tab_def) {
    for (auto d : tab_def) {
        // cout << "Key: " << d.first << " -> " << d.second.GetRotulo() << " " << d.second.GetEndereco() << endl;
        cout << "Key: " << d.first << " -> " << d.second.GetEndereco() << endl;
    }
}

void Functions::print_tab_uso (map<string, Uso> tab_uso) {
    for (auto d : tab_uso) {
        // cout << "Key: " << d.first << " -> " << d.second.GetRotulo() << " " << d.second.GetEndereco() << endl;
        cout << "Key: " << d.second.GetRotulo() << " -> " << d.second.GetEndereco() << endl;
    }
}

void Functions::print_tab_plus (map<string, Plus> tab_plus) {
    for (auto p : tab_plus) {
        // cout << "Key: " << p.first << " -> " << p.seconp.GetRotulo() << " " << p.seconp.GetEnpereco() << enpl;
        cout << "Key: " << p.second.GetRotulo() << " -> " << p.second.GetEndereco() << endl;
    }
}

Plus Functions::return_plus (map<string,Plus> tab_plus, string key) {
    Plus p;
    p.SetExiste() = false;
    map<string, Plus>::iterator it_tab_plus;

    it_tab_plus = tab_plus.find(key);
    if ( it_tab_plus != tab_plus.end()) {
        return it_tab_plus->second;
    } else {
        return p;
    }
}

void Functions::print_tab_simbol (map<string,Simbolo> tab_simbol) {
    for (auto d : tab_simbol) {
        // cout << "Key: " << d.first << " -> " << d.second.GetRotulo() << " " << d.second.GetEndereco() << endl;
        cout << "Key: " << d.first << " -> " << d.second.GetEndereco() << " | Ext-> " << d.second.GetExterno() << " | Pub-> " << d.second.GetPublico() << endl;
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

void Functions::extern_simbol (map<string,Simbolo>& tab_simbol, string key) {
    map<string, Simbolo>::iterator it_tab_simbol;
    
    it_tab_simbol = tab_simbol.find(key);
    if ( it_tab_simbol != tab_simbol.end()) {
        it_tab_simbol->second.SetExterno() = true;
    }
}

void Functions::public_simbol (map<string, Simbolo>& tab_simbol, map<string, Definicao>& tab_def) {
    map<string, Simbolo>::iterator it_tab_simbol;
    map<string, Definicao>::iterator it_tab_def;

    for (it_tab_def = tab_def.begin(); it_tab_def != tab_def.end(); it_tab_def++) {
        for (it_tab_simbol = tab_simbol.begin(); it_tab_simbol != tab_simbol.end(); it_tab_simbol++) {
            if (it_tab_def->first == it_tab_simbol->first) {
                it_tab_def->second.SetEndereco() = it_tab_simbol->second.GetEndereco();
                it_tab_simbol->second.SetPublico() = true;
            }
        }
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

Simbolo Functions::return_simbol (map<string,Simbolo> tab_simbol, string key) {
    Simbolo sim;
    sim.SetExiste() = false;
    map<string, Simbolo>::iterator it_tab_simbol;

    it_tab_simbol = tab_simbol.find(key);
    if ( it_tab_simbol != tab_simbol.end()) {
        return it_tab_simbol->second;
    } else {
        return sim;
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

bool Functions::busca_extend (map<string,DiretivaExtend> tab_extend, string key) {
    map<string, DiretivaExtend>::iterator it_tab_extend;
    
    it_tab_extend = tab_extend.find(key);
    if ( it_tab_extend != tab_extend.end()) {
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
    string name;
    string sn, sn1, sn2;
    int n1, n2;

    switch (cod)
    {
    case 1:
        cout << "\nErro LÉXICO::Declaração de Rótulo Inválida -- (Esperado \"[LABEL][:]\" - Mas foi encontrado \"[" << lexema << "]\" ) Erro::Linha: " << line_count << endl << endl;
        break;
    case 2:
        cout << "\nErro LÉXICO/SINTÁTICO::Tentativa de Dupla Declaração de Rótulo -- (Esperado \"[LABEL][:]\" - Mas foi encontrado \"[" << lexema << "]\" ) Erro::Linha: " << line_count << endl << endl;
        break;
    case 3:
        cout << "\nErro SEMÂNTICO::Dupla Declaração | Linha de Instrução Já Possui Rótulo -- (Esperado \"Instrução\" - Mas foi encontrado \"[" << lexema << "]\" ) Erro::Linha: " << line_count << endl << endl;
        break;
    case 4:
        cout << "\nErro SINTÁTICO::Instrução Indefinida -- (Esperado \"[INSTRUCTION]\" - Mas foi encontrado \"[" << lexema << "]\" ) Erro::Linha: " << line_count << endl << endl;
        break;
    case 5:
        cout << "\nErro SEMÂNTICO::Dupla Declaração | Linha de Instrução Já Possui Rótulo -- (Esperado \"Operando\" - Mas foi encontrado \"[" << lexema << "]\" ) Erro::Linha: " << line_count << endl << endl;
        break;
    case 6:
        cout << "\nErro LÉXICO::TOKEN Inválido | -- (Esperado \"[OP]\" - Mas foi encontrado \"[" << lexema << "]\" ) Erro::Linha: " << line_count << endl << endl;
        break;
    case 7:
        cout << "\nErro LÉXICO::TOKEN ROTULO Inválido | --> \"[" << lexema << "]\" ) Erro::Linha: " << line_count << endl << endl;
        break;
    case 8:
        cout << "Erro LÉXICO::TOKEN +99 Caracteres | --> Erro::Linha: " << line_count << endl;
        break;
    case 9:
        cout << "\nErro SINTÁTICO::Falta Secao Texto | -- (Esperado \"[SECAO TEXTO]\" - Mas foi encontrado \"[" << lexema << "]\" ) Erro::Linha: " << line_count << endl << endl;
        break;
    case 10:
        cout << "\nErro SINTÁTICO::Falta Secao Dados | -- (Esperado \"[SECAO DADOS]\" - Mas foi encontrado \"[" << lexema << "]\" ) Erro::Linha: " << line_count << endl << endl;
        break;
    case 11:
        cout << "\nRun ->   \n./montador_rb ['-p' ou '-o'] [Seu Arquivo de Entrada] [Nome Arquivo de Saída]" << endl;
        cout << "=============================================================================\n" << endl;
        break;
    case 12:
        name = GetNameFile(lexema, 0);
        cout << "Arquivo de Entrada Inexistente:: [" << name << "] \n::Ou Diretório [" << lexema << "] Inválido\n" << endl;
        break;
    case 13:
        cout << "Função do Montador Inválida:: [" << lexema << "]\nOpções: '-p' => PRE-PROCESSAR | '-o' => COMPILAR" << endl; 
        break;
    case 14:
        cout << "=============================================================================\n" << endl;
        break;
    case 15:
        for (int i =0; i<lexema.size(); i++) {
            if(lexema[i] == '_'){
                sn1 = sn;
                sn.clear();
            } else {
                sn += lexema[i];
            }
        }
        sn2 = sn;
        n1 = stoi(sn1);
        n2 = stoi(sn2);
        cout << "\nErro SINTÁTICO::Numero de Operandos Inválido -- (Esperado \"[" << n2 <<  " OP]\" - Mas foi encontrado \"[" << n1 << " OP] Operando(s)\" ) Erro::Linha: " << line_count << endl << endl;
        break;
    case 16:
        cout << "\nErro SEMÂNTICO::Símbolo/Operando Não Definido -- (Esperado \"Operando Declarado\" - Mas foi encontrado \"[" << lexema << "]\" ) Erro::Linha: " << line_count << endl << endl;
        break;
    case 17:
        cout << "\nErro SEMÂNTICO::Diretiva Na Secao Texto \n-- (Esperado \"\n[SECAO TEXTO] {INSTRUCAO}\n[SECAO DADOS] {DIRETIVA}\" - \nMas foi encontrado \"[SECAO TEXTO] {" << lexema << "}\" ) Erro::Linha: " << line_count << endl << endl;
        break;
    case 18:
        cout << "\nErro SEMÂNTICO::Instrução Na Secao Dados \n-- (Esperado \"\n[SECAO TEXTO] {INSTRUCAO}\n[SECAO DADOS] {DIRETIVA}\" - \nMas foi encontrado \"[SECAO DADOS] {" << lexema << "}\" ) Erro::Linha: " << line_count << endl << endl;
        break;
    default:
        cout << "\nErro não encontrado!!\n" << endl;
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
        if (!isAllDigit(lexema)) {
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
        } else {
            return true;
        }
    }
    return false;
}

void Functions::Analise_rot_instr(ifstream& arq_entrada, char& c, string& lexema, map<string, Instrucao>& tab_inst,
    map<string, Diretiva>& tab_diret, map<string, DiretivaExtend>& tab_extend, int& line_count, string* forma_linha, vector<string>& linha,
        int& begin_line, bool& line_analise, int& estado, pair<int,int>& virgula, int& flag_v,
        bool* section_t, bool* section_d, int& flag_sec_t, int& flag_sec_d, bool& flag_erros, bool& flag_ligador) {
    
    if (c == ' ' || c == '\n' || c == '\t') {
        int size = lexema.size();
        
        if (size > 0) {
            if (busca_instrucao(tab_inst, tab_diret, lexema) || busca_extend(tab_extend, lexema)) {

                // if (!section_t[0] && !section_t[1]) {
                //     // cout << "Nao chegou na secao texto ainda " << lexema << endl;
                // }

                if (lexema == "BEGIN" || lexema == "END") {
                    // cout <<"beg> " <<  lexema << endl;
                    flag_ligador = true;
                }
               
                if ((section_t[0] && section_t[1]) && (!section_d[0] && !section_d[1]) && busca_2(tab_diret,lexema)) {
                    Functions::print_errors(lexema, 17, line_count);
                } else {
                    // cout << "lex: " << lexema << " busca2: " << busca_2(tab_diret,lexema) << " flag_d: " << flag_sec_d << endl;
                    // cout << "section t0: " << section_t[0] << " section t1: " << section_t[1] << endl;
                    // cout << "section d0: " << section_d[0] << " section d1: " << section_d[1] << endl;
                    if ( (section_t[0] && section_t[1]) && (!section_d[0] || !section_d[1]) && busca_2(tab_diret,lexema) && flag_sec_d == 0) {
                        Functions::print_errors(lexema, 10, line_count);
                        flag_sec_d = 1;
                        // cout << "falta secao dados" << endl;
                    }
                }

                if ((section_d[0] && section_d[1]) && busca_1(tab_inst,lexema)) {
                    Functions::print_errors(lexema, 18, line_count);
                } else {
                    if ((!section_t[0] || !section_t[1]) && busca_1(tab_inst,lexema) && flag_sec_t == 0) {
                        Functions::print_errors(lexema, 9, line_count);
                        flag_sec_t = 1;
                        // cout << "falta secao texto" << endl;
                    }
                }
                
                if (lexema == "SECAO") {
                    section_t[0] = true;
                    section_d[0] = true;
                }
                if (lexema == "TEXTO") {
                    section_t[0] = true;
                    section_t[1] = true;
                    if (!section_d[1]) {
                        section_d[0] = false;
                    }
                }
                if (lexema == "DADOS") {
                    section_d[0] = true;
                    section_d[1] = true;
                    if (!section_t[1]) {
                        section_t[0] = false;
                    }
                }
                estado = 2;
            } else {
                if (forma_linha[0] == "nil") {
                    estado = 1;
                } else {
                    estado = 3;
                }
            }
            
            switch (estado) {
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
                        if (forma_linha[1] == "nil" && has_line_instruction(arq_entrada, tab_inst, tab_diret, tab_extend, begin_line, 1).first == -1) {
                            forma_linha[1] = "erro";
                            linha.push_back("[inst]");
                            // cout << lexema << endl;
                            Functions::print_errors(lexema, 4, line_count);
                        } else {
                            if (forma_linha[1] != "erro") {
                                if (forma_linha[0] == "nil") {
                                    forma_linha[0] = "erro";
                                    linha.push_back("[rotulo]");
                                    Functions::print_errors(lexema, 1, line_count);
                                }
                            } else {
                                forma_linha[0] = "check";
                                linha.push_back(lexema);
                            }
                        }
                    }
                    // cout << lexema << endl;

                    // cout << "Rotulo[" << forma_linha[0] << "] | Instrução[" << forma_linha[1] << "]" << endl;
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
                    
                    
                    if (forma_linha[1] == "nil" && has_line_instruction(arq_entrada, tab_inst, tab_diret, tab_extend, begin_line, 1).first == -1) {
                            forma_linha[1] = "erro";
                            linha.push_back("[inst]");
                            // cout << lexema << endl;
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
                                    virgula = has_line_instruction(arq_entrada, tab_inst, tab_diret, tab_extend, begin_line, 2);
                                    line_analise = false;
                                }

                                if (virgula.first > 0) {
                                    // cout << "flag_v: " << flag_v << endl;
                                    if (virgula.first > 1) {
                                        flag_v = 1;
                                        virgula.first--;
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
                                        if (virgula.second == 1) {
                                            linha.push_back(lexema+" ");
                                        } else {
                                            linha.push_back(lexema);
                                        }
                                    } else {
                                        
                                        if (virgula.first < 2 && flag_v == 1) {
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
                                        if (virgula.second == 1) {
                                            linha.push_back(lexema+" ");
                                        } else {
                                            linha.push_back(lexema);
                                        }
                                    }
                                } else {
                                    // cout << "mais " << lexema << endl;
                                    if (lexema != "+") {
                                        if (rot_valido(lexema, 3) && size <= 99+1) {
                                            // cout << "Rot valido" << endl;
                                        } else {
                                            cout << "erro Rot" << endl;
                                            if (size > 99+1) {
                                                Functions::print_errors(lexema, 8, line_count);
                                            } else {
                                                Functions::print_errors(lexema, 6, line_count);
                                            }
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

pair<int, int> Functions::has_line_instruction(ifstream& arq_entrada, map<string, Instrucao>& tab_inst, map<string, Diretiva>& tab_diret, map<string, DiretivaExtend>& tab_extend, int begin_line, int cod) {
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
                    if (busca_instrucao(tab_inst, tab_diret, word) || busca_extend(tab_extend, word)) {
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
        // cout << "Line:: " << line << endl;
        return make_pair(true, line);
    } else {
        return make_pair(false, line);
    }
}

void Functions::val_sections(int& flag_section, ifstream& arq_entrada, int& begin_line, string& msg, string& passagem_2) {
    if (flag_section == 0) {
        auto aux = Functions::section_test(arq_entrada, begin_line);
        // cout << "cod 1: aux first: " << aux.second << endl;
        if(aux.first) {
            flag_section = 1;
            passagem_2 += aux.second + "\n";
            arq_entrada.seekg(aux.second.size(), ios::cur);
        } else {
            msg = aux.second;
            arq_entrada.seekg(aux.second.size(), ios::cur);
        }
    }
}

string Functions::up_file(char *arq_in) {
    char c;
    string file;
    ifstream arq_entrada(arq_in);

    if (arq_entrada.is_open()){
        while(arq_entrada.good()){
            arq_entrada.get(c);
		    file += c;
        }
        
        arq_entrada.close();
        file.pop_back();
        for(int i=0; i<file.size(); i++) {
            file[i] = toupper(file[i]);
        }
    }
    return file;
}

void Functions::update_diretivas(map<string, string>& map_diret, map<string, Diretiva>& tab_diret, string& diret, int& flag_ign) {
    char b;
    string word, key, word_aux;
    int size;
    int flag_qu = 0;
    int flag_if = 0;
    int flag_const = 0;
    string diret_aux = diret;
    diret.clear();

    for (int i=0; i<diret_aux.size(); i++) {
        
        if (diret_aux[i] == ' ') {
            
            size = word.size();
            if (size > 0) {
                if (word[size-1] == ':') {
                    word_aux = word;
                    word_aux.pop_back();
                    key = word_aux;
                    auto it_diret = map_diret.find(word_aux);
                    if ( it_diret == map_diret.end()) {
                        map_diret.insert(make_pair(word_aux, "not"));    
                    }
                }
                else if (busca_2(tab_diret, word)) {
                    if (word == "EQU") {
                        auto it_diret = map_diret.find(key);
                        if ( it_diret != map_diret.end()) {
                            flag_qu = 1;

                            flag_ign = 1;
                        }
                    }
                    else if (word == "IF") {
                        flag_if = 1;
                        flag_ign = 1;
                    }
                    else if (word == "CONST") {
                        // cout << "const meu parceiro" << endl;
                        flag_const = 1;
                    }
                }
                // cout << "word: " << word << " size: " << word.size() << endl;
                diret += word + " ";
            }
            
            
            word.clear();
        } else {
            word += diret_aux[i];
        }
    }
    if (flag_const == 1) {
        auto it_diret = map_diret.find(word);
        if ( it_diret != map_diret.end()) {
            word = it_diret->second;
        }
        flag_const = 0;
    }

    if(!word.empty()) {
        diret += word + '\n';
    }
    // cout << "diret: " << diret << endl;

    if (flag_ign == 1) {
        // cout << "Apagando.. c" << endl;
        diret.erase();
        flag_ign = 0;
    }

    

    if (flag_qu == 1) {
        // cout << "key: " << key << endl;
        auto it_diret = map_diret.find(key);
        if ( it_diret != map_diret.end()) {
            it_diret->second = word;
        }
    }

    if (flag_if == 1) {
        auto it_diret = map_diret.find(word);
        if ( it_diret != map_diret.end()) {
            if (int(stoi(it_diret->second)) == 0) {
                flag_ign = 1;
            } 
        }
    }
}

string Functions::GetNameFile(string src, int cod) {
    string name;
    if (cod == 1) {
        // cout << "src " << src << endl;
        string name2;
        for (int i=0; i<src.size(); i++) {
            if (src[i] == '.') {
                break;
            }
            name2 += src[i];
        }
        // cout << "name2 " << name2 << endl;
        name = name2;
    } else {
        for (int i=src.size(); i>-1; i--) {
            if (src[i] == '/') {
                break;
            }
            name += src[i];
        }
        reverse(name.begin(), name.end());
    }
    return name;
}

void Functions::passagem1(map<string, Definicao>& tab_def, map<string, Simbolo>& tab_simbol, map<string,Instrucao>& tab_inst, map<string,Diretiva>& tab_diret,
    vector<string>& linha, int& cont_posicao, int& line_count, bool& flag_erros, map<string, Plus>& tab_plus) {
    
    int n_operandos = 0;
    int tam_instrucao = 0;
    int tam_diretiva = 0;
    int cont = 0;
    int achou_inst = 0;

    string rot;
    string mais;
    int flag_pub = 0;
    
    for (auto i = 0; i < linha.size(); i++) {
        if(retur_op_inst(tab_inst, linha[i]) != -1) {
            // cout << "Inst: " << linha[i] << " cont pos: " << cont_posicao << endl;
            n_operandos = retur_op_inst(tab_inst, linha[i]);
            tam_instrucao = retur_tam_inst(tab_inst, linha[i]);
            achou_inst = 1;
        }
        else if (retur_op_diret(tab_diret, linha[i]) != -1) {
            //cout << "Diret: " << linha[i] << " cont pos: " << cont_posicao << endl;
            n_operandos = retur_op_diret(tab_diret, linha[i]);
            tam_diretiva = retur_tam_diret(tab_diret, linha[i]);
            achou_inst = 1;
        } else {
            if (achou_inst == 1) {

                if (linha[i] == "+") {
                    mais = "+";
                }
                else if (!mais.empty()) {
                    // cout << "not emp " << linha[i] << " Ed. " << cont + cont_posicao << endl;
                    insere_tab_plus(tab_plus, to_string(cont+cont_posicao), stoi(linha[i]));
                    mais.clear();
                } else {
                    cont++;
                    // cout << "End. " << cont + cont_posicao << ": " << linha[i] << endl; 
                }
            } else {
                // cout << "else: " << linha[i] << endl;
                if (flag_pub == 1) {
                    insere_tab_def(tab_def, linha[i], cont_posicao, line_count);
                    flag_pub = 0;
                }
                if (linha[i] == "EXTERN") {
                    extern_simbol(tab_simbol, rot);
                    rot = "";
                } 
                else if (linha[i] == "PUBLIC") {
                    // cout << "pub: " << linha[i] << endl;
                    flag_pub = 1;
                }
                if(linha[i][linha[i].size()-1] == ':') {
                    string aux = linha[i];
                    aux.pop_back();
                    rot = aux;
                    // cout << "rot aux " << rot << endl;
                    insere_tab_simbol(tab_simbol, aux, cont_posicao, line_count);
                }
            }
            
        }
    }
    if (cont != n_operandos) {
        print_errors((to_string(cont) + "_" + to_string(n_operandos)), 15, line_count);
    }
    cont_posicao += tam_instrucao + tam_diretiva;
    // cout << "N_op: "<< n_operandos << " tam_inst: " << tam_instrucao << " tam diretiva: " << tam_diretiva << " cont: " << cont << endl;
}

void Functions::passagem2(string& cod_obj, map<string, Simbolo>& tab_simbol, map<string,Instrucao>& tab_inst, map<string,Diretiva>& tab_diret,
    string& passagem2, int& cont_posicao, int& line_count, map<string, DiretivaExtend>& tab_extend, map<string, Uso>& tab_uso, map<string, Plus>& tab_plus) {
    
    int flag_const = 0;
    string lexema;
    int libera_cont = 0;
    int cont = 0;
    int cont2 = 0;

    int flag_mais = 0;
    int flag_space = 0;
    // string mais;
    // int ini = 0;
    // int flag_i = 0;

    int inst_tam = 0;
    int diret_tam = 0;
    for (int i = 0; i < passagem2.size(); i++) {
        
        if (passagem2[i] == ' ' || passagem2[i] == '\n' || passagem2[i] == '\t') {
            
            if(lexema.size() > 0) {
                //if (lexema != "SECAO" && lexema != "TEXTO" && lexema != "DADOS") {
                   
                    if(!busca_instrucao(tab_inst, tab_diret, lexema) && !busca_extend(tab_extend, lexema)) {
                        
                        if (lexema[lexema.size()-1] != ':' && libera_cont == 1) {
                            
                            if (libera_cont == 1 && flag_const == 0) {
                                cont2++;
                                cont = cont_posicao + cont2;
                                // cout <<"lexema: " << lexema << " cont mano: " << cont << endl;
                            }

                            if (lexema[lexema.size()-1] == ',') {
                                lexema.pop_back();
                            }
                            // int end_sym = busca_tab_simbol(tab_simbol, lexema);
                            Simbolo s = return_simbol(tab_simbol, lexema);
                            if (s.GetExiste()) {
                                    
                                    if (s.GetExterno()) {
                                        // cout << "End symbol: " << lexema << " " <<  cont << endl;
                                        insere_tab_uso(tab_uso, lexema, cont, line_count);
                                    }

                                    Plus p = return_plus(tab_plus, to_string(cont));
                                    if(p.GetExiste()) {
                                        // cout << "p: " << p.GetRotulo() << endl;
                                        int m = stoi(p.GetRotulo()) + s.GetEndereco();
                                        cod_obj += to_string(m) + " ";
                                        // cout << "================= isere plus " << m <<  " s end: " << s.GetEndereco() << " -> " << cod_obj << endl; 
                                    } else {
                                        // cout <<"s exist: " << s.GetEndereco() << endl;
                                        cod_obj += to_string(s.GetEndereco()) + " ";
                                        // cout << "================= isere " << s.GetRotulo() << " -> " << cod_obj << endl;
                                    }
                            } else {
                                // cout <<"DENTRO IF " << lexema << "flag sp " << flag_space << endl;
                                if (lexema == "+") {
                                    flag_mais = 1;
                                } else {
                                        if (flag_const == 1 || flag_mais == 1) {
                                            flag_mais = 0;
                                            if (flag_const == 1) {
                                                flag_const = 0;
                                                if(isAllDigit(lexema)) {
                                                    // cout << "digit: "<< lexema << endl;
                                                    cod_obj += lexema + " ";
                                                }
                                            }
                                        } else {
                                            if (flag_space == 1) {
                                                int s = stoi(lexema);
                                                for(int i=0; i<s; i++) {
                                                    string z = "0";
                                                    cod_obj += z + ' ';
                                                }
                                                flag_space = 0;
                                            } else {
                                                print_errors(lexema, 16, line_count);
                                            }
                                        }
                                    
                                }
                            }
                        }
                    } else {
                        
                        if (lexema == "TEXTO") {
                            libera_cont = 1;
                        }
                        
                        if (busca_1(tab_inst, lexema)) {
                            // cout << "lexema1: " << lexema << endl;
                            auto inst = retur_inst(tab_inst, lexema);
                            inst_tam = inst.GetTamanho();
                            cod_obj += to_string(inst.GetCodigo()) + " ";
                        }
                        else if (busca_2(tab_diret, lexema)) {
                            // cout << "lexema2: " << lexema << endl;
                            auto diret = retur_diret(tab_diret, lexema);
                            diret_tam = diret.GetTamanho();
                            if (lexema == "SPACE") {
                                // cout << "op space " << diret.GetOperando() << endl;
                                // cod_obj += to_string(diret.GetOperando()) + " ";
                                flag_space = 1;
                            }
                            else if (lexema == "CONST") {
                                flag_const = 1;
                            }
                        }
                                  
                    }
                    
                    lexema.clear();
                // } else {
                //     lexema.clear();
                // }
            }
            if (passagem2[i] == '\n') {
                // cout << "Contador de posicao: " << cont_posicao << " cont: " << cont << " libera_cont: " << libera_cont << " flag_const: " << flag_const << endl;
                cont_posicao += inst_tam + diret_tam;
                inst_tam = 0;
                diret_tam = 0;
                cont = 0;
                cont2 = 0;
                line_count++;
            }
        } else {
            lexema += passagem2[i];
        }
        
    }

    cout << cod_obj << endl;
}

bool Functions::isAllDigit(string dig) {
    int flag = 0;
    for (int i=0; i<dig.size(); i++) {
        if (!isdigit(dig[i])) {
            flag++;
        }
    }
    if (flag > 0) {
        return false;
    } else {
        return true;
    }
}