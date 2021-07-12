#pragma once
#include "Object.h"
#include <iostream>


class Plane : public Object
{
private:
	float x2, y2;

public:
	Plane(int ID, float X1, float Y1, float X2, float Y2);
	~Plane();
	void Render();
	void Update(float deltaTime);
	bool CheckIsClicked(float X, float Y){return false;}

	float GetPositionX2() { return x2; };
	float GetPositionY2() { return y2; };

};

