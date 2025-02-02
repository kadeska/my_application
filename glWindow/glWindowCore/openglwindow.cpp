#include "openglwindow.hpp"
#include "../../game/core/gamecore.hpp"
// Include standard headers
#include <stdio.h>
#include <stdlib.h>

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
GLFWwindow* glWindow;

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#include <shader.hpp>
#include <texture.hpp>
#include <controls.hpp>


GLuint programID;
GLuint MatrixID;
GLuint Texture;
GLuint TextureID;

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

GLuint uvbuffer;
GLuint vertexbuffer;
GLuint VertexArrayID;

OpenglWindow::OpenglWindow(GameCore* gameCore)
{
    // Initialize GLFW
    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        getchar();
        //return -1;
    }

    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make macOS happy; should not be needed
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Open a window and create its OpenGL context
    glWindow = glfwCreateWindow( 1024, 768, "Tutorial 0 - Keyboard and Mouse", NULL, NULL);
    if( glWindow == NULL ){
        fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
        getchar();
        glfwTerminate();
        //return -1;
    }
    glfwMakeContextCurrent(glWindow);

    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwTerminate();
        //return -1;
    }

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(glWindow, GLFW_STICKY_KEYS, GL_TRUE);
    // Hide the mouse and enable unlimited movement
    glfwSetInputMode(glWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // Set the mouse at the center of the screen
    glfwPollEvents();
    glfwSetCursorPos(glWindow, 1024/2, 768/2);

    // Dark blue background
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

    // Enable depth test
    glEnable(GL_DEPTH_TEST);
    // Accept fragment if it is closer to the camera than the former one
    glDepthFunc(GL_LESS);

    // Cull triangles which normal is not towards the camera
    glEnable(GL_CULL_FACE);


    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    // Create and compile our GLSL program from the shaders
    programID = LoadShaders( "SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader" );

    // Get a handle for our "MVP" uniform
    MatrixID = glGetUniformLocation(programID, "MVP");

    // Load the texture
    Texture = loadDDS("uvtemplate.DDS");

    // Get a handle for our "myTextureSampler" uniform
    TextureID  = glGetUniformLocation(programID, "myTextureSampler");



    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);


    glGenBuffers(1, &uvbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);

    // render loop
    startRenderLoop();

    // Cleanup VBO and shader
    glDeleteBuffers(1, &vertexbuffer);
    glDeleteBuffers(1, &uvbuffer);
    glDeleteProgram(programID);
    glDeleteTextures(1, &TextureID);
    glDeleteVertexArrays(1, &VertexArrayID);

    // Close OpenGL window and terminate GLFW
    glfwTerminate();

    //return 0;
}
void OpenglWindow::startRenderLoop()
{
    glBindVertexArray(VertexArrayID); // Bind VAO before rendering

    do { // Main render loop

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Use our shader
        glUseProgram(programID);

        // Compute the MVP matrix from keyboard and mouse input
        computeMatricesFromInputs(glWindow);
        glm::mat4 ProjectionMatrix = getProjectionMatrix();
        glm::mat4 ViewMatrix = getViewMatrix();

        // First cube's transformation
        glm::mat4 ModelMatrix1 = glm::translate(glm::mat4(1.0f), glm::vec3(-2.0f, 0.0f, 0.0f)); // Move left
        glm::mat4 MVP1 = ProjectionMatrix * ViewMatrix * ModelMatrix1;

        // Send MVP matrix for first cube
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP1[0][0]);

        // Bind texture
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, Texture);
        glUniform1i(TextureID, 0);

        // Bind vertex buffer
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

        // Bind UV buffer
        glEnableVertexAttribArray(1);
        glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

        // Draw the first cube
        glDrawArrays(GL_TRIANGLES, 0, 36);

        // === Second Cube ===
        glm::mat4 ModelMatrix2 = glm::translate(glm::mat4(1.0f), glm::vec3(2.0f, 0.0f, 0.0f)); // Move right
        glm::mat4 MVP2 = ProjectionMatrix * ViewMatrix * ModelMatrix2;

        // Send MVP matrix for second cube
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP2[0][0]);

        // Draw the second cube (same buffers, different transformation)
        glDrawArrays(GL_TRIANGLES, 0, 36);

        // Disable arrays
        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);

        // Swap buffers
        glfwSwapBuffers(glWindow);
        glfwPollEvents();

    } while (glfwGetKey(glWindow, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
             glfwWindowShouldClose(glWindow) == 0);

    //glfwSetWindowShouldClose(glWindow, true);


}
