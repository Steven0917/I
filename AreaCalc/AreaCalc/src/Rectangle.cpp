///////////////////////////////////////////////////////////
//  Rectangle.cpp
//  Implementation of the Class Rectangle
//  Created on:      17-Aug-2019 22:53:37
///////////////////////////////////////////////////////////

#include "Rectangle.h"
#include "IVisitor.h"
#include <iostream>

Rectangle::Rectangle(double length, double width)
	: mLength(length), mWidth(width)
{
}

Rectangle::~Rectangle()
{
}

void Rectangle::Accept(IVisitor& v)
{
	std::cout << v.Visit(*this) << std::endl;
}


double Rectangle::Length()
{
	return mLength;
}


double Rectangle::Width()
{
	return mWidth;
}