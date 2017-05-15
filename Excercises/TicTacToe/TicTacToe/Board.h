#pragma once
class Board
{
public:
	
	char square[3][3] = { '1','2','3','4','5','6','7','8','9' };
	
	Board();
	~Board();
	void Reset();
	
	void PlayField(int ScoreX, int ScoreO);
};

