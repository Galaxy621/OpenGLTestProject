#include <GL/glew.h>
#include <GL/freeglut.h>

#include "render.h"

int main(int argc, char* argv[]) {
    Initialise(argc, argv);
    glutMainLoop();
    exit(EXIT_SUCCESS);
}