#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

enum Suits {
    CLUBS = 0,
    DIAMONDS = 1,
    HEARTS = 2,
    SPADES = 3
};

enum Ranks {
    ACE = 1,
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8,
    NINE = 9,
    TEN = 10,
    JACK = 11,
    QUEEN = 12,
    KING = 13
};

enum Numbers {
    DECKSIZE = 52
};

class Card
{
protected:
    Suits suit = CLUBS;
    Ranks rank = ACE;
    bool isFaceUp = true;
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

    Suits getSuit()
    {
        return suit;
    }

    friend std::ostream& operator<<(std::ostream& out, const Card& card);
};

std::ostream& operator<<(std::ostream& out, const Card& card)
{
    if (card.isFaceUp)
    {
        out << "\n" << card.rank << " " << card.suit;
    }
    else out << "XX";
    return out;
}

class Hand
{
protected:
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

    int GetValue() const
    {
        int sum = 0;
        for (Card* card : hand)
        {
            sum += card->getValue();
        }
        return sum;
    }

    virtual ~Hand()
    {
        Clear();
    }
};

class GenericPlayer : virtual public Hand
{
protected:
    std::string name;
public:
    GenericPlayer(const std::string& inputName)
        : name(inputName) {}

    virtual bool IsHitting() const = 0;

    bool IsBoosted() const
    {
        if (GetValue() > 21) return true;
        else return false;
    }

    void Bust()
    {
        std::cout << "\n" << name << " is Bust!\n";
    }

    friend std::ostream& operator<<(std::ostream& out, const GenericPlayer& genericPlayer);
};

std::ostream& operator<<(std::ostream& out, const GenericPlayer& genericPlayer)
{
    out << "\n" << genericPlayer.name << " has:\n";
    for (Card* card : genericPlayer.hand)
    {
        out << card->getValue() << " " << card->getSuit() << "\n";
    }
    out << genericPlayer.GetValue();
    return out;
}

class Player : virtual public GenericPlayer
{
public:
    Player(const std::string& inputName)
        : GenericPlayer(inputName) {}
    virtual bool IsHitting() const override
    {
        while (true)
        {
            std::cout << "\nTake another card? (Y/N): ";
            char* input = 0;
            std::cin >> input;
            if (std::cin && input == "Y") return true;
            else if (std::cin && input == "N") return false;
            else
            {
                system("cls");
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                std::cout << "Incorrect input!";
            }
        }
    }

    void Win() const
    {
        std::cout << "\n" << name << " have Won!";
    }

    void Lose() const
    {
        std::cout << "\n" << name << " have Lost.";
    }

    void Push() const
    {
        std::cout << "\n" << name << " played a Draw";
    }
};

class House : virtual public GenericPlayer
{
public:
    House()
        : GenericPlayer("Diler") {}

    virtual bool IsHitting() const override
    {
        if (GetValue() <= 16) return true;
        else return false;
    }

    void FlipFirstCard()
    {
        hand.front()->Flip();
    }
};

//Task 3

class Deck : virtual public Hand
{
private:
public:
    void Populate()
    {
        for (int suitCount = CLUBS; suitCount <= SPADES; suitCount++)
        {
            for (int rankCount = ACE; rankCount <= KING; rankCount++)
            {
                Add(new Card(static_cast<Ranks>(rankCount), static_cast<Suits>(suitCount)));
            }
        }
    }

    Deck()
    {
        Populate();
    }

    void Shuffle()
    {
        std::random_shuffle(hand.begin(), hand.end());
    }

    void Deal(Hand& aHand)
    {
        if (!hand.empty())
        {
            aHand.Add(hand.back());
            hand.pop_back();
        }
        else
        {
            std::cout << "No cards left!";
        }

    }

    void AdditionalCards(GenericPlayer& aGenericPlayer)
    {
        while (!aGenericPlayer.IsBoosted() && aGenericPlayer.IsHitting())
        {
            Deal(aGenericPlayer);
        }
        if (aGenericPlayer.IsBoosted()) aGenericPlayer.Bust();
    }
};

class Game
{
private:
    Deck gameDeck;
    House dealerHand;
    std::vector<Player*> players;
public:
    Game(std::vector<std::string> playerNames)
    {
        players.clear();
        players.resize(playerNames.size());
        std::vector<std::string>::const_iterator namesIterator = playerNames.begin();
        while (namesIterator != playerNames.end())
        {
            players.push_back(new Player(*namesIterator));
        }
        gameDeck.Shuffle();
    }

    void Play()
    {

    }


};
