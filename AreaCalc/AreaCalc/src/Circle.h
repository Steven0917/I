///////////////////////////////////////////////////////////
//  Circle.h
//  Implementation of the Class Circle
//  Created on:      17-Aug-2019 22:53:36
///////////////////////////////////////////////////////////

#if !defined(EA_8DF3018A_A47A_4f3f_9A89_1D12E5329EC9__INCLUDED_)
#define EA_8DF3018A_A47A_4f3f_9A89_1D12E5329EC9__INCLUDED_

#include "IShape.h"

class Circle : public IShape
{

public:
	Circle(double r);
	virtual ~Circle();

	void Accept(IVisitor& v);
	double Radius();

protected:
	double mRadius;

};
#endif // !defined(EA_8DF3018A_A47A_4f3f_9A89_1D12E5329EC9__INCLUDED_)
