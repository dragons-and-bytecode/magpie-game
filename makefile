
SOURCEDIR=sources
BUILDDIR=.build
OUTNAME=magpie

CFLAGS  +=-Idepends/include -g
LDFLAGS +=-Ldepends/lib/osx
LDLIBS  +=-lSDL2 -lSDL2main -lSDL2_image -lSDL2_ttf -lfreetype -lbz2 -lz

SRCS=$(wildcard $(SOURCEDIR)/*.c)
OBJS=$(patsubst $(SOURCEDIR)/%.c,$(BUILDDIR)/%.o,$(SRCS))

all: $(BUILDDIR)/$(OUTNAME)-debug

$(BUILDDIR)/%.o: $(SOURCEDIR)/%.c | $(BUILDDIR)
	$(CC) -c -o $@ $(CFLAGS) $?

$(BUILDDIR)/$(OUTNAME)-debug: $(OBJS)
	$(CC) -o $@ $(LDFLAGS) $(LDLIBS) $^

$(BUILDDIR)/$(OUTNAME)_test.dylib: $(OBJS)
	$(CC) $(LDFLAGS) $(LDLIBS) -shared $^ -o $@

$(BUILDDIR):
	mkdir -p $@

.PHONY: clean behave

behave: $(BUILDDIR)/$(OUTNAME)_test.dylib
	behave test/features

clean:
	rm -rf $(BUILDDIR)
