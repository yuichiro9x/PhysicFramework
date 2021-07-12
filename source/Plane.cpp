#include "Plane.h"



Plane::Plane(int ID, float X1, float Y1, float X2, float Y2) : Object(ID, X1, Y1)
{
	type = 0;
	x2 = X2;
	y2 = Y2;
	this->SetIsFalling(false);
	std::cout<<"Plane Created! \n";
}


Plane::~Plane()
{
	std::cout<<"Plane deleted! \n";
}

void Plane::Update(float deltaTime) {

}

void Plane::Render() {
	VideoDriver::GetInstance()->DrawLine(GetPositionX(), GetPositionY(), x2, y2);
}
