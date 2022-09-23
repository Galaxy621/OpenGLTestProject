#include "shader.h"

GLuint
    vertexShaderId,
    fragmentShaderId,
    programId,
    vaoId,
    vboId,
    colourBufferId;

const GLchar* VertexShader;
const GLchar* FragmentShader;

const GLchar* GetShaderFromFile(const char* filename) {
    FILE* shaderFile = fopen(filename, "r");

    if (shaderFile == NULL) {
        printf("Error: Shader file in %s cannot be accessed\n", filename);
        exit(EXIT_FAILURE);
    }

    size_t fileSize;

    fseek(shaderFile, 0, SEEK_END);
    fileSize = ftell(shaderFile);
    fseek(shaderFile, 0, SEEK_SET);

    GLchar * shader = (GLchar *) malloc(fileSize);
    fread(shader, 1, fileSize, shaderFile);
    fclose(shaderFile);

    return shader;
}

void InitialiseShaders() {
    VertexShader = GetShaderFromFile("assets/shaders/VertexShader.glsl");
    FragmentShader = GetShaderFromFile("assets/shaders/FragmentShader.glsl");
}

void Cleanup() {
    DestroyShaders();
    DestroyVBO();
}

void CreateVBO() {
    GLfloat verticies[12] = {
        -0.8f, -0.8f, 0.0f, 1.0f,
        0.0f, 0.8f, 0.0f, 1.0f,
        0.8f, -0.8f, 0.0f, 1.0f
    };

    GLfloat colours[12] = {
        1.0f, 0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f, 1.0f
    };

    GLenum errorCheckValue = glGetError();

    glGenVertexArrays(1, &vaoId);
    glBindVertexArray(vaoId);

    glGenBuffers(1, &vboId);
    glBindBuffer(GL_ARRAY_BUFFER, vboId);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    glGenBuffers(1, &colourBufferId);
    glBindBuffer(GL_ARRAY_BUFFER, colourBufferId);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colours), colours, GL_STATIC_DRAW);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(1);

    errorCheckValue = glGetError();

    if (errorCheckValue != GL_NO_ERROR) {
        printf("Error: Could not create a VBO: %s\n", gluErrorString(errorCheckValue));
        exit(EXIT_FAILURE);
    }
}

void DestroyVBO() {
    GLenum errorCheckValue = glGetError();

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glDeleteBuffers(1, &colourBufferId);
    glDeleteBuffers(1, &vboId);

    glBindVertexArray(0);
    glDeleteVertexArrays(1, &vaoId);

    errorCheckValue = glGetError();
    if (errorCheckValue != GL_NO_ERROR) {
        printf("Error: Could not destroy VBO: %s\n", gluErrorString(errorCheckValue));
        exit(EXIT_FAILURE);
    }
}

void CreateShaders(void) {
    GLenum errorCheckValue = glGetError();

    vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShaderId, 1, &VertexShader, NULL);
    glCompileShader(vertexShaderId);

    fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderId, 1, &FragmentShader, NULL);
    glCompileShader(fragmentShaderId);

    programId = glCreateProgram();
    glAttachShader(programId, vertexShaderId);
    glAttachShader(programId, fragmentShaderId);
    glLinkProgram(programId);
    glUseProgram(programId);

    errorCheckValue = glGetError();
    if (errorCheckValue != GL_NO_ERROR) {
        printf("Error: Could not create shaders: %s\n",gluErrorString(errorCheckValue));
        exit(EXIT_FAILURE);
    }
}

void DestroyShaders() {
    GLenum errorCheckValue = glGetError();

    glUseProgram(0);

    glDetachShader(programId, vertexShaderId);
    glDetachShader(programId, fragmentShaderId);

    glDeleteShader(vertexShaderId);
    glDeleteShader(fragmentShaderId);

    glDeleteProgram(programId);

    errorCheckValue = glGetError();
    if (errorCheckValue != GL_NO_ERROR) {
        printf("Error: Could not destroy shaders: %s\n",gluErrorString(errorCheckValue));
        exit(EXIT_FAILURE);
    }

}

/*

Todo:
    CreateShaders();
    DestroyShaders();
    
*/