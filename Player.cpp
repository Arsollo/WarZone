#include "Player.h"
#include "Map.h"
#include "PlayerStrategy.h"

using namespace std;

    Player::Player() //default constructor
    {
    	name = "No Name!";
    	reinforcementPool = -1;
        vector<Territory*> territories;
        vector<Card*> hand;
        vector<Order*> orderList;
        PlayerStrategy* ps;
        wasattacked = false;
    }

    Player::Player(string n) //constructor with parameters
	{
    	reinforcementPool = -1;
		this->name = n;
	}

    Player::Player(string n, int r, vector<Territory*> t, vector<Card*> h, vector<Order*> o, PlayerStrategy* p) //constructor with parameters
    {
    	this->reinforcementPool = r;
    	this->name = n;
        this->territories = t;
        this->hand = h;
        this->orderList = o;
        this->ps = p;
    }

    Player::Player(const Player& other) //copy constructor
    {
    	this->reinforcementPool = other.reinforcementPool;
    	this->name = other.name;
        this->territories = other.territories;
        this->hand = other.hand;
        this->orderList = other.orderList;
        this->ps = other.ps;
    }

    Player& Player::operator=(const Player &other) //assignment operator
    {
        if (this == &other)
        {
            return *this;
        }

        this->name = other.name;
        this->reinforcementPool = other.reinforcementPool;
        this->territories = other.territories;
        this->hand = other.hand;
        this->orderList = other.orderList;
        this->ps = other.ps;

        return *this;
    }

    Player::~Player() //destructor
    {
        territories.clear();
        hand.clear();
        orderList.clear();
    }

    vector<Territory *> Player::toDefend() //returns list of territories to be defended
    {
        return ps->toDefend();
    }

    vector<Territory *> Player::toAttack() //returns arbitrary list of territories to be attacked
    {
        return ps->toAttack();
    }

    void Player::issueOrder() //adds new order to the orderList
    {
        ps->issueOrder();
    }

    void Player::printOrderList() //for later display of orderList
    {
        for (int i = 0; i < orderList.size(); i++)
        {
            cout << orderList[i] << "" << endl;
        }
    }

    void Player::printHand() //for later display of hand of cards
    {
        for (int i = 0; i < hand.size(); i++)
        {
            cout << hand[i]->getAssignedType() << "" << endl;
        }
    }

    void Player::printTerritories() //for later display of owned territories
        {
            for (int i = 0; i < territories.size(); i++)
            {
                cout << "Territory #" << (i+1) << ": " <<territories[i]->getTerritory_name() << endl;
            }
        }

    void Player::assignTerritory(Territory* t)
    {
    	territories.push_back(t);
    }

    void Player::removeTerritory(Territory* t)
    {
        territories.erase(std::remove(territories.begin(), territories.end(), t), territories.end());
    }


    void Player::updateReinforcementPool(int r)
    {
    	reinforcementPool = r;
    }

    vector<Card*> Player::getHand()
    {
    	return hand;
    }

    void Player::addCardToHand(Card* card)
    {
    	hand.push_back(card);
    }

    string Player::getName()
	{
		return name;
	}

    int Player::getArmies()
    {
        return reinforcementPool;
    }

    int Player::getNoTerritories() {

        int length;
        for (Territory *element: territories)
        {
            length++;
        }
        return length;
    }

    vector<Territory*> Player::getTerritories()
    {

        return territories;
    }

    vector<Order*> Player::getOrderList()
    {
        return orderList;
    }

    void Player::setAttackState(bool a)
    {
        wasattacked = a;
    }