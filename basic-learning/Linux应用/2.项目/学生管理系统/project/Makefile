objects =  1-1.o 1-2.o 1-3.o


main: $(objects)
	gcc -o main $(objects)
%.o: %.c
	gcc -c $<
	

clean:
	rm *.o
	rm main



name = hw
curname := $(name)
name = hewei
print:
	@echo curname:$(curname)
