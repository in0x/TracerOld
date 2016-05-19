#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <cmath>

class vec3
{
public:
	vec3() {}
	vec3( float _x, float _y, float _z ) : m_x( _x ), m_y( _y ), m_z( _z ) {}

	// Public Member Functions
	float x() const {return m_x;}
	float y() const {return m_y;}
	float z() const {return m_z;}
	
	vec3 operator-() const { return vec3( -m_x, -m_y, -m_z ); };

	bool operator==( const vec3& rhs )
	{
		return m_x == rhs.m_x && m_y == rhs.m_y && m_z == rhs.m_z;
	}
	
	vec3& operator+=( const vec3& rhs ) 
	{ 
		m_x += rhs.m_x;
		m_y += rhs.m_y;
		m_z += rhs.m_z;
		return *this;
	}
	
	vec3& operator-=( const vec3& rhs )
	{
		m_x -= rhs.m_x;
		m_y -= rhs.m_y;
		m_z -= rhs.m_z;
		return *this;
	}
	
	vec3& operator*=( const vec3& rhs )
	{
		m_x *= rhs.m_x;
		m_y *= rhs.m_y;
		m_z *= rhs.m_z;
		return *this;
	}
	
	vec3& operator/=( const vec3& rhs )
	{
		m_x /= rhs.m_x;
		m_y /= rhs.m_y;
		m_z /= rhs.m_z;
		return *this;
	}

	vec3& operator*=( const float t )
	{
		m_x *= t;
		m_y *= t;
		m_z *= t;
		return *this;
	}

	vec3& operator/=( const float t )
	{
		m_x /= t;
		m_y /= t;
		m_z /= t;
		return *this;
	}

	float length() const
	{
		return sqrt( m_x*m_x + m_y*m_y + m_z*m_z );
	}

	float length2() const
	{
		return m_x*m_x + m_y*m_y + m_z*m_z;
	}

	void normalim_ze()
	{
		float len = 1 / length();
		m_x *= len; m_y *= len; m_z *= len;
	}

	float dot( const vec3& rhs ) const
	{
		return m_x * rhs.m_x + m_y * rhs.m_y + m_z * rhs.m_z;
	}

	vec3 cross( const vec3 rhs ) const
	{
		return vec3( 
			m_y * rhs.m_z - m_z * rhs.m_y,
			-( m_x * rhs.m_z - m_z * rhs.m_x ),
			m_x * rhs.m_y - m_y * rhs.m_x
		 );
	}

	vec3 unitVector() const;

private:
	// Private members
	float m_x;
	float m_y;
	float m_z;
};

inline std::ostream& operator<<( std::ostream& os, const vec3& vec )
{
	os << vec.x() << " " << vec.y() << " " << vec.z();
	return os;
}

inline vec3 operator+( const vec3& lhs, const vec3& rhs )
{
	return vec3( lhs.x() + rhs.x(), lhs.y() + rhs.y(), lhs.z() + rhs.z() );
}

inline vec3 operator-( const vec3& lhs, const vec3& rhs )
{
	return vec3( lhs.x() - rhs.x(), lhs.y() - rhs.y(), lhs.z() - rhs.z() );
}

inline vec3 operator*( const vec3& lhs, const vec3& rhs )
{
	return vec3( lhs.x() * rhs.x(), lhs.y() * rhs.y(), lhs.z() * rhs.z() );
}

inline vec3 operator/( const vec3& lhs, const vec3& rhs )
{
	return vec3( lhs.x() / rhs.x(), lhs.y() / rhs.y(), lhs.z() / rhs.z() );
}

inline vec3 operator*( const vec3& lhs, float rhs )
{
	return vec3( lhs.x() * rhs, lhs.y() * rhs, lhs.z() * rhs );
}

inline vec3 operator/( const vec3& lhs, float rhs )
{
	return vec3( lhs.x() / rhs, lhs.y() / rhs, lhs.z() / rhs );
}

inline vec3 operator*( float lhs, const vec3& rhs )
{
	return vec3( lhs * rhs.x(), lhs * rhs.y(), lhs * rhs.z() );
}

inline vec3 operator/( float lhs, const vec3& rhs )
{
	return vec3( lhs / rhs.x(), lhs / rhs.y(), lhs / rhs.z() );
}

inline vec3 vec3::unitVector() const 
{
	return *this / length();
}

#endif //VEC3_H