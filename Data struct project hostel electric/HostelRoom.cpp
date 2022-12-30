#include<iostream>
#include<string>
#include<iomanip>
#include"Hostel.h"
#include"HostelRoom.h"
using namespace std;


HostelRoom::HostelRoom() {

}

HostelRoom::HostelRoom(int no,int floor,string name) {
	this->roomNo = no;
	this->Floor = floor;
	for (int i = 0; i < name.length(); i++)
		name[i] = toupper(name[i]);
	this->address = name + "-" + to_string(floor) + "-" + to_string(roomNo);
}
HostelRoom::~HostelRoom() {

}

int HostelRoom::getRoomNo() {
	return this->roomNo;
}

string HostelRoom::getAddress() {
	return this->address;
}

double HostelRoom::getWattHour()
{
	return wattHour;
}
void HostelRoom::setWattHour(double w) {
	this->wattHour = w;
}

void HostelRoom::calElectricCharge(double rate) {
	this->electricCharge= rate * wattHour;
}

double HostelRoom::getElectricCharge() {
	return this->electricCharge;
}