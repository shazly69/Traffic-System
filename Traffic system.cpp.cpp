#include <iostream>
#include <string>
using namespace std;
const int streetSpeed = 80; //speed limit for calculating fines
 
							//data structures

struct Date
{
	int year = 0, month = 0, day = 0;
};
struct Fine
{
	double value = 0;
	string streetName;
	Date dateOfFine;
	string status = "unpaid";
};
struct Car
{
	int plateNumber = 0;
	string model;
	int productionYear = 0;
	Fine fine;
};
struct Driver
{
	int licencseNumber = 0;
	string name;
	Date birthdate;
	Car ownedCars[3];
} drivers[2];

                
                           // functions


float calculateFine(float carSpeed) //This function calculates the value of a certain fine
{
	if (streetSpeed >= carSpeed) return 0;
	return 2 * (carSpeed - streetSpeed);
}
void payFine(int currentDriver, int carNumber)// This function helps the user to pay his fine
{
	for (int i = 0; i < 3; i++)
	{
		if (drivers[currentDriver].ownedCars[carNumber].fine.status == "unpaid")
		{
			drivers[currentDriver].ownedCars[i].fine.status = "paid";
			drivers[currentDriver].ownedCars[i].fine.value = 0;
		}
		else
		{

			break;
		}
	}
}
void createDriver() //Takes the user through all of his information input process
{
	for (int i = 0; i < 2; i++)
	{
		cout << "plese type your name: ";
		cin >> drivers[i].name;
		cout << "\n";

		cout << "please enter your license number: ";
		cin >> drivers[i].licencseNumber;
		cout << "\n";
		cout << "please enter your birth date as folowing(day month year): ";
		cin >> drivers[i].birthdate.year;
		cin >> drivers[i].birthdate.month;
		cin >> drivers[i].birthdate.day;
		cout << "Car information: \n" << endl;
		for (int j = 0; j < 3; ++j)
		{
			char anotherCar;
			cout << "enter car model: " << endl;
			cin >> drivers[i].ownedCars[j].model;
			cout << "enter plate number: " << endl;
			cin >> drivers[i].ownedCars[j].plateNumber;
			cout << "enter production year: " << endl;
			cin >> drivers[i].ownedCars[j].productionYear;
			cout << "Do you want to add another car?(y/n)" << endl;
			cin >> anotherCar;
			if (anotherCar == 'n' || anotherCar == 'N')
			{
				break;
			}

		}
		cout << "Thank you for your information." << endl;
	}
}
void searchViaPlateNumber(int plate) // used to search for a certain car using its plate number
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (plate == drivers[i].ownedCars[j].plateNumber)
			{
				cout << "The info of the Vehicle you searched for: \n";
				cout << "model:   " << drivers[i].ownedCars[j].model << endl;
				cout << "Production Year:   " << drivers[i].ownedCars[j].productionYear << endl;
				if (drivers[i].ownedCars[j].fine.value != 0)
				{
					cout << "Fines due:   " << drivers[i].ownedCars[j].fine.value << "\t"
						<< "the fine's status:   " << drivers[i].ownedCars[j].fine.status << endl;
				}
				else cout << "No fines due." << endl;
			}
		}
	}

}
void searchViaOwnerName(string owner) // used to search for a car using its owner's name
{
	for (int j = 0; j < 2; j++)
	{
		if (owner == drivers[j].name)
		{
			for (int i = 0; i < 3; i++)
			{
				cout << "\n" << drivers[j].ownedCars[i].model << "\t" << drivers[j].ownedCars[i].productionYear << "\t";
				if (drivers[j].ownedCars[i].fine.value != 0)
				{
					cout << "Fines due:   " << drivers[j].ownedCars[i].fine.value << "\t"
						<< "the fine's status:   " << drivers[j].ownedCars[i].fine.status << "\n" << endl;
				}
				else cout << "No fines due.\n" << endl;
			}
		}
	}
}
                        ////// Start of main function



int main()
{
	//main loop of the program

	while (true)
	{
		char typeOfUser;
		string driverName;
		int licenseOfDriver = 0;
		int birthDay = 0, birthMonth = 0, birthYear = 0;
		cout << "You have to Enter 2 drivers' information to proceed!" << endl;
		if (drivers[0].name == "")
		{
			createDriver(); // function calling to create users in the system
		}
		cout << "Are you a driver or traffic man?(d/t): ";
		cin >> typeOfUser;
		if (typeOfUser == 'd')
		{
			//loop for the driver part of the system
			while (true)
			{

				int whichDriver = 0;
				char unPaidFines;
				string driverName;

				while (true)
				{
					cout << "Enter your name: " << endl;

					cin >> driverName;
					if (driverName == drivers[0].name || driverName == drivers[1].name)
					{
						if (driverName == drivers[1].name)
						{
							whichDriver = 1;
						}
						else
							whichDriver = 0;
						break;
					}
					else
					{
						cout << "You entered wrong name! Try another time" << endl;
						continue;
					}

				}

				cout << "Do you want to show total amount of unpaid fines?(y/n)\n";
				cin >> unPaidFines;
				if (unPaidFines == 'y')
				{
					for (int i = 0; i < 3; i++)
					{
						if (drivers[whichDriver].ownedCars[i].fine.status == "unpaid" && drivers[whichDriver].ownedCars[i].fine.value > 0)
						{
							char payfine;
							cout << " value: " << drivers[whichDriver].ownedCars[i].fine.value << "\t" << "status: "
								<< drivers[whichDriver].ownedCars[i].fine.status << endl;
							cout << "Do you want to pay this fine?(y/n)\n";
							cin >> payfine;
							if (payfine == 'y')
							{
								payFine(whichDriver, i);
								cout << drivers[whichDriver].ownedCars[i].fine.status << endl;
							}
							else break;
						}
						else
						{
							cout << "No fines!" << endl;
							break;
						}


					}
				}
				else
				{
					cout << "Do you want to make another process? (y/n)" << endl;
					char anotherProcess;
					cin >> anotherProcess;
					if (anotherProcess == 'y')
					{
						continue;
					}
					else
						break;
				}
				
			}
		}

		else //this is the traffic man's part of the system
		{

			while (true)
			{

				int officerChoice = 0;
				//the next part is a list of options for the traffic man to choose from
				cout << "Welcome officer\n" << "Would you like to:\n \n" << "1-calculate a certain fine.\n"
					<< "2-display driver's cars using his name.\n" << "3-Search driver's car using plate number." << endl << "4-Logout." << endl;
				cin >> officerChoice;
				if (officerChoice == 1)
				{
					int   whichDriver = 0, plateNumber1 = 0;
					float fine = 0, speed = 0;
					char attach;
					cout << "What was the driver's speed?\n";
					cin >> speed;
					fine = calculateFine(speed);
					cout << "the total cost of the fine is:  " << fine << endl;

					cout << "do you want to attach a fine to a car using plate number? (y/n)";
					cin >> attach;
					if (attach == 'y')
					{
						cout << "Which driver you want to attach the fine to?" << endl;
						cout << "1- " << drivers[0].name << endl;

						cout << "2- " << drivers[1].name << endl;
						cin >> whichDriver;
						cout << "Please enter the plate number" << endl;
						cin >> plateNumber1;
						for (int i = 0; i < 3; i++)
						{
							if (drivers[whichDriver - 1].ownedCars[i].plateNumber == plateNumber1)
							{
								drivers[whichDriver - 1].ownedCars[i].fine.value = fine;
								cout << "fine attatched!" << endl;
								break;
							}

						}
					}
					else if (attach == 'n')
					{
						break;
					}

				}


				else if (officerChoice == 2)
				{
					string driverName;
					cout << "Enter the driver's name " << endl;
					cin >> driverName;
					for (int i = 0; i < 2; i++)
					{
						if (drivers[i].name == driverName)
						{
							for (int j = 0; j < 3; j++)
							{
								cout << i + 1 << "-plate number:  " << drivers[i].ownedCars[j].plateNumber << "\t" <<
									"model:  " << drivers[i].ownedCars[j].model << "    the fine recorded to this vehicle is: "
									<< drivers[i].ownedCars[j].fine.status << endl;
								break;

							}
						}
						break;
					}

				}
				else if (officerChoice == 4)
				{
					break;
				}
				else if (officerChoice == 3)
				{
					int plateNumber;
					cout << "Enter the plate number." << endl;
					cin >> plateNumber;
					searchViaPlateNumber(plateNumber);
				}

			}

		}

	}
	return 0;
} // end main