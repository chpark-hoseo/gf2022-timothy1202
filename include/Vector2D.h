#pragma once
#include <math.h>

class Vector2D {
public:
	Vector2D(float x, float y) : m_x(x), m_y(y) {}
	float getX() { return m_x; }
	float getY() { return m_y; }
	void setX(float x) { m_x = x; }
	void setY(float y) { m_y = y; }

	float length() { return sqrt(m_x * m_x + m_y * m_y); }

	Vector2D operator+(const Vector2D& v2) const;
	Vector2D operator-(const Vector2D& v2) const;
	Vector2D operator*(float scalar);
	Vector2D operator/(float scalar);

	Vector2D& operator*=(float scalar);
	Vector2D& operator/=(float scalar);

	void normalize();

	friend Vector2D& operator+=(Vector2D& v1, const Vector2D& v2);
	friend Vector2D& operator-=(Vector2D& v1, const Vector2D& v2);

private:
	float m_x;
	float m_y;
};