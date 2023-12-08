#include <GL/freeglut.h>
#include <cmath>
#include <vector>
#include <iostream>

// Function to draw a point
void drawPoint(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

// Midpoint algorithm for drawing a line
void drawLine(int x1, int y1, int x2, int y2)
{
    int dx = std::abs(x2 - x1);
    int dy = std::abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true)
    {
        drawPoint(x1, y1);

        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

// Function to draw a curve using the Midpoint Algorithm
void drawCurve(const std::vector<int>& x, const std::vector<int>& y)
{
    int n = x.size();
    for (int i = 0; i < n - 1; i++)
    {
        drawLine(x[i], y[i], x[i + 1], y[i + 1]);
    }
}

int f(int x) {
    return pow(x, 3) - 3*pow(x, 2) - 4;
}

// Display callback function
void display()
{

    std::vector<int> x;
    std::vector<int> y;
    glClear(GL_COLOR_BUFFER_BIT);

    for (int i = -10; i <= 10; i++) {
        x.push_back(i);
        y.push_back(f(i));
    }

    drawCurve(x, y);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Curve using Midpoint Algorithm");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(-800, 800, -600, 600);
    glutDisplayFunc(display);
    glutMainLoop();
    // std::cout << f(2);
    return 0;
}