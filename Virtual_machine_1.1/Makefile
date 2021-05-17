CC=gcc
CFLAGS=-Wall -std=c99

FILES=Virtual_machine.c Virtual_machine_kernel.c VMlib/stack.c VMlib/hashtab.c VMlib/list.c 

.PHONY: default install build run clean
default: build run 
build: $(FILES)
	$(CC) -o Virtual_machine $(CFLAGS) $(FILES)
run:
	./Virtual_machine build main.vms -o main.vme
	./Virtual_machine run main.vme
clean:
	rm -f Virtual_machine Factorial/main.vme
