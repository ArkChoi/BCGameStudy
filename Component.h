#pragma once
class AActor;

class UComponent
{
public:
	UComponent();
	virtual ~UComponent();

	//순수 가상함수 | 자식이 무조건 재정의 해야하는 함수 | interface 처럼 구현
	virtual void Tick() = 0; 

	AActor* GetOwner() const;
	void SetOwner(AActor* InOwner);

protected:
	AActor* Owner;
};

