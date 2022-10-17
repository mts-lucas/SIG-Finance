run: all
	./sfinancemain.exe

all:
	gcc -c -Wall M1_/cadastro_moradores_main.c; gcc -c -Wall M2_/receitas_main.c; gcc -c -Wall M3_/despesas_main.c; gcc -c -Wall M5_/relatorios.c; gcc -c -Wall auxiliares/funcoes_auxiliares.c; 
	gcc -o sfinancemain.exe  sfinance_main.c cadastro_moradores_main.o receitas_main.o despesas_main.o relatorios.o funcoes_auxiliares.o

clean:
	rm ./*.o