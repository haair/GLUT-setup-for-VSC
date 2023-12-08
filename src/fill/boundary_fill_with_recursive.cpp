#include <iostream>
#include <GL/freeglut.h>

int width = 500;
int height = 500;

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, width, 0, height);
}

void boundaryFill(int x, int y, float fillColor[3], float borderColor[3]) {
    float currentColor[3];
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, currentColor);

    if (currentColor[0] != borderColor[0] || currentColor[1] != borderColor[1] || currentColor[2] != borderColor[2]) {
        if (currentColor[0] != fillColor[0] || currentColor[1] != fillColor[1] || currentColor[2] != fillColor[2]) {
            glColor3fv(fillColor);
            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
            glFlush();

            boundaryFill(x + 1, y, fillColor, borderColor);
            boundaryFill(x - 1, y, fillColor, borderColor);
            boundaryFill(x, y + 1, fillColor, borderColor);
            boundaryFill(x, y - 1, fillColor, borderColor);
        }
    }
}

void drawBoundary(int x, int y, int width, int height) {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the boundary
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(x, y);
    glVertex2i(x + width, y);
    glVertex2i(x + width, y + height);
    glVertex2i(x, y + height);
    glEnd();
}

void display() {
    drawBoundary(1, 1, 100, 150);    

    // Call boundary fill algorithm
    float fillColor[3] = {0.0, 0.0, 1.0}; // Red color
    float borderColor[3] = {1.0, 1.0, 1.0}; // White color
    boundaryFill(150, 150, fillColor, borderColor);

    glFlush();
}



int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("Boundary Fill Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}