#include <iostream>
#include <string>
#include <fstream>
#include <GL/glew.h>

class Shader
{
public:
	Shader(const std::string& fileName);

	void Bind();

	virtual ~Shader();
protected:
private:
	static const unsigned int NUM_SHADERS = 2;
	Shader(const Shader& other) {}
	Shader& operator=(const Shader& other) {}

	void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
	std::string LoadShader(const std::string& fileName);
	GLuint CreateShader(const std::string& text, GLenum shaderType);

	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];
};

