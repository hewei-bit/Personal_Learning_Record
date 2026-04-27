
vpath %.c = src/client/:src/
vpath %.o = bin/
vpath %.h = include/

A=bin/client.o
B=bin/IO.o 
C=bin/client_list.o 
D=bin/GUI.o
E=bin/thread_pool.o
F=bin/user.o

OBJ = client.o client_list.o GUI.o IO.o thread_pool.o user.o


G:=$(A) $(B) $(C) $(D) $(E) $(F)


CFLAGS=-Wall



bin/client:$(G)
	$(CC) $(^) -o $(@) -I include -lpthread $(CFLAGS)

bin/client.o:client.c
	$(CC) $(<) -o $(@) -c -I include

bin/client_list.o:client_list.c
	$(CC) $(<) -o $(@) -c -I include

bin/GUI.o:GUI.c
	$(CC) $(<) -o $(@) -c -I include

bin/IO.o:IO.c
	$(CC) $(<) -o $(@) -c -I include

bin/user.o:user.c
	$(CC) $(<) -o $(@) -c -I include

bin/thread_pool.o:thread_pool.c
	$(CC) $(<) -o $(@) -c -I include

clean:
	$(RM) bin/*

