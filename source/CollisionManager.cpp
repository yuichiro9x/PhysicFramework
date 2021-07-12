#include "CollisionManager.h"


CollisionManager* CollisionManager::s_Instance = NULL;

CollisionManager::CollisionManager(void)
{
	this->Init();
}

CollisionManager* CollisionManager::GetInstance()
{
	if (!s_Instance)
		s_Instance = new CollisionManager();
	return s_Instance;
}


CollisionManager::~CollisionManager()
{
}

void CollisionManager::Init()
{
	
}

void CollisionManager::Update(float deltaTime) {
}

bool CollisionManager::CheckOnCollision(std::shared_ptr<Object> obj1, std::shared_ptr<Object> obj2) {
	switch (obj1->type) {
		case 0:
			switch (obj2->type) {
				case 1:
					return CheckOnCollisionPR(obj1, obj2);
					break;
				case 2:
					return CheckOnCollisionPC(obj1, obj2);
					break;
			}
			break;
		case 1:
			switch (obj2->type) {
				case 0:
					return CheckOnCollisionPR(obj2, obj1);
					break;
				case 1:
					return CheckOnCollisionRR(obj1, obj2);
					break;
				case 2:
					return CheckOnCollisionRC(obj1, obj2);
					break;
			}
			break;
		case 2:
			switch (obj2->type) {
				case 0:
					return CheckOnCollisionPC(obj2, obj1);
					break;
				case 1:
					return CheckOnCollisionRC(obj2, obj1);
					break;
				case 2:
					return CheckOnCollisionCC(obj1, obj2);
					break;
			}
			break;
	}
	return false;
}

bool CollisionManager::CheckOnCollisionRR(std::shared_ptr<Object> o_Rect1, std::shared_ptr<Object> o_Rect2) {
	bool ColX = false, ColY = false;
	std::shared_ptr<Rect> rect1 = std::dynamic_pointer_cast<Rect>(o_Rect1);
	std::shared_ptr<Rect> rect2 = std::dynamic_pointer_cast<Rect>(o_Rect2);
	if (rect1->GetPositionX() <= rect2->GetPositionX()) {
		if (rect1->GetWidth() >= abs(rect1->GetPositionX() - rect2->GetPositionX()) - 5) {
			ColX = true;
		}
	}
	else {
		if (rect2->GetWidth() >= abs(rect1->GetPositionX() - rect2->GetPositionX()) - 5) {
			ColX = true;
		}
	}

	if (rect1->GetPositionY() <= rect2->GetPositionY()) {
		if (rect1->GetHeight() >= abs(rect1->GetPositionY() - rect2->GetPositionY()) - 5) {
			ColY = true;
		}
	}
	else {
		if (rect1->GetHeight() >= abs(rect1->GetPositionY() - rect2->GetPositionY()) - 5) {
			ColY = true;
		}
	}
	if (ColX && ColY) {
		std::cout << "Object Collision Detected! \n";
		return true;
	}
	return false;
}

bool CollisionManager::CheckOnCollisionCC(std::shared_ptr<Object> o_Circle1, std::shared_ptr<Object> o_Circle2) {
	std::shared_ptr<Circle> cir1 = std::dynamic_pointer_cast<Circle>(o_Circle1);
	std::shared_ptr<Circle> cir2 = std::dynamic_pointer_cast<Circle>(o_Circle2);
	if (((cir1->GetRadius() + cir2->GetRadius()) >= -5 + (sqrt(((cir1->GetPositionX() - cir2->GetPositionX()) * (cir1->GetPositionX() - cir2->GetPositionX())) + ((cir1->GetPositionY() - cir2->GetPositionY()) * (cir1->GetPositionY() - cir2->GetPositionY())))))) {
		std::cout << "Object Collision Detected! \n";
		return true;
	}
	return false;
}

bool CollisionManager::CheckOnCollisionRC(std::shared_ptr<Object> o_Rectangle, std::shared_ptr<Object> o_Circle) {
	std::shared_ptr<Rect> rect = std::dynamic_pointer_cast<Rect>(o_Rectangle);
	std::shared_ptr<Circle> cir = std::dynamic_pointer_cast<Circle>(o_Circle);
	float x2 = rect->GetPositionX() + rect->GetWidth(), y2 = rect->GetPositionY() + rect->GetHeight();
	float xA = cir->GetPositionX();
	float yA = cir->GetPositionY();

	if (xA < rect->GetPositionX()) xA = rect->GetPositionX();
	else if (xA > x2) xA = x2;

	if (yA < rect->GetPositionY()) yA = rect->GetPositionY();
	else if (yA > y2) yA = y2;

	if (cir->GetRadius() >= -5 + sqrt((xA - cir->GetPositionX()) * (xA - cir->GetPositionX()) + (yA - cir->GetPositionY()) * (yA - cir->GetPositionY()))) {
		//std::cout << "Object Collision Detected! \n";
		return true;
	}
	return false;
}

bool CollisionManager::CheckOnCollisionPC(std::shared_ptr<Object> o_Plane, std::shared_ptr<Object> o_Circle) {
	std::shared_ptr<Plane> plane = std::dynamic_pointer_cast<Plane>(o_Plane);
	std::shared_ptr<Circle> cir = std::dynamic_pointer_cast<Circle>(o_Circle);

	float x1 = plane->GetPositionX(), x2 = plane->GetPositionX2(), y1 = plane->GetPositionY(), y2 = plane->GetPositionY2();
	float a = y2 - y1, b = -(x2 - x1);

	if (cir->GetRadius() >= -5 + abs(a*cir->GetPositionX() + b*cir->GetPositionY() + y1*x2 - y2*x1) / sqrt(a*a + b*b)) {
		//std::cout << "Edge Collision Deteced!\n";
		return true;
	}
	return false;
}

bool CollisionManager::CheckOnCollisionPR(std::shared_ptr<Object> o_Plane, std::shared_ptr<Object> o_Rectangle) {
	std::shared_ptr<Plane> plane = std::dynamic_pointer_cast<Plane>(o_Plane);
	std::shared_ptr<Rect> rect = std::dynamic_pointer_cast<Rect>(o_Rectangle);

	float x1 = plane->GetPositionX(), x2 = plane->GetPositionX2(), y1 = plane->GetPositionY(), y2 = plane->GetPositionY2();
	float xR = rect->GetPositionX(), yR = rect->GetPositionY();
	if ((y1 >= yR && y1 <= yR + rect->GetHeight()) || (y2 >= yR && y2 <= yR + rect->GetHeight())) {
		//std::cout << "Edge Collision Deteced!\n";
		return true;
	}
	if ((x1 >= xR && x1 <= xR + rect->GetWidth()) || (x2 >= xR && x2 <= xR + rect->GetWidth())) {
		//std::cout << "Edge Collision Deteced!\n";
		return true;
	}
	return false;
}

void CollisionManager::SetBounce(std::shared_ptr<Object> obj1, std::shared_ptr<Object> obj2) {
	
}

bool CollisionManager::CheckGravity(std::shared_ptr<Object> obj1, std::shared_ptr<Object> obj2) {
	if (std::dynamic_pointer_cast<Plane>(obj2) && obj2->GetID() == 7) {
		return true;
	}
	if (std::dynamic_pointer_cast<Plane>(obj1) && obj1->GetID() == 7) {
		return true;
	}
}
