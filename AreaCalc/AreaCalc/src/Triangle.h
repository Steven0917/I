///////////////////////////////////////////////////////////
//  Triangle.h
//  Implementation of the Class Triangle
//  Created on:      17-Aug-2019 22:53:37
///////////////////////////////////////////////////////////

#if !defined(EA_02AFC572_C2A4_4ad7_A330_F02C3B96DBE6__INCLUDED_)
#define EA_02AFC572_C2A4_4ad7_A330_F02C3B96DBE6__INCLUDED_

#include "IShape.h"

class Triangle : public IShape
{

public:
	Triangle(double a, double b, double c);
	virtual ~Triangle();

	void Accept(IVisitor& v);
	double EdgeA();
	double EdgeB();
	double EdgeC();

protected:
	double mEdgeA;
	double mEdgeB;
	double mEdgeC;

};
#endif // !defined(EA_02AFC572_C2A4_4ad7_A330_F02C3B96DBE6__INCLUDED_)
