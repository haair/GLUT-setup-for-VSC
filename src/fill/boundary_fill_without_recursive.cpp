#include <iostream>
#include <GL/freeglut.h>
#include <vector>

int width = 500;
int height = 500;

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, width, 0, height);
}

void boundaryFill(int x, int y, float fillColor[3], float borderColor[3]) {
    std::vector<std::pair<int, int> > stack;
    stack.push_back(std::make_pair(x, y));

    while (!stack.empty()) {
        std::pair<int, int> currentPixel = stack.back();
        stack.pop_back();

        int currentX = currentPixel.first;
        int currentY = currentPixel.second;

        float currentColor[3];
        glReadPixels(currentX, currentY, 1, 1, GL_RGB, GL_FLOAT, currentColor);

        if (currentColor[0] != borderColor[0] || currentColor[1] != borderColor[1] || currentColor[2] != borderColor[2]) {
            if (currentColor[0] != fillColor[0] || currentColor[1] != fillColor[1] || currentColor[2] != fillColor[2]) {
                glColor3fv(fillColor);
                glBegin(GL_POINTS);
                glVertex2i(currentX, currentY);
                glEnd();
                glFlush();

                stack.push_back(std::make_pair(currentX + 1, currentY));
                stack.push_back(std::make_pair(currentX - 1, currentY));
                stack.push_back(std::make_pair(currentX, currentY + 1));
                stack.push_back(std::make_pair(currentX, currentY - 1));
            }
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the boundary
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(125, 125);
    glVertex2i(375, 125);
    glVertex2i(375, 375);
    glVertex2i(125, 375);
    glEnd();

    // Call boundary fill algorithm
    float fillColor[3] = {1.0, 0.0, 0.0}; // Red color
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