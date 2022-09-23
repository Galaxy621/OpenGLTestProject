#ifndef RENDER_H
#define RENDER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "shader.h"

#define WINDOW_TITLE_PREFIX "Hello, Chat"

void Initialise(int argc, char* argv[]);
void InitWindow(int argc, char* argv[]);

void ResizeFunction(int width, int height);
void RenderFunction();
void TimerFunction(int value);
void IdleFunction();

#endif