#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <GL/glew.h>
#include <GL/freeglut.h>

#define WINDOW_TITLE_PREFIX "Hello, Chat"

int currentWidth = 800,
    currentHeight = 600,
    windowHandle = 0;

void Initialise(int argc, char* argv[]);
void InitWindow(int argc, char* argv[]);
void ResizeFunction(int width, int height);
void RenderFunction(void);

int main(int argc, char* argv[]) {
    Initialise(argc, argv);
    glutMainLoop();
    exit(EXIT_SUCCESS);
}

void Initialise(int argc, char* argv[]) {
    InitWindow(argc, argv);

    printf("INFO: OpenGL Version: %s\n", glGetString(GL_VERSION));

    glClearColor(0.0f, 0.5f, 0.5f, 1.0f);
}

void InitWindow(int argc, char* argv[]) {
    glutInit(&argc, argv);

    glutInitContextVersion(4, 0);
    glutInitContextFlags(GLUT_FORWARD_COMPATIBLE);
    glutInitContextProfile(GLUT_CORE_PROFILE);

    glutSetOption(
        GLUT_ACTION_ON_WINDOW_CLOSE,
        GLUT_ACTION_GLUTMAINLOOP_RETURNS
    );

    glutInitWindowSize(currentWidth, currentHeight);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

    windowHandle = glutCreateWindow(WINDOW_TITLE_PREFIX);

    if (windowHandle < 1) {
        printf("Error: Could not create a new rendering window\n");
        exit(EXIT_FAILURE);
    }

    glutReshapeFunc(ResizeFunction);
    glutDisplayFunc(RenderFunction);
}

void ResizeFunction(int width, int height) {
    currentWidth = width;
    currentHeight = height;
    glViewport(0, 0, currentWidth, currentHeight);
}

void RenderFunction(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSwapBuffers();
    glutPostRedisplay();
}