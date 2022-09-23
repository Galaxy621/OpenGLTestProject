#include "render.h"

int currentWidth = 800,
    currentHeight = 600,
    windowHandle = 0;

uint32_t FrameCount = 0;

void Initialise(int argc, char* argv[]) {
    GLenum glewInitResult;

    InitialiseShaders();
    InitWindow(argc, argv);

    glewInitResult = glewInit();
    if (glewInitResult != GLEW_OK) {
        printf("Error: %s\n", glewGetErrorString(glewInitResult));
        exit(EXIT_FAILURE);
    }

    printf("INFO: OpenGL Version: %s\n", glGetString(GL_VERSION));

    glClearColor(0.0f, 0.5f, 0.5f, 0.0f);
    CreateShaders();
    CreateVBO();
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
    glutIdleFunc(IdleFunction);
    glutTimerFunc(0, TimerFunction, 0);
    glutCloseFunc(Cleanup);
}

void ResizeFunction(int width, int height) {
    currentWidth = width;
    currentHeight = height;
    glViewport(0, 0, currentWidth, currentHeight);
}

void RenderFunction(void) {
    FrameCount++;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    glutSwapBuffers();
    glutPostRedisplay();
}

void TimerFunction(int value) {
    if (value != 0) {
        // FPS Counter in titlebar
        char* tempTitle = (char*) malloc(
            512 + strlen(WINDOW_TITLE_PREFIX)
        );

        sprintf(
            tempTitle,
            "%s: %d FPS @ %d * %d",
            WINDOW_TITLE_PREFIX,
            FrameCount * 4,
            currentWidth,
            currentHeight
        );

        glutSetWindowTitle(tempTitle);
        free(tempTitle);
    }

    FrameCount = 0;
    glutTimerFunc(250, TimerFunction, 1);
}

void IdleFunction(void) {
    glutPostRedisplay();
}