#pragma once
#include <iostream>
#include <fstream>
#include "esUtil.h"
#include "log.h"
#include "define.h"
#include "VideoDriver.h"
#include "CollisionManager.h"
#include "Rect.h"
#include "Circle.h"
#include "Plane.h"
#include <crtdbg.h>
#include <vector>

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG

class SceneManager
{
private:
	static SceneManager* s_Instance;
	std::vector<std::shared_ptr<Object>> m_Object;
	FILE* f_SM;

	float xOld, yOld;
public:

	SceneManager();
	~SceneManager();
	//std::list<Object> *object = new std::list<Object>;

	void Init();
	void Update(float deltaTime);
	void Render();
	void OnMouseButtonDown(float X, float Y);
	void OnMouseButtonUp(float X, float Y);
	void TouchActionMove(float X, float Y);


	void AddObject(std::shared_ptr<Object> obj);
	void GameExit();
	void ReadFile();
	void CheckOnCollision();

	static SceneManager* GetInstance();
};



