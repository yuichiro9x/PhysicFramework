#pragma once
#include "videoDriver.h"

class Object
{
private:
	bool m_bIsFalling = true;
	bool m_bIsClicked = false;
	int m_Id;
	struct xOy {
		float x;
		float y;
	};
	xOy m_Pos;
	xOy m_Force;
	float m_Mass = 1, m_Velocity = 10, m_Gravity = 10;


public:
	int type = 0;
	Object(int ID, float X, float Y);
	Object(int ID, float X, float Y, float G);
	~Object();

	virtual void Render() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual bool CheckIsClicked(float X, float Y) = 0;

	void MoveObject(float X, float Y);
	void AddForce(float deltaX, float deltaY);

	void SetIsFalling(bool fall);
	bool GetIsFalling();
	void SetIsClicked(bool move);
	bool GetIsClicked();


	inline int GetID(){return m_Id;};
	void SetPositionX(float X);
	void SetPositionY(float Y);
	float GetPositionX();
	float GetPositionY();
	void SetGravity(float V);
	float GetGravity();
	float GetVelocity(){return m_Velocity;}
	void SetForceX(float X){m_Force.x = X;}
	float GetForceX();
	void SetForceY(float Y) {m_Force.y = Y;}
	float GetForceY();
	void SetMass(float mass);
	float GetMass();
};

