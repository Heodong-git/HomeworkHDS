#pragma once

class Int4
{
public:
	int X = 0;
	int Y = 0;
	int W = 0;
	int Z = 0;

	Int4& operator +=(const Int4& _other)
	{
		X += _other.X;
		Y += _other.Y;
		W += _other.W;
		Z += _other.Z;

		return *this;
	}

	bool operator ==(const Int4& _other)
	{
		int Count = 0;
		if (X == _other.X)
		{
			++Count;
		}
		if (Y == _other.Y)
		{
			++Count;
		}
		if (W == _other.W)
		{
			++Count;
		}
		if (Z == _other.Z)
		{
			++Count;
		}
		
		if (4 == Count)
		{
			return true;
		}

		return false;
	}
};