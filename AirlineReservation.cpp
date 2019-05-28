#include <iostream>
#include <string>
#include <string>
#include <ctime>

using namespace std;

void displayMenu();
void fcBooker(int array[]);
void ecBooker(int array[]);
void reservationStatus(int array[]);

int main()
{
	srand(time(NULL));

	int seatingPlan[10] = { };
	int choice;
	int bookings = 0;

	int fcCounter(0), ecCounter(0);

	bool finished = false;

	string whenFull = "";

	cout << "				Eric's Airline Reservation System				" << endl;
	cout << "			 ===============================================		" << endl;

	cout << "\nWelcome to Eric's Airlines! Please follow the menu options for us to serve you better!" << endl;

	while (bookings < 9)
	{
		displayMenu();
		cout << "\n";
		cin >> choice
			while ((choice < 1) || (choice > 3))
			{
				cout << "please enter a number between 1 and 3" << endl;
				cin >> choice;

			}
		switch (choice)
		{
		case 1:
			fcBooker(seatingPlan);
			fcCounter++;

			if (fcCounter == 5)
			{
				cout << "First class is full, book economy? (yes/no)(Case Sensitive)" << endl;
				cin >> whenFull;

				if ((whenFull == "Yes") && (ecCounter != 5))
					ecBooker(seatingPlan);
				else
					finished = true;
			}
			bookings += 1;

			break;

		case 2:
			ecBooker(seatingPlan);
			ecCounter++;
			if (ecCounter == 5)
			{
				cout << "Economy is full, book first class? (Yes/No)(Case Sensitive)" << endl;
				cin >> whenFull;

				if ((whenFull == "Yes") && (fcCounter != 5))
				{
					fcBooker(seatingPlan);
				}
				else
				{
					finished = True;
				}
			}
			bookings += 1;

		case 3:
			reservationStatus(seatingPlan);
			break

		};
		if (finished)
		{
			break;
		}
	}
	if (bookings == 9)
	{
		reservationStatus(seatingPlan);
		cout << "\nThe plan is full";
	}
	cout << "Next flight leaves in 3 hours" << endl;
}

void displayMenu()
{
	cout << "\n<1>First Class" << endl;
	cout << "<2> Economy Class" << endl;
	cout << "<3> Reservation Class" << endl;
}

void fcBooker(int array[)
{
	int seatNumber = 0;

	while (array[seatNumber - 1] != 0)
	{
		seatNumber = 1 + rand() % 5;
	}
	array[seatNumber - 1] = 1;
	cout << "\nYour seat number is " << seatNumber << " In First Class" << endl;
}

void ecBooker(int array[)
{
	int seatNumber = 0;
	while (array[seatNumber - 1] != 0)
	{
		seatNumber = 6 + rand() % 5;
	}
	array[seatNumber - 1] = 1;
	cout << "\nYour seat number is " << seatNumber << " In Economy Class" << endl;
}

void reservationStatus(int array[])
{
	string reservation;
	cout << "\n";

	for (int i = 0; i <= 9; i++)
	{
		if (array[i] == 1)
		{
			reservation = "RESERVED";
		}

		else
		{
			reservation = "UNRESERVED";
		}

		//if i is less than 5, that means that it is First Class. Else it is Economy Class
		if (i < 5)
		{
			cout << "Seat " << (i + 1) << " First Class: " << reservation << endl;

		}
		else
		{
			cout << "Seat " << (i + 1) << " Economy Class: " << reservation << endl;
		}
	}
}