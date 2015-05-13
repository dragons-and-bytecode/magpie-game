
SOURCEDIR=sources
BUILDDIR=.build

CFLAGS  +=-Idepends/include
LDFLAGS +=-Ldepends/lib/osx
LDLIBS  +=-lSDL2 -lSDL2main

SRCS=$(wildcard $(SOURCEDIR)/*.c)
OBJS=$(patsubst $(SOURCEDIR)/%.c,$(BUILDDIR)/%.o,$(SRCS))

all: $(BUILDDIR)/magpie-debug

$(BUILDDIR)/%.o: $(SOURCEDIR)/%.c | $(BUILDDIR)
	$(CC) -c -o $@ $(CFLAGS) $?

$(BUILDDIR)/magpie-debug: $(OBJS)
	$(CC) -o $@ $(LDFLAGS) $(LDLIBS) $^

$(BUILDDIR):
	mkdir -p $@
