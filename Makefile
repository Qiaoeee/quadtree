
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/quadtree

SRC= main.c writeTree.c buildTree.c nodeValue.c

# generic build details

CC=      cc
COPT=    -g
CFLAGS= -lm

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(COPT) -c -o $@ $<

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(EXE) 

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

main.o:  main.c buildTree.h writeTree.h nodeValue.h treeStructure.h
buildTree.o: buildTree.c buildTree.h writeTree.h nodeValue.h treeStructure.h
writeTree.o: writeTree.c buildTree.h writeTree.h nodeValue.h treeStructure.h
nodeValue.o: nodeValue.c buildTree.h writeTree.h nodeValue.h treeStructure.h