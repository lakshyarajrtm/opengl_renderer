
#include "shader.h"


std::vector<int> Shader::shader_id;
std::vector<int> Shader::program_id;

Shader::Shader() {}

Shader::~Shader()
{
    glDeleteShader(this->s_id);
}



void Shader::uploadShader(const std::string fileName)
{
    std::ifstream file;
    file.open(fileName, std::ios::in);
    std::ostringstream content;
    if (file.is_open())
        content << file.rdbuf();
    else
        std::cout << "Failed to read" << "\n";
  
    shader_source = content.str();
    file.close();
}

void Shader::compileShader(const GLuint shader_type, const int shader_count)
{
    unsigned int id = glCreateShader(shader_type);
    const char* src = shader_source.c_str();
    glShaderSource(id, shader_count, &src, nullptr);
    shader_id.push_back(id);
    s_id = id;
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        int len;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &len);
        char* message = (char*)alloca(len * sizeof(char));
        glGetShaderInfoLog(id, len, &len, message);

        std::cout << "ERROR::SHADER_COMPILATION: Failed to compile " <<
            (shader_type == GL_VERTEX_SHADER ? "Vertex" : "fragment") << " shader !" << std::endl;
        std::cout << message << std::endl;
    }
}

unsigned int Shader::createProgram(const Shader vertexShader, const Shader fragmentShader)
{
    int success;
    int program = glCreateProgram();
    glAttachShader(program, vertexShader.s_id);
    glAttachShader(program, fragmentShader.s_id);
    glLinkProgram(program);
    glValidateProgram(program);
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (success == GL_FALSE)
    {
        int len;
        glGetShaderiv(program, GL_INFO_LOG_LENGTH, &len);
        char* message = (char*)alloca(len * sizeof(char));
        glGetProgramInfoLog(program, len, &len, message);
        std::cout << "ERROR::SHADER_LINKING: failed to link\n" << message << std::endl;
    }
    program_id.push_back(program);
    return program;
}