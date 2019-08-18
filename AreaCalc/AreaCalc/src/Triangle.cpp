///////////////////////////////////////////////////////////
//  Triangle.cpp
//  Implementation of the Class Triangle
//  Created on:      17-Aug-2019 22:53:37
///////////////////////////////////////////////////////////

#include "Triangle.h"
#include "IVisitor.h"
#include <iostream>

Triangle::Triangle(double a, double b, double c)
	: mEdgeA(a), mEdgeB(b), mEdgeC(c)
{
}



Triangle::~Triangle()
{
}


void Triangle::Accept(IVisitor& v)
{
	std::cout << v.Visit(*this) << std::endl;
}


double Triangle::EdgeA()
{
	return mEdgeA;
}


double Triangle::EdgeB()
{
	return mEdgeB;
}


double Triangle::EdgeC()
{
	return mEdgeC;
}