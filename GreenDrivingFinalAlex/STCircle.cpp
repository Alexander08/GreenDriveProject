#include "STCircle.h"

STCircle::STCircle()
{
	this->type = static_cast<STT>(0);
	this->restriction_color = "black";
	this->radius = 0;
}

STCircle::STCircle(STCircle & str)
{
	this->type = str.type;
	this->restriction_color = str.restriction_color;
	this->center = str.center;
	this->radius = str.radius;
}

SpecialTerrain & STCircle::operator=( const STCircle & str)
{

	this->type = str.type;
	this->restriction_color = str.restriction_color;
	this->center = str.center;
	this->radius = str.radius;

	return *this;
}

int STCircle::check_car(Coordinates c)
{
	return 0;
}

STCircle::~STCircle()
{
}

void STCircle::set_Type(STT type)
{
	this->type = type;
}

void STCircle::set_Type(string type)
{
	if (type.compare("circle")) this->type = static_cast<STT>(0);
//	if (type.compare("rectangle")) this->type = static_cast<STT>(1);
}

void STCircle::set_Restrction_Color(string color)
{
	this->restriction_color = string(color);
}

void STCircle::set_Radius(short int radius)
{
	this->radius = radius;
}

void STCircle::set_Center_Long(double longi)
{
	this->center.Longitude = longi;
}

void STCircle::set_Center_Lat(double lati)
{
	this->center.Latitude = lati;
}

STT STCircle::get_Type(void)
{
	return this->type;
}

string STCircle::get_Type_toString(void)
{
	if (this->type == 0) return "circle";
	if (this->type == 1) return "rectangle";

	return "no geofence form set yet!";
}

string STCircle::get_Color(void)
{
	return this->restriction_color;
}

ostream & operator<<(ostream & os, STCircle st)
{
	os << "----- Zona Geofence cu urmatoarele specificatii ------" << endl;
	os << "Tipul Restrictiei: " <<st.get_Type_toString() << endl;
	os << "Culoarea Restrictiei: " << st.restriction_color << endl;
	os << "Raza Restrictiei: " << st.radius << " km"<< endl;
	os << "Coordonatele Restrictiei: " << endl;
	os << "Longitudine: " << st.center.Longitude << endl;
	os << "Latitudine: " << st.center.Latitude << endl;
	os << "--------- Sfarsit zona geofence ----------------------" << endl << endl;

	return os;
}
