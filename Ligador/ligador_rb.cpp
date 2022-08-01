#include "./headers/Functions.h"

int main (int argc, char **argv) {

    // (./ligador myfile.o myfle2.o

    char* arq_a = argv[1];
    char* arq_b = argv[2];

    map<string, Instrucao> tab_inst;    // Map tabela de instruções
    Functions::ler_tab_instr(tab_inst);     // Tabela de instruções

    
    
    map<string, Definicao> tab_def_a;  // Map tabela de definicao
    map<string, Uso> tab_uso_a;  // Map tabela de uso
    vector<int> cod_obj_a;    // vetor cod objeto

    map<string, Definicao> tab_def_b;  // Map tabela de definicao
    map<string, Uso> tab_uso_b;  // Map tabela de uso
    vector<int> cod_obj_b;    // vetor cod objeto

    map<string, Definicao> tab_def_global;  // Map tabela de definicao global
    map<string, Uso> tab_uso_global;  // Map tabela de uso global
    vector<int> cod_obj_ligado;     // cod objeto final


    Functions::ler_arquivos(argv[1], argv[2], tab_def_a, tab_uso_a, cod_obj_a, tab_def_b, tab_uso_b, cod_obj_b);

    
    

    map<string, Definicao>::iterator it_tab_def_b;

    int f_correcao_a = 0;
    int f_correcao_b = cod_obj_a.size();

    for(auto it_a = tab_def_a.begin(); it_a != tab_def_a.end(); it_a++) {
        Functions::insere_tab_def(tab_def_global, it_a->second.GetRotulo(), it_a->second.SetEndereco() + f_correcao_a, 0);
    }

    for(auto it_b = tab_def_b.begin(); it_b != tab_def_b.end(); it_b++) {
        Functions::insere_tab_def(tab_def_global, it_b->second.GetRotulo(), it_b->second.SetEndereco() + f_correcao_b, 0);
    }

    for(auto it_a = tab_uso_a.begin(); it_a != tab_uso_a.end(); it_a++) {
        Functions::insere_tab_uso(tab_uso_global, it_a->second.GetRotulo(), it_a->second.SetEndereco() + f_correcao_a, 0);
    }

    for(auto it_b = tab_uso_b.begin(); it_b != tab_uso_b.end(); it_b++) {
        Functions::insere_tab_uso(tab_uso_global, it_b->second.GetRotulo(), it_b->second.SetEndereco() + f_correcao_b, 0);
    }

    cod_obj_a.insert(cod_obj_a.end(), cod_obj_b.begin(), cod_obj_b.end());
    copy(cod_obj_a.begin(), cod_obj_a.end(), back_inserter(cod_obj_ligado));

    for(auto it = tab_uso_global.begin(); it != tab_uso_global.end(); it++) {
        auto it_tab_def = tab_def_global.find(it->second.GetRotulo());
        if ( it_tab_def != tab_def_global.end()) {
            cod_obj_ligado[it->second.GetEndereco()] += it_tab_def->second.GetEndereco(); 
        }
    }

    for (int i=f_correcao_b; i<cod_obj_ligado.size(); i++) {
        int op = Functions::retur_op_inst_cod(tab_inst, cod_obj_ligado[i]);
        if (op > -1) {
            i += op;
            auto it = tab_uso_global.find(to_string(i));
            if (it == tab_uso_global.end()) {
                cod_obj_ligado[i] += f_correcao_b;
            }

        }
    }

    cout << endl;
    for (int i=0; i<cod_obj_ligado.size(); i++) {
        cout << cod_obj_ligado[i] << " ";
    }
    cout << endl;

    string name_a = Functions::GetNameFile(arq_a, 1);
    string name_b = Functions::GetNameFile(arq_b, 0);

    ofstream arq_lig(name_a + "_LIGADO_" + name_b);

    for (int i=0; i<cod_obj_ligado.size(); i++) {
        arq_lig << cod_obj_ligado[i] << " ";
    }
    

    return 0;
}