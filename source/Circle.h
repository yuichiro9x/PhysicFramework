#pragma once
#include "Object.h"
#include <iostream>


class Circle: public Object
{
private:
	float m_Radius;

public:
	Circle(int ID, float X, float Y, float Radius, float Velocity);
	~Circle();
	void Render();
	void Update(float deltaTime);
	void Impulse(float deltaTime);
	bool CheckIsClicked(float X, float Y);

	inline float GetRadius() { return m_Radius; };
	inline void SetRadius(float R) { m_Radius = R; }	

};

