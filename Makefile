CFLAGS=-Wall -g

all: ex1 ex3 ex4 ex5 ex6 ex7 ex8 ex9 ex10 ex11 ex12 ex13 ex14 ex15 ex16 ex17 ex18 ex19 ex20 ex22 ex23 ex24 ex25 ex26 ex27 ex31

ex19:	make_subdir
	cd ex19d; $(MAKE)

ex22:	make_subdir
	cd ex22d; $(MAKE)

ex26:	make_subdir
	cd ex26d; $(MAKE)

make_subdir:
	true

clean_all:
	rm -f ex1
	rm -f ex3
	rm -f ex4
	rm -f ex5
	rm -f ex6
	rm -f ex7
	rm -f ex8
	rm -f ex9
	rm -f ex10
	rm -f ex11
	rm -f ex12
	rm -f ex13
	rm -f ex14
	rm -f ex15
	rm -f ex16
	rm -f ex17
	rm -f ex18
	rm -f ex19; cd ex19d; $(MAKE) clean
	rm -f ex20
	rm -f ex22; cd ex22d; $(MAKE) clean
	rm -f ex23
	rm -f ex24
	rm -f ex25
	rm -f ex26; cd ex26d; $(MAKE) clean
	rm -f ex31

clean:
	rm -f ex31
