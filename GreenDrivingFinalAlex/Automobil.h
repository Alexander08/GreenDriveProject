#pragma once
#include "Telematics.h"
#include <string>
#include <vector>

using namespace std;

class Automobil {

private:

	string name;
	string engine;

	int max_speed;
	int engine_cc;

	int avg_consumption_urban;
	int avg_speed_urban;

	int avg_consumption;
	int avg_speed;

	static int nr_masini;

public:
	// Folosim Vector pentru a permite adaugarea de noi trasee din
	// fisiere (conform enuntului proiectului)
	vector<Telematics> telematic_auto;

	// constructor fara pearametrii
	Automobil();

	// constructor de copiere
	Automobil(const Automobil& a);

	// constructor cu parametri
	Automobil(string nume, string motor, int viteza, int cc, int consum_urban, int viteza_urban, int consum_mediu, int viteza_medie);

	//-------------- Superaincarcare operatori 

	Automobil& operator=( const Automobil& a);

	friend ostream& operator<<(ostream &os, Automobil a);

	friend istream& operator>>(istream &is, Automobil& a);

	// ------------- Metode de access la parametrii (Accesori) -----

	static int get_Nr_masini();

	string get_name();
	void set_name(string name);

	string get_engine();
	void set_engine(string engine);

	int get_max_speed();
	void set_max_speed(int max_speed);

	int get_engine_cc();
	void set_engine_cc(int engine_cc);

	int get_avg_speed_urban();
	void set_avg_speed_urban(int avg_speed);

	int get_avg_speed();
	void set_avg_speed(int avg_speed);

	int get_avg_consumption_urban();
	void set_avg_consumption_urban(int avg_consumption_urban);

	int get_avg_consumption();
	void set_avg_consumption(int avg_consumption);

	void set_telematics_auto(Telematics ts);

	// ------------ Alte Metode ----------------------------------
	

	//------------- Destructorul ---------------------------------

	~Automobil();
};