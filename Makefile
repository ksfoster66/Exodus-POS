#OBJS specifies the files being compiled
OBJS= src/*.cpp

#CC specifies the compiler being used
CC= g++

#INCLUDE_PATHS specifies the paths to include
INCLUDE_PATHS= -IInclude

#LIBRARY_PATHS
LIBRARY_PATHS= 

#COMPILER FLAGS
COMPILER_FLAGS= 

#LINKER_FLAGS
LINKER_FLAGS= 

#OBJ_NAME
OBJ_NAME= Build/CLI.exe

#Target
all : $(OBJS)
	$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)