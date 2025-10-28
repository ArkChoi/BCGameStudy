#include "Goal.h"
#include "PaperFillpbookComponent.h"

AGoal::AGoal()
{
	//ZOrder = 1;
	//Color = { 255,255,0,0 };

	UPaperFillpbookComponent* Paper = new UPaperFillpbookComponent();
	Paper->SetShape('G');
	Paper->SetOwner(this);
	Paper->ZOrder = 1;
	Paper->Color = { 255,255,0,0 };
	AddComponent(Paper);
}

AGoal::~AGoal()
{
}
