#pragma once

#include <GL/glew.h>

class CubeModel {
public:
    CubeModel();
    ~CubeModel();
    void bind();
private:
    GLuint vertexBuffer, uvBuffer, vertexArray;
};
