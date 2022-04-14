#include <iostream>
#include <vector>
#include <algorithm>
#include "ArrayInt.h"
#include "BlackJack.h"


//Task 1
void Task1()
{
    ArrayInt array;
    array.push_back(5);
    array.push_back(3);
    array.push_back(2);
    array.push_back(16);
    array.push_back(8);
    array.push_back(7);
    array.push_back(9);
    array.push_back(9);
    array.push_back(8);
    array.push_back(8);


    std::cout << "Initial array:";
    array.print();

    array.pop_back();
    std::cout << "Array after pop_back:";
    array.print();

    array.pop_front();
    std::cout << "Array after pop_front:";
    array.print();

    array.sort();
    std::cout << "Sorted array:";
    array.print();
}

//Task 2
void printVector(std::vector<int>& input)
{
    std::cout << "\n";
    for (std::vector<int>::iterator it = input.begin(); it != input.end(); ++it)
        std::cout << *it << " ";
}
int countUniqueNumbers(std::vector<int> input)
{
    std::sort(input.begin(), input.end());
    std::vector<int>::iterator it;
    it = std::unique(input.begin(), input.end());
    input.resize(std::distance(input.begin(), it));
    //printVector(input);
    return input.size();
}


int main()
{
    Task1();

    //Task 2

    std::vector<int> array = { 2, 3, 5, 6, 6, 6, 7, 6, 1, 1, 2, 11, 24, 5311 };
    std::cout << "\nInitial array:";
    printVector(array);
    int count = countUniqueNumbers(array);
    std::cout << "\nUnique numbers: " << count;

    //Task 3

    Card aceClubs(ACE, CLUBS);
    Card aceHearts(ACE, HEARTS);
    Card kingClubs(KING, CLUBS);

    Hand playerHand;
    playerHand.Add(&aceClubs);
    playerHand.Add(&aceHearts);
    playerHand.Add(&kingClubs);

    int sum = playerHand.GetValue();
    std::cout << "\n\nPlayer's hand value is: " << sum;
    playerHand.Clear();
    sum = playerHand.GetValue();
    std::cout << "\nHand cleared! New value is: " << sum;
}

