#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include "renderer.h"
#include "loader.h"
#include "raw_model.h"
#include "event_manager.h"

const std::vector<float> vertices {

    -0.5f,  0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.5f,  0.5f, 0.0f,
    -0.5f,  0.5f, 0.0f
};

int main(void)
{
    GLFWwindow* window;
    rend_eng::Renderer renderer;
    rend_eng::Loader loader;
    rend_eng::EventManager::createEventManager();
 
    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(640, 640, "OPENGL RENDERER", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    rend_eng::RawModel raw = loader.loadToVao(vertices);
    
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        renderer.prepare();
        renderer.render(raw);
        
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}