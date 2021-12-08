//
// Created by Remi Peyras on 08/12/2021.
//

//
// Created by Remi Peyras on 13/10/2021.
//

#include "generalInclude.hpp"

/**
 * @function drawLinearInterpolation
 * @desc Draw a triangle with linear interpolation
 */
void drawLinearInterpolation() {
    glBegin(GL_TRIANGLES);
    {
        glColor3f(1, 0, 0);
        glVertex2f(-9, -9);
        glColor3f(0, 1, 0);
        glVertex2f(9, -9);
        glColor3f(0, 0, 1);
        glVertex2f(0, 9);
    }
    glEnd();
}

/**
 * @function processInput
 * @desc Function to manage the different style of input only ESCAPE is available to leave the program
 *
 * @param {GLFWwindow *} window Window active by OpenGL
 */
void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

/**
 * @function initGlwWindow
 * @desc Initialization of the structure GLFWwindow
 *
 * @returns {GLFWwindow *} Structure GLFWwindow setup correctly
 */
GLFWwindow *initGlwWindow() {
    GLFWwindow *window;

    if (!glfwInit()) {
        throw std::exception();
    }
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE,
                              nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        throw std::exception();
    }
    glfwMakeContextCurrent(window);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
    return window;
}

int main() {
    GLFWwindow *window;
    try {
        window = initGlwWindow();
    } catch (std::string &exception) {
        std::cerr << "Error when initialize something ..." << std::endl;
        return EXIT_FAILURE;
    }
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        processInput(window);
        drawLinearInterpolation();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return EXIT_SUCCESS;
}
