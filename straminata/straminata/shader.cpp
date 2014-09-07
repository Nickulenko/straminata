#include "shader.h"

static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
//static std::string loadShader(const std::string& fileName);
static GLuint CreateShader(const std::string& text, GLenum shaderType);

Shader::Shader(const std::string& fileName)
{
	m_program = glCreateProgram();
	//m_shaders[0] = CreateShader(loadShader(fileName), GL_VERTEX_SHADER);
	//m_shaders[1] = CreateShader(loadShader(fileName), GL_FRAGMENT_SHADER);
}

Shader::~Shader()
{
	glDeleteProgram(m_program);
}

static GLuint CreateShader(const std::string& text, GLenum shaderType)
{

}
/*
static std::string loadShader(const std::string& fileName)
{
	std::ifstream file;
	file.open((fileName).c_str());

	std::string output;
	std::string line;

	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, line);
			output.append(line + "\n");
		}
	}
	else
	{
		std::cerr << "Unable to load shader : " << fileName << std::endl;
	}

	return output;
}
*/

static void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
	GLuint success = 0;
	GLchar error[1024] = { 0 };

	if (isProgram)
		glGetProgramInfoLog(shader, sizeof(error), NULL, error);
	else
		glGetShaderInfoLog(shader, sizeof(error), NULL, error);

	std::cerr << errorMessage << ": '" << error << "'" << std::endl;
}