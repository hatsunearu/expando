CC = gcc
CFLAGS = -Wall -g -fPIC -c
LIBNAME = libexpando
PY3 = python3

build: expando.c expando.h
	$(CC) $(CFLAGS) expando.c -o $(LIBNAME).o
	ar rcs $(LIBNAME).a $(LIBNAME).o
    
clean:
	rm -f $(LIBNAME).a $(LIBNAME).o
	rm -rf pyexpando/build/
	rm -f pyexpando/*.so
	rm -f pyexpando/*.c

cython: $(LIBNAME).a
	cd pyexpando; $(PY3) setup.py build_ext --inplace
