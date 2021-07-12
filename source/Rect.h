#pragma once
#include "Object.h"
#include <iostream>


class Rect: public Object
{
private:
	float m_Width, m_Height;

public:
	Rect(int ID, float X, float Y, float W, float H, float V);
	~Rect();
	void Render();
	void Update(float deltaTime);
	void Impulse(float deltaTime);
	bool CheckIsClicked(float X, float Y);

	float GetWidth();
	float GetHeight();

};

