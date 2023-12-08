#include <GL/freeglut.h>
#include <cmath>

// Function to draw the graph
void drawGraph()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the color for the graph lines
    glColor3f(1.0f, 1.0f, 1.0f);

    // Set the line width
    glLineWidth(5.0f);

    // Start drawing the graph lines
    glBegin(GL_LINE_STRIP);

    // Define the range and step size for x
    float xMin = -1.0f;
    float xMax = 1.0f;
    float xStep = 0.01f;

    // Calculate and draw the graph points
    for (float x = xMin; x <= xMax; x += xStep)
    {
        float y = pow(x, 3);
        glVertex2f(x, y);
    }

    // End drawing the graph lines
    glEnd();

    // Swap the buffers to display the graph
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    // Initialize the glut library
    glutInit(&argc, argv);

    // Set the display mode
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    // Set the window size
    glutInitWindowSize(800, 600);

    // Create the window with a title
    glutCreateWindow("Cubic Graph");

    // Set the display function
    glutDisplayFunc(drawGraph);

    // Enter the glut main loop
    glutMainLoop();

    return 0;
}