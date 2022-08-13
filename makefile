FLAGS = `pkg-config --static --libs glew`
FLAGS += `pkg-config --static --libs glfw3`

FLAGS += `pkg-config --cflags glew`
FLAGS += `pkg-config --cflags glfw3`

default:
	g++ main.cpp -std=c++11 -Wall $(FLAGS) -o shader-compiler.out
