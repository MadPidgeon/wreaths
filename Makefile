OBJ=wreath.o main.o

%.o: %.c
	g++ $< -o $@

main: $(OBJ)
	g++ -o $@ $^