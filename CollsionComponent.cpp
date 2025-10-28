#include "CollsionComponent.h"
#include "Actor.h"

UCollsionComponent::UCollsionComponent()
{
}

UCollsionComponent::~UCollsionComponent()
{
}

bool UCollsionComponent::CheakCollsion(const UCollsionComponent* Other)
{
	if (Other->bIsOverlap)
	{
		return false;
	}

	if (this != Other && Other->bIsCollision && bIsCollision
		&& this->GetOwner()->GetActorLocation() == Other->GetOwner()->GetActorLocation())
	{
		return true;
	}
	return false;
}