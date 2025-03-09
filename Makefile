#### CONFIG ####
CPPCONFIG = g++
CXXCONFIG = gcc

BIN = TianHu.exe




#### FLAGS ####
CPPFLAGS = -Wall -Wextra
CXXFLAGS = -Wall -Wextra
DEBUGFLAGS = -g -DDEBUG




#### DIRECTORIES ####
DAPP = app
DAC = app/core
DAU = app/user
DAP = app/proc

DBIN = bin

DLOG = config/logs

DSCRIPT = scripts

DTEST = tests




# PROGS - SRCS - OBJS
SRCS = $(wildcard $(DAP)/*.cpp $(DAC)/*.cpp $(DAU)/*.cpp)
OBJS = $(SRCS:.cpp=.o)




#### MAKE RULES ####
all: $(BIN)

$(BIN): $(OBJS)
	$(CPPCONFIG) $(DEBUGFLAGS) $(OBJS) -o $@

%.o: %.cpp
	$(CPPCONFIG) $(DEBUGFLAGS) -c $< -o $@

%.o: %.c
	$(CXXCONFIG) $(DEBUGFLAGS) -c $< -o $@


run: $(BIN)
	./$(BIN)


clean:
	@if exist "$(BIN)" cmd /c del /f "$(BIN)"
	@if exist "$(DAC)\*.o" cmd /c del /f "$(DAC)\*.o"
	@if exist "$(DAP)\*.o" cmd /c del /f "$(DAP)\*.o"
	@if exist "$(DAU)\*.o" cmd /c del /f "$(DAU)\*.o"


debug: $(BIN)
	gdb -q ./$(BIN)

