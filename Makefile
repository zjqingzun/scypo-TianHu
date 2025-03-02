#### CONFIG ####
CPP = g++
OBC = gcc




#### FLAGS ####
#CPPFLAGS = -Wall -Wextra
CPPFLAGS = -Wall -Wextra -IC:\Users\IS14p\AppData\Roaming\Python\Python313\site-packages\pybind11\include -IC:\Python313\Include
OBCFLAGS = -Wall -Wextra

DEBUGFLAGS = -g -DDEBUG

PYTHON_LDFLAGS = -LC:/Python313/libs -lpython313




#### DIRECTORIES ####
APPDIR_CPP = app
APPDIR_OBC = app
BUILDAPPDIR_CPP = app
BUILDAPPDIR_OBC = app

MODEDIR_CPP := mode 
BUILDMODEDIR_CPP := mode

MDLSDIR_CPP = mode/mdls
BUILDMDLSDIR_CPP = mode/mdls

BIN = TianHu.exe




#### RUN CODE ####
all: $(BIN)

MDLS := \
	$(MDLSDIR_CPP)/help/help.o


OBJS := \
    $(BUILDAPPDIR_OBC)/cchar.o \
    $(BUILDAPPDIR_OBC)/cfile.o \
    $(BUILDAPPDIR_OBC)/cerr.o  \
    $(BUILDAPPDIR_CPP)/cpcpr.o \
    $(BUILDAPPDIR_CPP)/main.o \
    $(BUILDAPPDIR_OBC)/cnavg.o \
    $(BUILDAPPDIR_CPP)/cpctlr.o \
    $(BUILDMODEDIR_CPP)/taskconvert.o \
	$(MDLS)


$(BIN): $(OBJS)
	$(CPP) $(DEBUGFLAGS) $(OBJS) -o $@ $(PYTHON_LDFLAGS)



# APP
$(BUILDAPPDIR_OBC)/cchar.o: $(APPDIR_OBC)/cchar.c $(APPDIR_OBC)/cchar.h
	if not exist "$(BUILDAPPDIR_OBC)" mkdir "$(BUILDAPPDIR_OBC)"
	$(OBC) $(OBCFLAGS) -c $< -o $@

$(BUILDAPPDIR_OBC)/cfile.o: $(APPDIR_OBC)/cfile.c $(APPDIR_OBC)/cfile.h
	if not exist "$(BUILDAPPDIR_OBC)" mkdir "$(BUILDAPPDIR_OBC)"
	$(OBC) $(OBCFLAGS) -c $< -o $@

$(BUILDAPPDIR_OBC)/cerr.o: $(APPDIR_OBC)/cerr.c $(APPDIR_OBC)/cerr.h
	if not exist "$(BUILDAPPDIR_OBC)" mkdir "$(BUILDAPPDIR_OBC)"
	$(OBC) $(OBCFLAGS) -c $< -o $@

$(BUILDAPPDIR_CPP)/cpcpr.o: $(APPDIR_CPP)/cpcpr.cpp $(APPDIR_CPP)/cpcpr.h
	if not exist "$(BUILDAPPDIR_CPP)" mkdir "$(BUILDAPPDIR_CPP)"
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(BUILDAPPDIR_CPP)/main.o: $(APPDIR_CPP)/main.cpp $(APPDIR_CPP)/main.h
	if not exist "$(BUILDAPPDIR_CPP)" mkdir "$(BUILDAPPDIR_CPP)"
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(BUILDAPPDIR_OBC)/cnavg.o: $(APPDIR_OBC)/cnavg.c $(APPDIR_OBC)/cnavg.h
	if not exist "$(BUILDAPPDIR_OBC)" mkdir "$(BUILDAPPDIR_OBC)"
	$(OBC) $(OBCFLAGS) -c $< -o $@

$(BUILDAPPDIR_CPP)/cpctlr.o: $(APPDIR_CPP)/cpctlr.cpp $(APPDIR_CPP)/cpctlr.h
	if not exist "$(BUILDAPPDIR_CPP)" mkdir "$(BUILDAPPDIR_CPP)"
	$(CPP) $(CPPFLAGS) -c $< -o $@


# MODE
$(BUILDMODEDIR_CPP)/taskconvert.o: mode/taskconvert.cpp mode/taskconvert.h
	if not exist "$(BUILDMODEDIR_CPP)" mkdir "$(BUILDMODEDIR_CPP)"
	$(CPP) $(CPPFLAGS) -c $< -o $@


# MODE - MODULES
$(BUILDMDLSDIR_CPP)/help/help.o: $(MDLSDIR_CPP)/help/help.cpp $(MDLSDIR_CPP)/help/help.h
	if not exist "$(BUILDMDLSDIR_CPP)/help" mkdir "$(BUILDMDLSDIR_CPP)/help"
	$(CPP) $(CPPFLAGS) -c $< -o $@


clean:
	@if exist "$(BUILDAPPDIR_OBC)\cchar.o" del /f "$(BUILDAPPDIR_OBC)\cchar.o"
	@if exist "$(BUILDAPPDIR_OBC)\cfile.o" del /f "$(BUILDAPPDIR_OBC)\cfile.o"
	@if exist "$(BUILDAPPDIR_OBC)\cerr.o" del /f "$(BUILDAPPDIR_OBC)\cerr.o"
	@if exist "$(BUILDAPPDIR_CPP)\cpcpr.o" del /f "$(BUILDAPPDIR_CPP)\cpcpr.o"
	@if exist "$(BUILDAPPDIR_CPP)\main.o" del /f "$(BUILDAPPDIR_CPP)\main.o"
	@if exist "$(BUILDAPPDIR_OBC)\cnavg.o" del /f "$(BUILDAPPDIR_OBC)\cnavg.o"
	@if exist "$(BUILDAPPDIR_CPP)\cpctlr.o" del /f "$(BUILDAPPDIR_CPP)\cpctlr.o"
	
	@if exist "$(BUILDMODEDIR_CPP)\taskconvert.o" del /f "$(BUILDMODEDIR_CPP)\taskconvert.o"

	@if exist "$(BUILDMDLSDIR_CPP)\help\help.o" del /f "$(BUILDMDLSDIR_CPP)\help\help.o"

	@if exist "$(BIN)" del /f "$(BIN)"
	@if exist mode\services\task\py\__pycache__ rmdir /s /q mode\services\task\py\__pycache__


run: $(BIN)
	./$(BIN)


debug: $(BIN)
	gdb -q ./$(BIN)
