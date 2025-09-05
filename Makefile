CC = g++
CFLAGS = -std=c++17 -Iinclude -Ithird-party/headers -Iinclude/Built-In/Components
LDFLAGS_COMMON = -Llib -Lthird-party/lib/raylib -lraylib

PROJECT_NAME = kruger_engine
PLATFORM ?= windows
HIDE_CONSOLE ?= 1
BUILD_DIR = build

ifeq ($(PLATFORM),windows)
    LDFLAGS = $(LDFLAGS_COMMON) -lopengl32 -lgdi32 -lwinmm -luser32 -lkernel32
    ifeq ($(HIDE_CONSOLE),1)
        LDFLAGS += -mwindows
    endif
    SHELL = cmd
    RM = del /Q /F
    EXEC_EXT = .exe
else
    LDFLAGS = $(LDFLAGS_COMMON) -lopengl -lm -lpthread -ldl -lrt -lX11
    SHELL = /bin/bash
    RM = rm -f
    EXEC_EXT =
endif

SRC = main.cpp $(wildcard src/*.cpp src/Built-In/Components/*.cpp)
OBJ = $(SRC:.cpp=.o)
EXEC = $(PROJECT_NAME)

all: $(BUILD_DIR)/$(EXEC)$(EXEC_EXT)

$(BUILD_DIR)/$(EXEC)$(EXEC_EXT): $(OBJ) | $(BUILD_DIR)
	$(CC) -o $@ $^ $(LDFLAGS)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clear all the .o files
o-cls:
	$(RM) *.o
	for /r src %%f in (*.o) do $(RM) "%%f"

# Clear all the .o files + the executable
cls:
	$(RM) *.o
	for /r src %%f in (*.o) do $(RM) "%%f"
	$(RM) .\\$(BUILD_DIR)\\$(EXEC)$(EXEC_EXT)