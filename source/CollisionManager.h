#pragma once
#include <iostream>
#include <fstream>
#include "esUtil.h"
#include "log.h"
#include "define.h"
#include "VideoDriver.h"
#include "Rect.h"
#include "Circle.h"
#include "Plane.h"
#include <crtdbg.h>
#include <vector>
#include <memory>


#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG

class CollisionManager
{
private:
	static CollisionManager* s_Instance;

public:

	CollisionManager();
	~CollisionManager();

	void Init();
	void Update(float deltaTime);

	bool CheckOnCollision(std::shared_ptr<Object> obj1, std::shared_ptr<Object> obj2);
	bool CheckOnCollisionRR(std::shared_ptr<Object> obj1, std::shared_ptr<Object> obj2);
	bool CheckOnCollisionCC(std::shared_ptr<Object> obj1, std::shared_ptr<Object> obj2);
	bool CheckOnCollisionRC(std::shared_ptr<Object> obj1, std::shared_ptr<Object> obj2);
	bool CheckOnCollisionPC(std::shared_ptr<Object> obj1, std::shared_ptr<Object> obj2);
	bool CheckOnCollisionPR(std::shared_ptr<Object> obj1, std::shared_ptr<Object> obj2);

	void SetBounce(std::shared_ptr<Object> obj1, std::shared_ptr<Object> obj2);
	bool CheckGravity(std::shared_ptr<Object> obj1, std::shared_ptr<Object> obj2);


	static CollisionManager* GetInstance();
};



