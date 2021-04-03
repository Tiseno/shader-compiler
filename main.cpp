#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <sstream>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int compileShader(GLuint shaderType, string shaderPath) {
	ifstream ifs(shaderPath);
	const string content((istreambuf_iterator<char>(ifs)), istreambuf_iterator<char>());

	GLuint shaderId = glCreateShader(shaderType);
	const char * source = content.c_str();
	glShaderSource(shaderId, 1, &source, nullptr);
	glCompileShader(shaderId);

	GLint result;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		GLint length;
		glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &length);

		GLchar * strInfoLog = new GLchar[length + 1];
		glGetShaderInfoLog(shaderId, length, &length, strInfoLog);

		istringstream ss(strInfoLog);
		string line;
		while (std::getline(ss, line)) {
			cout << shaderPath << " " << line << endl;
		}
		delete[] strInfoLog;
		return -1;
	}
	return shaderId;
}


int main(int argc, char *argv[]) {
	// If we have no arguments
  if(argc < 2) {
		// TODO Read from std in
		cout << "shader-compiler error: no file specified" << endl;
		return 1;
	}
	// Otherwise we read from the files passed

	auto glfwInitResult = glfwInit();

	if (!glfwInitResult) {
		cout << "shader-compiler error: could not init glfw" << endl;
		return 1;
	}

	auto window = glfwCreateWindow(1, 1, "Compile shader", NULL, NULL);

	if (!window) {
		cout << "shader-compiler error: could not create glfw window" << endl;
		glfwTerminate();
		return 1;
	}

	glfwMakeContextCurrent(window);

	auto err = glewInit();
	if (err != GLEW_OK) {
		cout << "shader-compiler error: could not init glew: " << glewGetErrorString(err) << endl;
		glfwTerminate();
		return 1;
	}

	glCreateProgram();

	for (int i = 1; i < argc; i++) {
		// Only supports files ending in .frag, .vert, .fragment, and .vertex
		string args = argv[i];
		auto isFragmentShader = args.substr(args.length() - 5, 5).compare(".frag") == 0 || args.substr(args.length() - 9, 9).compare(".fragment") == 0;
		auto isVertexShader = args.substr(args.length() - 5, 5).compare(".vert") == 0 || args.substr(args.length() - 7, 7).compare(".vertex") == 0;
		if (!isFragmentShader && !isVertexShader) {
			cout << "shader-compiler error: wrong file type of shader '" << args << "', shader-compiler only supports .frag, .vert, .fragment, and .vertex extensions" << endl;
			return 1;
		}
		compileShader(isFragmentShader ? GL_FRAGMENT_SHADER : GL_VERTEX_SHADER, args);
	}

	return 0;
}
