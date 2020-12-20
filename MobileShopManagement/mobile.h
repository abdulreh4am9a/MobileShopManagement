#include<iostream>
#include<string>
#include<fstream>
#include<list>
using namespace std;
struct mobilePhone
{
	char company[30];		//////////////////////////////
	char name[30];			//////////////////////////////
	double display;			//////////////////////////////
	char processor[30];		//////////////////////////////
	int frontCamera;		//////////////////////////////
	int rareCamera;			///FEATURES OF MOBILE PHONE///
	int ram;				//////////////////////////////
	int storage;			//////////////////////////////
	int battery;			//////////////////////////////
	char os[30];			//////////////////////////////
	int price;				//////////////////////////////
	bool operator==(const mobilePhone& rhs) const;
};
void addMobile(const char* filename, list<mobilePhone>& l);			//Function to get input against different features from user and to store that record on file
void filterMobile(const char* filename, list<mobilePhone>& l);		//Function to ask user wether to filter by company, name, display size, processor, camera resolutions, ram, storage, battery or in price range
void searchMobile(const char* filename, list<mobilePhone>& l);		//Function to ask user wether to search by company, name, display size, processor, camera resolutions, ram, storage, battery or in price range
list<mobilePhone> searchbyCompany(const list<mobilePhone>& l);		//Search by company name
list<mobilePhone> searchbyName(const list<mobilePhone>& l);		//Search by mobile name
list<mobilePhone> searchbyDisplay(const list<mobilePhone>& l);		//Search by display size
list<mobilePhone> searchbyProcessor(const list<mobilePhone>& l);	//Search by Processor
list<mobilePhone> searchbyFrontCamera(const list<mobilePhone>& l); //Search by front camera resolution
list<mobilePhone> searchbyRareCamera(const list<mobilePhone>& l);	//Search by rare camera resolution
list<mobilePhone> searchbyRAM(const list<mobilePhone>& l);			//Search by ram capacity
list<mobilePhone> searchbyStorage(const list<mobilePhone>& l);		//Search by storage capacity
list<mobilePhone> searchbyBattery(const list<mobilePhone>& l);		//Search by battery capacity
list<mobilePhone> searchbyOS(const list<mobilePhone>& l);			//Search by operating system type
list<mobilePhone> searchbyPrice(const list<mobilePhone>& l);		//Search by price range
void updateMobile(const char* filename, list<mobilePhone>& l);		//Update a record
void deleteMobile(const char* filename, list<mobilePhone>& l);		//Delete a record
void displayMobile(const mobilePhone& m);				//Display a record
void displayFile(const char* filename);			//Display all records present in files
void systemMenu(const char* filename, list<mobilePhone>& l);			//Menu to call all functions