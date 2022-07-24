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