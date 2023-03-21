#include "Collision.h"

Collision::Collision(sf::Sprite& body) :
body(body)
{
}

bool Collision::checkCollision(Collision& other, float recoil)
{
sf::Vector2f otherPosition = other.getPosition();
sf::Vector2f otherHalfSize = other.getHalfSize();
sf::Vector2f thisPosition = getPosition();
sf::Vector2f thisHalfSize = getHalfSize();

float deltaX = otherPosition.x-thisPosition.x;
float deltaY = otherPosition.y-thisPosition.y;

float intersectX= abs(deltaX)-(otherHalfSize.x+thisHalfSize.x);
float intersectY= abs(deltaY)-(otherHalfSize.y+thisHalfSize.y);

if(intersectX<0.0f && intersectY <0.0f){

recoil=std::min(std::max(recoil,0.0f),1.0f); //Clamping
if (intersectX>intersectY){
	if (deltaX>0.0f)
	{
		Move(intersectX*(1.0f-recoil),0.0f);
		other.Move(-intersectX*recoil,0.0f);
	}
	else
	{
		Move(- intersectX*(1.0f-recoil),0.0f);
		other.Move(intersectX*recoil,0.0f);
	}
}
else
{
	if (deltaY>0.0f)
	{
		Move(0.0f,intersectY*(1.0f-recoil));
		other.Move(0.0f,-intersectY*recoil);
	}
	else
	{
		Move(0.0f,-intersectY*(1.0f-recoil));
		other.Move(0.0f,intersectY*recoil);
	}

}

return true;
}
return false;

}


