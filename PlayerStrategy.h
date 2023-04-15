#pragma once
#include "Player.h"

class PlayerStrategy
{
public:
	Player* p;

	virtual void issueOrder() = 0;
	virtual vector<Territory*> toAttack() = 0;
	virtual vector<Territory*> toDefend() = 0;
};

class HumanPlayerStrategy : PlayerStrategy
{
	void issueOrder();
	vector<Territory*> toAttack();
	vector<Territory*> toDefend();
};

class AggressivePlayerStrategy : PlayerStrategy
{
	void issueOrder();
	vector<Territory*> toAttack();
	vector<Territory*> toDefend();
};

class BenevolentPlayerStrategy : PlayerStrategy
{
	void issueOrder();
	vector<Territory*> toAttack();
	vector<Territory*> toDefend();
};

class NeutralPlayerStrategy : PlayerStrategy
{
	void issueOrder();
	vector<Territory*> toAttack();
	vector<Territory*> toDefend();
};

class CheaterPlayerStrategy : PlayerStrategy
{
	void issueOrder();
	vector<Territory*> toAttack();
	vector<Territory*> toDefend();
};