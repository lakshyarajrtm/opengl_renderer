
#include "shader.h"

std::vector<int> Shader::shader_id;
std::vector<int> Shader::program_id;

Shader::Shader() {}

Shader::~Shader()
{
    glDeleteShader(this->vertex_shader_id);
    glDeleteShader(this->fragment_shader_id);
}

void Shader::uploadVertexShader(const std::string& fileName)
{
    std::ifstream file;
    file.open(fileName, std::ios::in);
    std::ostringstream content;
    if (file.is_open())
        content << file.rdbuf();
    else
        std::cout << "Failed to read" << "\n";
  
    vertex_shader_source = content.str();
    file.close();
}

void Shader::uploadFragmentShader(const std::string& fileName)
{
    std::ifstream file;
    file.open(fileName, std::ios::in);
    std::ostringstream content;
    if (file.is_open())
        content << file.rdbuf();
    else
        std::cout << "Failed to read" << "\n";

    fragment_shader_source = content.str();
    file.close();
}

void Shader::compileShader(const GLuint shader_type, const int shader_count)
{
    unsigned int id = glCreateShader(shader_type);
    const char* src;
    if (shader_type == GL_VERTEX_SHADER)
    {
        src = vertex_shader_source.c_str();
        vertex_shader_id = id;
    }
    if (shader_type == GL_FRAGMENT_SHADER)
    {
        src = fragment_shader_source.c_str();
        fragment_shader_id = id;
    }
    glShaderSource(id, shader_count, &src, nullptr);
    shader_id.push_back(id);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int len;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &len);
        char* message = (char*) alloca(len * sizeof(char));
        glGetShaderInfoLog(id, len, &len, message);

        std::cout << "ERROR::SHADER_COMPILATION: Failed to compile " <<
            (shader_type == GL_VERTEX_SHADER ? "Vertex" : "fragment") << " shader !" << std::endl;
        std::cout << message << std::endl;
    }
}

unsigned int Shader::createProgram()
{
    int success;
    int program = glCreateProgram();
    glAttachShader(program, vertex_shader_id);
    glAttachShader(program, fragment_shader_id);
    glLinkProgram(program);
    glValidateProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (success == GL_FALSE)
    {
        int len;
        glGetShaderiv(program, GL_INFO_LOG_LENGTH, &len);
        char* message = (char*) alloca(len * sizeof(char));
        glGetProgramInfoLog(program, len, &len, message);
        std::cout << "ERROR::SHADER_LINKING: failed to link\n" << message << std::endl;
    }
    program_id.push_back(program);
    p_id = program;
    return program;
}

void Shader::uploadAndCompileShader(rend_eng::RawModel& raw, std::string& vertex_shader_file, std::string& fragment_shader_file)
{
    uploadVertexShader(vertex_shader_file);
    uploadFragmentShader(fragment_shader_file);
    compileShader(GL_VERTEX_SHADER, 1);
    compileShader(GL_FRAGMENT_SHADER, 1);
    raw.p_id = createProgram();
}

void Shader::useProgram()
{
    glUseProgram(p_id);
}