CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG $(OPTFLAGS)
LIBS=-ldl $(OPTLIBS)
PREFIX?=/usr/local

SOURCES=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

TEST_SRC=$(wildcard tests/*_tests.c)
TESTS=$(patsubst %.c,%,$(TEST_SRC))

TARGET=build/libLIBNAME.a
SO_TARGET=$(patsubst %.a,%.so,$(TARGET))

# Build targets
all: $(TARGET) $(SO_TARGET) tests

dev: CFLAGS=-g -Wall -Isrc -Wall -Wextra $(OPTFLAGS)
dev: all

$(TARGET): CFLAGS += -fPIC
$(TARGET): build $(OBJECTS)
	ar rcs $@ $(OBJCEST)
	ranlib $@

$(SO_TARGET): $(TARGET) $(OBJECTS)
	$(CC) -shared -o $@ $(OBJECTS)

build:
	@mkdir -p build
	@mkdir -p bin

# The unit tests
.PHONY: tests
tests: CFLAGS += $(TARGET)
tests: $(TESTS)
	sh ./tests/runtests.sh

valgrind:
	VALGRIND="valgrind --log-file=/tmp/valgrind-%p.log" $(MAKE)

# The cleanup
clean:
	rm -rf build $(OBJECTS) $(TESTS)
	rm -f tests/test.log
	find . -name "*.gc*" -exec rm {} \;
	rm -rf $(find . -name "*.dSYM" -print)

# The installer
install: all
	install -d $(DESTDIR)/$(PREFIX)/lib
	install $(TARGET) $(DESTDIR)/$(PREFIX)/lib

# The checker
BADFUNCS='[^_->a-zA-Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)|stpn?cpy||a?sn?printf|byte_))'
check:
	@echo Files with potentially bad functions
	@egrep $(BADFUNCS) $(SOURCES) || true
