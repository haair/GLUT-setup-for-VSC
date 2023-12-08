#include <GL/freeglut.h>
#include <cmath>

const float PI = 3.14159265359f;
const int segments = 50;
const float height = 1.0f;
const float radius = 0.5f;

void drawCylinder() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);

    // Draw the top circle
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f, height / 2.0f, 0.0f);
    for (int i = 0; i <= segments; ++i) {
        float theta = static_cast<float>(i) / segments * 2.0f * PI;
        float x = radius * std::cos(theta);
        float z = radius * std::sin(theta);
        glVertex3f(x, height / 2.0f, z);
    }
    glEnd();

    // Draw the bottom circle
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0f, -height / 2.0f, 0.0f);
    for (int i = 0; i <= segments; ++i) {
        float theta = static_cast<float>(i) / segments * 2.0f * PI;
        float x = radius * std::cos(theta);
        float z = radius * std::sin(theta);
        glVertex3f(x, -height / 2.0f, z);
    }
    glEnd();

    // Draw the side surface
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= segments; ++i) {
        float theta = static_cast<float>(i) / segments * 2.0f * PI;
        float x = radius * std::cos(theta);
        float z = radius * std::sin(theta);

        glVertex3f(x, height / 2.0f, z);
        glVertex3f(x, -height / 2.0f, z);
    }
    glEnd();

    glFlush();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, static_cast<double>(width) / height, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Cylinder Example");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(drawCylinder);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}