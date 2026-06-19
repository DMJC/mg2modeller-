#include "../include/shader.h"

ShaderProgram::ShaderProgram() {}

ShaderProgram::~ShaderProgram() {
	cleanup();
}

GLuint ShaderProgram::compileShader(GLenum type, const char* source) {
	GLuint shader = glCreateShader(type);
	glShaderSource(shader, 1, &source, nullptr);
	glCompileShader(shader);

	GLint success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		char log[512];
		glGetShaderInfoLog(shader, 512, nullptr, log);
		const char* type_str = (type == GL_VERTEX_SHADER) ? "VERTEX" : "FRAGMENT";
		std::cerr << "Shader compilation failed (" << type_str << "): " << log << std::endl;
		glDeleteShader(shader);
		return 0;
	}
	return shader;
}

bool ShaderProgram::build(const char* vertex_src, const char* fragment_src) {
	GLuint vert = compileShader(GL_VERTEX_SHADER, vertex_src);
	if (!vert) return false;

	GLuint frag = compileShader(GL_FRAGMENT_SHADER, fragment_src);
	if (!frag) {
		glDeleteShader(vert);
		return false;
	}

	program_id = glCreateProgram();
	glAttachShader(program_id, vert);
	glAttachShader(program_id, frag);
	glLinkProgram(program_id);

	GLint success;
	glGetProgramiv(program_id, GL_LINK_STATUS, &success);
	if (!success) {
		char log[512];
		glGetProgramInfoLog(program_id, 512, nullptr, log);
		std::cerr << "Shader link failed: " << log << std::endl;
		glDeleteProgram(program_id);
		program_id = 0;
	}

	glDeleteShader(vert);
	glDeleteShader(frag);
	return program_id != 0;
}

void ShaderProgram::use() const {
	glUseProgram(program_id);
}

void ShaderProgram::cleanup() {
	if (program_id) {
		glDeleteProgram(program_id);
		program_id = 0;
	}
	uniform_cache.clear();
}

GLuint ShaderProgram::getId() const {
	return program_id;
}

GLint ShaderProgram::getUniformLoc(const std::string& name) {
	auto it = uniform_cache.find(name);
	if (it != uniform_cache.end()) return it->second;
	GLint loc = glGetUniformLocation(program_id, name.c_str());
	uniform_cache[name] = loc;
	return loc;
}

void ShaderProgram::setInt(const std::string& name, int value) {
	glUniform1i(getUniformLoc(name), value);
}

void ShaderProgram::setFloat(const std::string& name, float value) {
	glUniform1f(getUniformLoc(name), value);
}

void ShaderProgram::setVec3(const std::string& name, const float* value) {
	glUniform3fv(getUniformLoc(name), 1, value);
}

void ShaderProgram::setVec4(const std::string& name, const float* value) {
	glUniform4fv(getUniformLoc(name), 1, value);
}

void ShaderProgram::setMat3(const std::string& name, const float* value) {
	glUniformMatrix3fv(getUniformLoc(name), 1, GL_FALSE, value);
}

void ShaderProgram::setMat4(const std::string& name, const float* value) {
	glUniformMatrix4fv(getUniformLoc(name), 1, GL_FALSE, value);
}
