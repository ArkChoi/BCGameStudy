#include "Wall.h"

AWall::AWall()
{
	ZOrder = 1;
	bIsCollision = true;
	bIsOverlap = false;
	Color = { 200,200,200,0 };
}

AWall::~AWall()
{
}
