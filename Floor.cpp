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

	Flipbook = new UPaperFillpbookComponent();
	Flipbook->SetShape(' ');
	Flipbook->SetOwner(this);
	Flipbook->ZOrder = 0;
	Flipbook->Color = { 255,255,255,0 };
	SetupAttachment(Flipbook);
}

AFloor::~AFloor()
{
}
