CC = g++
INCDIR = inc
SRCDIR = src 
OBJDIR = obj
OBJECTS = obj/TriangleIntersaction.o
TESTSDIR = testSys

OBJCOMPFLAGS = -c -g -std=c++17 -I $(INCDIR) #-Wall -Wextra -Weffc++ -Wc++0x-compat -Wc++11-compat -Wc++14-compat 
# OBJCOMPFLAGS += -Waggressive-loop-optimizations -Walloc-zero -Walloca -Walloca-larger-than=8192 -Warray-bounds 
# OBJCOMPFLAGS += -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy 
# OBJCOMPFLAGS += -Wdangling-else -Wduplicated-branches -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security 
# OBJCOMPFLAGS += -Wformat-signedness -Wformat=2 -Wformat-overflow=2 -Wformat-truncation=2 -Winline -Wlarger-than=8192 
# OBJCOMPFLAGS += -Wvla-larger-than=8192 -Wlogical-op -Wmissing-declarations -Wnon-virtual-dtor -Wopenmp-simd 
# OBJCOMPFLAGS += -Woverloaded-virtual -Wpacked -Wpointer-arith -Wredundant-decls -Wrestrict -Wsign-promo 
# OBJCOMPFLAGS += -Wstack-usage=8192 -Wstrict-null-sentinel -Wstrict-overflow=2 -Wstringop-overflow=4 
# OBJCOMPFLAGS += -Wsuggest-attribute=noreturn -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum 
# OBJCOMPFLAGS += -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wvariadic-macros -Wno-literal-suffix 
# OBJCOMPFLAGS += -Wno-missing-field-initializers -Wnarrowing -Wno-old-style-cast -Wvarargs -Waligned-new 
# OBJCOMPFLAGS += -Walloc-size-larger-than=1073741824 -Walloc-zero -Walloca -Walloca-larger-than=8192 -Wcast-align=strict 
# OBJCOMPFLAGS += -Wdangling-else -Wduplicated-branches -Wformat-overflow=2 -Wformat-truncation=2 -Wmissing-attributes 
# OBJCOMPFLAGS += -Wmultistatement-macros -Wrestrict -Wsuggest-attribute=malloc -fcheck-new 
# OBJCOMPFLAGS += -fsized-deallocation -fstrict-overflow
# OBJCOMPFLAGS += -flto-odr-type-merging -fno-omit-frame-pointer

COMPFLAGS = -std=c++17 -g -I $(INCDIR) #-Wall -Wextra -Weffc++ -Wc++0x-compat -Wc++11-compat -Wc++14-compat 
# COMPFLAGS += -Waggressive-loop-optimizations -Walloc-zero -Walloca -Walloca-larger-than=8192 -Warray-bounds 
# COMPFLAGS += -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy 
# COMPFLAGS += -Wdangling-else -Wduplicated-branches -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security 
# COMPFLAGS += -Wformat-signedness -Wformat=2 -Wformat-overflow=2 -Wformat-truncation=2 -Winline -Wlarger-than=8192 
# COMPFLAGS += -Wvla-larger-than=8192 -Wlogical-op -Wmissing-declarations -Wnon-virtual-dtor -Wopenmp-simd 
# COMPFLAGS += -Woverloaded-virtual -Wpacked -Wpointer-arith -Wredundant-decls -Wrestrict -Wsign-promo 
# COMPFLAGS += -Wstack-usage=8192 -Wstrict-null-sentinel -Wstrict-overflow=2 -Wstringop-overflow=4 
# COMPFLAGS += -Wsuggest-attribute=noreturn -Wsuggest-final-types -Wsuggest-override -Wswitch-default -Wswitch-enum 
# COMPFLAGS += -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wvariadic-macros -Wno-literal-suffix 
# COMPFLAGS += -Wno-missing-field-initializers -Wnarrowing -Wno-old-style-cast -Wvarargs -Waligned-new 
# COMPFLAGS += -Walloc-size-larger-than=1073741824 -Walloc-zero -Walloca -Walloca-larger-than=8192 -Wcast-align=strict 
# COMPFLAGS += -Wdangling-else -Wduplicated-branches -Wformat-overflow=2 -Wformat-truncation=2 -Wmissing-attributes 
# COMPFLAGS += -Wmultistatement-macros -Wrestrict -Wsuggest-attribute=malloc -fcheck-new 
# COMPFLAGS += -fsized-deallocation -fstrict-overflow 
# COMPFLAGS += -flto-odr-type-merging -fno-omit-frame-pointer

#task for default cache. *.inl files don't need to be compiled to objects btw.


Driver: program.out

program.out: $(OBJECTS)
	$(CC) $(COMPFLAGS) $^ -o $@

$(OBJDIR)/TriangleIntersaction.o: TriangleIntersaction.cpp
	$(CC) $(OBJCOMPFLAGS) $^ -o $@

PHONY.:clean testCache memcheck

clean:
	rm -f $(OBJDIR)/*.o
	rm -f $(TESTSDIR)/randTests/*.txt
	rm -f *.out
	rm -f *.o
	clear

testCache: 
	python3 ./$(TESTSDIR)/generateTests.py

memcheck:
	valgrind --leak-check=full \
    --show-leak-kinds=all \
    --track-origins=yes \
    --verbose \
    --log-file=valgrind-out.txt \
    ./a.out