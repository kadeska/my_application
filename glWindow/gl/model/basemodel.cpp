#include "basemodel.hpp"
#include "shader.hpp"
#include "texture.hpp"

BaseModel::BaseModel()
    : vertexBuffer(0), uvBuffer(0), programID(0), textureID(0), textureSamplerID(0), matrixID(0) {}

BaseModel::~BaseModel() {
    glDeleteBuffers(1, &vertexBuffer);
    glDeleteBuffers(1, &uvBuffer);
    glDeleteProgram(programID);
    glDeleteTextures(1, &textureID);
}

void BaseModel::initializeBuffers(const GLfloat* vertices, size_t vertexSize, const GLfloat* uvs, size_t uvSize) {
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, vertexSize, vertices, GL_STATIC_DRAW);

    glGenBuffers(1, &uvBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, uvBuffer);
    glBufferData(GL_ARRAY_BUFFER, uvSize, uvs, GL_STATIC_DRAW);
}

void BaseModel::loadShaders(const std::string& vertexShaderPath, const std::string& fragmentShaderPath) {
    programID = LoadShaders(vertexShaderPath.c_str(), fragmentShaderPath.c_str());
    matrixID = glGetUniformLocation(programID, "MVP");
    textureSamplerID = glGetUniformLocation(programID, "myTextureSampler");
}

void BaseModel::loadTexture(const std::string& texturePath) {
    textureID = loadDDS(texturePath.c_str());
}

void BaseModel::render(const glm::mat4& MVP) {
    glUseProgram(programID);

    glUniformMatrix4fv(matrixID, 1, GL_FALSE, &MVP[0][0]);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glUniform1i(textureSamplerID, 0);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, uvBuffer);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glDrawArrays(GL_TRIANGLES, 0, 12 * 3);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}
