CXXFLAGS = -g -I.. -Wall -Wshadow  -Werror
LDFLAGS = -lm

CPROGRAMS = arith_simple 

# the three files that comprise the Arithmetic Coding library
LIBCODE=../arith_code.cc ../arith_code.hh ../arith_code_config.hh

all : ${CPROGRAMS}  

V=-DAC_COLORED -DAC_VERBOSE -DVERBOSE


#######
arith_simple: arith_simple.cc ${LIBCODE} frequencies.cc  Makefile
	${CXX} ${CXXFLAGS}  ${LDFLAGS} -g -O  arith_simple.cc  -o arith_simple

.PHONY: arith_simple_test

clean:
	rm   -f ${CPROGRAMS}
