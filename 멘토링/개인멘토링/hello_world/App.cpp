#if 0
// C STANDARD
// 절차지향 프로그램(전지적 작가시점)
#include <stdio.h>
int main(void) //int main(int argc, char** argv)
{
	printf("Hello, World!")
		return (0);
}
#endif

#if 0
// CPP STANDARD
// 객체지향 프로그램
#include <iostream>
// using namespace std;
// NAMESPACE::FUNCTION

// 여전히 절차지향적인 문제가 있다

int main()
{
	std::cout << "Hello, World!" << std::endl;
}
#endif

// CLASS
// STRUCT(구조체)
/*
typedef struct _player
{
	char* _name;
	int _hp;
	...
	+함수(SetName, GetName)
}
Player;
SetName();
GetName();
// !! 구조체는 무조건 Public(공개된 자료형)이다
// 원래라면 함수는 들어갈 수가 없음(함수 포인터를 이용해서 편법으로는 가능함)
// Class 개념
// Class는 '형틀'
// C With Class
// i++; i = i + 1;
// c++;
*/
#if 0
#include <iostream>

// App 객체 정의
class App
{
public:
	void Print()
	{
		std::cout << "Hello, World!" << std::endl;
	}
};

int main()
{
	// App 객체 생성
	App app;
	app.Print();
}
#endif

// 플레이어의 위치값을 저장하는 변수를 만들고 싶어짐
// float x, float y;
/*
	typedef struct _vector2
	{
		float x;
		float y;
	} Vector2;
	SetVector(Vector2 *v, float x, float y);
	GetVector();

	...
	Vector2 v1;
	SetVector(&v1.x, &v1.y, 1.0f, 1.0f);
*/

#if 0
#include <iostream>

class Vector2
{
private:
	float _x;
	float _y;
public:
	void SetVector(float x, float y)
	{
		_x = x;
		_y = y;
	}
	void PrintVector()
	{
		std::cout << "X: " << _x << "|| Y: " << _y << std::endl;
	}
};

// x, y, z Vector3

int main()
{
	Vector2 v;
	v.SetVector(1.0f, 1.0f);
	v.PrintVector();
}
#endif

#if 0
#include <iostream>
class Vector3
{
private:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
public:
	void SetVector(float a, float b, float c)
	{
		x = a;
		y = b;
		z = c;
	}
	void PrintVector()
	{
		std::cout << "X: " << x << " || Y: " << y << " || Z: " << z << std::endl;
	}
};

int main()
{
	Vector3 v;
	v.SetVector(1.0f, 1.0f, 1.0f);
	v.PrintVector();
}
#endif

// Vector3
// (1) 생성자와 소멸자 적용
// (2) Vector3 = Vector3 + Vector3
//		v1 = v2 + v3;

#include <iostream>
class Vector3
{
private:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
public:
	Vector3();
	~Vector3();
	Vector3(float x, float y, float z);

	float GetX() const;
	float GetY() const;
	float GetZ() const;
	
	void GetVector()
	{
		std::cin >> x >> y >> z;
	}

	static Vector3 Sum(Vector3 a, Vector3 b, Vector3 c);

};

int main()
{
	Vector3 v;
	v.GetVector();
	Vector3 a(1, 2, 3), b(4, 5, 6), c(v.GetX(), v.GetY(), v.GetZ());
	Vector3 sum = Vector3::Sum(a, b, c);
	std::cout << "X: " << sum.GetX() << " || Y: " << sum.GetY() << " || Z: " << sum.GetZ() << std::endl;
}
Vector3::Vector3() : x(0), y(0), z(0){}
Vector3::~Vector3() { std::cout << "소멸자 호출" << std::endl; }
Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

float Vector3::GetX() const { return x; }
float Vector3::GetY() const { return y; }
float Vector3::GetZ() const { return z; }

Vector3 Vector3::Sum(Vector3 a, Vector3 b, Vector3 c)
{
	return Vector3(a.x + b.x + c.x, a.y + b.y + c.y, a.z + b.z + c.z);
}