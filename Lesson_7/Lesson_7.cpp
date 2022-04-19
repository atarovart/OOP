#include <iostream>

//Task 1 

class Date
{
private:
	int day, month, year;
public:
	Date()
		: day(0), month(0), year(0) {}
	Date(int inputDay, int inputMonth, int inputYear)
		: day(inputDay), month(inputMonth), year(inputYear) {}

	int getDay()
	{
		return day;
	}

	int getMonth()
	{
		return month;
	}

	int getYear()
	{
		return year;
	}

	friend std::ostream& operator<<(std::ostream& out, const Date& date);
};

std::ostream& operator<<(std::ostream& out, const Date& date)
{
	out << "\n" << date.day << "/" << date.month << "/" << date.year;
	return out;
}

//Task 2 

Date findLaterDate(const std::unique_ptr<Date>& date1, const std::unique_ptr<Date>& date2)
{
	if (date1->getYear() > date2->getYear()) return *date1;
	else if (date1->getYear() < date2->getYear()) return *date2;

	if (date1->getMonth() > date2->getMonth()) return *date1;
	else if (date1->getMonth() < date2->getMonth()) return *date2;

	if (date1->getDay() > date2->getDay()) return *date1;
	else if (date1->getDay() < date2->getDay()) return *date2;

	return *date1;
}

void swapDates(std::unique_ptr<Date>& date1, std::unique_ptr<Date>& date2)
{
	std::swap(date1, date2);
}

int main()
{
	//Task 1 
	std::unique_ptr<Date> today(new Date(17, 9, 2021));
	std::cout << "\n" << today->getDay() << ".0" << today->getMonth() << "." << today->getYear();
	std::cout << *today;
	std::unique_ptr<Date> date(new Date());
	std::swap(today, date);
	std::cout << *date;
	today = nullptr;
	if (date == nullptr) std::cout << "\nPointer \"date\" is null";
	else std::cout << "\nPointer \"date\" is not null";
	if (today == nullptr) std::cout << "\nPointer \"today\" is null";
	else std::cout << "\nPointer \"today\" is not null";
	//Task 2 
	std::unique_ptr<Date> date1(new Date(17, 3, 19));
	std::unique_ptr<Date> date2(new Date(16, 3, 19));
	std::cout << "\n\nLater date is: " << findLaterDate(date1, date2);
	std::cout << "\n\nOld dates:" << *date1;
	std::cout << *date2;
	swapDates(date1, date2);
	std::cout << "\nNew dates (swapped):" << *date1;
	std::cout << *date2;
}
