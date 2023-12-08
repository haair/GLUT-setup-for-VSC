#include <GL/freeglut.h>
#include <vector>

struct Point
{
    int x;
    int y;
};

int fact(int n)
{
    if (n == 0)
        return 1;
    else
        return n * fact(n - 1);
}

float power(float a, int n)
{
    if (n == 0)
        return 1;
    else
        return a * power(a, n - 1);
}

float BernStein(float t, int n, int k)
{
    float ckn, kq;
    ckn = fact(n) / (fact(k) * fact(n - k));
    kq = ckn * power(1 - t, n - k) * power(t, k);
    return kq;
}

Point TPt(std::vector<Point> vPoint, float t, int n)
{
    Point point;
    float B;
    int k;

    point.x = 0;
    point.y = 0;

    for (k = 0; k <= n; k++)
    {
        B = BernStein(t, n, k);
        point.x = point.x + vPoint[k].x * B;
        point.y = point.y + vPoint[k].y * B;
    }
    return point;
}

void DrawBezier(int n, std::vector<Point> vPoint)
{
    Point point;
    float dt;
    float t;
    float m;

    int i;
    t = 0;
    m = 100;
    dt = 1 / m;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(2.0f);

    glBegin(GL_LINE_STRIP);

    glVertex2i(vPoint[0].x, vPoint[0].y);
    for (i = 1; i <= m; i++)
    {
        point = TPt(vPoint, t, n);
        glVertex2i(point.x, point.y);
        t = t + dt;
    }
    glVertex2i(vPoint[n].x, vPoint[n].y);
    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    std::vector<Point> vPoint = {{1, 2}, {2, 4}, {3, 5}};
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bezier Curve Example");
    glutDisplayFunc(DrawBezier(3, vPoint));
    glutMainLoop();
    return 0;
}
