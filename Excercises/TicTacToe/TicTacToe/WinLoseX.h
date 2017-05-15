#pragma once
class WinLoseX
{
public:
	WinLoseX();
	~WinLoseX();
	bool WinLoseX::CheckWinX(char square[3][3]);
	int ScoreX = 0;
protected:
	bool Win = false;
};

