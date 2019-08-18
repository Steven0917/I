///////////////////////////////////////////////////////////
//  AreaVisitor.cpp
//  Implementation of the Class AreaVisitor
//  Created on:      17-Aug-2019 22:53:36
///////////////////////////////////////////////////////////

#include "AreaVisitor.h"
#include <cmath>
#define PI 3.14

AreaVisitor::AreaVisitor()
{
}

AreaVisitor::~AreaVisitor()
{
}

double AreaVisitor::Visit(Circle& c)
{
	return PI * c.Radius() * c.Radius();
}

double AreaVisitor::Visit(Rectangle& r)
{
	return r.Width() * r.Length();
}

double AreaVisitor::Visit(Triangle& t)
{
	double a = t.EdgeA();
	double b = t.EdgeB();
	double c = t.EdgeC();
	double p = (a + b + c) / 2;

	return sqrt(p * (p - a) * (p - b) * (p - c));
}