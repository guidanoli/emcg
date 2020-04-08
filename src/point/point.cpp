#include "glh.h"

void display_function()
{
	glClearColor(0, 0, 0, 0); // Set the color used by glClear to space dark

	glClear(GL_COLOR_BUFFER_BIT); // Clear buffer with the clear color

	glColor3f(0, 0.467f, 0.745f); // Sets the current color to ocean blue

	glBegin(GL_POINTS);     // Start plotting points
		glVertex2f(0, 0);   // Plot a point at the origin
	glEnd();                // Stop plotting points

	glutSwapBuffers(); // Refresh the buffer
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv); // Initialize toolkit

	glutInitDisplayMode(GLUT_RGBA |    // RGBA mode
	                    GLUT_DOUBLE);  // Double buffered

	glutInitWindowSize(640, 480); // Set window size

	glutInitWindowPosition(10, 10); // Set window initial position

	glutCreateWindow("Pale Blue Dot"); // Create window with a title

	gluOrtho2D(-1, 1, -1, 1); // Define the orthographic 2d projection matrix
							  // In other words, sets '-1' as the far left,
							  //                      '1' as the far right,
							  //                      '-1' as the far bottom,
							  //                  and '1' as the far top.

	glutDisplayFunc(display_function); // Register display function

	glutMainLoop(); // Call the main loop

	return 0;
}