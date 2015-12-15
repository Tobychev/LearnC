PREFIX?=/usr/local
CFLAGS=-Wall -g -llibapr1 -llibaprutil1
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
