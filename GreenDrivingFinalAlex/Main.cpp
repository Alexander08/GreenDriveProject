#include <iostream>
#include <string.h>
#include <conio.h>
#include <iomanip>

#include <Windows.h>

#include "Menu.h" 
#include "Ecologic.h"
#include "SpecialTerrain.h"

using namespace std;

void main(){

	Automobil a;

	Menu m;
	vector<SpecialTerrain*> s;

	vector<Ecologic> e;
	e.reserve(3);
	e.push_back(Ecologic());
	e.push_back(Ecologic());
	e.push_back(Ecologic());

	string nume;
	int buff, autoIndex;

	//char buff[20];

	vector<int> old_option;

	m.start_page();
	m.open_auto_file(m.get_file_name(0));
	m.open_telematics_file(m.get_file_name(1));
	cin >> buff;
	while (buff != 9) {
	
		switch (buff) {

		case 1: { // Vizualizati lista de auto
			old_option.push_back(buff);
			m.header_page();
			m.masina_page();
			m.show_auto_list();
			m.footer_page();
			cin >> buff;
			break;
		}
		case 11: { // Adaugati auto
			m.header_page();
			m.footer_page();
			cin >> buff;
			break; 
		}
		case 12: { // Stergeti auto
			m.header_page();
			m.footer_page();
			cin >> buff;
			break; 
		}
		case 13: {	// Get all auto
			m.header_page();
			m.footer_page();
			cin >> buff;
			break; 
		}
		case 14: { // Get auto1
			old_option.push_back(buff);
			m.header_page();
			autoIndex = buff - 14;
			cout << m.get_automobil(buff - 14);
			m.auto_single_page();
			m.footer_page();
			cin >> buff;
			break;
		}
		case 15: { // Get auto2
			old_option.push_back(buff);
			m.header_page();
			autoIndex = buff - 14;
			cout << m.get_automobil(buff - 14);
			m.auto_single_page();
			m.footer_page();
			cin >> buff;
			break;
		}
		case 16: { // Get auto3
			old_option.push_back(buff);
			m.header_page();
			autoIndex = buff - 14;
			cout << m.get_automobil(buff - 14);
			m.auto_single_page();
			m.footer_page();
			cin >> buff;
			break;
		}
		case 111:{
			old_option.push_back(buff);
			m.header_page();
			e[autoIndex].calculate_time(m.get_automobil(autoIndex));
			m.footer_page();
			cin >> buff;
			break;
		}
		case 112: { // Analizati traseu
			old_option.push_back(buff);
			m.header_page();
			if (e[autoIndex].get_traseu().size() > 2) cout << "Traseul a fost deja analizat!" << endl;
			else e[autoIndex].build_traseu(m.get_automobil(autoIndex), 0);
			cout << "Doriti sa vizualizati analiza punct cu punct? (y\\n)" << endl;
			cout << "Poate fi intrerupta cu tasta \"s\" " << endl;
			if (_getch() == 'y') cout << e[autoIndex];
			m.footer_page();
			cin >> buff;
			break;
		}
		case 113: {
			old_option.push_back(buff);
			m.header_page();
			e[autoIndex].print_GreenDrive(m.get_automobil(autoIndex));
			m.footer_page();
			cin >> buff;
			break;
		}

		case 2: { // Informatii geofence
			old_option.push_back(buff);
			m.header_page();
			m.open_geofence_file(s, m.get_file_name(2));
			m.show_Geofence_info(s);
			m.footer_page();
			cin >> buff;
			break;
		}
		case 3: {
			old_option.push_back(buff);
			m.header_page();
		//	cout<< m;
			m.show_files(m.get_files_name());
			m.files_menu_page();
			cin >> nume;
			m.extrage_fisiere_din_folder(nume);
			m.show_files(m.get_Fisiere_noi_adaugate());
			m.footer_page();
			cin >> buff;
		}
		case 9:
			break;
		case 0: { // Back Option
			old_option.pop_back();
			if (old_option.empty()) {
			
				m.start_page();
				cin >> buff;
			}
			else {
				buff = old_option.back();
				old_option.pop_back();
			}

			break;
		}
		case 99: { // Debugging vector oprion
		
			for ( unsigned short int i = 0; i < old_option.size(); i++) { cout << old_option.at(i) << "\t"; }
			cout << endl;
			cin >> buff;
			break;
		}
		default: { // Default value
		
			cout << endl << "Introduceti o optiune valida: ";
		//	cin.clear();
		//	cin.ignore(256, '\n');
			cin >> buff;
			break;
		}

		}
	}


//	cout << "hello world!" << endl;
//
//	for (int i = 0; i < 3; i++) {
//
//		cout << m.get_automobil(i);
//	}
//
//	Ecologic e;
//
//	for (int i = 0; i < 3; i++) {
//
//		cout << m.get_automobil(i);
//	}
//	cout << "Nume folder de listat: ";
////	cin >> nume;
////	m.extrage_fisiere_din_folder(nume);
//
//	//cout << m.get_new_Fisier();/// error
//
//	cout <<fixed << setprecision(12)<< endl << endl << m.get_automobil(1).telematic_auto.at(0).avg_speed();
//	//Automobil b = Automobil(m.get_automobil(0));
//	//e.time_between_two_points(m.get_automobil(0));
//	e.calculate_time(m.get_automobil(0));
//	cout << endl << m.get_automobil(0).telematic_auto.at(0).avg_speed();
//	Sleep(1000);
//	cout << endl << m.get_automobil(1).telematic_auto.at(0).avg_speed();
//	Sleep(1000);
//	cout << endl << m.get_automobil(2).telematic_auto.at(0).avg_speed();
//
//	e.build_traseu(m.get_automobil(0), 0);
//	cout << e;
//	_getch();
}