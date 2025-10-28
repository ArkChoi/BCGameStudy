#pragma once
#include "SceneComponent.h"
#include "SDL3/SDL.h"

class UPaperFillpbookComponent : public USceneComponent
{
public:
	UPaperFillpbookComponent();
	virtual ~UPaperFillpbookComponent();

	virtual void Tick() override;
	virtual void Render() override;

	__forceinline char GetShape()
	{
		return Shape;
	}

	void SetShape(char Temp)
	{
		Shape = Temp;
	}

	__forceinline int GetZOrder() const
	{
		return ZOrder;
	}

	SDL_Color Color = { 255, 255, 255, 255 };
	int ZOrder;
	char Shape;
};

