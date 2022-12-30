#pragma once
#include <string>
using namespace std;
#include"Hostel.h"
#ifndef HOSTELROOM_H
#define	HOSTELROOM_H


class HostelRoom {
private:
		int roomNo;
		int Floor;
		string address="";
		double wattHour;
		double electricCharge;



public:
	HostelRoom();
	HostelRoom(int no, int floor,string name);
	~HostelRoom();
	int getRoomNo();
	int getFloor();
	double getWattHour();
	void setWattHour(double w);
	string getAddress();
	void calElectricCharge(double rate);
	double getElectricCharge();


};
#endif