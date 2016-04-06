#pragma once
#include "SpecialTerrain.h"


class STCircle : public SpecialTerrain {


private:

	STT type;
	string restriction_color;

	Coordinates center;
	short int radius;

public:

	STCircle();
	STCircle(STCircle& str);

	// ------------- Supraincarcarea Operatorilor =, <<, >>	--------

	SpecialTerrain& operator=(const STCircle& st);

	friend ostream&  operator<<(ostream& os, STCircle st);

	friend istream& operator>>(istream is, SpecialTerrain& st);

	// ----------------------- Accesori ---------------------------

	void set_Type(STT type);

	void set_Type(string type);

	void set_Restrction_Color(string color);

	void set_Radius(short int radius);

	void set_Center_Long(double longi);

	void set_Center_Lat(double lati);

	STT get_Type(void);

	string get_Type_toString(void);

	string get_Color(void);

	// ----------------------- Metode -----------------------------

	// Primeste un traseu si o masina si verifica daca masina se afla in zona speciala,returneaza true (0) 
	// daca masina este in zona speciala si false (1) in rest
	int check_car(Coordinates c);

	// ----------------------- Destructor -------------------------

	~STCircle();
};