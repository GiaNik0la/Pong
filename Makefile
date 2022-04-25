build: main.c
	clear
	cc main.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

bnr:
	clear
	make build
	./a.out

run: 
	clear
	./a.out