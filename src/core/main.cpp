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

extern std::unique_ptr<rend_eng::EventManager> event_manager;

const std::vector<rend_eng::Position> square {

    rend_eng::Position{ -0.5f,  0.5f, 0.0f},
    rend_eng::Position{ -0.5f, -0.5f, 0.0f},
    rend_eng::Position{  0.5f, -0.5f, 0.0f},
    rend_eng::Position{  0.5f,  0.5f, 0.0f},
    
};

const std::vector<rend_eng::Index> square_indices {
    
    rend_eng::Index{0, 1, 3},
    rend_eng::Index{2, 1, 3}
};

const std::vector<rend_eng::Position> star {

    rend_eng::Position{ -0.5f,  0.5f, 0.0f},
    rend_eng::Position{ -0.5f, -0.5f, 0.0f},
    rend_eng::Position{  0.5f, -0.5f, 0.0f},
    rend_eng::Position{  0.5f,  0.5f, 0.0f},
    rend_eng::Position{  1.0f,  0.0f, 0.0f},
    rend_eng::Position{ -1.0f,  0.0f, 0.0f},
    rend_eng::Position{  0.0f,  1.0f, 0.0f},
    rend_eng::Position{  0.0f, -1.0f, 0.0f},
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

    const std::string path = "C:\\Users\\dell\\source\\repos\\opengl_renderer\\opengl_tutorial\\assets\\";
    std::string vertex_shader_path = path + "vertex_shader.glsl";
    std::string fragment_shader_path = path + "fragment_shader.glsl";

    rend_eng::RawModel raw = loader.loadModel(square, square_indices);
    raw.uploadAndCompileShader(vertex_shader_path, fragment_shader_path);
    
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