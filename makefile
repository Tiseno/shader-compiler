default:
	g++ main.cpp -std=c++11 -Wall -L/usr/local/lib/ -lGL -lGLU -lglut -lGLEW -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor -o shader-compiler.out
