#pragma once
#include <string>
#include "CoordinatesAndTimeSTT.h"

using namespace std;

class SpecialTerrain {

public:

	// ------------- Supraincarcarea Operatorilor =, <<, >>	--------

//	virtual SpecialTerrain& operator=(const SpecialTerrain& st) = 0;

	// ----------------------- Accesori ---------------------------
	
	virtual void set_Type(STT type) = 0;
	
	virtual void set_Type(string type) = 0;
	
	virtual void set_Restrction_Color(string color) = 0;

	virtual STT get_Type(void) = 0;
	
	virtual string get_Type_toString(void) = 0;

	virtual string get_Color(void) = 0;

	// ----------------------- Metode -----------------------------

	// Primeste un traseu si o masina si verifica daca masina se afla in zona speciala,returneaza true (0) 
	// daca masina este in zona speciala si false (1) in rest
	virtual	int check_car(Coordinates c) = 0;
};