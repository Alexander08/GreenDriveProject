#pragma once
#include "Ecologic.h"
#include <Windows.h>
#include <iostream>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <stdlib.h>

#include <math.h>

#define R 6371
#define TO_RAD (3.1415926536 / 180)

using namespace std;

	// ----------------------- Construcotri -----------------------

Ecologic::Ecologic()
{
	this->car_name = string("Anonim");
	this->traseu.reserve(1);
	this->traseu.push_back(Optimal());
}

Ecologic::Ecologic(const Ecologic & e)
{
	this->car_name = string(e.car_name);
	this->traseu = e.traseu;
}

	// ------------- Supraincarcarea Operatorilor =, <<, >>	--------

ostream & operator<<(ostream & os, const Ecologic e)
{
	for (unsigned int i = 0; i < e.traseu.size(); i++) {
		os << fixed << setprecision(14);
		os << "Coordonatele de inceput: " << endl << e.traseu.at(i).start.Latitude << endl;
		os << e.traseu.at(i).start.Longitude << endl;
		os << "Coordonatele de final: " << endl << e.traseu.at(i).end.Latitude << endl;
		os << e.traseu.at(i).end.Longitude << endl;
		os << "Numarul de puncte: " << e.traseu.at(i).nr_of_points << endl;
		os << fixed << setprecision(2);
		os << "Viteza medie:  " << e.traseu.at(i).avg_speed << endl;
		os << "---------------------" << endl;
		Sleep(300);
		if (_kbhit())
			if (_getch() == 's') break;
	}

	return os;
}

	// ----------------------- Accesori ---------------------------



	// ----------------------- Metode -----------------------------



vector<Optimal> Ecologic::get_traseu()
{
	return this->traseu;
}

void Ecologic::build_traseu(Automobil a, int inedx_traseu)
{
	int cnt = 1;	// nr de puncte cu viteza optima
	int i = 0;		// nr de puncte de variatie

	int sum_speed = 0;
	vector<int> p = a.telematic_auto.at(inedx_traseu).get_speed();
	this->car_name = a.get_name();
	this->traseu.at(0).start = a.telematic_auto.at(inedx_traseu).get_Coodrdinates().at(0);
	int size = p.size();
	cout << "\t --------- Loading... 0% -------------" << endl;
	for ( int it = 0; it < size - 1; it++) {
	
		if ( abs( p.at(it + 1) - p.at(it) ) > 9 ) { // omori procesorul aici si in for (optimizeaza urgent!!! 18.59 sec)
			sum_speed += p.at(it);
			this->traseu.at(i).end = a.telematic_auto.at(inedx_traseu).get_Coodrdinates().at(it);
			this->traseu.at(i).nr_of_points = cnt;
			this->traseu.at(i).avg_speed = (double)sum_speed / (double)cnt;

			this->traseu.push_back(Optimal());
			i++;
			this->traseu.at(i).start = a.telematic_auto.at(inedx_traseu).get_Coodrdinates().at(it + 1);
			cnt = 1;
			sum_speed = 0;
		}
		else {
			sum_speed += p.at(it);
			cnt++;
		}
		if (it == (size/2) ) cout << "\t --------- Loading...50% -------------" << endl;
		if (it == (3*size / 4)) cout << "\t --------- Loading...75% -------------" << endl;
	}
	cout << "\t\t Analiza completa!" << endl;
}


void Ecologic::calculate_time(Automobil a)
{
	time_t durata = a.telematic_auto.begin()->get_utc_vector().at(a.telematic_auto.begin()->get_utc_vector().size() - 1) / 1000 - a.telematic_auto.begin()->get_utc_vector().at(0)/1000;

	const time_t end = a.telematic_auto.begin()->get_utc_vector().at(a.telematic_auto.begin()->get_utc_vector().size() - 1) / 1000;
	const time_t start = a.telematic_auto.begin()->get_utc_vector().at(0) / 1000;


	cout << "start: " << ctime(&start) << endl;
	cout << "end: " << ctime(&end) << endl;

	cout << (durata / 60.0) / 60.0 << " ore a durat calatoria" << endl;
}

void Ecologic::time_between_two_points(Automobil a)
{

	for (vector<Telematics>::iterator i = a.telematic_auto.begin(); i != a.telematic_auto.end(); ++i){
	
		cout << "Incepe primul traseu\n==================================" << endl;
		for (unsigned int t = 0; t < (*i).get_utc_vector().size() - 1; t++) {
		
			cout << "Au trecut " << (*i).get_utc_vector().at(t+1) - (*i).get_utc_vector().at(t) << " milisecunde intre cele doua puncte" << endl;
			
			const time_t tt = (const time_t)( (*i).get_utc_vector().at(t) /1000);
			cout << "timpul: " << ctime(&tt) << endl;
		}
	}
	cout << "----------------Gata!--------------------------" << endl;
}

void Ecologic::print_GreenDrive( Automobil a)
{
	string line(61, '-');
	line.at(21) = '|';
	double point;
	int pos;

	double p100 = 1.0;
	double p0 = (double) a.get_max_speed() / (double) a.get_avg_speed();

	int length = this->traseu.size();
	line.replace(0,6, "(-50%)");
	line.replace(10,6, "(-25%)");
	line.replace(20,3, "0%");
	line.replace(30,3, "25%");
	line.replace(40,3, "50%");
	line.replace(50,3, "75%");
	line.insert(60, "100%");
	cout << setw(4) << 0 << ". " << line << endl;
	line = string(61, '.');
	line.at(21) = '|';
	for (int i = 0; i < length; i++) {
	
		// check_car() geofence - 
		point = (double) this->traseu.at(i).avg_speed / (double)a.get_avg_speed();
		point = point/ (p0 - 1.0);
		point = point * 40;
		pos = (int)point + 19;
		if (pos == 21) pos++;
		if (pos >= 61) pos = 60;

		line.at(pos) = 'X';
		cout << setw(4) << i + 1 << ". " << line << endl;
		line = string(61, '.');
		line.at(21) = '|';
	}
	line.replace(0, 4, "-50%");
	line.replace(10, 4, "-25%");
	line.replace(20, 3, "0%");
	line.replace(30, 3, "25%");
	line.replace(40, 3, "50%");
	line.replace(50, 3, "75%");
	line.insert(60, "100%");
	cout << setw(4) << "F!" << ". " << line << endl;
	cout << "Final Grafic Geofence! " << endl;
}

double Ecologic::distance_between_two_points(double th1, double ph1, double th2, double ph2)
{
	double dx, dy, dz;
	ph1 -= ph2;
	ph1 *= TO_RAD, th1 *= TO_RAD, th2 *= TO_RAD;

	dz = sin(th1) - sin(th2);
	dx = cos(ph1) * cos(th1) - cos(th2);
	dy = sin(ph1) * cos(th1);
	return asin(sqrt(dx * dx + dy * dy + dz * dz) / 2) * 2 * R;
}


	// ----------------------- Destructor -------------------------


Ecologic::~Ecologic()
{
}

