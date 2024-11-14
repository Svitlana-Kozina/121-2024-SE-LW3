#include <iostream>
#include <limits>
#include <iomanip>
#include <cmath>

void checkValidInput()
{
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		throw "You entered invalid data. Please enter exactly a number, not a letter or symbol.";
	}
}

double roundTo2DPlaces(double parameter)
{
	return std::nearbyint(parameter * 100.0) / 100.0;
}


double inputX() 
{
	double x{};
	std::cout << "Enter number x: ";
	std::cin >> x;
	checkValidInput();
	return x;
}

void checkValidParams (int n)
{
	if (n <= 4)
		throw "You entered invalid data. n must be greater than 4.";
}

int inputN()
{
	int n{};
	std::cout << "Enter integer n greater than 4: ";
	std::cin >> n;
	checkValidInput();
	checkValidParams(n);
	return n;
}

double calculate(double x, int n)
{	
	double y{};
	if (x <= 0)
	{
		y = 1.;
		for (int i = 0; i <= n - 1; i++)
		{
			y *= (i * i * i) + i;
		}
	}
	else
	{
		y = 0.;
		for (int i = 0; i <= n - 1; i++)
		{
			for (int j = 0; j <= n - 1; j++)
			{
				if ((i + j) != 0)
				{
					y += (x / (i + j));
				}
			}
		}
	}
	return  roundTo2DPlaces(y);
}

void printY(double parameter1) 
{
	std::cout << "y = " << parameter1 << std::endl;
}

int main()
{
	std::cout << std::fixed << std::setprecision(2);
	bool ready = false;
	double x{};
	int n{};
	while (ready == false)
	{
		try
		{
			x = inputX();
			ready = true;
		}
		catch (const char* e)
		{
			std::cerr << e << std::endl;
		}
		catch (...)
		{
			std::cerr << "Unknown exception" << std::endl;
		}
	}
	ready = false;
	while (ready == false)
	{
		try
		{
			n = inputN();
			ready = true;
		}
		catch (const char* e)
		{
			std::cerr << e << std::endl;
		}
		catch (...)
		{
			std::cerr << "Unknown exception" << std::endl;
		}
	}				
	printY(calculate(x,n));
			
	return 0;
}


