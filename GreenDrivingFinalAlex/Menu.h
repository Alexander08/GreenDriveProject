#include <string>
#include <vector>

#include "Automobil.h"
#include "SpecialTerrain.h"

using namespace std;

class Menu{

private:

	Automobil *Auto;

	vector<string> fisiere_noi_adaugate;

	// Este un vector care retine toate fisierele dintr-un director
	vector<string> files_name;

public:

	// ----------------------- Constructorii -----------------------
	Menu();
	Menu(const Menu& m);

	Menu& operator=(Menu & m);
	// ------------- Supraincarcarea Operatorilor =, <<, >>	--------

	//imi da ERROR nu uita de ea!!!!
	friend ostream& operator<<(ostream &os, Menu a);
	// ----------------------- Accesori ---------------------------

	// Returneaza numele unui fisier specificat dupa un index
	// Se va putea face o interogare in meniul programului
	string get_file_name(int i);

	vector<string> Menu::get_Fisiere_noi_adaugate();

	// Returneaza lista de fisiere incarcate in program
	vector<string> get_files_name();

	// Returneaza un anutomobil specificat dupa un index
	Automobil& get_automobil(int i);

	// ----------------------- Metode -----------------------------

	// Returneaza parametrul din fisier
	// Obs: toti parametrii au ca predecesor succesiunea ": "
	// pe care o vom folosi ca punct de reper;
	string get_parameter(char *buff);

	int only_int(string buff);


	// Metoda care extrage datele din fisier de tip auto si le incarca in 
	// variabilele din interiorul obiectului
	int open_auto_file(string nume);

	// Metoda care extrage datele din fisier de tip Telematics si le incarca in
	// variabilele din interiorul obiectului
	int open_telematics_file(string nume);

	// Metoda care extrage datele din fisier de tip Geofence si le incarca in
	// variabilele din interiorul obiectului
	int open_geofence_file(vector<SpecialTerrain*> &STobj, string nume);

	// Extrage fisierele dintr-un folder, sau o cale trimisa ca parametru de la
	// tastatura sau dintr-un alt fisier
	int extrage_fisiere_din_folder(string director);

	// Cauta o masina in vectorul de masini si returneza pozitia in vector
	int search_for_name(string name);


	// Prima pagina din program
	void start_page();

	void header_page();

	void footer_page();

	void masina_page();

	void show_auto_list();

	void auto_single_page();

	void show_Geofence_info(vector<SpecialTerrain*>s);

	void files_menu_page();

	void show_files(vector<string> );

	// ----------------------- Destructor -------------------------
	~Menu();
};