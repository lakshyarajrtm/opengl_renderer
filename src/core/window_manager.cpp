#include "window_manager.h"
extern std::unique_ptr<rend_eng::EventManager> event_manager;

const std::vector<rend_eng::Vertex> square {

    {rend_eng::Position{ -0.5f,  0.5f, 0.0f}, rend_eng::Color{ 1.0f, 0.0f, 1.0f, 1.0f}},
    {rend_eng::Position{ -0.5f, -0.5f, 0.0f}, rend_eng::Color{ 0.6f, 0.4f, 0.2f, 1.0f}},
    {rend_eng::Position{  0.5f, -0.5f, 0.0f}, rend_eng::Color{ 1.0f, 0.4f, 0.0f, 1.0f}},
    {rend_eng::Position{  0.5f,  0.5f, 0.0f}, rend_eng::Color{ 0.4f, 0.0f, 1.0f, 1.0f}}
};

const std::vector<rend_eng::Index> square_indices {

    rend_eng::Index{0, 1, 3},
    rend_eng::Index{2, 1, 3}
};


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
}

int rend_eng::WindowManager::update()
{
    rend_eng::Renderer renderer;
    rend_eng::Loader loader;

    const std::string path = "C:\\Users\\dell\\source\\repos\\opengl_renderer\\opengl_tutorial\\assets\\";
    std::string vertex_shader_path = path + "vertex_shader.glsl";
    std::string fragment_shader_path = path + "fragment_shader.glsl";

    rend_eng::RawModel raw = loader.loadModel(square, square_indices);
    raw.uploadAndCompileShader(vertex_shader_path, fragment_shader_path);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        renderer.transform(raw, 40.0f, 0.5, 0);
        /* Render here */
        renderer.prepare();
        renderer.render(raw, GL_TRIANGLES);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}