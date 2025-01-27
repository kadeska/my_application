#include "windowcreation.hpp"
#include "../../helper.hpp"
#include "controls.hpp"
#include "shader.hpp"
#include "texture.hpp"


// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

namespace fun = UsefulFunctions;

// Create and compile our GLSL program from the shaders
GLuint programID;
// Get a handle for our "MVP" uniform
GLuint MatrixID;
// Load the texture
GLuint Texture;
// Get a handle for our "myTextureSampler" uniform
GLuint TextureID;
// vertex buffer
GLuint vertexbuffer;
// UV buffer
GLuint uvbuffer;
// Our vertices. Tree consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
// A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
static const GLfloat g_vertex_buffer_data[] = {
    -1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, 1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    -1.0f,-1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    -1.0f,-1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f,-1.0f,
    1.0f,-1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f,-1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f,-1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f,
    1.0f,-1.0f, 1.0f
};

// Two UV coordinatesfor each vertex. They were created with Blender.
static const GLfloat g_uv_buffer_data[] = {
    0.000059f, 0.000004f,
    0.000103f, 0.336048f,
    0.335973f, 0.335903f,
    1.000023f, 0.000013f,
    0.667979f, 0.335851f,
    0.999958f, 0.336064f,
    0.667979f, 0.335851f,
    0.336024f, 0.671877f,
    0.667969f, 0.671889f,
    1.000023f, 0.000013f,
    0.668104f, 0.000013f,
    0.667979f, 0.335851f,
    0.000059f, 0.000004f,
    0.335973f, 0.335903f,
    0.336098f, 0.000071f,
    0.667979f, 0.335851f,
    0.335973f, 0.335903f,
    0.336024f, 0.671877f,
    1.000004f, 0.671847f,
    0.999958f, 0.336064f,
    0.667979f, 0.335851f,
    0.668104f, 0.000013f,
    0.335973f, 0.335903f,
    0.667979f, 0.335851f,
    0.335973f, 0.335903f,
    0.668104f, 0.000013f,
    0.336098f, 0.000071f,
    0.000103f, 0.336048f,
    0.000004f, 0.671870f,
    0.336024f, 0.671877f,
    0.000103f, 0.336048f,
    0.336024f, 0.671877f,
    0.335973f, 0.335903f,
    0.667969f, 0.671889f,
    1.000004f, 0.671847f,
    0.667979f, 0.335851f
};

WindowCreation::WindowCreation(GameCore* gameCore)
    : gameCore(gameCore), window(nullptr) {
    // Leave window creation to `initializeWindow`
}

WindowCreation::~WindowCreation() {
    terminate();
}

void WindowCreation::initializeWindow(int width, int height, const std::string& title) {
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        throw std::runtime_error("GLFW initialization failed");
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if (!window) {
        fprintf(stderr, "Failed to open GLFW window\n");
        glfwTerminate();
        throw std::runtime_error("GLFW window creation failed");
    }

    glfwMakeContextCurrent(window);

    glewExperimental = true;
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        glfwTerminate();
        throw std::runtime_error("GLEW initialization failed");
    }

    setupOpenGL();

}

void WindowCreation::setupOpenGL() {
    helper.log(3, "setupOpenGL()");
    glClearColor(BackgroundColor::R, BackgroundColor::G, BackgroundColor::B, BackgroundColor::A);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_CULL_FACE);

    programID = LoadShaders( "SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader" );
    MatrixID = glGetUniformLocation(programID, "MVP");
    Texture = loadDDS("uvtemplate.DDS");
    TextureID  = glGetUniformLocation(programID, "myTextureSampler");
}

void WindowCreation::startRenderLoop(BaseModel* model) {
    helper.log(3, "startRenderLoop()");
    if (!window) {
        throw std::runtime_error("Window not initialized before starting render loop");
    }

    do {
        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Use our shader
        glUseProgram(programID);

        // Compute the MVP matrix from keyboard and mouse input
        computeMatricesFromInputs(window);
        glm::mat4 ProjectionMatrix = getProjectionMatrix();
        glm::mat4 ViewMatrix = getViewMatrix();
        glm::mat4 ModelMatrix = glm::mat4(1.0);
        glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;

        //model->render(MVP);
        genBuffers();

        // Send our transformation to the currently bound shader,
        // in the "MVP" uniform
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

        // Bind our texture in Texture Unit 0
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, Texture);
        // Set our "myTextureSampler" sampler to use Texture Unit 0
        glUniform1i(TextureID, 0);

        // 1rst attribute buffer : vertices
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(
            0,                  // attribute. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*)0            // array buffer offset
            );

        // 2nd attribute buffer : UVs
        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
        glVertexAttribPointer(
            1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
            2,                                // size : U+V => 2
            GL_FLOAT,                         // type
            GL_FALSE,                         // normalized?
            0,                                // stride
            (void*)0                          // array buffer offset
            );

        // Draw the triangle !
        glDrawArrays(GL_TRIANGLES, 0, 12*3); // 12*3 indices starting at 0 -> 12 triangles

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();

    } while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(window));

    gameCore->gameRunning = false;
    gameCore->stop();
}

void WindowCreation::terminate() {
    if (window) {
        glfwDestroyWindow(window);
    }
    glfwTerminate();
}

void WindowCreation::genBuffers()
{
    // vertex buffer
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
    // UV buffer
    glGenBuffers(1, &uvbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);

}
