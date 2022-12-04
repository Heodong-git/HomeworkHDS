#pragma once

class Int4;

class CEngine
{
private:
	char GameMap[5][6];
	char Curchar;

public:
	void Init();
	void SetMap(const char _Text);
	void SetTile(const Int4& _Pos, char _Char);
	void Render();
	const char GetChar() { return Curchar; }
};

