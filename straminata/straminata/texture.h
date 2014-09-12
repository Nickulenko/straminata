#include <string>
#include <GL/glew.h>

class Texture
{
public:
	Texture(const std::string& fileName);

	void Bind();

	virtual ~Texture();
protected:
private:
	Texture(const Texture& other) {}
	void operator=(const Texture&other) {}

	GLuint m_texture;
};

