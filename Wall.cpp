#include "Wall.h"
#include "PaperFillpbookComponent.h"

AWall::AWall()
{
	//ZOrder = 1;
	bIsCollision = true;
	bIsOverlap = false;
	//Color = { 200,200,200,0 };

	UPaperFillpbookComponent* Paper = new UPaperFillpbookComponent();
	Paper->SetShape('*');
	Paper->SetOwner(this);
	Paper->ZOrder = 1;
	Paper->Color = { 200,200,200,0 };
	AddComponent(Paper);
}

AWall::~AWall()
{
}
