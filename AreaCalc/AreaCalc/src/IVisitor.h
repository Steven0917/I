///////////////////////////////////////////////////////////
//  IVisitor.h
//  Implementation of the Interface IVisitor
//  Created on:      17-Aug-2019 22:53:36
///////////////////////////////////////////////////////////

#if !defined(EA_51A3A0F6_7B09_4ea9_BE97_C4A7D431F20C__INCLUDED_)
#define EA_51A3A0F6_7B09_4ea9_BE97_C4A7D431F20C__INCLUDED_

#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

class IVisitor
{

public:
	IVisitor() {

	}

	virtual ~IVisitor() {

	}

	virtual double Visit(Circle& c) = 0;
	virtual double Visit(Rectangle& r) = 0;
	virtual double Visit(Triangle& t) = 0;

};
#endif // !defined(EA_51A3A0F6_7B09_4ea9_BE97_C4A7D431F20C__INCLUDED_)
