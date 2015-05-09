
SOURCEDIR=sources
BUILDDIR=.build

SRCS=$(wildcard $(SOURCEDIR)/*.c)
OBJS=$(patsubst $(SOURCEDIR)/%.c,$(BUILDDIR)/%.o,$(SRCS))

all: $(BUILDDIR)/magpie-debug

$(BUILDDIR)/%.o: $(SOURCEDIR)/%.c | $(BUILDDIR)
	$(CC) -c -o $@ $(CFLAGS) $?

$(BUILDDIR)/magpie-debug: $(OBJS)
	$(CC) -o $@ $(LDFLAGS) $^

$(BUILDDIR):
	mkdir -p $@
