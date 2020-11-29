NAME = game
TEST = $(NAME)_test

C_FILES:= $(shell find ./src -name *.cpp)
INCLUDES:= -I ./include 
DEPS = ./include/*.hpp
LIB_PATH = /home/liorcoeh/git/lior-cohen/Game/lib

CC = g++
CFLAGS = -std=c++11 -pedantic-errors -Wall -Wextra -g 				# For Debbuging
LDFLAGS = -std=c++11 -pedantic-errors -Wall -Wextra -DNDEBUG -O3 	# Not Debbug

# Link the test binary to shared objects
test:  libgame.so ./test/$(TEST).cpp $(DEPS)
	@$(CC) -L./lib -Wl,-rpath=$(LIB_PATH) $(INCLUDES) $(LDFLAGS) -o $(TEST) ./$@/$(TEST).cpp -lgame -lsfml-graphics -lsfml-window -lsfml-system
	@mv $(TEST) ./$@/bin
	@./$@/bin/$(TEST) 

debug:	./test/$(TEST).cpp libgame.so $(DEPS)
		@$(CC) -L./lib -Wl,-rpath=$(LIB_PATH) $(INCLUDES) $(CFLAGS) ./test/$(TEST).cpp -o main -lgame -lsfml-graphics -lsfml-window -lsfml-system
		@mv main ./test/debbuging 

libgame.so: $(C_FILES) $(DEPS) 
	@$(CC) $(INCLUDES) $(CFLAGS) $(C_FILES) -fPIC -shared -o $@
	@mv $@ ./lib
		
gt: ./test/bin/main
	clear
	@gdbtui ./test/bin/main
	
vlg: ./test/bin/tic_tac_toe_test
	@valgrind --leak-check=full --leak-check=full --show-leak-kinds=all --track-origins=yes ./test/bin/tic_tac_toe_test

.PHONY: clean

clean:
	 @rm -f -R *.o *.so *_test
