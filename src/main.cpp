#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include "renderer.h"
#include "loader.h"
#include "raw_model.h"
#include "event_manager.h"
#include "glm/vec3.hpp"


const std::vector<rend_eng::Vertex> square {

    rend_eng::Vertex{ -0.5f,  0.5f, 0.0f},
    rend_eng::Vertex{ -0.5f, -0.5f, 0.0f},
    rend_eng::Vertex{  0.5f, -0.5f, 0.0f},
    rend_eng::Vertex{  0.5f,  0.5f, 0.0f},
    
};

const std::vector<rend_eng::Index> square_indices{
    
    rend_eng::Index{0, 1, 3},
    rend_eng::Index{2, 1, 3}
};

const std::vector<rend_eng::Vertex> star{

    rend_eng::Vertex{ -0.5f,  0.5f, 0.0f},
    rend_eng::Vertex{ -0.5f, -0.5f, 0.0f},
    rend_eng::Vertex{  0.5f, -0.5f, 0.0f},
    rend_eng::Vertex{  0.5f,  0.5f, 0.0f},
    rend_eng::Vertex{  1.0f,  0.0f, 0.0f},
    rend_eng::Vertex{ -1.0f,  0.0f, 0.0f},
    rend_eng::Vertex{  0.0f,  1.0f, 0.0f},
    rend_eng::Vertex{  0.0f, -1.0f, 0.0f},
};

const std::vector<rend_eng::Index> star_indices {

    rend_eng::Index{6, 0, 3},
    rend_eng::Index{1, 0, 3},
    rend_eng::Index{1, 3, 2}
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

    rend_eng::RawModel raw = loader.loadModel(square, square_indices);
    
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        renderer.prepare();
        renderer.render(raw, GL_TRIANGLES);
        
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}