#pragma once
#include <iostream>
#include <vector>

enum Suits {
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
};

enum Ranks {
    ACE = 1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING
};

class Card
{
private:
    Suits suit = CLUBS;
    Ranks rank = ACE;
    bool isFaceUp = false;
public:
    Card() {}
    Card(Ranks inputRank, Suits inputSuit)
        : suit(inputSuit), rank(inputRank)
    {

    }
    void Flip()
    {
        isFaceUp = !isFaceUp;
    }

    Ranks getValue()
    {
        return rank;
    }
};

class Hand
{
private:
    std::vector<Card*> hand;
public:
    void Add(Card* input)
    {
        hand.push_back(input);
    }

    void Clear()
    {
        hand.clear();
    }

    int GetValue()
    {
        int sum = 0;
        for (Card* card : hand)
        {
            sum += card->getValue();
        }
        return sum;
    }
};

//Task 4 

class GenericPlayer : public Hand
{
private:
    std::string name;
public:
    GenericPlayer(std::string inputName)
        : name(inputName) {}

    virtual void IsHitting() = 0;

    bool IsBoosted()
    {
        if (GetValue() > 21) return true;
        else return false;
    }

    void Bust()
    {
        std::cout << "\n" << name << " is Bust!\n";
    }
};
