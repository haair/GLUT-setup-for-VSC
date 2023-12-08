#include <GL/freeglut.h>
#include <cmath>
#include <vector>

struct Point
{
    float x;
    float y;
};

std::vector<Point> controlPoints; // Control points for the Bezier curve

// Calculate the value of n choose k
int binomialCoefficient(int n, int k)
{
    if (k == 0 || k == n)
    {
        return 1;
    }
    return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
}

// Calculate the point on the Bezier curve at parameter t
Point calculateBezierPoint(float t)
{
    int n = controlPoints.size() - 1;
    Point point = {0, 0};

    for (int i = 0; i <= n; i++)
    {
        float coefficient = binomialCoefficient(n, i) * std::pow(t, i) * std::pow(1 - t, n - i);
        point.x += controlPoints[i].x * coefficient;
        point.y += controlPoints[i].y * coefficient;
    }

    return point;
}

void drawBezierCurve()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(2.0f);

    glBegin(GL_LINE_STRIP);
    for (float t = 0.0f; t <= 1.0f; t += 0.01f)
    {
        Point point = calculateBezierPoint(t);
        glVertex2f(point.x, point.y);
    }
    glEnd();

    glFlush();
}

void mouseClick(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        float normalizedX = static_cast<float>(x) / glutGet(GLUT_WINDOW_WIDTH);
        float normalizedY = 1.0f - static_cast<float>(y) / glutGet(GLUT_WINDOW_HEIGHT);

        Point controlPoint = {normalizedX, normalizedY};
        controlPoints.push_back(controlPoint);

        glutPostRedisplay();
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Bezier Curve Example");
    glutDisplayFunc(drawBezierCurve);
    glutMouseFunc(mouseClick);
    glutMainLoop();
    return 0;
}