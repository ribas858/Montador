all: 	montador_rb.o Functions.o
	g++ -o montador_rb montador_rb.o Functions.o
	rm -rf *.o

montador_rb.o: montador_rb.cpp
	g++ -c montador_rb.cpp

Functions.o: sources/Functions.cpp
	g++ -c sources/Functions.cpp

# TROQUE POR SEUS ARQUIVOS E(OU) DIRETÓRIOS
# run:
# 	./montador_rb -o files/testes/seu_arquivo_entrada.txt seu_arquivo_saida.txt