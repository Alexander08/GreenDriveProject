#include "STRectangle.h"

STRectangle::STRectangle()
{
	this->type = static_cast<STT>(1);
	this->restriction_color = "black";
}

STRectangle::STRectangle( const STRectangle & str)
{
	this->type = str.type;
	this->restriction_color = str.restriction_color;
	this->LUC = str.LUC;
	this->RDC = str.RDC;
}

STRectangle & STRectangle::operator=(const STRectangle & str)
{

	this->type = str.type;
	this->restriction_color = str.restriction_color;
	this->LUC = str.LUC;
	this->RDC = str.RDC;

	return *this;
}

int STRectangle::check_car(Coordinates c)
{
	return 0;
}

STRectangle::~STRectangle()
{
}

void STRectangle::set_Type(STT type)
{
	this->type = type;
}

void STRectangle::set_Type(string type)
{
	if (type.compare("rectangle")) this->type = static_cast<STT>(1);
//	if (type.compare("circle")) this->type = static_cast<STT>(0);
}

void STRectangle::set_Restrction_Color(string color)
{
	this->restriction_color = string(color);
}

void STRectangle::set_Corner_long(double longi, short int i)
{
	if (i == 0) this->LUC.Longitude = longi;
	if (i == 1) this->RDC.Longitude = longi;
}

void STRectangle::set_Corner_lati(double lati, short int i)
{
	if (i == 0) this->LUC.Latitude = lati;
	if (i == 1) this->RDC.Latitude = lati;
}

STT STRectangle::get_Type(void)
{
	return this->type;
}

string STRectangle::get_Type_toString(void)
{
	if (this->type == 0) return "circle";
	if (this->type == 1) return "rectangle";

	return "no geofence form set yet!";
}

string STRectangle::get_Color(void)
{
	return this->restriction_color;
}

ostream & operator<<(ostream & os, STRectangle st)
{
	os << "----- Zona Geofence cu urmatoarele specificatii ------" << endl;
	os << "Tipul Restrictiei: " << st.get_Type_toString() << endl;
	os << "Culoarea Restrictiei: " << st.restriction_color << endl;
	os << "Coordonatele Restrictiei: " << endl;
	os << "Upper Left Corner:" << endl;
	os << "Longitudine: " << st.LUC.Longitude << endl;
	os << "Latitudine: " << st.LUC.Latitude << endl;
	os << "Right Down Corner:" << endl;
	os << "Longitudine: " << st.RDC.Longitude << endl;
	os << "Latitudine: " << st.RDC.Latitude << endl;
	os << "--------- Sfarsit zona geofence ----------------------" << endl << endl;

	return os;
}
