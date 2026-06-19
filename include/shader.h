#ifndef SHADER_H
#define SHADER_H

#include <epoxy/gl.h>
#include <string>
#include <unordered_map>
#include <iostream>

class ShaderProgram {
private:
	GLuint program_id = 0;
	std::unordered_map<std::string, GLint> uniform_cache;

	GLuint compileShader(GLenum type, const char* source);
	GLint getUniformLoc(const std::string& name);

public:
	ShaderProgram();
	~ShaderProgram();

	bool build(const char* vertex_src, const char* fragment_src);
	void use() const;
	void cleanup();
	GLuint getId() const;

	void setInt(const std::string& name, int value);
	void setFloat(const std::string& name, float value);
	void setVec3(const std::string& name, const float* value);
	void setVec4(const std::string& name, const float* value);
	void setMat3(const std::string& name, const float* value);
	void setMat4(const std::string& name, const float* value);
};

#endif // SHADER_H
