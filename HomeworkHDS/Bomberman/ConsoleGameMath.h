#pragma once

// 좌표값을 표현하기 위한 클래스 
class int4
{
public:
	int X = 0;
	int Y = 0;
	int Z = 0;
	int W = 0;

	int4& operator +=(const int4& _other)
	{
		X += _other.X;
		Y += _other.Y;
		W += _other.W;
		Z += _other.Z;

		return *this;
	}
};