#### CONFIG ####
CPP = g++
OBC = gcc





#### FLAGS ####
CPPFLAGS = -Wall -Wextra
OBCFLAGS = -Wall -Wextra

DEBUGFLAGS = -g -DDEBUG




#### DIRECTORIES ####
SRC_DIR_CPP = app
SRC_DIR_OBC = app

BUILD_DIR_CPP = app
BUILD_DIR_OBC = app

BIN = TianHu.exe




#### RUN CODE ####
all: $(BIN)

$(BIN): $(BUILD_DIR_OBC)/cchar.o $(BUILD_DIR_OBC)/cfile.o $(BUILD_DIR_OBC)/cerr.o  $(BUILD_DIR_CPP)/cpcpr.o $(BUILD_DIR_CPP)/main.o $(BUILD_DIR_OBC)/cnavg.o $(BUILD_DIR_CPP)/cpctlr.o
	$(CPP) $(DEBUGFLAGS) $^ -o $@



$(BUILD_DIR_OBC)/cchar.o: $(SRC_DIR_OBC)/cchar.c $(SRC_DIR_OBC)/cchar.h
	if not exist "$(BUILD_DIR_OBC)" mkdir "$(BUILD_DIR_OBC)"
	$(OBC) $(OBCFLAGS) -c $< -o $@

$(BUILD_DIR_OBC)/cfile.o: $(SRC_DIR_OBC)/cfile.c $(SRC_DIR_OBC)/cfile.h
	if not exist "$(BUILD_DIR_OBC)" mkdir "$(BUILD_DIR_OBC)"
	$(OBC) $(OBCFLAGS) -c $< -o $@

$(BUILD_DIR_OBC)/cerr.o: $(SRC_DIR_OBC)/cerr.c $(SRC_DIR_OBC)/cerr.h
	if not exist "$(BUILD_DIR_OBC)" mkdir "$(BUILD_DIR_OBC)"
	$(OBC) $(OBCFLAGS) -c $< -o $@

$(BUILD_DIR_CPP)/cpcpr.o: $(SRC_DIR_CPP)/cpcpr.cpp $(SRC_DIR_CPP)/cpcpr.h
	if not exist "$(BUILD_DIR_CPP)" mkdir "$(BUILD_DIR_CPP)"
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR_CPP)/main.o: $(SRC_DIR_CPP)/main.cpp $(SRC_DIR_CPP)/main.h
	if not exist "$(BUILD_DIR_CPP)" mkdir "$(BUILD_DIR_CPP)"
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR_OBC)/cnavg.o: $(SRC_DIR_OBC)/cnavg.c $(SRC_DIR_OBC)/cnavg.h
	if not exist "$(BUILD_DIR_OBC)" mkdir "$(BUILD_DIR_OBC)"
	$(OBC) $(OBCFLAGS) -c $< -o $@

$(BUILD_DIR_CPP)/cpctlr.o: $(SRC_DIR_CPP)/cpctlr.cpp $(SRC_DIR_CPP)/cpctlr.h
	if not exist "$(BUILD_DIR_CPP)" mkdir "$(BUILD_DIR_CPP)"
	$(CPP) $(CPPFLAGS) -c $< -o $@


clean:
	@if exist "$(BUILD_DIR_OBC)\cchar.o" del /f "$(BUILD_DIR_OBC)\cchar.o"
	@if exist "$(BUILD_DIR_OBC)\cfile.o" del /f "$(BUILD_DIR_OBC)\cfile.o"
	@if exist "$(BUILD_DIR_OBC)\cerr.o" del /f "$(BUILD_DIR_OBC)\cerr.o"
	@if exist "$(BUILD_DIR_CPP)\cpcpr.o" del /f "$(BUILD_DIR_CPP)\cpcpr.o"
	@if exist "$(BUILD_DIR_CPP)\main.o" del /f "$(BUILD_DIR_CPP)\main.o"
	@if exist "$(BUILD_DIR_OBC)\cnavg.o" del /f "$(BUILD_DIR_OBC)\cnavg.o"
	@if exist "$(BUILD_DIR_CPP)\cpctlr.o" del /f "$(BUILD_DIR_CPP)\cpctlr.o"
	@if exist "$(BIN)" del /f "$(BIN)"


run: $(BIN)
	./$(BIN)


debug: $(BIN)
	gdb -q ./$(BIN)
