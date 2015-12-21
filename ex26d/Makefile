PREFIX?=/usr/local
LIBS=-l apr-1 -l aprutil-1
INCLUDES=-I /usr/include/apr-1.0/ $(LIBS) 
FLAGS=-Wall -g -D_LARGEFILE64_SOURCE=1

CFLAGS=$(FLAGS) $(INCLUDES)
LDFLAGS=-pthread $(LIBS)

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
