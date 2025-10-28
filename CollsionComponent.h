#pragma once
#include "SceneComponent.h"
class AActor;

class UCollsionComponent : public USceneComponent
{
public:
	UCollsionComponent();
	virtual ~UCollsionComponent();

	bool CheakCollsion(const UCollsionComponent* Ohter); //지금은 틱에서 체크하는 충돌처리 엔진은 완전히 다르다.

	bool bIsCollision = false; //충돌감지를 위한 변수 | 본래는 protected 이 맞다만.. 함수 만들기 싫어서 넘긴다고.
	bool bIsOverlap = true;   //현실에는 없다만 동전이랑 충돌해서 못 먹을 수는 없으니 생긴 개념

};

