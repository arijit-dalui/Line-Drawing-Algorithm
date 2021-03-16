#include<windows.h>
#include<GL/glut.h>
#include <stdlib.h>
#include<iostream>
#include <math.h>
using namespace std;
static HWND sHwnd;



void init (void)
{
glClearColor (1.0, 1.0, 1.0, 0.0);
glMatrixMode (GL_PROJECTION);
gluOrtho2D (0.0, 200.0, 0.0, 150.0);
}

void SetWindowHandle(HWND hwnd)
{
    sHwnd=hwnd;
}


int round (float a)
{ return int (a + 0.5); }

void lineDDAalgo (int x0, int y0, int xEnd, int yEnd)
{
     int dx = xEnd - x0, dy = yEnd - y0, steps, k;
     float xIncrement, yIncrement, x = x0, y = y0;

       if (fabs (dx) > fabs (dy))
          steps = fabs (dx);

       else
       steps = fabs (dy);

       xIncrement = float (dx) / float (steps);
       yIncrement = float (dy) / float (steps);
       HDC hdc=GetDC(sHwnd);
       SetPixel(hdc,round (x), round (y),RGB(255,0,0));

      for (k = 0; k < steps; k++) {
       x += xIncrement;
       y += yIncrement;
       HDC hdc=GetDC(sHwnd);
       SetPixel(hdc,round (x), round (y),RGB(255,0,0));}
}

int main(int argc,char **argv)
{
  cout<<"Enter starting point";
  int xs,ys,xe,ye;
  cin>>xs>>ys;
  cout<<"Enter ending point";
  cin>>xe>>ye;
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(50,100);
  glutInitWindowSize(400,300);
  glutCreateWindow("DDA Algorithm");
  glutDisplayFunc(lineDDAalgo(xs,ys,xe,ye));
  init();
  glutMainLoop();
}
