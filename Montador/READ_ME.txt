
READ-ME
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Trabalho Prático 1
Software Básico
Prof. Bruno Macchiavello
1 o Semestre de 2022

Lucas Junior Ribas - Matrícula - 160052289

MONTADOR ======================================================

// Desenvolvido no Ubuntu 20.04.4 LTS - 64 bits | Compilardor: gcc/g++ (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0


Para compilar basta entrar na pasta "Montador" pelo terminal, e executar o "make". Caso desejar, ha uma linha comentada no Makefile que é responsável por executar o montador, onde pode ser editado os caminhos dos arquivos de entrada e saida. Caso queira usar o Makefile para executar, basta rodar "make run".

Caso contrário apenas rode o "make" e execute "./montador_rb [-p ou -o] seu_arquivo.txt seu_arq_saida.txt

Na opção "-p", o arquivo sera pre-processado e enviado para pasta "files/pre_processado/pre_seu_arquivo.txt".

Na opção "-o", o arquivo também será pre-processado e envidado para mesma pasta("files/pre_processado/pre_seu_arquivo.txt"), e automaticamente sera usado como entrada para o montador, montando o codigo. Ou seja, a opção "-o" pre-processa e monta em sequência.

Obs: O arquvio objeto de saida vai para um diretório de sua escolha, ou na mesma pasta da main(montador_rb). Mas o arquivo pre-processado sempre vai para o diretório "files/pre_processado/pre_seu_arquivo.txt".

ALTERAÇÕES ======================================================

O montador aceita argumentos na diretiva SPACE, ou seja é possiver ter um "vetor". Eu alterei a tabela de diretivas, fazendo com que o SPACE nescessite de 1 argumento.

Durante as aulas, o SPACE quando não tem nada significa reserve 1 espaço de memória. Agora com minha mudança é nescessário que o argumento de SPACE seja >= 1 : SPACE (>=1).

OBS: Não precisa alterar os seus arquivos de teste, (colocando 1 em SPACE). O PRE-PROCESSAMENTO irá cuidar dessa questão. Ou seja, qualquer SPACE que não tenha um argumento, por exemplo (SPACE), passará a ser (SPACE 1).





////////////////////////////////////////////////////////////////////////////////////////////////////////////////
