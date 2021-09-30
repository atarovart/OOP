#include <iostream>
#include <cmath>
#include <cstdint>
using namespace std;

class Power
{
public:
	void setPower(double a, double b)
	{
		m_a = a;
		m_b = b;
		m_c = pow(a, b);
	}
	double calculate()
	{
		cout << "pow: " << m_c << endl;
		return m_c;
	}

private:
	double m_a;
	double m_b;
	double m_c;
};

class RGBA
{
public:
	void setcolors()
	{
		m_red = 0;
		m_green = 0;
		m_blue = 0;
		m_alpha = 255;	
	}
	void user()
	{
		int r = m_red;
		cout << "red: ";
		cin >> r;
		int g = m_green;
		cout << "green: ";
		cin >> g;
		int b = m_blue;
		cout << "blue: ";
		cin >> b;
		int a = m_alpha;
		cout << "alpha: ";
		cin >> a;
	}

	void printRGBA()
	{
		cout << m_red << " " << m_green << " " << m_blue << " " << m_alpha << endl; //не работает..??
	}
private:
	uint8_t m_red;
	uint8_t m_green;
	uint8_t m_blue;
	uint8_t m_alpha;

};

int main()
{
	cout << "Task_1" << endl;
	Power power;
	power.setPower(4, 3);
	power.calculate();
	cout << "--------------------" << endl << "Task_2" << endl;
	RGBA rgba;
	rgba.setcolors();
	rgba.user();
	rgba.printRGBA();


	return 0;
}
//Третье задание не успеваю сделать. Да и со вторым требуется помощь (я новичок, изучаю с самого нуля).
