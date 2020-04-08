#include <cassert>
#include <cstddef>
#include <cmath>
#include <functional>
#include <iostream>
#include <memory>
#include <string>

#include "glh.h"
#include "function.hpp"

struct func_info
{
	std::string name;
	std::function<float(float)> f;
};

struct func_info const functions[] = {
	{ "sin", [] (float x) { return sin(x); } },
	{ "x^3", [] (float x) { return x * x * x; } },
	{ "sin * e^-x", [] (float x) { return exp(-x) * sin(x); } },
};

// Function to be plotted
std::unique_ptr<Function> f;

// Plotting parameters
float x0, xn;
float ymin, ymax;
int n;

void draw_axis()
{
	glColor3f(0.5f, 0.5f, 0.5f);
	glBegin(GL_LINES);
	glVertex2f(0, ymin);
	glVertex2f(0, ymax);
	glVertex2f(x0, 0);
	glVertex2f(xn, 0);
	glEnd();
}

void display_function()
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	draw_axis();
	glColor3f(1, 1, 1);
	f->plot();
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	// Choose function

	std::size_t i = 0;
	for (auto const& [name, f] : functions) {
		std::cout << i << ": " << name << std::endl;
		++i;
	}

	std::cout << "Choose a function to plot:" << std::endl;
	std::cout << ">>> ";

	std::size_t choice;
	std::cin >> choice;

	if (choice >= std::size(functions)) {
		std::cout << "Invalid input!" << std::endl;
		return 1;
	}
	
	std::cout << "Initial x: ";
	std::cin >> x0;

	std::cout << "Final x: ";
	std::cin >> xn;

	assert(x0 < xn);

	std::cout << "Low y: ";
	std::cin >> ymin;

	std::cout << "High y: ";
	std::cin >> ymax;

	assert(ymin < ymax);

	std::cout << "#Points: ";
	std::cin >> n;

	assert(n > 0);

	f = std::make_unique<Function>(functions[choice].f, x0, xn, n);

	// Initialize glut

	float ratio = (ymax - ymin) / (xn - x0);
	int width = 680;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA |
	                    GLUT_DOUBLE);
	glutInitWindowSize(width, (int) (width * ratio));
	glutInitWindowPosition(10, 10);
	glutCreateWindow(functions[choice].name.c_str());
	gluOrtho2D(x0, xn, ymin, ymax);
	glutDisplayFunc(display_function);
	glutMainLoop();
	return 0;
}