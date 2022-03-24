CC = g++
EXE = Craps
OBJ = Craps.o
CFLAGS =
DEPS =

%.0 : %.cpp $(DEPS)
	$(CC) -c -o $@ $^ $(CFLAGS)

$(EXE) : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) $(EXE)