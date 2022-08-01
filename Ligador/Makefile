all: 	ligador_rb.o Functions.o
	g++ -o ligador_rb ligador_rb.o Functions.o
	rm -rf *.o

ligador_rb.o: ligador_rb.cpp
	g++ -c ligador_rb.cpp

Functions.o: sources/Functions.cpp
	g++ -c sources/Functions.cpp

# TROQUE PELO SEU ARQUIVO E(OU) SEU DIRETÓRIO
# run:
# 	./ligador_rb files/saidas/seu_arquivo_a.txt files/saidas/seu_arquivo_b.txt