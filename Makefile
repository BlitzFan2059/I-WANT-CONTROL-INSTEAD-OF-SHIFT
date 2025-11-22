# Number of cores for parallel builds
MAKEFLAGS += -j$(shell nproc)

# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra \
    -I./include \
    -I./src/headers \
    -I./include/imgui \
    -I./include/rlImGui

# Linker flags
LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Target binary
TARGET = build/utility

# Object directories
OBJ_DIR = out/linux

# Source files
SRCS = $(shell find src -name "*.cpp") \
       include/imgui/imgui.cpp \
       include/imgui/imgui_draw.cpp \
       include/imgui/imgui_tables.cpp \
       include/imgui/imgui_widgets.cpp \
       include/rlImGui/rlImGui.cpp

# Object files
OBJS = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Default Linux build
all: $(TARGET)

$(TARGET): $(OBJS)
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS) -static-libgcc -static-libstdc++

# Compile object files (incremental)
$(OBJ_DIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Windows build
windows:
	$(MAKE) CXX=x86_64-w64-mingw32-g++ \
	        OBJ_DIR=out/win64 \
	        CXXFLAGS="-std=c++17 -Wall -Wextra -I./include -I./src/headers -I./include/imgui -I./include/rlImGui -I./include/raylibWin64/include" \
	        LDFLAGS="-L./include/raylibWin64/lib -static -lraylib -lopengl32 -lgdi32 -lwinmm -static-libgcc -static-libstdc++ -Wl,-Bstatic -lstdc++ -mwindows -lpthread -Wl,-Bdynamic" \
	        TARGET=build/utility.exe

# Clean build and object directories
clean:
	rm -rf build
	rm -rf out/linux
	rm -rf out/win64

.PHONY: all windows clean
