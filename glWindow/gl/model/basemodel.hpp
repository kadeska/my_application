#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>

class BaseModel {
public:
    BaseModel();
    virtual ~BaseModel();

    void initializeBuffers(const GLfloat* vertices, size_t vertexSize, const GLfloat* uvs, size_t uvSize);
    void loadShaders(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
    void loadTexture(const std::string& texturePath);
    void render(const glm::mat4& MVP);

protected:
    GLuint vertexBuffer;
    GLuint uvBuffer;
    GLuint programID;
    GLuint textureID;
    GLuint textureSamplerID;
    GLuint matrixID;
};
