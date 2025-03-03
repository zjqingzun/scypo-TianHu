#### CONFIG ####
CPPCONFIG = g++
CXXCONFIG = gcc

BIN = TianHu.exe




#### FLAGS ####
CPPFLAGS = -Wall -Wextra
CXXFLAGS = -Wall -Wextra
DEBUGFLAGS = -g -DDEBUG




#### DIRECTORIES ####
APP = app
AC = app/core
AU = app/user
AP = app/proc


# SRCS - OBJS
SRCS = $(wildcard $(AP)/*.cpp $(AC)/*.cpp $(AU)/*.cpp)
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
	@if exist "$(AC)\*.o" cmd /c del /f "$(AC)\*.o"
	@if exist "$(AP)\*.o" cmd /c del /f "$(AP)\*.o"
	@if exist "$(AU)\*.o" cmd /c del /f "$(AU)\*.o"


debug: $(BIN)
	gdb -q ./$(BIN)

