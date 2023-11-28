SRC = $(shell echo ’Ouch!’ 1>&2 ; echo *.[cy])
#$(info $(SRC))
#A = $(filter %.y,$(SRC))

#$(info $(A))

#B = $(patsubst %.y,%.o,$(A))
#$(info $(B))
OBJ = \
	$(patsubst %.c,%.o, $(filter %.c,$(SRC))) \
	$(patsubst %.y,%.o, $(filter %.y,$(SRC)))

#$(info $(OBJ))
test: $(OBJ)
	$(CC) -o $@ $(OBJ)
