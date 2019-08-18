///////////////////////////////////////////////////////////
//  IShape.h
//  Implementation of the Interface IShape
//  Created on:      17-Aug-2019 22:53:36
///////////////////////////////////////////////////////////

#if !defined(EA_4F6445D1_06C4_47b5_AF11_FBCDE306BD22__INCLUDED_)
#define EA_4F6445D1_06C4_47b5_AF11_FBCDE306BD22__INCLUDED_

class IVisitor;
class IShape
{

public:
	IShape() {

	}

	virtual ~IShape() {

	}

	virtual void Accept(IVisitor& visitor) = 0;

};
#endif // !defined(EA_4F6445D1_06C4_47b5_AF11_FBCDE306BD22__INCLUDED_)
