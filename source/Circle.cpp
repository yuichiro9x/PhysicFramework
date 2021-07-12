#include "Circle.h"



Circle::Circle(int ID, float X, float Y, float Radius, float Velocity) : Object(ID, X, Y, Velocity)
{
	type = 2;
	m_Radius = Radius;
	AddForce(0, 0);
	SetIsFalling(true);
	std::cout<<"Circle Created! \n";
}


Circle::~Circle()
{
	std::cout<<"Circle deleted! \n";
}

void Circle::Update(float deltaTime) {
	Impulse(deltaTime);
}

void Circle::Render() {
	VideoDriver::GetInstance()->DrawCircle(GetPositionX(), GetPositionY(), m_Radius);
}


bool Circle::CheckIsClicked(float X, float Y) {
	if (m_Radius > sqrt((X - GetPositionX())*(X - GetPositionX()) + (Y - GetPositionY())*(Y - GetPositionY()))) {
		SetIsClicked(true);
		return true;
	}
	return false;
}

void Circle::Impulse(float deltaTime) {
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