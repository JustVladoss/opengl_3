#include <Windows.h>
#include <tchar.h>
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib,"glut32.lib")
#include "glut.h"
#include <stdlib.h>
#include <cmath>

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-20.0, 15.0, -20.0, 15.0);
}

void setPixel(int x, int y) {
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void linesBrasenhem(int x0, int y0, int xend, int yend) {
    int dx = abs(xend - x0), dy = abs(yend - y0), x = x0, y = y0, x_inc, y_inc;
    float tan = float(dy) / float(dx);

    if (yend < y0)
        y_inc = -1;
    else
        y_inc = 1;
    if (xend < x0)
        x_inc = -1;
    else
        x_inc = 1;

    if (tan < 1)
    {
        int p = 2 * (dx - dy);
        setPixel(x, y);
        while (x != xend)
        {
            x += x_inc;
            if (p > 0)
                p -= 2 * dy;
            else
            {
                y += y_inc;
                p += 2 * (dx - dy);
            }
            setPixel(x, y);
        }
    }

    else if (tan > 1)
    {
        int p = 2 * (dy - dx);
        setPixel(x, y);
        while (y != yend)
        {
            y += y_inc;
            if (p > 0)
                p -= 2 * dx;
            else
            {
                x += x_inc;
                p += 2 * (dy - dx);
            }
            setPixel(x, y);
        }
    }

    else
    {
        setPixel(x, y);
        while (y != yend)
        {
            x += x_inc;
            y += y_inc;
            setPixel(x, y);
        }
    }
}

void _display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    linesBrasenhem(-4, 9, 0, 8);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Пример ");
    //fdffdf
    init();
    glutDisplayFunc(_display);
    glutMainLoop();
}
