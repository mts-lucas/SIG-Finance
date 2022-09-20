run: all
	./sfinancemain

all:
	gcc -c -Wall M1_/cadastro_moradores_main.c; gcc -c -Wall M2_/receitas_main.c; gcc -c -Wall M3_/despesas_main.c; gcc -o sfinancemain  sfinance_main.c cadastro_moradores_main.o receitas_main.o despesas_main.o
