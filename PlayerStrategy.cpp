#pragma once
#include "PlayerStrategy.h"

// Human Player Strategy
void HumanPlayerStrategy::issueOrder()
{
	string ordername;
	cin >> ordername;
	Order* o = new Order();
	p->orderList.push_back(o);
}


vector<Territory*> HumanPlayerStrategy::toAttack()
{
	return p->getTerritories();
}

vector<Territory*> HumanPlayerStrategy::toDefend()
{
	return p->getTerritories();
}



// Aggressive Player Strategy
void AggressivePlayerStrategy::issueOrder()
{
    vector<Order*> orderList = p->getOrderList();
    Order* order = new Order;
    orderList.push_back(order);
}

vector<Territory> AggressivePlayerStrategy::toAttack()
{
    vector<Territory*> territories = p->getTerritories();
    int max = 0;
    Territory* tmax;
    for (int i = 0; i < territories.size(); i++)
    {
        int temp = territories[i]->getNumOfArmies();
        Territory* ttemp = territories[i];
        if (temp >= max)
        {
            max = temp;
            tmax = ttemp;
        }
    }

    vector<Territory> tAttack;
    tAttack = m.getAdjacentTerritories(*tmax);

    return tAttack;

}

Territory* AggressivePlayerStrategy::toDefend()
{
    vector<Territory*> territories = p->getTerritories();
    int max = 0;
    Territory* tmax;
    for (int i = 0; i < territories.size(); i++)
    {
        int temp = territories[i]->getNumOfArmies();
        Territory* ttemp = territories[i];
        if (temp >= max)
        {
            max = temp;
            tmax = ttemp;
        }
    }
    return tmax;

}



// Benevolent Player Strategy
void BenevolentPlayerStrategy::issueOrder()
{
    vector<Order*> orderList = p->getOrderList();
    Order* order = new Order;
    orderList.push_back(order);
}


vector<Territory*> BenevolentPlayerStrategy::toAttack()

{

}

Territory* BenevolentPlayerStrategy::toDefend()
{
    vector<Territory*> territories = p->getTerritories();
    int min = 100;
    Territory* tmin;
    for (int i = 0; i < territories.size(); i++)
    {
        int temp = territories[i]->getNumOfArmies();
        Territory* ttemp = territories[i];
        if (temp <= min)
        {
            min = temp;
            tmin = ttemp;
        }
    }
    return tmin;
}


// Neutral Player Strategy
void NeutralPlayerStrategy::issueOrder()
{
	//do nothing
}


vector<Territory*> NeutralPlayerStrategy::toAttack()
{
	//do nothing
	return p->getTerritories();
}

vector<Territory*> NeutralPlayerStrategy::toDefend()
{
	if (p->getNoTerritories() < oldterritorycount)
	{
		p->setAttackState(true);
	}

	oldterritorycount = p->getNoTerritories();
}




// Cheater Player Strategy
void CheaterPlayerStrategy::issueOrder()
{
	//do nothing
}


vector<Territory*> CheaterPlayerStrategy::toAttack()

{
	//iterate through the player's territories, find the adjacent ones, and assign them to the cheater player
	for (auto i : p->getTerritories())
	{
        //iterate through the vector list returned by getTerritories()
        for (auto j : m.getAdjacentTerritories(*i))
        {
            p->assignTerritory(new Territory(j));   //assign the territory to the cheater player
            delete i;   //delete the old territory
        }
	}
}


vector<Territory*> CheaterPlayerStrategy::toDefend()
{
	//do nothing
	return p->getTerritories();

}