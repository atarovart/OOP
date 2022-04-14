#include <iostream>
#include "BlackJack.h"

//Task 1

template <class T>
class Pair1
{
private:
    T a, b;
public:
    Pair1(T input1, T input2)
        : a(input1), b(input2) {};

    T first() const
    {
        return a;
    }

    T second() const
    {
        return b;
    }
};

//Task 2

template <typename T1, typename T2>
class Pair
{
private:
    T1 a;
    T2 b;
public:
    Pair() {}
    Pair(T1 inputA, T2 inputB)
        : a(inputA), b(inputB) {}

    T1 first() const
    {
        return a;
    }

    T2 second() const
    {
        return b;
    }
};

//Task 3

template <typename T>
class StringValuePair : public Pair<std::string, T>
{
public:
    StringValuePair(std::string inputString, T inputValue)
        : Pair<std::string, T>(inputString, inputValue) {}
};


int main()
{
    //Task 1

    Pair1<int> p1(6, 9);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    //Task 2

    Pair<int, double> p3(6, 7.8);
    std::cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';

    const Pair<double, int> p4(3.4, 5);
    std::cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';

    //Task 3

    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

    return 0;
}