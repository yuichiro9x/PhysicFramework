#include "Object.h"

Object::Object(int ID, float X, float Y)
{
	m_Id = ID;
	m_Pos.x = X;
	m_Pos.y = Y;
	m_Gravity = 0;
}

Object::Object(int ID, float X, float Y, float G)
{
	m_Id = ID;
	m_Pos.x = X;
	m_Pos.y = Y;
	m_Velocity = G;
	m_Gravity = m_Velocity;
}

Object::~Object()
{
}

void Object::MoveObject(float X, float Y) {
	m_Pos.x = X;
	m_Pos.y = Y;
}

void Object::AddForce(float deltaX, float deltaY) {
	m_Force.x = deltaX;
	m_Force.y = deltaY;
}

void Object::SetIsFalling(bool fall) {
	m_bIsFalling = fall;
}

bool Object::GetIsFalling() {
	return m_bIsFalling;
}

bool Object::GetIsClicked() {
	return m_bIsClicked;
}

void Object::SetIsClicked(bool click) {
	m_bIsClicked = click;
}

void  Object::SetPositionX(float X) {
	m_Pos.x = X;
}

void  Object::SetPositionY(float Y) {
	m_Pos.y = Y;
}

float Object::GetPositionX(){
	return m_Pos.x;
}

float Object::GetPositionY() {
	return m_Pos.y;
}

void  Object::SetGravity(float Gravity) {
	m_Gravity = Gravity;
}

float Object::GetGravity() {
	return m_Gravity;
}

float Object::GetForceX() {
	return m_Force.x;
}

float Object::GetForceY() {
	return m_Force.y;
}

void Object::SetMass(float Mass) {
	m_Mass = Mass;
}

float Object::GetMass() {
	return m_Mass;
}