#ifndef SHADER_H
#define SHADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <fts.h>

#include <GL/glew.h>
#include <GL/freeglut.h>

const GLchar* VertexShader;
const GLchar* FragmentShader;

const GLchar* GetShaderFromFile(const char* filename);
void InitialiseShaders();

void Cleanup();
void CreateVBO();
void DestroyVBO();
void CreateShaders();
void DestroyShaders();

#endif