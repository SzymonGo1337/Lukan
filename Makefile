ENGINE_OBJS = Engine/*.hpp Engine/*.cpp Engine/Systems/*.hpp Engine/Systems/*.cpp
RENDERER_OBJS = Engine/Renderer/*.hpp Engine/Renderer/*.cpp

#OBJS specifies which files to compile as part of the project
OBJS = $(ENGINE_OBJS) $(RENDERER_OBJS) src/*.cpp

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#VENDORS
VENDOR_glad = -Lvendor/glad/lib -Ivendor/glad/include vendor/glad/include/glad/glad.c
VENDOR_GLFW = -Lvendor/GLFW/lib -Ivendor/GLFW/include
VENDOR_glm = -Ivendor/glm/include
VENDOR_SOIL2 = -Lvendor/SOIL2/lib -Ivendor/SOIL2/include
VENDOR_SimplexNoise = vendor/SimplexNoise/*.h vendor/SimplexNoise/*.cpp

VENDOR = $(VENDOR_glad) $(VENDOR_GLFW) $(VENDOR_glm) $(VENDOR_SOIL2) $(VENDOR_SimplexNoise)

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = $(VENDOR) -lopengl32 -lglu32 -lglfw3dll -lsoil2-debug

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = bin/demo

#This is the target that compiles our executable
all : $(OBJS)
	mkdir -p bin
	mkdir -p bin/res
	cd ..
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
	cp vendor/dlls/* bin/
	cp res/* bin/res/