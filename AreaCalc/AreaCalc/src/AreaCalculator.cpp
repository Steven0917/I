///////////////////////////////////////////////////////////
//  AreaCalculator.cpp
//  Implementation of the Class AreaCalculator
//  Created on:      17-Aug-2019 22:53:36
///////////////////////////////////////////////////////////

#include "AreaCalculator.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "AreaVisitor.h"

int main(int argc, char *argv[])
{
	Circle    c(2.7);
	Triangle  t(3, 4, 5);
	Rectangle r(6, 8);
	AreaVisitor visitor;

	c.Accept(visitor);
	t.Accept(visitor);
	r.Accept(visitor);

	return 0;
}