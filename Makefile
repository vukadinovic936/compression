IDIR=include
CC=g++
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR=lib

SRC=src

LIBS=-lm

DEPS=$(wildcard $(IDIR)/*.h)
_SRC=$(notdir $(wildcard $(SRC)/*.cpp))
OBJ=$(patsubst %,$(ODIR)/%,$(_SRC:.cpp=.o))

$(ODIR)/%.o: $(SRC)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

say_hello:
	@echo "Installing Zeno..."