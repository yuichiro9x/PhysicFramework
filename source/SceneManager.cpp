#include "SceneManager.h"


SceneManager* SceneManager::s_Instance = NULL;

SceneManager::SceneManager(void)
{
	this->Init();
}

SceneManager* SceneManager::GetInstance()
{
	if (!s_Instance)
		s_Instance = new SceneManager();
	return s_Instance;
}


SceneManager::~SceneManager()
{
	GameExit();
}

void SceneManager::Init() {
	f_SM = fopen("SceneManager.txt", "r+");
	m_Object.clear();
	if (f_SM != NULL) {
		this->ReadFile();
	} else std::cout<<"Khong tim thay file Scene Manager! \n";
	

	/*std::shared_ptr<Object> plane = std::make_shared<Plane>(3, padding, padding, SCREEN_W - padding, padding);
	AddObject(plane);
	plane = std::make_shared<Plane>(4, SCREEN_W - padding, padding, SCREEN_W - padding, SCREEN_H - padding);
	AddObject(plane);
	plane = std::make_shared<Plane>(5, padding, padding, padding, SCREEN_H - padding);
	AddObject(plane);
	plane = std::make_shared<Plane>(6, padding, SCREEN_H - padding, SCREEN_W - padding, SCREEN_H - padding);
	AddObject(plane);*/
}

void SceneManager::ReadFile()
{
	int num;
	fscanf(f_SM, "#OBJECT_NUM %d\n", &num);
	std::cout <<"Num of Object(s): "<< num << std::endl;

	for (register int i = 0; i < num; i++) {
		int ID;
		char type[10];
		char s[10] = "RECT";
		float x = 0, y = 0, z = 0, w = 0;
		int v = 0;
		fscanf(f_SM, "#ID %d\n", &ID);
		fscanf(f_SM, "TYPE: %s\n", &type);
		
		if (strcmp(type, "RECT") == 0) {
			fscanf(f_SM, "POSITION: %f, %f, %f, %f\n", &x, &y, &z, &w);
			fscanf(f_SM, "VELOCITY: %d\n\n", &v);
			printf("ID: %d, TYPE: %s, POSITION: %f %f %f %f, Velo: %d\n", ID, type, x, y, z, w, v);
			std::shared_ptr<Object> obj = std::make_shared<Rect>(ID, x, y, z, w, v);
			AddObject(obj);
		}else if (strcmp(type, "CIRCLE") == 0){
			fscanf(f_SM, "POSITION: %f, %f, %f\n", &x, &y, &z);
			fscanf(f_SM, "VELOCITY: %d\n\n", &v);
			printf("ID: %d, TYPE: %s, POSITION: %f %f %f, Velo: %d\n", ID, type, x, y, z, v);
			std::shared_ptr<Object> obj = std::make_shared<Circle>(ID, x, y, z, v);
			AddObject(obj);
		}
		else if (strcmp(type, "PLANE") == 0){
			fscanf(f_SM, "POSITION: %f, %f, %f, %f\n", &x, &y, &z, &w);
			printf("ID: %d, TYPE: %s, POSITION: %f %f %f %f\n", ID, type, x, y, z, w);
			std::shared_ptr<Object> obj = std::make_shared<Plane>(ID, x, y, z, w);
			AddObject(obj);
		}		
	}
	fclose(f_SM);
}

void SceneManager::Update(float deltaTime) {
	for (int i = 0; i < m_Object.size(); i++) {
		m_Object[i]->Update(deltaTime);
	}
	this->CheckOnCollision();
}

void SceneManager::AddObject(std::shared_ptr<Object> obj) {
	m_Object.push_back(obj);
}

void SceneManager::Render() {
	for (int i = 0; i < m_Object.size(); i++) {
		m_Object[i]->Render();
	}
}

void SceneManager::OnMouseButtonDown(float X, float Y) {
	for (int i = 0; i < m_Object.size(); i++) {
		if (m_Object[i]->CheckIsClicked(X, Y)) {
			break;
		}
	}
	xOld = X;
	yOld = Y;
}

void SceneManager::OnMouseButtonUp(float X, float Y) {
	for (int i = 0; i < m_Object.size(); i++) {
		if (m_Object[i]->GetIsClicked()) {
			m_Object[i]->SetIsClicked(false);
		}
	}
}

void SceneManager::TouchActionMove(float X, float Y) {
	for (int i = 0; i < m_Object.size(); i++) {
		if (m_Object[i]->GetIsClicked()) {		
			m_Object[i]->MoveObject(m_Object[i]->GetPositionX() + (X - xOld), m_Object[i]->GetPositionY() + (Y - yOld));
			m_Object[i]->AddForce(X - xOld, Y - yOld);
		}	
	}
	xOld = X;
	yOld = Y;
}

void SceneManager::CheckOnCollision() {
	for (register int i = 0; i < m_Object.size()-1; i++) {
		int d = 0;
		for (int j = i+1; j < m_Object.size(); j++) {
			if(CollisionManager::GetInstance()->CheckOnCollision(m_Object[i], m_Object[j])){
				CollisionManager::GetInstance()->SetBounce(m_Object[i], m_Object[j]);
				if (CollisionManager::GetInstance()->CheckGravity(m_Object[i], m_Object[j])) {
					d++;
					m_Object[i]->SetGravity(0);
				}
			}
		}
		if (d == 0) {
			m_Object[i]->SetGravity(m_Object[i]->GetVelocity());
		}
	}
}

void SceneManager::GameExit() {
	std::cout<<"Scene Deleted! \n";
}