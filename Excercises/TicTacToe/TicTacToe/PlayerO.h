#pragma once
class PlayerO
{
public:
	char PlayerOMark(char square[3][3]);
	PlayerO();
	~PlayerO();
protected:
	bool Win = false;
};

