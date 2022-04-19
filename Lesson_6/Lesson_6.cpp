#include <iostream>
#include <cstdlib>
#include <string>

//Task 1 

int getInt()
{
    std::string input;
    int intInput = 0;

    while (true)
    {
        bool formatCheck = true;
        std::cout << "Enter your number: ";
        std::getline(std::cin, input);
        for (unsigned int i = 0; i < input.length(); i++)
        {
            if (!isdigit(input[i])) formatCheck = false;
        }
        if (formatCheck)
        {
            intInput = std::stoi(input);
            return intInput;
        }
        else
        {
            system("cls");
            std::cerr << "Incorrect format!" << std::endl;
            std::cin.clear();
            //std::cin.ignore(10000, '\n');           
        }
    }
}

//Task 2 

std::ostream& endll(std::ostream& stream)
{
    stream << "\n\n";
    stream.clear();
    return stream;
}

int main()
{
    int result = getInt();
    std::cout << "Your number is " << result << endll << "Task 2 test";
}
