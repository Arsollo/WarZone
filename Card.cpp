//============================================================================
// Name        : Card.cpp
// Author      : Arsany Fahmy
// Version     :
// Copyright   :
// Description : Comp 345 Ass 1
//============================================================================

#include <iostream>
#include <vector>
#include <random>
#include <stdexcept>
#include "Card.h"


using namespace std;


// ----------------------------------------- Card Class -----------------------------------------//
Card::Card(string type)
{
	assignedType = type;
}


void Card::copy(Card &c)
{
	assignedType = c.assignedType;
}

string Card::getAssignedType()
{
	return assignedType;
}

void play()
{
	//To be implemented
}




// ----------------------------------------- Deck Class -----------------------------------------//
Deck::Deck(): remainingCards(), cardTypes()
{
	//Storing all possible card types
	cardTypes.push_back("Bomb");
	cardTypes.push_back("Reinforcement");
	cardTypes.push_back("Blockade");
	cardTypes.push_back("Airlift");
	cardTypes.push_back("Diplomacy");

	totalNumCards = 0;
	numRemainingCards = 0;

	create();
}

Deck::Deck(int numCards): remainingCards(), cardTypes()
{
	//Storing all possible card types
	cardTypes.push_back("Bomb");
	cardTypes.push_back("Reinforcement");
	cardTypes.push_back("Blockade");
	cardTypes.push_back("Airlift");
	cardTypes.push_back("Diplomacy");

	totalNumCards = numCards;
	numRemainingCards = numCards;

	create();
}


void Deck::copy(Deck &d)
{
	totalNumCards = d.totalNumCards;
	numRemainingCards = d.numRemainingCards;
	cardTypes = d.cardTypes;
	remainingCards = d.remainingCards;
}


Card Deck::draw()
{
	//Printing an error message if no cards available to draw
	if(numRemainingCards < 1)
	{
		throw std::runtime_error(std::string("No cards left to draw from the deck :("));
	}
	else
	{
//		//Generating random number between 0 and sizeOfArray of remaining cards - 1
//		//in order to draw a random card from the pile of remaining cards
//		std::random_device rd; // obtain a random number from hardware
//		std::mt19937 gen(rd()); // seed the generator
//		std::uniform_int_distribution<> distr(0, numRemainingCards-1); // define the range
//		int randomIndex = distr(gen) ; // generate number
//
//		//Card to return
//		Card card("asdasdas");
//
//		//Copying content of randomly selected card
//		card.copy(remainingCards[0]);
//
//		//Updating the deck by removing the card that was picked
//		remainingCards.erase(remainingCards.begin() + randomIndex);
//
//		//Updating number of remaining cards
//		numRemainingCards--;
//
//		return card;

		//Drawing the last card on the deck then popping it from the deck

		//Card to return
		Card card("asdasdas");

		//Copying content of  selected card
		card.copy(remainingCards[numRemainingCards-1]);

		//Updating the deck by removing the card that was picked
		remainingCards.pop_back();

		//Updating number of remaining cards
		numRemainingCards--;

		return card;
	}
}

void Deck::create()
{
	for (int i = 0; i < totalNumCards; i++)
	{
		//Generating a random index to use to create a random card type
		std::random_device rd; // obtain a random number from hardware
		std::mt19937 gen(rd()); // seed the generator
		std::uniform_int_distribution<> distr(0, 4); // since 5 possible types
		int randomIndex = distr(gen) ; // generate number

		//Getting random type
		string type = cardTypes[randomIndex];

		//Creating a new card to be added to deck
		Card card(type);

		//Adding card to deck
		remainingCards.push_back(card);

	}
}

void Deck::display()
{

	cout << "\nRemaining cards: " << endl;
	//Iterate over all cards
	for(int i = 0; i < numRemainingCards; i++)
	{
		cout << "Card #" << (i+1) << " ->";

		cout << remainingCards[i].getAssignedType() << ",";

		cout << endl;
	}

}





// ----------------------------------------- Hand Class -----------------------------------------//


Hand::Hand(): cards()
{
	numCards = 0;
}


void Hand::copy(Hand &d)
{
	cards = d.cards;
	numCards = d.numCards;

}

void Hand::display()
{

	cout << "\nCards in Hand: " << endl;
	//Iterate over all cards
	for(int i = 0; i < numCards; i++)
	{
		cout << "Card #" << (i+1) << " ->";

		cout << cards[i].getAssignedType() << ",";

		cout << endl;
	}

}

void Hand::addCard(Card card)
{
	numCards++;
	cards.push_back(card);
}
