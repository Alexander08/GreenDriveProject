#include <string>
#include <vector>
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <iomanip>

#include "Telematics.h"

using namespace std;

Telematics::Telematics(){
	this->coordinates.clear();

	this->speed.clear();

	this->utc.clear();
}

Telematics::Telematics::Telematics(vector<time_t> utc, vector<Coordinates> coordinates, vector<int> speed) {

	this->coordinates = coordinates;

	this->speed = speed;

	this->utc = utc;

}

Telematics::Telematics(const Telematics& t){

	this->coordinates.clear();

	this->coordinates = vector<Coordinates>(t.coordinates.begin(), t.coordinates.end());
	
	//this->coordinates = t.coordinates;

	this->speed = t.speed;

	this->utc = t.utc;

}

	// ------------- Supraincarcarea Operatorilor =, <<, >>	--------

Telematics& Telematics::operator=(const Telematics& t) {

	if (this == &t) return *this;

	this->coordinates.clear();

	this->coordinates = vector<Coordinates>(t.coordinates.begin(), t.coordinates.end());

//	this->coordinates = t.coordinates;

	this->speed = t.speed;

	this->utc = t.utc;

	return *this;

}

ostream& operator<<(ostream & os, const Telematics t) {

	for (unsigned short int i = 0; i < t.coordinates.size(); i++) {
		os << "....punct " << i << "..........." << endl;
		os << t.utc.at(i) << endl;
		os << fixed << setprecision(15) << t.coordinates.at(i).Longitude << endl;
		os << fixed << setprecision(15) << t.coordinates.at(i).Latitude << endl;
		os << fixed << setprecision(2) << t.speed.at(i) << endl;
		Sleep(140);
		if (_kbhit())
			if(_getch() == 's') break;
	}
	return os;
}

	// ----------------------- Accesori ---------------------------

void Telematics::set_coordinates(Coordinates c)
{
	this->coordinates.push_back(c);
}

void Telematics::set_coordinates_lat(double lat)
{
	this->coordinates.back().Latitude = lat;
}

void Telematics::set_coordinates_long(double longi)
{
	this->coordinates.back().Longitude = longi;
}

void Telematics::set_speed(int speed) {
	
	this->speed.push_back(speed);
}

void Telematics::set_utc(time_t utc) {
	
	this->utc.push_back(utc);
}

vector<int> Telematics::get_speed()
{
	return this->speed;
}

vector<time_t> Telematics::get_utc_vector()
{
	return this->utc;
}

vector<Coordinates> Telematics::get_Coodrdinates()
{
	return this->coordinates;
}


	// ----------------------- Metode -----------------------------

void Telematics::show_telematics_parameters() {

	cout << "Vectorul de coordinates are urmatoarele proprietati:" << endl;
	cout << "Capacitate: " << this->coordinates.capacity() <<endl;
	cout << "Marime: " << this->coordinates.size() << endl;
	cout << "Max size: " << this->coordinates.max_size() << endl;

	cout << "Vectorul de utc are urmatoarele proprietati:" << endl;
	cout << "Capacitate: " << this->utc.capacity() << endl;
	cout << "Marime: " << this->utc.size() << endl;
	cout << "Max size: " << this->utc.max_size() << endl;
	
	cout << "Vectorul de speed are urmatoarele proprietati:" << endl;
	cout << "Capacitate: " << this->speed.capacity() << endl;
	cout << "Marime: " << this->speed.size() << endl;
	cout << "Max size: " << this->speed.max_size() << endl;
}

double Telematics::avg_speed()
{
	double avg = 0;
	int ii = 0;
	for (vector<int>::iterator i = this->speed.begin(); i != this->speed.end(); ++i) {
		//cout << *i << "\t";
		//ii++;
		//if (ii == 239) break;
		avg =(double) avg + ((double)*i / (double)this->speed.size());

	}
	return avg;
}

	// ----------------------- Destructor -------------------------

Telematics::~Telematics() {	}
