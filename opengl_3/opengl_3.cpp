#include <Windows.h>
#include <tchar.h>
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib,"glut32.lib")
#include "glut.h"
#include <stdlib.h>
#include <cmath>

void setPixel(int x, int y) {
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void linesBrasenhem(int x0, int y0, int xend, int yend) {
    int dx = abs(xend - x0), dy = abs(yend - y0);
    int p = 2 * dy - dx;
    int x, y;
    if (x0 > xend) {
        x = xend;
        y = yend;
        xend = x0;
    }
    else
    {
        x = x0;
        y = y0;
    }
    setPixel(x, y);

    while (x < xend) {
        x++;
        if (p < 0)
            p += 2 * dy;
        else
        {
            y++;
            p += 2 * (dy - dx);
        }
        setPixel(x, y);
    }
}

void _display(void)
{

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Пример ");
    glutDisplayFunc(_display);
    glutMainLoop();
}
