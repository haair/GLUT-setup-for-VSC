#include <GL/freeglut.h>
#include <cmath>

// Function to draw the face
void drawFace()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the face outline
    glBegin(GL_LINE_LOOP);
    glColor3f(0.0, 0.0, 0.0); // Black color
    for (int i = 0; i <= 360; ++i)
    {
        float angle = i * M_PI / 180.0;
        float x = 0.5 * cos(angle);
        float y = 0.5 * sin(angle);
        glVertex2f(x, y);
    }
    glEnd();

    // Draw the eyes
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0); // Red color
    glVertex2f(-0.2, 0.2);    // Left eye
    glVertex2f(0.2, 0.2);     // Right eye
    glEnd();

    // Draw the mouth
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 1.0); // Blue color
    glVertex2f(-0.2, -0.2);
    glVertex2f(0.2, -0.2);
    glEnd();

    glFlush();
}

// Function to handle window resizing
void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Curve Face");

    glutDisplayFunc(drawFace);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}