#include <iostream>
#include "openGLHeader.hpp"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

void renderSmoothPoints(const glm::vec2 &vector, const float pointSize) {
    GLfloat pointVertex[] = {vector.x, vector.y};
    // Render OpenGL here
    glEnable(GL_POINT_SMOOTH); // make the point circular
    glEnableClientState(GL_VERTEX_ARRAY); // tell OpenGL that you're using a vertex array for fixed-function attribute
    glPointSize(pointSize); // must be added before glDrawArrays is called
    glVertexPointer(2, GL_FLOAT, 0, pointVertex); // point to the vertices to be used
    glDrawArrays(GL_POINTS, 0, 1); // draw the vertixes
    glDisableClientState(GL_VERTEX_ARRAY); // tell OpenGL that you're finished using the vertex arrayattribute
    glDisable(GL_POINT_SMOOTH); // stop the smoothing to make the points circular
}

void renderNoSmoothPoints(const glm::vec2 &vector) {
    GLfloat pointVertex[] = {vector.x, vector.y};

    glEnableClientState(GL_VERTEX_ARRAY); // tell OpenGL that you're using a vertex array for fixed-function attribute
    glVertexPointer(2, GL_FLOAT, 0, pointVertex); // point to the vertices to be used
    glPointSize(10); // must be added before glDrawArrays is called
    glDrawArrays(GL_POINTS, 0, 1); // draw the vertixes
    glDisableClientState(GL_VERTEX_ARRAY); // tell OpenGL that you're finished using the vertex arrayattribute
}

/*
int main() {
    GLFWwindow *window;
    if (!glfwInit()) {
        std::cerr << "ERROR 1" << std::endl;
        return EXIT_FAILURE;
    }
    if (!(window = glfwCreateWindow(800, 800, "HomeWork", nullptr, nullptr))) {
        std::cerr << "ERROR 2" << std::endl;
        glfwTerminate();
        return EXIT_FAILURE;
    }
    glfwMakeContextCurrent(window);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);


    Figure::Object2D object2D("Triangle", {
            Figure::Point2D("A", 0, 0),
            Figure::Point2D("B", 1, 0),
            Figure::Point2D("C", 0.5f, 1),
    });

    while (!glfwWindowShouldClose(window)) {
        float x = 0, y = 0, z = 0;
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
        glOrtho(-100.0f, 100.0f, -100.0f, 100.0f, -100.0f, 100.0f);
        renderPoint();
        renderCircle();
        renderLines();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return (0);
}
*/


GLFWwindow *initGlwWindow() {
    GLFWwindow *window;
    if (!glfwInit()) {
        throw "Enable to do : glfwInit";
    }

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World", NULL, NULL);
    if (!window) {
        glfwTerminate();
        throw "Enable to do : glfwCreateWindow";
    }
    // Make the window's context current
    glfwMakeContextCurrent(window);
    glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    // specifies the part of the window to which OpenGL will draw (in pixels), convert from normalised to pixels
    glMatrixMode(GL_PROJECTION);
    // projection matrix defines the properties of the camera that views the objects in the world coordinate frame. Here you typically set the zoom factor, aspect ratio and the near and far clipping planes
    glLoadIdentity();
    // replace the current matrix with the identity matrix and starts us a fresh because matrix transforms such as glOrpho and glRotate cumulate, basically puts us at (0, 0, 0)
    //glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1);
    // essentially set coordinate system
    glMatrixMode(GL_MODELVIEW);
    // (default matrix mode) modelview matrix defines how your objects are transformed (meaning translation, rotation and scaling) in your world
    glLoadIdentity();
    // same as above comment
    glfwMakeContextCurrent(window);
    return window;
}

int main() {
    GLFWwindow *window;
    try {
        window = initGlwWindow();
    } catch (std::exception exception) {
        return EXIT_FAILURE;
    }

    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        renderSmoothPoints({0, 0}, 10);
        renderSmoothPoints({0.5, 1}, 12);
        renderSmoothPoints({1, 0}, 15);
        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

