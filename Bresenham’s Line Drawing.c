/*
	North East University Bangladesh
	Shib Prosad Roy
	ID:190303020013
	8th semester
	dept: Bsc(Engg:) in CSE
*/
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
float x1,y1,x2,y2,a,b,c,w;
int dx=0,dy=0;
void display(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glEnd();

    glColor3f (0.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    w=(2*dy)-dx;
    for(b=x1,c=y1;b<=x2,c<=y2; ){
        if(w>=0){
            b=b+1;
            c=c+1;
            if((b>x2)||(c>y2)){
                break;
            }
            printf("%0.2f %0.2f\n",b,c);
            glVertex3f ((b/100), (c/100), 0.0);
            w=w+(2*dy)-(2*dx);
            }
            else if(w<0){
            b=b+1;
            if((b>x2)||(c>y2)){
                break;
            }
            printf("%0.2f %0.2f\n",b,c);
            glVertex3f ((b/100), (c/100), 0.0);
            w=w+(2*dy);
            }
        }
glEnd();
glFlush ();
}
void init (void)
{
glClearColor (0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
int main(int argc, char** argv)
{

    printf("Enter first point: ");
    scanf("%f %f",&x1,&y1);
    printf("Enter second point: ");
    scanf("%f %f",&x2,&y2);
    dx=x2-x1;
    dy=y2-y1;
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100, 100);
glutCreateWindow ("Bresenham Line Drawing Algorithm");
init ();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
