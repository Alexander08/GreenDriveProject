#include <istream>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdlib>

#include "Menu.h"
#include "SpecialTerrain.h"
#include "STCircle.h"
#include "STRectangle.h"

using namespace std;

Menu::Menu(){
	///-------daca eu imi fac un obiect menu1 cand am 3 masini si mai fac un obiect menu2 cand am 5 masini si o sa zici menu1 = menu2? Ce iti rezulta??? testeaza!!!
	this->Auto = new Automobil[3];
	this->fisiere_noi_adaugate.reserve(1);

	this->files_name.reserve(3);

	this->files_name.push_back("auto.txt");
	this->files_name.push_back("telematics.txt");
	this->files_name.push_back("geofence.txt");
}

Menu::Menu(const Menu & m)
{
	for (int i = 0; i < 3; i++)
		this->Auto[i] = Automobil(m.Auto[i]);
//	int test = 1;
	//memcpy(this->Auto, m.Auto, (Automobil::get_Nr_masini() -1) * sizeof(Automobil));

	this->files_name = m.files_name;
	this->fisiere_noi_adaugate = m.fisiere_noi_adaugate;
}

Menu & Menu::operator=(Menu & m)
{
	for (int i = 0; i < 3; i++)
		this->Auto[i] = Automobil(m.Auto[i]);
	this->files_name = m.files_name;
	this->fisiere_noi_adaugate = m.fisiere_noi_adaugate;

	return *this;
}

ostream & operator<<(ostream & os, Menu a)
{
	if (a.files_name.size() != 0) {
		os << "Fisierele deja existente in program sunt:" << endl;

		for (unsigned int i = 0; i < a.files_name.size() - 1; i++) {

			os << "\t" << i << ". " << a.files_name.at(i) << endl;
		}
		os << "-----------------------------" << endl;
	}
	return os;
}

	// ----------------------- Accesori ---------------------------

string Menu::get_file_name(int i) { 
	
	return this->files_name.at(i); 
}

vector<string> Menu::get_Fisiere_noi_adaugate(){

	return this->fisiere_noi_adaugate;
}

vector<string> Menu::get_files_name()
{
	return this->files_name;
}

Automobil & Menu::get_automobil(int i){

	return this->Auto[i];
}

	// ----------------------- Metode -----------------------------
 
string Menu::get_parameter(char *buff){

	string *line = new string(buff);

	int pos = line->find_last_of(": ");
	
	line->erase(0, pos + 1);
	return *line;
}

int Menu::only_int(string buff)
{
	int pos = buff.find_last_of("km");
	buff.erase(pos, buff.size());
	return atoi(buff.c_str());
}

int Menu::open_auto_file(string nume){

	int i = 0;
	char line[255];

	ifstream file(nume);

	if (file.is_open())
	{
		while (!file.eof()){
			
	//		this->Auto[i] = new Automobil();

			file.getline(line, 255);
			this->Auto[i].set_name(line);
//----------------------------------------------------conditie de nume---------pentru a adauga o noua masina, daca nu  exista (generalizeaza pentru a putea adauga noi masini)----------
			file.getline(line, 255);
			this->Auto[i].set_engine(get_parameter(line));
		
			file.getline(line, 255);
			this->Auto[i].set_max_speed( atoi( get_parameter( line ).c_str() ) );
			
			file.getline(line, 255);
			this->Auto[i].set_engine_cc( atoi( get_parameter( line ).c_str() ) );
				
			file.getline(line, 255);
			this->Auto[i].set_avg_consumption_urban( atoi( get_parameter( line ).c_str() ) );

			file.getline(line, 255);
			this->Auto[i].set_avg_speed_urban( atoi( get_parameter( line ).c_str() ) );
				
			file.getline(line, 255);
			this->Auto[i].set_avg_consumption( atoi( get_parameter( line ).c_str() ) );
			
			file.getline(line, 255);
			this->Auto[i].set_avg_speed( atoi( get_parameter( line ).c_str() ) );

			i++;	
		}
	}
	file.close();

	return i;
}

int Menu::open_telematics_file(string nume)
{
	int i = 0;
	char line[255];

	ifstream file(nume);

	if ( file.is_open() )
	{
		while ( !file.eof() ) {

			file.getline( line, 255 );

			i = search_for_name(line);
			if ( i == Automobil::get_Nr_masini() ) {
			
				cout << "Aubomobilul " << line << "nu este inregistrat!" << endl;
				return -1;
			}

			// Acest if a redus memoria consumata de la 42 Mb la 6.8 Mb
			if ( this->Auto[i].telematic_auto.size() < this->Auto[i].telematic_auto.capacity() ) {
			
				this->Auto[i].telematic_auto.push_back(Telematics());
			}

			file.getline(line, 255);
			this->Auto[i].telematic_auto.back().set_utc( atoll (line) );

			this->Auto[i].telematic_auto.back().set_coordinates(Coordinates());
			
			file.getline(line, 255);
			this->Auto[i].telematic_auto.back().set_coordinates_long( atof(line) );
			
			file.getline(line, 255);
			this->Auto[i].telematic_auto.back().set_coordinates_lat( atof(line) );

			file.getline(line, 255);
			this->Auto[i].telematic_auto.back().set_speed( atoi(line) );

		}
	}

	file.close();

	return i;
}

int Menu::open_geofence_file(vector<SpecialTerrain*>& STobj, string nume)
{
	int i = 0;
	char line[255];

	ifstream file(nume);

	if (file.is_open())
	{
		while (!file.eof()) {

			file.getline(line, 255);
			string buff = get_parameter(line);
			
			if(buff.compare("circle") == 0){
				
				STCircle *stc = new STCircle();
				
				stc->set_Type(buff);

				file.getline(line, 255);
				stc->set_Restrction_Color(get_parameter(line));

				file.getline(line, 255);
				buff = get_parameter(line);
				stc->set_Center_Long( atof( buff.substr( 0, buff.find_last_of(";") ).c_str() ) ); // aici e posibil sa trebuiiasca sa dai -1
				stc->set_Center_Lat( atof( buff.substr(buff.find_last_of(";") + 1 ).c_str() ) );

				file.getline(line, 255);
				stc->set_Radius( only_int( get_parameter( line ) ) );
				
				STobj.push_back(stc);
			}
			if (buff.compare("rectangle") == 0) {
			
				STRectangle *str = new STRectangle();

				str->set_Type(buff);

				file.getline(line, 255);
				str->set_Restrction_Color(get_parameter(line));
				
				file.getline(line, 255);
				buff = get_parameter(line);
				str->set_Corner_long( atof( buff.substr(0, buff.find_last_of(";") ).c_str()), 0);
				str->set_Corner_lati(atof(buff.substr(buff.find_last_of(";")+1).c_str()), 0);
				
				file.getline(line, 255);
				buff = get_parameter(line);
				str->set_Corner_long(atof(buff.substr(0, buff.find_last_of(";")).c_str()), 1);
				str->set_Corner_lati(atof(buff.substr(buff.find_last_of(";")+1).c_str()), 1);

				STobj.push_back(str);
			}
		}
	}

	file.close();

	return i;
}

int Menu::extrage_fisiere_din_folder(string director){

	FILE* pipe = NULL;
	char buf[256];

	string pCmd = "dir /a-d /b /OG " + string(director);
//	cout << pCmd;
	if (NULL == (pipe = _popen(pCmd.c_str(), "rt"))) return -1;

	while (!feof(pipe)) {

		if (fgets(buf, 256, pipe) != NULL) {
			
			this->fisiere_noi_adaugate.push_back(string(buf));
	//		cout << buf;
		}
	}
	_pclose(pipe);
	return 1;
}

int Menu::search_for_name(string name){

	for (int i = 0; i < Automobil::get_Nr_masini(); i++)
		if (this->Auto[i].get_name().compare(name) == 0) return i;

	return Automobil::get_Nr_masini();
}

void Menu::start_page()
{
	system("cls");
	cout << "\t\t\t\t\tGreenDrive Project" << endl;
	cout << "\t\t\t\t----------------------------------" << endl;
	cout << "\tOptions: " << endl << endl;
	cout << "\t1. Lista Masini Monitorizate" << endl;
	cout << "\t2. Informatii Geofence" << endl;
	cout << "\t3. Lista Fisierelor din program" << endl;
	cout << "\t4. Salvati Rapoarte" << endl;
	cout << "" << endl << endl << endl;
	cout << "\t9. Exit\t\t" << endl;
	cout << "\t\tOption: ";
}

void Menu::header_page()
{
	system("cls");
	cout << "\t\t\t\t\tGreenDrive Project" << endl;
	cout << "\t\t\t\t----------------------------------" << endl;
	cout << "\tOptions: " << endl << endl;

}

void Menu::footer_page()
{
	cout << "\t9. Exit\t\t";
	cout << "0. Back" << endl;
	cout << "\t\tOption: ";

}

void Menu::masina_page()
{
	cout << "\t 11. Adaugati masini" << endl;;
	cout << "\t 12. Stergeti masini " << endl;
	cout << "\t 13. Vizualizati informatii despre masina (introduceti la optiuni indexul masinii): " << endl;
}

void Menu::show_auto_list()
{
	cout << endl;
	for (int i = 0; i < Automobil::get_Nr_masini() - 1; i++) {
	
		cout << "\t\t " << i + 14 <<". "<< this->Auto[i].get_name() << endl;
	}
}

void Menu::auto_single_page()
{
	cout << "\t 111. Informatii generale " << endl;;
	cout << "\t 112. Analizati traseu" << endl;
	cout << "\t 113. Afisare grafic Green Drive" << endl;

}

void Menu::show_Geofence_info(vector<SpecialTerrain*> s)
{
	for ( unsigned int i = 0; i < s.size(); i++) {

		if (s.at(i)->get_Type() == circle) {
		
			STCircle *stc = (STCircle*)s.at(i);
			cout << *stc;
		}
		if (s.at(i)->get_Type() == rectangle) {

			STRectangle *str = (STRectangle*)s.at(i);
			cout << *str;
		}
		
	}
}

void Menu::files_menu_page()
{
	cout << "\t 31. Listati un director (Introduceti calea absoluta): ";
}

void Menu::show_files(vector<string> str)
{
	if (str.size() != 0) {
		for (unsigned int i = 0; i < str.size(); i++) {

			cout << "\t" << i + 300 << ". " << str.at(i) << endl;
		}
		cout << "------ Introduceti Indexul fisierului pe care doriti sa il deschideti: -----" << endl;
		cout << "Fisierul va fi adaugat in lista fisierelor din program" << endl;
	}
}

	// ----------------------- Destructor -------------------------

Menu::~Menu(){

	delete [] this->Auto;
	this->files_name.clear();
	this->fisiere_noi_adaugate.clear();
}

