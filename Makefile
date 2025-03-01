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

$(BIN): $(BUILD_DIR_OBC)/cerror.o $(BUILD_DIR_CPP)/cpright.o $(BUILD_DIR_CPP)/main.o $(BUILD_DIR_OBC)/cnavigation.o
	$(CPP) $(DEBUGFLAGS) $^ -o $@


$(BUILD_DIR_OBC)/cerror.o: $(SRC_DIR_OBC)/cerror.c $(SRC_DIR_OBC)/cerror.h
	if not exist "$(BUILD_DIR_OBC)" mkdir "$(BUILD_DIR_OBC)"
	$(OBC) $(OBCFLAGS) -c $< -o $@

$(BUILD_DIR_CPP)/cpright.o: $(SRC_DIR_CPP)/cpright.cpp $(SRC_DIR_CPP)/cpright.h
	if not exist "$(BUILD_DIR_CPP)" mkdir "$(BUILD_DIR_CPP)"
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR_CPP)/main.o: $(SRC_DIR_CPP)/main.cpp $(SRC_DIR_CPP)/main.h
	if not exist "$(BUILD_DIR_CPP)" mkdir "$(BUILD_DIR_CPP)"
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR_OBC)/cnavigation.o: $(SRC_DIR_OBC)/cnavigation.c $(SRC_DIR_OBC)/cnavigation.h
	if not exist "$(BUILD_DIR_OBC)" mkdir "$(BUILD_DIR_OBC)"
	$(OBC) $(OBCFLAGS) -c $< -o $@


clean:
	@if exist "$(BUILD_DIR_OBC)\cerror.o" del /f "$(BUILD_DIR_OBC)\cerror.o"
	@if exist "$(BUILD_DIR_CPP)\cpright.o" del /f "$(BUILD_DIR_CPP)\cpright.o"
	@if exist "$(BUILD_DIR_CPP)\main.o" del /f "$(BUILD_DIR_CPP)\main.o"
	@if exist "$(BUILD_DIR_OBC)\cnavigation.o" del /f "$(BUILD_DIR_OBC)\cnavigation.o"
	@if exist "$(BIN)" del /f "$(BIN)"


run: $(BIN)
	./$(BIN)


debug: $(BIN)
	gdb -q ./$(BIN)
