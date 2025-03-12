#### CONFIGURATION ####
CXX = g++
CC = gcc

BIN = TianHu.exe




#### COMPILATION FLAGS ####
CPPFLAGS = -Wall -Wextra
CXXFLAGS = -Wall -Wextra
DEBUGFLAGS = -g -DDEBUG
RELEASEFLAGS = -O2




#### DIRECTORIES ####
DAPP = app
DAC = app/core
DAU = app/user
DAP = app/proc

DOBJ = obj

DLOG = config/logs
DSCRIPT = scripts
DTEST = tests




#### OBJECT FILES ####
# Ensure the directories exist
$(shell mkdir -p $(DOBJ) $(DLOG))

# List object files manually, one per line, in the $(DOBJ) directory
OBJS = \
	$(DOBJ)/char.o \
	$(DOBJ)/err.o \
	$(DOBJ)/file.o \
	$(DOBJ)/gui.o \
	$(DOBJ)/str.o \
	$(DOBJ)/main.o \
	$(DOBJ)/cli.o \
	$(DOBJ)/cpright.o \
	$(DOBJ)/ctl.o

# Print object files for debugging
print-objs:
	@echo $(OBJS)




#### DEPENDENCIES ####
DEPS = $(OBJS:.o=.d)




#### MAKE RULES ####
# Default target is debug build
all: debug


# Debug build
debug: CPPFLAGS += $(DEBUGFLAGS)
debug: $(BIN)


# Release build
release: CPPFLAGS += $(RELEASEFLAGS)
release: $(BIN)


# Link object files to create the executable
$(BIN): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(BIN)

# Compilation rules for C++ files
$(DOBJ)/char.o: $(DAC)/char.c
	$(CC) $(CPPFLAGS) -MMD -MP -c $< -o $@
$(DOBJ)/err.o: $(DAC)/err.c
	$(CC) $(CPPFLAGS) -MMD -MP -c $< -o $@
$(DOBJ)/file.o: $(DAC)/file.c
	$(CC) $(CPPFLAGS) -MMD -MP -c $< -o $@
$(DOBJ)/gui.o: $(DAC)/gui.c
	$(CC) $(CPPFLAGS) -MMD -MP -c $< -o $@
$(DOBJ)/str.o: $(DAC)/str.c
	$(CC) $(CPPFLAGS) -MMD -MP -c $< -o $@

$(DOBJ)/main.o: $(DAP)/main.cpp
	$(CXX) $(CPPFLAGS) -MMD -MP -c $< -o $@
$(DOBJ)/cli.o: $(DAP)/cli.cpp
	$(CXX) $(CPPFLAGS) -MMD -MP -c $< -o $@
$(DOBJ)/ctl.o: $(DAP)/ctl.cpp
	$(CXX) $(CPPFLAGS) -MMD -MP -c $< -o $@

$(DOBJ)/cpright.o: $(DAU)/cpright.cpp
	$(CXX) $(CPPFLAGS) -MMD -MP -c $< -o $@


# Include dependency files
-include $(DEPS)


# Run the executable
run: $(BIN)
	./$(BIN)


# Clean up generated files
clean:
	-@rm -f $(BIN) $(DOBJ)/*.o $(DOBJ)/*.d 2>/dev/null || del /f /q $(BIN) $(DOBJ)\*.o $(DOBJ)\*.d 2>NUL


# Debug with gdb
debug-gdb: $(BIN)
	gdb -q ./$(BIN)


# Declare phony targets
.PHONY: all debug release run clean debug-gdb print-objs