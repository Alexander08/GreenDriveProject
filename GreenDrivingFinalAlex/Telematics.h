#pragma once
#include <string>
#include <vector>

#include "CoordinatesAndTimeSTT.h"

using namespace std;

class Telematics {

private:

	vector<Coordinates> coordinates;
	vector<int> speed;
	vector<time_t> utc;

public:

	// ----------------------- Constructorii -----------------------
	Telematics();
	Telematics( const Telematics& t );
	Telematics::Telematics(vector<time_t> utc, vector<Coordinates> coordinates, vector<int> speed);

	// ------------- Supraincarcarea Operatorilor =, <<, >>	--------

	Telematics& operator=( const Telematics& t);

	friend ostream& operator<<(ostream &os, const Telematics t);

	friend istream& operator>>(istream &is, Telematics& t);

	// ----------------------- Accesori ---------------------------

	// Adauga un set de coorodonate la finalul vectorului
	void set_coordinates( Coordinates c);

	// Adauga latitudine la ultimul set de coordonate din vector
	void set_coordinates_lat(double lat);

	// Adauga longitudine la ultimul set de coordonate din vector
	void set_coordinates_long(double longi);

	// Adauga viteza la finalul vectorului care inregistreaza viteza
	void set_speed(int speed);
	
	// Adauga o valoarea la finalul ultimei structuri de timp din vector
	void set_utc(time_t utc);

	vector<int> get_speed();

	vector<time_t> get_utc_vector();

	vector<Coordinates> get_Coodrdinates();

	// ----------------------- Metode -----------------------------
	// -----Pentru debugging -----------
	void show_telematics_parameters();

	double avg_speed();

	// ----------------------- Destructor -------------------------

	~Telematics();

};

