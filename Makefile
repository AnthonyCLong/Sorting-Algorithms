# driver: driver.o sorting_algos.o
# 	g++ -o driver driver.o sorting_algos.o
# 	@echo LINKING FILES...
# driver.o: sorting_algos.cpp sorting_algos.hpp
# 	g++ -c driver.cpp
# sorting_algos.o: sorting_algos.cpp sorting_algos.hpp
# 	g++ -c sorting_algos.cpp
# .PHONY : clean
# clean:
# 	$(REMOVE) *.o
# 	@echo CLEANING DIRECTORY

CFLAGS = -O
CC = g++
SRC = driver.cpp sorting_algos.cpp
OBJ = $(SRC:.cpp = .o)

driver: $(OBJ)
	$(CC) $(CFLAGS) -o driver $(OBJ)
	@echo CLEANING DIRECTORY
.PHONY : clean
clean:
	-rm *.o