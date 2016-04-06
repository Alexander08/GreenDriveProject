#pragma once
#include <string>
#include <vector>

#include "Automobil.h"

#include "CoordinatesAndTimeSTT.h"

using namespace std;

class Ecologic{

private:

	string car_name;
	vector<Optimal> traseu;

public:

	// ----------------------- Construcotri -----------------------
	Ecologic();

	Ecologic(const Ecologic& e);

	// ------------- Supraincarcarea Operatorilor =, <<, >>	--------

	Ecologic& operator=(Ecologic& e);

	friend ostream& operator<<(ostream &os, const Ecologic e);
	friend istream& operator>>(istream &is, Ecologic& e);

	// ----------------------- Accesori ---------------------------

	vector<Optimal> get_traseu();

	// ----------------------- Metode -----------------------------

	void build_traseu(Automobil a, int i);

	// Calculeaza distanta traseului intre doua puncte de coordonate
	void calculate_distance();

	// Calculeaza distanta dintre doua puncte consecutive
	int distance_speed_between_two_points(Automobil a);

	// Calculeaza timpul necesar pentru parcurgerea traseului
	void calculate_time(Automobil a);

	// Calculeaza timpul dintre doua puncte consecutive
	void time_between_two_points(Automobil a);

	void print_GreenDrive( Automobil a);

	double distance_between_two_points(double th1, double ph1, double th2, double ph2);

	// ----------------------- Destructor -------------------------
	~Ecologic();

};