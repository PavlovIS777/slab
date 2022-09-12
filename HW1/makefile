CC = g++
INCDIR = inc
SRCDIR = src 
OBJDIR = obj
OBJECTS = obj/main.o
TESTSDIR = testSys
#flags
OBJCOMPFLAGS = -c -g -std=c++17 -I $(INCDIR) -O2
COMPFLAGS = -std=c++17 -g -I $(INCDIR) -O2


#task for default cache. *.inl files don't need to be compiled to objects btw.
cache: program.out
$(OBJDIR)/main.o: main.cpp
	$(CC) $(OBJCOMPFLAGS) $^ -o $@

program.out: $(OBJECTS)
	$(CC) $(COMPFLAGS) $^ -o $@

PHONY.:clean

driver: driver.cpp
	$(CC) $^ -o drive.out
clean:
	rm -f $(OBJDIR)/*.o
	rm -f $(TESTSDIR)/randTests/*.txt
	rm -f *.out
	rm -f *.o
	clear

PHONY.:testCache

testCache: 
	python3 ./$(TESTSDIR)/generateTests.py

PHONY.:memcheck
memcheck:
	valgrind --leak-check=full \
    --show-leak-kinds=all \
    --track-origins=yes \
    --verbose \
    --log-file=valgrind-out.txt \
    ./a.out