#include "Floor.h"
#include "PaperFillpbookComponent.h"
#include "CollsionComponent.h"

AFloor::AFloor()
{
	//ZOrder = 0;
	//bIsCollision = false;
	//Color = {255,255,255,0};

	UCollsionComponent* Collision = new UCollsionComponent();
	Collision->bIsCollision = false;
	Collision->bIsOverlap = false;

	UPaperFillpbookComponent* Paper = new UPaperFillpbookComponent();
	Paper->SetShape(' ');
	Paper->SetOwner(this);
	Paper->ZOrder = 0;
	Paper->Color = { 255,255,255,0 };
	SetupAttachment(Paper);
}

AFloor::~AFloor()
{
}
