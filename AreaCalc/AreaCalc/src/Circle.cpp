///////////////////////////////////////////////////////////
//  Circle.cpp
//  Implementation of the Class Circle
//  Created on:      17-Aug-2019 22:53:36
///////////////////////////////////////////////////////////

#include "Circle.h"
#include "IVisitor.h"
#include <iostream>

Circle::Circle(double r): mRadius(r)
{

}


Circle::~Circle()
{

}


void Circle::Accept(IVisitor& v)
{
	std::cout << v.Visit(*this) << std::endl;
}


double Circle::Radius()
{

	return mRadius;
}