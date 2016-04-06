#include "Automobil.h"
#include <string>
#include <Windows.h>
#include <conio.h>

using namespace std;

// ------------- Constructorii ---------------------------------

int Automobil::nr_masini = 0;

Automobil::Automobil(){

	this->name.clear();
	this->engine.clear();

	this->max_speed = 0;
	this->engine_cc = 0;

	this->avg_consumption_urban = 0;
	this->avg_speed_urban = 0;

	this->avg_consumption = 0;
	this->avg_speed = 0;

	this->telematic_auto.reserve(1);
	this->telematic_auto.clear();

	this->nr_masini++;
}

	// constructor cu parametri fara telematics
Automobil::Automobil(string nume, string motor, int viteza, int cc, int consum_urban, int viteza_urban, int consum_mediu, int viteza_medie)
{
	this->name = string(nume);
	this->engine = string(motor);

	this->max_speed = viteza;
	this->engine_cc = cc;

	this->avg_consumption_urban = consum_urban;
	this->avg_speed_urban = viteza_urban;

	this->avg_consumption = consum_mediu;
	this->avg_speed = viteza_medie;

	this->telematic_auto.reserve(1);

	this->nr_masini++;
}

	//constructor de copiere

Automobil::Automobil(const Automobil& a){

	this->name = string(a.name);
	this->engine = string(a.engine);

	this->max_speed = a.max_speed;
	this->engine_cc = a.engine_cc;

	this->avg_consumption_urban = a.avg_consumption_urban;
	this->avg_speed_urban = a.avg_speed_urban;

	this->avg_consumption = a.avg_consumption;
	this->avg_speed = a.avg_speed;

	this->telematic_auto = a.telematic_auto;

	this->nr_masini++;
}

	// ------------- Supraincarcarea Operatorilor =, <<, >>	--------

Automobil& Automobil::operator = (const Automobil& a){

	if (this == &a) return *this;

	this->name = string(a.name);
	this->engine = string(a.engine);

	this->max_speed = a.max_speed;
	this->engine_cc = a.engine_cc;

	this->avg_consumption_urban = a.avg_consumption_urban;
	this->avg_speed_urban = a.avg_speed_urban;

	this->avg_consumption = a.avg_consumption;
	this->avg_speed = a.avg_speed;

	this->telematic_auto = a.telematic_auto;

	return *this;
}

ostream& operator<<(ostream &os, Automobil a) {


	os << "\n===== Automobilul cu numele: " << a.name << "=====" << endl;
	os << "Are urmatoarele proprietati" << endl;
	os << "Engine: " << a.engine << endl;
	os << "Viteza Maxima: " << a.max_speed << endl;
	os << "Capacitate Cilindrica: " << a.engine_cc << endl;
	os << "Consumul Mediu Urban: " << a.avg_consumption_urban << endl;
	os << "Viteza medie Urbana: " << a.avg_speed_urban << endl;
	os << "Consumul Mediu: " << a.avg_consumption << endl;
	os << "Viteza Medie: " << a.avg_speed << endl;
	os << "-----------------------------------------" << endl << endl;
	os << "Vizualizati traseul Inregistrat?: ( apasati tasta \"y\") " << endl;
	os << "Atentie! dureaza foarte mult timp ( aprox 30 min) " << endl;
	os << "Operatia poate fi intrerupta apasand tasta \"s\" " << endl;


	if (_getch() == 'y')
	for (vector<Telematics>::iterator i = a.telematic_auto.begin(); i != a.telematic_auto.end(); i++) {

		os << *i << endl;

		os << "Sfarsitul traseului!" << endl;
		os << "Un nou traseu incepe in 3 secunde" << endl;
		Sleep(3000);
	}
	os << "Pentru parametrii vectorului apasati tasta p" << endl;
	if (_getch() == 'p') a.telematic_auto.at(0).show_telematics_parameters();
	os << "------Final Aubomobil--------" << endl;

	return os;
}

istream& operator>>(istream &is, Automobil& a){

	char * buff = new char;

	fgets(buff, BUFSIZ, stdin);
	a.name = string(buff);

	fgets(buff, BUFSIZ, stdin);
	a.engine = string(buff);

	fgets(buff, BUFSIZ, stdin);	
	a.max_speed = atoi(buff);

	fgets(buff, BUFSIZ, stdin);
	a.engine_cc = atoi(buff);

	fgets(buff, BUFSIZ, stdin);
	a.avg_consumption_urban = atoi(buff);
	
	fgets(buff, BUFSIZ, stdin);
	a.avg_speed_urban = atoi(buff);
	
	fgets(buff, BUFSIZ, stdin);
	a.avg_consumption = atoi(buff);
	
	fgets(buff, BUFSIZ, stdin);
	a.avg_speed = atoi(buff);

	return is;
}
	
	// ------------- Metode de access la parametrii (Accesori) -----

int Automobil::get_Nr_masini(){

	return nr_masini;
}

string Automobil::get_name(){

	return this->name; 
}

void Automobil::set_name(string name){ 

	this->name = string(name); 
}

string Automobil::get_engine(){ 

	return this->engine; 
}

void Automobil::set_engine(string engine){

	this->engine = string(engine);
}

int Automobil::get_max_speed(){ 
	
	return this->max_speed; 
}

void Automobil::set_max_speed(int max_speed){

	this->max_speed = max_speed;
}

int Automobil::get_engine_cc(){ 
	
	return this->engine_cc; 
}

void Automobil::set_engine_cc(int engine_cc){

	this->engine_cc = engine_cc;
}

int Automobil::get_avg_speed_urban(){ 
	
	return this->avg_speed_urban;
}

void Automobil::set_avg_speed_urban(int avg_speed){

	this->avg_speed_urban = avg_speed;
}

int Automobil::get_avg_speed(){ 
	
	return this->avg_speed; 
}

void Automobil::set_avg_speed(int avg_speed){

	this->avg_speed = avg_speed;
}

int Automobil::get_avg_consumption_urban(){
	
	return this->avg_consumption_urban; 
}

void Automobil::set_avg_consumption_urban(int avg_consumption_urban){

	this->avg_consumption_urban = avg_consumption_urban;
}

int Automobil::get_avg_consumption(){
	
	return this->avg_consumption; 
}

void Automobil::set_avg_consumption(int avg_consumption){

	this->avg_consumption = avg_consumption;
}

void Automobil::set_telematics_auto(Telematics ts){

	this->telematic_auto.push_back(ts);
}

	// ------------ Alte Metode ----------------------------------




	//------------- Destructorul ---------------------------------

Automobil::~Automobil(){
	
	this->name.clear();
	this->engine.clear();
	this->nr_masini--;
}