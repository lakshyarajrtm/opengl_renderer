#include "window_manager.h"
extern std::unique_ptr<rend_eng::EventManager> event_manager;

const std::vector<rend_eng::Vertex> square {

    {rend_eng::Position{ -0.5f,  0.5f, 0.0f}, rend_eng::Color{ 0.87f, 0.23f, 0.28f, 1.0f}},
    {rend_eng::Position{ -0.5f, -0.5f, 0.0f}, rend_eng::Color{ 0.87f, 0.23f, 0.28f, 1.0f}},
    {rend_eng::Position{  0.5f, -0.5f, 0.0f}, rend_eng::Color{ 0.87f, 0.23f, 0.28f, 1.0f}},
    {rend_eng::Position{  0.5f,  0.5f, 0.0f}, rend_eng::Color{ 0.87f, 0.23f, 0.28f, 1.0f}}
};

const std::vector<rend_eng::Index> square_indices{

    rend_eng::Index{0, 1, 3},
    rend_eng::Index{2, 1, 3}
};


const std::vector<rend_eng::Vertex> cube{

    {rend_eng::Position{-1.0, -1.0, 1.0}, rend_eng::Color{ 0.87f, 0.23f, 0.28f, 1.0f}},
    {rend_eng::Position{1.0, -1.0, 1.0}, rend_eng::Color{ 0.87f, 0.23f, 0.28f, 1.0f}},
    {rend_eng::Position{1.0,  1.0, 1.0}, rend_eng::Color{ 0.87f, 0.23f, 0.28f, 1.0f}},
    {rend_eng::Position{-1.0,  1.0, 1.0}, rend_eng::Color{ 0.87f, 0.23f, 0.28f, 1.0f}},


    {rend_eng::Position{-1.0, -1.0, -1.0}, rend_eng::Color{ 0.87f, 0.23f, 0.28f, 1.0f}},
    {rend_eng::Position{1.0, -1.0, -1.0}, rend_eng::Color{ 0.87f, 0.23f, 0.28f, 1.0f}},
    {rend_eng::Position{1.0,  1.0, -1.0}, rend_eng::Color{ 0.87f, 0.23f, 0.28f, 1.0f}},
    {rend_eng::Position{-1.0,  1.0, -1.0}, rend_eng::Color{ 0.87f, 0.23f, 0.28f, 1.0f}}

};


const std::vector<rend_eng::Index> cube_indices{

    rend_eng::Index{0, 1, 2},
    rend_eng::Index{2, 3, 0},

    rend_eng::Index{1, 5, 6},
    rend_eng::Index{6, 2, 1},

    rend_eng::Index{7, 6, 5},
    rend_eng::Index{5, 4, 7},

    rend_eng::Index{4, 0, 3},
    rend_eng::Index{3, 7, 4},

    rend_eng::Index{4, 5, 1},
    rend_eng::Index{1, 0, 4},

    rend_eng::Index{3, 2, 6},
    rend_eng::Index{6, 7, 3}
};

//const std::vector<rend_eng::Vertex> cube{
//
//    {rend_eng::Position{-0.5f, -0.5f, -0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//    {rend_eng::Position{ 0.5f, -0.5f, -0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//    {rend_eng::Position{ 0.5f,  0.5f, -0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//    {rend_eng::Position{ 0.5f,  0.5f, -0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//    {rend_eng::Position{-0.5f,  0.5f, -0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//    {rend_eng::Position{-0.5f, -0.5f, -0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//                                               
//    {rend_eng::Position{-0.5f, -0.5f,  0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//    {rend_eng::Position{ 0.5f, -0.5f,  0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//    {rend_eng::Position{ 0.5f,  0.5f,  0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//    {rend_eng::Position{ 0.5f,  0.5f,  0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//    {rend_eng::Position{-0.5f,  0.5f,  0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//    {rend_eng::Position{-0.5f, -0.5f,  0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//                                           
//    {rend_eng::Position{-0.5f,  0.5f,  0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//    {rend_eng::Position{-0.5f,  0.5f, -0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//    {rend_eng::Position{-0.5f, -0.5f, -0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//    {rend_eng::Position{-0.5f, -0.5f, -0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//    {rend_eng::Position{-0.5f, -0.5f,  0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//    {rend_eng::Position{-0.5f,  0.5f,  0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//                                           
//    {rend_eng::Position{ 0.5f,  0.5f,  0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//    {rend_eng::Position{ 0.5f,  0.5f, -0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//    {rend_eng::Position{ 0.5f, -0.5f, -0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//    {rend_eng::Position{ 0.5f, -0.5f, -0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//    {rend_eng::Position{ 0.5f, -0.5f,  0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//    {rend_eng::Position{ 0.5f,  0.5f,  0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//                                           
//    {rend_eng::Position{-0.5f, -0.5f, -0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//    {rend_eng::Position{ 0.5f, -0.5f, -0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//    {rend_eng::Position{ 0.5f, -0.5f,  0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//    {rend_eng::Position{ 0.5f, -0.5f,  0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//    {rend_eng::Position{-0.5f, -0.5f,  0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//    {rend_eng::Position{-0.5f, -0.5f, -0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//                                           
//    {rend_eng::Position{-0.5f,  0.5f, -0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//    {rend_eng::Position{ 0.5f,  0.5f, -0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//    {rend_eng::Position{ 0.5f,  0.5f,  0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//    {rend_eng::Position{ 0.5f,  0.5f,  0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//    {rend_eng::Position{-0.5f,  0.5f,  0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}},
//    {rend_eng::Position{-0.5f,  0.5f, -0.5f}, rend_eng::Color{ 1.0f, 1.0f, 1.0f, 1.0f}}
//
//};


rend_eng::WindowManager::WindowManager() : height(0), width(0)
{

}

rend_eng::WindowManager::~WindowManager()
{

}

int rend_eng::WindowManager::init(int width, int height)
{   
    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(width, height, "OPENGL RENDERER", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    glEnable(GL_DEPTH_TEST);
    return 0;
}

int rend_eng::WindowManager::update()
{
    rend_eng::Renderer renderer;
    rend_eng::Loader loader;
    Shader shader;

    const std::string path = "C:\\Users\\dell\\source\\repos\\opengl_renderer\\opengl_tutorial\\assets\\";
    std::string vertex_shader_path = path + "vertex_shader.glsl";
    std::string fragment_shader_path = path + "fragment_shader.glsl";

    rend_eng::RawModel raw = loader.loadModel(cube, cube_indices);
    shader.uploadAndCompileShader(raw, vertex_shader_path, fragment_shader_path);
    shader.useProgram();
    
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        //renderer.transform(raw, { 0.5f, 0.5f, 0.0f }, 40.0f, 0.5, 0);

        renderer.transform3d(raw);
        /* Render here */
        renderer.prepare();
        renderer.render_model(raw, GL_TRIANGLES);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}