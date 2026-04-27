
vpath %.c = src/
vpath %.o = bin/
A=bin/main.o
B=bin/fun1.o 
C=bin/fun2.o 
D=bin/fun3.o

OBJ = main.o fun1.o fun2.o fun3.o


E:=$(A) $(B) $(C) $(D)
G=$(E:.o=.c)

define F
	@"pwd"
	@"ls"
endef

CFLAGS=-Wall

ifdef TEST
	E = $(A) 
else
	E = $(B)
endif


bin/main:$(E)
	@echo $(F)
	@echo $(G)
	@echo "hello"
	@echo $(^)
	$(CC) $(^) -o $(@) -I include $(CFLAGS)

bin/main.o:main.c
	$(CC) $(<) -o $(@) -c -I include

bin/fun1.o:fun1.c
	$(CC) $(<) -o $(@) -c -I include

bin/fun2.o:fun2.c
	$(CC) $(<) -o $(@) -c -I include

bin/fun3.o:fun3.c
	$(CC) $(<) -o $(@) -c -I include

clean:

	@echo $(E)



clean_all:
	$(RM) bin/*

