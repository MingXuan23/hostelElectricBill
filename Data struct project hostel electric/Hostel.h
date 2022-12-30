#pragma once
#include <string>
#include<cstring>
#include<iomanip>
#include "HostelRoom.h"
using namespace std;
#ifndef HOSTEL_H
#define	HOSTEL_H

template<class T>
class Node {
public:
	Node();
	Node* link;
	T data;
};

template <class T>
class Hostel {

	private:
		Node<T>* pHead;
		Node<T>* pCurr;
		int numRoom=0;
		double chargeRate=1;
	public:
		Hostel();
		~Hostel();
		void setData(int& a,string text);
		void setChargeRate();
		double getChargeRate();
		void FirstRoom(T a);
		void AddRoom(T a);
		void Tranverse();
		void swap(int a);
		void bubbleSort();
		void bubbleSort(string a);
		int getNumRoom();
		Node<T> * searchRoom(int num);
		Node<T> *middle(Node<T>* pStart, Node<T>* pLast);
		void searchRoom();
		void searchRoom(string a);
};

#endif // !HOSTELROOM_h

template <class T>
Hostel<T> ::Hostel() {}

template <class T>
Hostel<T>::~Hostel() {}

template<class T>
Node<T> ::Node(){}

template<class T>
void Hostel<T>::setData(int&a ,string text) {
	while (true)
	{
		cout << text ;
		cin >> a;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		if (a > 0) {
			break;
		}
		cout << "***Invalid data! Please try again***" << endl;
	}
}
	

template<class T>
int Hostel<T>::getNumRoom() {
	return this->numRoom;
}

template<class T>
void Hostel<T>::setChargeRate() {
	double a;
	bool cont;
	cout << "Current Charge Rate : " << getChargeRate() << " per KWh" << endl;
	do {
		cont = false;
		cout << "Please enter latest Charge Rate : RM";S
		cin >> a;
		if (cin.fail()||a<0)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "***Incorrect Data***" << endl;
			cont = true;
		}
		
	} while (cont);
	this->chargeRate = a;
}

template <class T>
double Hostel<T>::getChargeRate()
{
	return this->chargeRate;
}
template <class T>
void Hostel<T>::FirstRoom(T a) {
	Node<T>* pNew = new Node<T>;
	numRoom ++;
	pNew->data = a;
	pHead = pNew;
	pCurr = pHead;
}

template <class T>
void Hostel<T>::AddRoom(T a) {
	Node<T>* pNew = new Node<T>;
	pNew->data = a;
	pCurr->link = pNew;
	pCurr = pNew;
	numRoom++;
}

template <class T>
void Hostel<T>::Tranverse() {
	pCurr = pHead;
	int i = 0;
	try {
		cout << setfill('-') << setw(45)  << '\n';
		cout << "|"<<setfill(' ') << setw(12) << "Room " << "|" << setw(10) << "kWh used" << "|" << setw(18) << "Electric Bill (RM)" << "|" << endl;
		cout << setfill('-') << setw(45)  << '\n';
		while (pCurr!= NULL && i++ < numRoom)
		{
			pCurr->data.calElectricCharge(getChargeRate());
			cout << "|" << setfill(' ') << setw(12) << pCurr->data.getAddress() << "|" << setw(10) << setprecision(3) << fixed<< pCurr->data.getWattHour() << "|"
				<< setw(18) <<setprecision(2)<<fixed<< pCurr->data.getElectricCharge() << "|" << endl;
			
			pCurr = pCurr->link;
		}
		cout << setfill('-') << setw(45) << '\n';
	}
	catch(const char* e)
	{
	}
	
}

template <class T>
void Hostel<T>::swap(int a) {
	
	Node<T>* A = searchRoom(a);
	Node<T>* B = searchRoom(a+1);
	if (A == NULL || B == NULL)
		return;
	Node<T>* Temp = new Node<T>;
	if (a != 1)
	{
		Node<T>* befA = searchRoom(a - 1);
		
		befA->link = B;
		Temp=B->link ;
		B->link = A;
		A->link = Temp;
	}
	else
	{
		pHead = B;
		Temp = B->link;
		pHead->link = A;
		A->link = Temp;	
	}
}

template <class T>
Node<T>* Hostel<T>::searchRoom(int num)
 {
	pCurr = pHead;
	//cout << num << endl;
	int i = 0;
	while (pCurr->data.getAddress() != "" && ++i < num)
	{
			pCurr = pCurr->link;
	}
	return pCurr;
}

//binary search
template<class T>
void Hostel<T>::searchRoom() {
	bubbleSort("Sort by Address");
	string key;
	bool found = 0;
	cout << "Enter the room no: ";
	cin >> key;
	for (int i = 0; i < key.length(); i++)
		key[i] = toupper(key[i]);
	Node<T>* pStart = pHead;
	Node<T>* pLast = NULL;
	do {
		Node<T>* pMiddle = middle(pStart, pLast);
		//if middle element is NULL
		if (pMiddle == NULL) {
			break;
		}
		string address = pMiddle->data.getAddress();
		int result = key.compare(address);
		if (result == 0) {
			cout << "\n****Room Found****" << endl;
			cout << "Room No: " << pMiddle->data.getAddress() << endl;
			cout << "kWh used :" << pMiddle->data.getWattHour() << endl;
			cout << "Total electric bill : RM" << pMiddle->data.getElectricCharge() << endl;
			found = 1;
			break;
		}
		// If value is more than mid 
		else if (result > 0)
			pStart = pMiddle->link;
		else//if value is less than mid
			pLast = pMiddle;//last pointer to the middle element
	} while (pLast == NULL || pStart != pLast);
	if (!found) {
		cout << "\n****Room Is Not In The List****" << endl << endl;
	}
}

template<class T>
void Hostel<T>::searchRoom(string a) {
	bubbleSort("Sort by Address");
	string key;
	bool found = 0;
	cout << "Enter the room no: ";
	cin >> key;
	for (int i = 0; i < key.length(); i++)
		key[i] = toupper(key[i]);
	Node<T>* pStart = pHead;
	Node<T>* pLast = NULL;
	do {
		Node<T>* pMiddle = middle(pStart, pLast);
		//if middle element is NULL
		if (pMiddle == NULL) {
			break;
		}
		string address = pMiddle->data.getAddress();
		int result = key.compare(address);
		if (result == 0) {
			cout << "\n****Room Found****" << endl;
			cout << "Room No: " << pMiddle->data.getAddress() << endl;
			cout << "Current kWh used : " << pMiddle->data.getWattHour() << endl;
			double watt;
			bool cont;
			do {
				cout << "Enter the updated kWh :";
				cont = false;
				cin >> watt;
				if (cin.fail() || watt < 0)
				{
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "***Invalid Data***" << endl;
					cont = true;
				}
			} while (cont);

			pMiddle->data.setWattHour(watt);
			pMiddle->data.calElectricCharge(chargeRate);
			found = 1;
			cout << "\n****Updated Info****" << endl;
			cout << "Room No: " << pMiddle->data.getAddress() << endl;
			cout << "kWh used :" << pMiddle->data.getWattHour() << endl;
			cout << "Total electric bill : RM" << pMiddle->data.getElectricCharge() << endl;
			break;
		}
		// If value is more than mid 
		else if (result > 0)
			pStart = pMiddle->link;
		else//if value is less than mid
			pLast = pMiddle;//last pointer to the middle element
	} while (pLast == NULL || pStart != pLast);
	if (!found) {
		cout << "\n****Room Is Not In The List****" << endl << endl;
	}
}

template <class T>
Node<T>* Hostel<T>::middle(Node<T>* pStart, Node<T>* pLast) {
	if (pStart == NULL) {
		return NULL;
	}
	Node<T>* pSlow = pStart;
	Node<T>* pFast = pStart->link;

	while (pFast != pLast) {
		pFast = pFast->link;//moved one step ahead
		if (pFast != pLast) {
			pSlow = pSlow->link;//moved one step ahead
			pFast = pFast->link;//moved second step ahead
		}
	}
	return pSlow;//after the loop pSlow is in the middle
}

template<class T>
void Hostel<T>::bubbleSort() {

	int numRoom = getNumRoom();
	while (numRoom > 0)
	{
		for (int i = 1; i <=numRoom-1; i++)
		{	
			Node<T>* roomBef = searchRoom(i);
			Node<T>* roomAft = searchRoom(i + 1);
			double wattRoomBef = roomBef->data.getWattHour();
			double wattRoomAft = roomAft->data.getWattHour();
			if (wattRoomBef<wattRoomAft)
			{
				swap(i);
			}
		}
		numRoom--;
	}
}

template<class T>
void Hostel<T>::bubbleSort(string a) {
	int numRoom = getNumRoom();
	while (numRoom > 0)
	{
		for (int i = 1; i <= numRoom - 1; i++)
		{
			Node<T>* roomBef = searchRoom(i);
			Node<T>* roomAft = searchRoom(i + 1);
			string addrRoomBef = roomBef->data.getAddress();
			string addrRoomAft = roomAft->data.getAddress();
			int result = addrRoomBef.compare(addrRoomAft);
			if (result>0&&addrRoomBef.length() >= addrRoomAft.length())
			{
				swap(i);
			}
		}
		numRoom--;
	}
}

