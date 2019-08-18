///////////////////////////////////////////////////////////
//  Rectangle.h
//  Implementation of the Class Rectangle
//  Created on:      17-Aug-2019 22:53:37
///////////////////////////////////////////////////////////

#if !defined(EA_A9CF483F_1696_4ad6_90FB_C5A776F630DA__INCLUDED_)
#define EA_A9CF483F_1696_4ad6_90FB_C5A776F630DA__INCLUDED_

#include "IShape.h"

class Rectangle : public IShape
{

public:
	Rectangle(double length, double width);
	virtual ~Rectangle();

	void Accept(IVisitor& v);
	double Length();
	double Width();

protected:
	double mLength;
	double mWidth;

};
#endif // !defined(EA_A9CF483F_1696_4ad6_90FB_C5A776F630DA__INCLUDED_)
