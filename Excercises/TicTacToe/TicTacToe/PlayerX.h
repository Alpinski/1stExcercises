#pragma once
class PlayerX
{
public:
	char PlayerXMark(char square[3][3]);
	PlayerX();
	~PlayerX();
protected:
	bool Win = false;

};

