#pragma once


class int4
{
public:
	int X = 0;
	int Y = 0;
	int Z = 0;
	int W = 0;

	// int랑 똑같이 만들려고
	int4& operator+=(const int4& _Value)
	{
		X += _Value.X;
		Y += _Value.Y;
		Z += _Value.Z;
		W += _Value.W;
		return *this;
	}

	int4 operator +(const int4& _other)
	{
		int4 Result;
		Result.X = X + _other.X;
		Result.Y = Y + _other.Y;
		Result.Z = Z + _other.Z;
		Result.W = W + _other.W;

		return Result;
	}

	// 1 == 1 
	bool operator==(const int4& _Value)
	{
		return X == _Value.X && Y == _Value.Y;
	}

};