#pragma once
class WinLoseO
{
public:
	WinLoseO();
	~WinLoseO();
	bool CheckWinO(char square[3][3]);
	int ScoreO = 0;
protected:
	bool Win = false;
};

