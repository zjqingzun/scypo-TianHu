#### CONFIGURATION ####
CXX = g++
CC = gcc

# Phát hiện hệ điều hành
ifdef ComSpec
    OS = Windows
    SHELL = cmd.exe
    COPY = copy
    RM = del /f /q
    MKDIR = mkdir
    PATHSEP = \\
    BIN = TianHu.exe
    DLL_EXT = dll
    DLL_LIB_EXT = dll.lib
else ifeq ($(MSYSTEM),MINGW32)
    OS = Windows
    SHELL = cmd.exe
    COPY = copy
    RM = del /f /q
    MKDIR = mkdir
    PATHSEP = \\
    BIN = TianHu.exe
    DLL_EXT = dll
    DLL_LIB_EXT = dll.lib
else ifeq ($(MSYSTEM),MINGW64)
    OS = Windows
    SHELL = cmd.exe
    COPY = copy
    RM = del /f /q
    MKDIR = mkdir
    PATHSEP = \\
    BIN = TianHu.exe
    DLL_EXT = dll
    DLL_LIB_EXT = dll.lib
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        OS = Linux
        COPY = cp
        RM = rm -f
        MKDIR = mkdir -p
        PATHSEP = /
        BIN = TianHu
        DLL_EXT = so
        DLL_LIB_EXT = so
    else ifeq ($(UNAME_S),Darwin)
        OS = macOS
        COPY = cp
        RM = rm -f
        MKDIR = mkdir -p
        PATHSEP = /
        BIN = TianHu
        DLL_EXT = dylib
        DLL_LIB_EXT = dylib
    else
        $(error Hệ điều hành không được hỗ trợ: $(UNAME_S))
    endif
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
# Đường dẫn đến các thư viện động và import library
DRUSTLCIPH = $(DCIPH)/ciph.$(DLL_LIB_EXT)
DRUSTDCIPH = $(DCIPH)/ciph.$(DLL_EXT)

DRUSTLSECRUST = $(DRUSTSECRUST)/secrust.$(DLL_LIB_EXT)
DRUSTDSECRUST = $(DRUSTSECRUST)/secrust.$(DLL_EXT)

#### OBJECT FILES ####
# Quy tắc tạo thư mục
dirs:
ifeq ($(OS),Windows)
	-@if not exist "$(subst /,\,$(DOBJ))" $(MKDIR) "$(subst /,\,$(DOBJ))" && echo Created directory $(DOBJ)
	-@if not exist "$(subst /,\,$(DLOG))" $(MKDIR) "$(subst /,\,$(DLOG))" && echo Created directory $(DLOG)
else
	-@$(MKDIR) $(DOBJ) && echo Created directory $(DOBJ)
	-@$(MKDIR) $(DLOG) && echo Created directory $(DLOG)
endif

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
# Default target: Build the project in debug mode
all: debug

# Check versions of build tools
check-tools:
	@echo Checking versions of build tools...
	@gcc --version | head -n 1
	@g++ --version | head -n 1
	@cargo --version
	@echo Build tools check completed.

# Debug build: Compile with debug flags and copy required DLLs
debug: CPPFLAGS += $(DEBUGFLAGS)
debug: dirs check-tools $(DRUSTLCIPH) $(DRUSTLSECRUST) $(BIN) copy-dlls

# Release build: Compile with optimization flags and copy required DLLs
release: CPPFLAGS += $(RELEASEFLAGS)
release: dirs check-tools $(DRUSTLCIPH) $(DRUSTLSECRUST) $(BIN) copy-dlls

# Quy tắc để biên dịch Rust Crate ciph
$(DRUSTLCIPH):
	@if not exist "$(subst /,\,$(DRUSTLCIPH))" (cd config/ciph && cargo build --release) else (echo $(DRUSTLCIPH) already exists, skipping build)

# Quy tắc để biên dịch Rust Crate secrust
$(DRUSTLSECRUST):
	@if not exist "$(subst /,\,$(DRUSTLSECRUST))" (cd plugins/rust/secrust && cargo build --release) else (echo $(DRUSTLSECRUST) already exists, skipping build)

# Link object files to create the executable
$(BIN): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $(BIN) $(DRUSTLCIPH) $(DRUSTLSECRUST) -L$(DCIPH) -L$(DRUSTSECRUST)
	@echo Linking completed: $(BIN) created successfully

# Quy tắc sao chép các tệp thư viện động vào thư mục thực thi
copy-dlls: $(DRUSTDCIPH) $(DRUSTDSECRUST)
ifeq ($(OS),Windows)
	-@if exist "$(subst /,\,$(DRUSTDCIPH))" $(COPY) "$(subst /,\,$(DRUSTDCIPH))" . && echo Copied $(DRUSTDCIPH) to current directory
	-@if exist "$(subst /,\,$(DRUSTDSECRUST))" $(COPY) "$(subst /,\,$(DRUSTDSECRUST))" . && echo Copied $(DRUSTDSECRUST) to current directory
else
	-@if [ -f "$(DRUSTDCIPH)" ]; then $(COPY) "$(DRUSTDCIPH)" . && echo Copied $(DRUSTDCIPH) to current directory; fi
	-@if [ -f "$(DRUSTDSECRUST)" ]; then $(COPY) "$(DRUSTDSECRUST)" . && echo Copied $(DRUSTDSECRUST) to current directory; fi
endif

# Compilation rules for C files
$(DOBJ)/%.o: $(DAC)/%.c
	$(CC) $(CPPFLAGS) -I$(DINCLUDE) -I$(DINCLUDERUST) -MMD -MP -c $< -o $@
	@echo Compiled $< to $@

# Compilation rules for C++ files
$(DOBJ)/%.o: $(DAP)/%.cpp
	$(CXX) $(CPPFLAGS) -I$(DINCLUDE) -I$(DINCLUDERUST) -MMD -MP -c $< -o $@
	@echo Compiled $< to $@

$(DOBJ)/%.o: $(DAU)/%.cpp
	$(CXX) $(CPPFLAGS) -I$(DINCLUDE) -I$(DINCLUDERUST) -MMD -MP -c $< -o $@
	@echo Compiled $< to $@

# Include dependency files
-include $(DEPS)

# Quy tắc kiểm tra trước khi chạy
check-before-run: $(BIN)
	@echo Checking for required files...
ifeq ($(OS),Windows)
	-@if not exist "$(BIN)" echo Error: $(BIN) not found && exit /b 1
	-@if not exist "$(subst /,\,$(DRUSTDCIPH))" echo Error: $(DRUSTDCIPH) not found && exit /b 1
	-@if not exist "$(subst /,\,$(DRUSTDSECRUST))" echo Error: $(DRUSTDSECRUST) not found && exit /b 1
else
	-@if [ ! -f "$(BIN)" ]; then echo Error: $(BIN) not found; exit 1; fi
	-@if [ ! -f "$(DRUSTDCIPH)" ]; then echo Error: $(DRUSTDCIPH) not found; exit 1; fi
	-@if [ ! -f "$(DRUSTDSECRUST)" ]; then echo Error: $(DRUSTDSECRUST) not found; exit 1; fi
endif
	@echo All required files are present.

# Run the executable after checking required files
run: check-before-run
	./$(BIN)

# Clean up all generated files
clean:
ifeq ($(OS),Windows)
	-@$(RM) $(subst /,\,$(BIN)) 2>NUL
	-@$(RM) $(subst /,\,$(DOBJ)/*.o) 2>NUL
	-@$(RM) $(subst /,\,$(DOBJ)/*.d) 2>NUL
	-@$(RM) ciph.$(DLL_EXT) 2>NUL
	-@$(RM) secrust.$(DLL_EXT) 2>NUL
else
	-@$(RM) $(BIN) $(DOBJ)/*.o $(DOBJ)/*.d ciph.$(DLL_EXT) secrust.$(DLL_EXT)
endif
	-@cd config/ciph && cargo clean
	-@cd plugins/rust/secrust && cargo clean

# Debug with gdb
debug-gdb: $(BIN)
	gdb -q ./$(BIN)

# Declare phony targets
.PHONY: all debug release run clean debug-gdb print-objs copy-dlls dirs check-before-run check-tools