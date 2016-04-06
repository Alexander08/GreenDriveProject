#pragma once
#include "SpecialTerrain.h"


class STRectangle : public SpecialTerrain {


private:

	STT type;
	string restriction_color;

	Coordinates LUC;
	Coordinates RDC;

public:

	STRectangle();
	STRectangle( const STRectangle& str);

	// ------------- Supraincarcarea Operatorilor =, <<, >>	--------

	STRectangle& operator=(const STRectangle& st);

	friend ostream&  operator<<(ostream& os, STRectangle st);

	friend istream& operator>>(istream is, SpecialTerrain& st);

	// ----------------------- Accesori ---------------------------

	void set_Type(STT type);

	void set_Type(string type);

	void set_Restrction_Color(string color);

	void set_Corner_long(double longi, short int i);

	void set_Corner_lati(double lati, short int i);


	STT get_Type(void);

	string get_Type_toString(void);

	string get_Color(void);



	// ----------------------- Metode -----------------------------

	// Primeste un traseu si o masina si verifica daca masina se afla in zona speciala,returneaza true (0) 
	// daca masina este in zona speciala si false (1) in rest
	int check_car(Coordinates c);

	// ----------------------- Destructor -------------------------

	~STRectangle();
};