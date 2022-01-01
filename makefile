# beps.make
# make file to compile beps program

# CFLAGS=-std=c99 -O3
CFLAGS=-std=c99 -g -O3 -Iinclude

ODIR=src
IDIR=src

# first name a variable OBJSects for all OBJSect files
_OBJS = beps.o display.o doflux.o inter.o model.o pixtolon.o readawc.o readb_init.o readclim.o readindex.o readlc.o rs.o zcomp.o \
  carbon.o dmatrix.o doxx.o melt.o penmon.o ra.o readb.o readbm.o readconf.o readlai.o readsnow.o rsoil.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))

# now give target as makebeps with OBJSects as variable dependencies + command line

# gcc=/usr/bin/gcc-9
CC=gcc
#	icc -g -lm -o bepsp $(OBJSects)
# echo $(OBJS) 

beps.exe: $(OBJS) 
	echo $(OBJS) 
	$(CC) $(CFLAGS) -o beps.exe $(OBJS) -lm
	# gcc $(CFLAGS) -o beps $(OBJSects) -lm

# list the dependencies for OBJSect files - those header files which help build OBJSects
# how to build all OBJSect files from all dependent source files

$(ODIR)/%.o: $(IDIR)/%.c
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm $(OBJS) *.exe

# $(OBJSects): $(sources)
#	icc -g -c $(sources)
# gcc $(CFLAGS) -c $(sources)


# $@: The filename representing the target.

# $%: The filename element of an archive member specification.

# $<: The filename of the first prerequisite.

# $?: The names of all prerequisites that are newer than the target, separated by spaces.

# $^: The filenames of all the prerequisites, separated by spaces. This list has duplicate filenames removed since for most uses, such as compiling, copying, etc., duplicates are not wanted.

# $+: Similar to $^, this is the names of all the prerequisites separated by spaces, except that $+ includes duplicates. This variable was created for specific situations such as arguments to linkers where duplicate values have meaning.

# $*: The stem of the target filename. A stem is typically a filename without its suffix. Its use outside of pattern rules is discouraged.
