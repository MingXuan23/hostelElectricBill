#include<iostream>
#include<string>
#include<iomanip>
#include"HostelRoom.h"
#include "Hostel.h"
using namespace std;

int main() {
	Hostel<HostelRoom> Kasturi;
	int floor, room;
	cout << "***Welcome to Kasturi Electric Bill Management System***\n\n" << endl;
	Kasturi.setData(floor, "Please enter the number of floors : ");
	Kasturi.setData(room, "Please enter the number of rooms each floor : ");
	cout << "\nPlease complete the data insertion below" << endl;
	for (int i = 1; i <= floor; i++)//floor
	{
		for (int j = 1; j <= room; j++)//room no
		{
			
			HostelRoom roomNew(j, i, "K");
			double a;
			do{
				cout << "Please enter kWh of " << roomNew.getAddress() << " : ";
				cin >> a;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "***Incorrect Data!***" << endl;
					continue;
				}
				if (a >= 0)
					break;
				cout << "***Incorrect Data!***" << endl;
			} while (1);
			
			roomNew.setWattHour(a);
			roomNew.calElectricCharge(Kasturi.getChargeRate());
			if (i == 1 &&j==1)
			{
				Kasturi.FirstRoom(roomNew);
			}
			else
			{
				Kasturi.AddRoom(roomNew);
			}
			
		}		
	}
	int choice;
	do
	{
		cout << "\n\n***OPTION***" << endl;
		cout << "1.Display Hostel Room based on kWh" << endl;
		cout << "2.Display Hostel Room based on Room Number" << endl;
		cout << "3.Update Charge Rate" << endl;
		cout << "4.Search Hostel Room" << endl;
		cout << "5.Edit kWh used of the selected room" << endl;
		cout << "0.Exit" << endl;
		cout << "choice : ";
		cin >> choice;
		if (cin.fail()||choice>5||choice<0)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\n***invalid action***" << endl;
			cout << "choice : ";
			cin >> choice;
			if (cin.fail() ||choice > 5 || choice < 0)
				break;
		}
		cout << endl;
		switch (choice)
		{
		case 1:
			Kasturi.bubbleSort();
			Kasturi.Tranverse();
			break;
		case 2:
			Kasturi.bubbleSort("Address");
			Kasturi.Tranverse();
			break;
		case 3:
			Kasturi.setChargeRate();
			break;
		case 4:
			Kasturi.bubbleSort("Address");
			Kasturi.searchRoom();
			break;
		case 5:
			Kasturi.bubbleSort("Address");
			Kasturi.searchRoom("Edit");
			break;
		}
	} while (choice!=0);
	cout << "*****Thank you for using our programme*****" << endl;
}