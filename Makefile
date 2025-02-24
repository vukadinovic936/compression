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

zeno: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)
	$(MAKE) -C lib/ArithCodeTut/src/
	pip3 install -r requirements.txt

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 

say_hello:
	@echo "Installing Zeno..."
