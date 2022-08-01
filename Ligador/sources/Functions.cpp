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


int Functions::retur_op_inst_cod(map<string,Instrucao> tab_inst, int key) {

    map<string, Instrucao>::iterator it_tab_inst;

    for(auto it = tab_inst.begin(); it != tab_inst.end(); it++) {
        if (it->second.GetCodigo() == key) {
            return it->second.GetOperando();
        }
    }
    return -1;
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
    } else {
        cout << "Não abriu" << endl;
    }
    return file;
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

void Functions::tabs_ligador(map<string, Definicao>& tab_def, map<string, Uso>& tab_uso, string& linha, int& flag_uso, int& flag_def, int flag_cod, vector<int>& cod_obj) {
    string word, word_aux;
    if (flag_cod == 1) {
        for (int i=0; i<linha.size(); i++) {
            if (linha[i] == ' ' || linha[i] == '\n' || linha[i] == '\t') {
                word_aux = word;
                word.clear();
            } else {
                word += linha[i];
            }
        }
        if (word == "USO") {
            flag_uso = 1;
        }
        else if(word == "DEF") {
            flag_uso = 0;
            flag_def = 1;
        }
        if (flag_uso == 1 && flag_def == 0) {
            if (word.size() > 0) {
                // cout << word << " " << word_aux << endl;
                if (isAllDigit(word)) {
                    insere_tab_uso(tab_uso, word_aux, stoi(word), 0);
                    
                }
            }
        }
        if (flag_uso == 0 && flag_def == 1) {
            if (word.size() > 0) {
                if (isAllDigit(word)) {
                    insere_tab_def(tab_def, word_aux, stoi(word), 0);
                }
            }

        }
    }
    if (flag_cod == 2) {
        for (int i=0; i<linha.size(); i++) {

            if (linha[i] == ' ' || linha[i] == '\n' || linha[i] == '\t') {
                if (word.size() > 0) {
                    cod_obj.push_back(stoi(word));
                }
                word.clear();
            } else {
                word += linha[i];
            }

        }
        if (word.size() > 0) {
            cod_obj.push_back(stoi(word));
        }
    }
}

void Functions::ler_arquivos(char* arq_a, char* arq_b, map<string, Definicao>& tab_def_a, map<string, Uso>& tab_uso_a, vector<int>& cod_obj_a,
    map<string, Definicao>& tab_def_b, map<string, Uso>& tab_uso_b, vector<int>& cod_obj_b) {

    string file_string_a;
    string file_string_b;

    file_string_a =  Functions::up_file(arq_a);
    file_string_b =  Functions::up_file(arq_b);

    string linha;
    int flag_uso = 0;
    int flag_def = 0;

    for (int i=0; i<file_string_a.size(); i++) {
        if (file_string_a[i] == '\n') {
            Functions::tabs_ligador(tab_def_a, tab_uso_a, linha, flag_uso, flag_def, 1, cod_obj_a);
            linha.clear();
        } else {
            linha += file_string_a[i];
        }
    }
    Functions::tabs_ligador(tab_def_a, tab_uso_a, linha, flag_uso, flag_def, 2, cod_obj_a);

    flag_uso = 0;
    flag_def = 0;
    for (int i=0; i<file_string_b.size(); i++) {

        if (file_string_b[i] == '\n') {
            Functions::tabs_ligador(tab_def_b, tab_uso_b, linha, flag_uso, flag_def, 1, cod_obj_b);
            linha.clear();
        } else {
            linha += file_string_b[i];
        }
    }
    Functions::tabs_ligador(tab_def_b, tab_uso_b, linha, flag_uso, flag_def, 2, cod_obj_b);
}