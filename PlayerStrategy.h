#pragma once
#include "Player.h"

class PlayerStrategy
{
public:
	Player* p;
	Map m;

	virtual void issueOrder() = 0;
	virtual vector<Territory> toAttack() = 0;
	virtual Territory* toDefend() = 0;
};

class HumanPlayerStrategy : PlayerStrategy
{
	void issueOrder();
	vector<Territory> toAttack();
	Territory* toDefend();
};

class AggressivePlayerStrategy : PlayerStrategy
{
	void issueOrder();
	vector<Territory> toAttack();
	Territory* toDefend();
};

class BenevolentPlayerStrategy : PlayerStrategy
{
	void issueOrder();
	vector<Territory> toAttack();
	Territory* toDefend();
};

class NeutralPlayerStrategy : PlayerStrategy
{
	void issueOrder();
	vector<Territory> toAttack();
	Territory* toDefend();

	private:
		int oldterritorycount;
};

class CheaterPlayerStrategy : PlayerStrategy
{
	void issueOrder();
	vector<Territory> toAttack();
	Territory* toDefend();
};