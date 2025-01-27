#include "windowcreation.hpp"
#include "../../helper.hpp"
// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>

#include "controls.hpp"

WindowCreation::WindowCreation(GameCore* gameCore)
    : gameCore(gameCore), window(nullptr) {}

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
    glClearColor(Background_color::R, Background_color::G, Background_color::B, Background_color::A);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_CULL_FACE);
}

void WindowCreation::startRenderLoop(BaseModel* model) {
    do {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        computeMatricesFromInputs();
        glm::mat4 MVP = getProjectionMatrix() * getViewMatrix() * glm::mat4(1.0f);

        model->render(MVP);

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
