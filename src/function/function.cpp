#include "function.hpp"

#include "glh.h"

void Function::plot() const
{
	float x = x0;
	float dx = (xn - x0) / n;
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < n; ++i) {
		float y = f(x);
		glVertex2f(x, y);
		x += dx;
	}
	glEnd();
}