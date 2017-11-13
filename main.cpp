//#include <stdio.h>
#include <glut.h>

//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	glPushMatrix();
//	glTranslatef(0, 0, 0);
//	glutSolidSphere(1.0, 50, 50);
//	glPopMatrix();
//
//	glMatrixMode(GL_MODELVIEW);
//
//	glutSwapBuffers();
//
//	glutPostRedisplay();
//}
//
//void resize(int width, int height)
//{
//	const float ar = (float)width / (float)height;
//
//	glViewport(0, 0, width, height);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//
//int main(int argc, char *argv[])
//{
//	const GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };
//	const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
//	const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
//	const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };
//
//	const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f };
//	const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
//	const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
//	const GLfloat high_shininess[] = { 100.0f };
//
//	glutInit(&argc, argv);
//	glutInitWindowSize(640, 480);
//	glutInitWindowPosition(10, 10);
//	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
//
//	glutCreateWindow("planet");
//
//	glutDisplayFunc(display);
//	glutReshapeFunc(resize);
//
//	glClearColor(0, 0, 0, 0);
//	glEnable(GL_CULL_FACE);
//	glCullFace(GL_FRONT);
//
//	glEnable(GL_DEPTH_TEST);
//	glDepthFunc(GL_LESS);
//
//	glEnable(GL_LIGHT0);
//	glEnable(GL_NORMALIZE);
//	glEnable(GL_COLOR_MATERIAL);
//	glEnable(GL_LIGHTING);
//
//	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
//	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
//	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
//
//	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
//
//	glutMainLoop();
//
//	return 0;
//}

GLfloat rotated = 0;
 
void redisplayFunc(void)
{
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
 
	glTranslatef(0, 0, -4);
	glColor3f(0, 2, 1);
	glRotatef(rotated, 10, 0, 0);
	glRotatef(rotated, 0, 10, 0);
	glRotatef(rotated, 0, 0, 10);
	glScalef(0.3, 0.3, 0.3);
	glutWireSphere(2, 100, 100);
 
	glLoadIdentity();
	glTranslatef(0, 0, -4);
	glColor3f(1, 0, 0);
	glRotatef(rotated, 10, 0, 0);
	glRotatef(rotated, 0, 10, 0);
	glRotatef(rotated, 0, 0, 10);
	glScalef(0.3, 0.3, 0.3);
	glutSolidSphere(3, 10, 10);


	glFlush();
}
 
void reshapeFunc(int x, int y)
{
	//if (y == 0 || x == 0) return;  //Nothing is visible then, so return
	//Set a new projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
 
	gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, x, y);  //Use the whole window for rendering
}
 
void idleFunc(void)
{
	rotated += 0.05;
 
	redisplayFunc();
}
 
 
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 500);

	glutCreateWindow("Sphere");
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
 
	glClearColor(0.0, 0.0, 0.0, 0.0);

	glutDisplayFunc(redisplayFunc);
	glutReshapeFunc(reshapeFunc);
	glutIdleFunc(idleFunc);

	glutMainLoop();
	return 0;
}