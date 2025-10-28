#include "Wall.h"
#include "PaperFillpbookComponent.h"
#include "CollsionComponent.h"

AWall::AWall()
{
	//ZOrder = 1;
	//bIsCollision = true;
	//bIsOverlap = false;
	//Color = { 200,200,200,0 };

	UCollsionComponent* Collision = new UCollsionComponent();
	Collision->SetOwner(this);
	Collision->bIsCollision = true;
	Collision->bIsOverlap = false;
	SetupAttachment(Collision);

	UPaperFillpbookComponent* Paper = new UPaperFillpbookComponent();
	Paper->SetShape('*');
	Paper->SetOwner(this);
	Paper->ZOrder = 1;
	Paper->Color = { 200,200,200,0 };
	SetupAttachment(Paper);
}

AWall::~AWall()
{
}
