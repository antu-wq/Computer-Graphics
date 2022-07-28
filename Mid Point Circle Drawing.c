#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
float x=0,y,x2,y2,a,b,c,w;
int dx=0,dy=0,r;
void display(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glEnd();

    glColor3f (0.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    w=1-r;
    while((x<=y)){
        if(w<0){
          x=x+1;
          y=y;
            printf("%0.2f %0.2f\n",x,y);
            w=w+(2*x)+1;
            }


            else{
            x=x+1;
            y=y-1;
            printf("%0.2f %0.2f\n",x,y);
            w=w+(2*x)+1-(2*y);
            }
            glVertex3f (((x/100)), ((y/100)), 0.0);
            glVertex3f (((y/100)), ((x/100)), 0.0);
            glVertex3f ((-(x/100)), (-(y/100)), 0.0);
            glVertex3f ((-(x/100)), ((y/100)), 0.0);
            glVertex3f (((x/100)), (-(y/100)), 0.0);
            glVertex3f (((y/100)), (-(x/100)), 0.0);
            glVertex3f ((-(y/100)), (-(x/100)), 0.0);
            glVertex3f ((-(y/100)), ((x/100)), 0.0);
        }
glEnd();

glFlush ();
}
void init (void)
{
glClearColor (0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{

    printf("Enter radius: ");
    scanf("%d",&r);
    y=r;
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100, 100);
glutCreateWindow ("Midpoint Circle Drawing Algorithm");
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
