PREFIX?=/usr/local
INCLUDES=-I/usr/include/apr-1.0/ -llibapr1 -llibaprutil1
FLAGS=-Wall -g -D_LARGEFILE64_SOURCE=1

CFLAGS=$(FLAGS) $(INCLUDES)
LDFLAGS=-llibapr1 -pthread -llibaprutil1

all: devpkg
	cp devpkg ../devpkg

devpkg: bstrlib.o db.o shell.o commands.o

install: all
	install -d $(DESTDIR)/$(PREFIX)/bin/
	install devpkg $(DESTDIR)/$(PREFIX)/bin/ 

clean:
	rm -f *.o
	rm -f devpkg
	rm -rf .dSYM
