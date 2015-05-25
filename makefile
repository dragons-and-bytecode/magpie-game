
SOURCEDIR=sources
BUILDDIR=.build

CFLAGS  +=-Idepends/include
LDFLAGS +=-Ldepends/lib/osx
LDLIBS  +=-lSDL2 -lSDL2main -lSDL2_image -lSDL2_ttf -lfreetype -lbz2 -lz

SRCS=$(wildcard $(SOURCEDIR)/*.c)
OBJS=$(patsubst $(SOURCEDIR)/%.c,$(BUILDDIR)/%.o,$(SRCS))

all: $(BUILDDIR)/magpie-debug

$(BUILDDIR)/%.o: $(SOURCEDIR)/%.c | $(BUILDDIR)
	$(CC) -c -o $@ $(CFLAGS) $?

$(BUILDDIR)/magpie-debug: $(OBJS)
	$(CC) -o $@ $(LDFLAGS) $(LDLIBS) $^

$(BUILDDIR):
	mkdir -p $@

.PHONY: clean

clean:
	rm -rf $(BUILDDIR)
