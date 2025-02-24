#### CONFIG ####
CPP = g++

CPPFLAGS = -Wall -Wextra
DEBUGFLAGS = -g -DDEBUG

SRC_DIR_CPP = cent/cplus
BUILD_DIR_CPP = cent/cplus
BIN = TianHu.exe

#### RUN CODE ####
all: $(BIN)

$(BIN): $(BUILD_DIR_CPP)/cpright.o $(BUILD_DIR_CPP)/main.o
	$(CPP) $(DEBUGFLAGS) $^ -o $@


$(BUILD_DIR_CPP)/cpright.o: $(SRC_DIR_CPP)/cpright.cpp $(SRC_DIR_CPP)/cpright.h
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(BUILD_DIR_CPP)/main.o: $(SRC_DIR_CPP)/main.cpp $(SRC_DIR_CPP)/main.h
	if not exist "$(BUILD_DIR_CPP)" mkdir "$(BUILD_DIR_CPP)"
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@if exist "$(BUILD_DIR_CPP)\cpright.o" del /f "$(BUILD_DIR_CPP)\cpright.o"
	@if exist "$(BUILD_DIR_CPP)\main.o" del /f "$(BUILD_DIR_CPP)\main.o"
	@if exist "$(BIN)" del /f "$(BIN)"


run: $(BIN)
	./$(BIN)

debug: $(BIN)
	gdb -q ./$(BIN)
