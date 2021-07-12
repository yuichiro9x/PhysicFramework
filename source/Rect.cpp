#include "Rect.h"



Rect::Rect(int ID, float X, float Y, float W, float H, float V) : Object(ID, X, Y, V)
{
	type =1;
	m_Width = W;
	m_Height = H;
	AddForce(0, 0);
	std::cout<<"Rect Created! \n";
}


Rect::~Rect()
{
	std::cout<<"Rect deleted! \n";
}

void Rect::Render() {
	VideoDriver::GetInstance()->DrawRect(GetPositionX(), GetPositionY(), m_Width, m_Height);
}


void Rect::Update(float deltaTime) {
	Impulse(deltaTime);
}

bool Rect::CheckIsClicked(float X, float Y) {
	if (X > GetPositionX() && X < GetPositionX() + m_Width) {
		if (Y > GetPositionY() && Y < GetPositionY() + m_Height) {
			SetIsClicked(true);
			return true;
		}
	}
	return false;
}


void Rect::Impulse(float deltaTime) {
	if (!GetIsClicked()) {
		MoveObject(GetPositionX() + GetForceX() * 10 / GetMass() * deltaTime, GetPositionY() + ((GetForceY() + GetGravity()) * 10 / GetMass() * deltaTime));
		if (GetForceX() > 1) {
			SetForceX(GetForceX() - 5 * deltaTime);
		}
		else if (GetForceX() < -1) {
			SetForceX(GetForceX() + 5 * deltaTime);
		}
		else SetForceX(0);
		if (GetForceY() > 1) {
			SetForceY(GetForceY() - 5 * deltaTime);
		}
		else if (GetForceY() < -1) {
			SetForceY(GetForceY() + 5 * deltaTime);
		}
		else SetForceY(0);
	}
}

float Rect::GetWidth() {
	return m_Width;
}

float Rect::GetHeight() {
	return m_Height;
}
