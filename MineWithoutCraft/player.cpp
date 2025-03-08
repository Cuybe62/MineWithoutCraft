#include "player.h"

Player::Player(const Vector3f& position, float rotX, float rotY) : m_position(m_position), m_rotX(rotX), m_rotY(rotY)
{
	m_position = position;
}

void Player::TurnLeftRight(float value)
{
	m_rotX += value;
}

void Player::TurnTopBottom(float value)
{
	if (m_rotX + value > 90)
		m_rotX = 90;
	else if (m_rotX + value < -90)
		m_rotX = -90;
	else
		m_rotY += value;
	
}

void Player::Move(bool front, bool back, bool left, bool right, bool sprint ,float elapsedTime)
{
	int speed;
	if (sprint)
		speed = 2;
	else
		speed = 1;
	
	
	
	if (front == true) //w
	{

		float xrotrad, yrotrad;
		yrotrad = (m_rotY / 180 * 3.141592654f);
		xrotrad = (m_rotX / 180 * 3.141592654f);
		m_position.x += float(sin(yrotrad)) * elapsedTime * 10 * speed;
		m_position.z -= float(cos(yrotrad)) * elapsedTime * 10 * speed;
		
	}
	
	if (back == true) {//s
		float xrotrad, yrotrad;
		yrotrad = (m_rotY / 180 * 3.141592654f);
		xrotrad = (m_rotX / 180 * 3.141592654f);
		m_position.x -= float(sin(yrotrad)) * elapsedTime * 10 * speed;
		m_position.z += float(cos(yrotrad)) * elapsedTime * 10 * speed;

	}
	
	if (left == true){ //a
		float yrotrad;
		yrotrad = (m_rotY / 180 * 3.141592654f);
		m_position.x -= float(cos(yrotrad)) * 0.2;
		m_position.z -= float(sin(yrotrad)) * 0.2;
	}
	
	if (right == true){ //d
		float yrotrad;
		yrotrad = (m_rotY / 180 * 3.141592654f);
		m_position.x += float(cos(yrotrad)) * 0.2 ;
		m_position.z += float(sin(yrotrad)) * 0.2 ;
	
	}
	
	
	
}

void Player::ApplyTransformation(Transformation& transformation) const
{
	transformation.ApplyRotation(-m_rotX, 1.f, 0, 0);
	transformation.ApplyRotation(-m_rotY, 0, 1.f, 0);
	transformation.ApplyTranslation(-m_position);


}
