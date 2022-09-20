run: all
	./sfinance_main

all:
	gcc -c -Wall M1/.c; gcc -c -Wall M2/.c; gcc -c -Wall M3_/.c; gcc -o sfinance_main sfinancemain.o ./M1/.o ./M2/*.o ./M3/d espesas_main.o