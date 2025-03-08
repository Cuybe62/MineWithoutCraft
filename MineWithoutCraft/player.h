#ifndef PLAYER_H_
#define PLAYER_H_
 
#include "vector3.h"
#include "transformation.h"


class Player
{
public:
    Player(const Vector3f& position, float rotX = 0, float rotY = 0);
    void TurnLeftRight(float value);
    void TurnTopBottom(float value);
	void Move(bool front, bool back, bool left, bool right,bool sprint, float elapsedTime);
    void ApplyTransformation(Transformation& transformation) const;

private:
    Vector3f m_position;
	float m_rotX;
	float m_rotY;
};



#endif // !PLAYER_H_
