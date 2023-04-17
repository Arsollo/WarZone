#include "PlayerStrategy.h"
#include "Map.h"
// Human Player Strategy
void HumanPlayerStrategy::issueOrder()
{

}

vector<Territory*> HumanPlayerStrategy::toAttack()
{

}

vector<Territory*> HumanPlayerStrategy::toDefend()
{

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

Territory * AggressivePlayerStrategy::toDefend()
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

Territory * BenevolentPlayerStrategy::toDefend()
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

}

vector<Territory*> NeutralPlayerStrategy::toAttack()
{

}

vector<Territory*> NeutralPlayerStrategy::toDefend()
{

}




// Cheater Player Strategy
void CheaterPlayerStrategy::issueOrder()
{

}

vector<Territory*> CheaterPlayerStrategy::toAttack()
{

}

vector<Territory*> CheaterPlayerStrategy::toDefend()
{

}
