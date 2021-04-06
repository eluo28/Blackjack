#pragma once


#include <string>

class Player
{

public:
	Player(const std::string& name);
	bool isHitting() const;
	void Win() const;
	void Lose() const;
	void Hit() const;
	void Bust() const;
protected:
	std::string m_name;
};

