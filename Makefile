#### CONFIGURATION ####
CXX = g++
CC = gcc

BIN = TianHu.exe

# Xác định lệnh sao chép tùy thuộc vào hệ điều hành
ifdef ComSpec
    COPY = copy
else
    COPY = cp
endif

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

DLOG  = config/logs
DCIPH = config/ciph/target/release

DINCLUDE = include
DINCLUDERUST = include/cxx-secrust

DOBJ = obj

DRUST = plugins/rust
DRUSTSECRUST = $(DRUST)/secrust/target/release

DSCRIPT = scripts
DTEST = tests

#### DYNAMIC LIBRARY DIRECTORY ####
DRUSTLCIPH = $(DCIPH)/ciph.dll.lib
DRUSTDCIPH = $(DCIPH)/ciph.dll

DRUSTLSECRUST = $(DRUSTSECRUST)/secrust.dll.lib
DRUSTDSECRUST = $(DRUSTSECRUST)/secrust.dll

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
	$(DOBJ)/ctl.o \
	$(DOBJ)/cli.o \
	$(DOBJ)/cpright.o

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
debug: $(DRUSTLCIPH) $(DRUSTLSECRUST) $(BIN) copy-dlls

# Release build
release: CPPFLAGS += $(RELEASEFLAGS)
release: $(DRUSTLCIPH) $(DRUSTLSECRUST) $(BIN) copy-dlls

# Quy tắc để biên dịch Rust Crate ciph
$(DRUSTLCIPH):
	cd config/ciph && cargo build --release

# Quy tắc để biên dịch Rust Crate secrust
$(DRUSTLSECRUST):
	cd plugins/rust/secrust && cargo build --release

# Link object files to create the executable
$(BIN): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(BIN) $(DRUSTLCIPH) $(DRUSTLSECRUST) -L$(DCIPH) -L$(DRUSTSECRUST)

# Quy tắc sao chép các tệp .dll vào thư mục thực thi
copy-dlls: $(DRUSTDCIPH) $(DRUSTDSECRUST)
	@$(COPY) "$(DRUSTDCIPH)" .
	@$(COPY) "$(DRUSTDSECRUST)" .

# Compilation rules for C++ files
$(DOBJ)/char.o: $(DAC)/char.c
	$(CC) $(CPPFLAGS) -I$(DINCLUDE) -I$(DINCLUDERUST) -MMD -MP -c $< -o $@
$(DOBJ)/err.o: $(DAC)/err.c
	$(CC) $(CPPFLAGS) -I$(DINCLUDE) -I$(DINCLUDERUST) -MMD -MP -c $< -o $@
$(DOBJ)/file.o: $(DAC)/file.c
	$(CC) $(CPPFLAGS) -I$(DINCLUDE) -I$(DINCLUDERUST) -MMD -MP -c $< -o $@
$(DOBJ)/gui.o: $(DAC)/gui.c
	$(CC) $(CPPFLAGS) -I$(DINCLUDE) -I$(DINCLUDERUST) -MMD -MP -c $< -o $@
$(DOBJ)/str.o: $(DAC)/str.c
	$(CC) $(CPPFLAGS) -I$(DINCLUDE) -I$(DINCLUDERUST) -MMD -MP -c $< -o $@

$(DOBJ)/main.o: $(DAP)/main.cpp
	$(CXX) $(CPPFLAGS) -I$(DINCLUDE) -I$(DINCLUDERUST) -MMD -MP -c $< -o $@
$(DOBJ)/ctl.o: $(DAP)/ctl.cpp
	$(CXX) $(CPPFLAGS) -I$(DINCLUDE) -I$(DINCLUDERUST) -MMD -MP -c $< -o $@
$(DOBJ)/cli.o: $(DAP)/cli.cpp
	$(CXX) $(CPPFLAGS) -I$(DINCLUDE) -I$(DINCLUDERUST) -MMD -MP -c $< -o $@

$(DOBJ)/cpright.o: $(DAU)/cpright.cpp
	$(CXX) $(CPPFLAGS) -I$(DINCLUDE) -I$(DINCLUDERUST) -MMD -MP -c $< -o $@

# Include dependency files
-include $(DEPS)

# Run the executable
run: $(BIN)
	./$(BIN)

# Clean up generated files
clean:
	-@rm -f $(BIN) $(DOBJ)/*.o $(DOBJ)/*.d ciph.dll secrust.dll 2>/dev/null || del /f /q $(BIN) $(DOBJ)\*.o $(DOBJ)\*.d ciph.dll secrust.dll 2>NUL
	-@cd config/ciph && cargo clean
	-@cd plugins/rust/secrust && cargo clean

# Debug with gdb
debug-gdb: $(BIN)
	gdb -q ./$(BIN)

# Declare phony targets
.PHONY: all debug release run clean debug-gdb print-objs copy-dlls