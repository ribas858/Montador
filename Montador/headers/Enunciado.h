#ifndef ENUNCIADO_H
#define ENUNCIADO_H

class Enunciado {

    public:
        int* GetForm() {
            return form;
        }
        
        const int& GetOpc() const {
            return op_c;
        }

        int& SetOpc() {
            return op_c;
        }

    private:
        int form[2];
        int op_c;
};

#endif