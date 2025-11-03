#pragma once
#include "SceneComponent.h"
#include "SDL3/SDL.h"

#include <string>

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

	void LoadBMP(std::string Filename);

	SDL_Color Color = { 255, 255, 255, 255 };
	SDL_Surface* BitmapImage = nullptr;
	SDL_Texture* Texture = nullptr;//GPU 건들기 위해 만듬 | 대부분이런 작업을 거펴야 한다고.

	int ZOrder;
	char Shape;
};

