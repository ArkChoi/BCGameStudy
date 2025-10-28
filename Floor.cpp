#include "Floor.h"
#include "PaperFillpbookComponent.h"

AFloor::AFloor()
{
	//ZOrder = 0;
	bIsCollision = false;
	//Color = {255,255,255,0};

	UPaperFillpbookComponent* Paper = new UPaperFillpbookComponent();
	Paper->SetShape(' ');
	Paper->SetOwner(this);
	Paper->ZOrder = 0;
	Paper->Color = { 255,255,255,0 };
	AddComponent(Paper);
}

AFloor::~AFloor()
{
}
