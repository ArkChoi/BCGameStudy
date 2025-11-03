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
	SDL_Color ColorKey = { 255, 0, 255, 255}; //요상한 색갈이라 날려버리는 용도로 주로 사용하는 값이라고 함

	bool bAnimation = false;
	float TotalTime = 0.0f;

	float SpriteCountX = 5;
	float SpriteCountY = 5;
	float XIndex = 0;
	float YIndex = 0;

	int ZOrder;
	char Shape;

	int SizeX = 60;
	int SizeY = 60;

protected:
	float ExecuteTime = 0.2f;
};

