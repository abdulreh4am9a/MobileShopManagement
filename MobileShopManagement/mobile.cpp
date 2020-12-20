#include"Mobile.h"
void systemMenu(const char* filename, list<mobilePhone>& l) { //filename is taken as command line argument that's why passed as const char* so that we can not change the file name accidentally
	char choice; //to find user's choice
	while (1) { //always true so that the menu gets displayed after termination of each function //it will only terminate if user wants to
		//menu display using escape characters
		cout << endl << "\tF U N C T I O N S \t M E N U :" << endl << endl;
		cout << "\t[A] : Add  a new Mobile Phone" << endl;
		cout << "\t[S] : Search a Mobile Phone" << endl;
		cout << "\t[U] : Update a Mobile Phone" << endl;
		cout << "\t[D] : Delete a Mobile Phone" << endl;
		cout << "\t[F] : Display all File Data" << endl;
		cout << "\t[Q] : Exit" << endl;
		cout << endl << "Please enter a relevant character: ";
		cin >> choice; //getting a char by user for the function he or she wants to call
		switch (choice) //the char entered by user is passed in switch statement to check different cases
		{
		case 'A':
		case'a':addMobile(filename, l);break;

		case'S':
		case's':searchMobile(filename, l);break;

		case'U':
		case'u':updateMobile(filename, l);break;

		case'D':
		case'd':deleteMobile(filename, l);break;

		case'F':
		case'f':displayFile(filename);break;

		case'Q':
		case'q':exit(0);break; //if user enters q the program ends

		default:cout << endl << "PLEASE ENTER THE CORRECT OPTION [A/S/U/D/F/Q]" << endl << endl;break;
			//in case of wrong option the above msg is displayed and while loop again shows the functions menu
		}
	}
}

void addMobile(const char* filename, list<mobilePhone>& l) {
	cout << endl;
	ofstream thefile(filename, ios::binary | ios::app);
	if (thefile.is_open()) {
		thefile.seekp(0, ios::end);
		mobilePhone m;
		cout << "Enter Company Name: ";
		cin.ignore(30, '\n');
		cin.getline(m.company, 30);
		cout << "Enter Model Name: ";
		cin.getline(m.name, 30);
		cout << "Enter Display Size [Inches]: ";
		cin >> m.display;
		cout << "Enter Processor Name: ";
		cin.ignore(30, '\n');
		cin.getline(m.processor, 30);
		cout << "Enter Front Camera [MP]: ";
		cin >> m.frontCamera;
		cout << "Enter Rare Camera [MP]: ";
		cin >> m.rareCamera;
		cout << "Enter RAM Capacity [GB]: ";
		cin >> m.ram;
		cout << "Enter Storage Capacity [GB]: ";
		cin >> m.storage;
		cout << "Enter Battery Capacity [mAh]: ";
		cin >> m.battery;
		cout << "Enter Operating System [iOS/Android]: ";
		cin.ignore(30, '\n');
		cin.getline(m.os, 30);
		cout << "Enter Price [PKR]: ";
		cin >> m.price;
		cout << endl << "Record Entered!" << endl;
		thefile.write((const char*)&m, sizeof(mobilePhone));
		thefile.close();
		l.push_back(m);
		displayMobile(m);
	}
	else
		cout << "Couldn't Open file" << endl;
}
void filterMobile(const char* filename, list<mobilePhone>& l) {
	char choice, c;
	cout << endl << "Do you want to filter records? [Y/N] : ";
	cin >> c;
	while (c == 'y' || c == 'Y') {
		cout << endl << "\tF I L T E R \t C R I E T E R I A :" << endl << endl;
		cout << "\t[C] : Filter by Company" << endl;
		cout << "\t[N] : Filter by Name/Model" << endl;
		cout << "\t[D] : Filter by Display Size" << endl;
		cout << "\t[P] : Filter by Processor" << endl;
		cout << "\t[F] : Filter by Front Camera Resolution" << endl;
		cout << "\t[R] : Filter by Rare  Camera Resolution" << endl;
		cout << "\t[M] : Filter by RAM Capacity" << endl;
		cout << "\t[S] : Filter by Storage Capacity" << endl;
		cout << "\t[B] : Filter by Battery Capacity" << endl;
		cout << "\t[O] : Filter by Operating System" << endl;
		cout << "\t[X] : Filter in Price Range" << endl;
		cout << "\t[Q] : Go back to Search Menu" << endl;
		cout << endl << "Please enter a relevant character: ";
		cin >> choice;
		switch (choice)
		{
		case 'C':
		case'c':searchbyCompany(l);break;

		case 'N':
		case'n':searchbyName(l);break;

		case 'D':
		case'd':searchbyDisplay(l);break;

		case 'P':
		case'p':searchbyProcessor(l);break;

		case 'F':
		case'f':searchbyFrontCamera(l);break;

		case 'R':
		case'r':searchbyRareCamera(l);break;

		case 'M':
		case'm':searchbyRAM(l);break;

		case 'S':
		case's':searchbyStorage(l);break;

		case 'B':
		case'b':searchbyBattery(l);break;

		case 'O':
		case'o':searchbyOS(l);break;

		case 'X':
		case'x':searchbyPrice(l);break;

		case 'Q':
		case'q':searchMobile(filename, l);break; 

		default:cout << endl << "PLEASE ENTER THE CORRECT OPTION [C/N/D/P/F/R/M/S/B/O/X/Q]" << endl << endl;break;
		}
	}
}

void searchMobile(const char* filename, list<mobilePhone>& l) {
	list<mobilePhone> l1;
	char choice;
	while (1) {
		cout << endl << "\tS E A R C H \t C R I E T E R I A :" << endl << endl;
		cout << "\t[C] : Search by Company" << endl;
		cout << "\t[N] : Search by Name/Model" << endl;
		cout << "\t[D] : Search by Display Size" << endl;
		cout << "\t[P] : Search by Processor" << endl;
		cout << "\t[F] : Search by Front Camera Resolution" << endl;
		cout << "\t[R] : Search by Rare  Camera Resolution" << endl;
		cout << "\t[M] : Search by RAM Capacity" << endl;
		cout << "\t[S] : Search by Storage Capacity" << endl;
		cout << "\t[B] : Search by Battery Capacity" << endl;
		cout << "\t[O] : Search by Operating System" << endl;
		cout << "\t[X] : Search in Price Range" << endl;
		cout << "\t[Q] : Go back to Main Menu" << endl;
		cout << endl << "Please enter a relevant character: ";
		cin >> choice;
		switch (choice)
		{
		case 'C':
		case'c':
			l1 = searchbyCompany(l);
			filterMobile(filename,l1);
			break;

		case 'N':
		case'n':l1 = searchbyName(l);
			filterMobile(filename, l1);
			break;

		case 'D':
		case'd':l1 = searchbyDisplay(l);
			filterMobile(filename, l1);
			break;

		case 'P':
		case'p':l1 = searchbyProcessor(l);
			filterMobile(filename, l1);
			break;

		case 'F':
		case'f':l1 = searchbyFrontCamera(l);
			filterMobile(filename, l1);
			break;

		case 'R':
		case'r':l1 = searchbyRareCamera(l);
			filterMobile(filename, l1);
			break;

		case 'M':
		case'm':l1 = searchbyRAM(l);
			filterMobile(filename, l1);
			break;

		case 'S':
		case's':l1 = searchbyStorage(l);
			filterMobile(filename, l1);
			break;

		case 'B':
		case'b':l1 = searchbyBattery(l);
			filterMobile(filename, l1);
			break;

		case 'O':
		case'o':l1 = searchbyOS(l);
			filterMobile(filename, l1);
			break;

		case 'X':
		case'x':l1 = searchbyPrice(l);
			filterMobile(filename, l1);
			break;

		case 'Q':
		case'q':systemMenu(filename, l);break; 

		default:cout << endl << "PLEASE ENTER THE CORRECT OPTION [C/N/D/P/F/R/M/S/B/O/X/Q]" << endl << endl;break;
		}
	}
}
list<mobilePhone> searchbyCompany(const list<mobilePhone>& l) {
	list<mobilePhone> l1;
	cout << endl;
	if (!l.empty()) {
		char temp[30];
		cout << "Enter the name of company whose mobiles you want to search: ";
		cin.ignore(30, '\n');
		cin.getline(temp, 30);
		list<mobilePhone>::const_iterator it;
		it = l.begin();
		int i = 0;
		while (it != l.end()) {
			mobilePhone m;
			m = *it;
			it++;
			if (strcmp(temp, m.company) == 0) {
				cout << endl << "Record " << ++i << ":";
				displayMobile(m);
				l1.push_back(m);
			}
		}
		if (i == 0) {
			cout << endl << "Sorry! No such record found!" << endl;
		}
		else {
			cout << endl << i << " Record(s) Found!" << endl;
		}
	}
	else {
		cout << "List is empty!" << endl;
	}
	return l1;
}

list<mobilePhone> searchbyName(const list<mobilePhone>& l) {
	list<mobilePhone> l1;
	cout << endl;
	if (!l.empty()) {
		char temp[30];
		cout << "Enter the name of mobile you want to search: ";
		cin.ignore(30, '\n');
		cin.getline(temp, 30);
		list<mobilePhone>::const_iterator it;
		it = l.begin();
		int i = 0;
		while (it != l.end()) {
			mobilePhone m;
			m = *it;
			it++;
			if (strcmp(temp, m.name) == 0) {
				cout << endl << "Record " << ++i << ":";
				displayMobile(m);
				l1.push_back(m);
			}
		}
		if (i == 0) {
			cout << endl << "Sorry! No such record found!" << endl;
		}
		else {
			cout << endl << i << " Record(s) Found!" << endl;
		}
	}
	else {
		cout << "List is empty!" << endl;
	}
	return l1;
}

list<mobilePhone> searchbyDisplay(const list<mobilePhone>& l) {
	list<mobilePhone> l1;
	cout << endl;
	if (!l.empty()) {
		int min, max;
		cout << "Enter the Display Size Range in inches of mobiles you want to search" << endl;
		cout << "MIN: ";
		cin >> min;
		cout << "MAX: ";
		cin >> max;
		list<mobilePhone>::const_iterator it;
		it = l.begin();
		int i = 0;
		while (it != l.end()) {
			mobilePhone m;
			m = *it;
			it++;
			if (m.display >= min && m.display <= max) {
				cout << endl << "Record " << ++i << ":";
				displayMobile(m);
				l1.push_back(m);
			}
		}
		if (i == 0) {
			cout << endl << "Sorry! No such record found!" << endl;
		}
		else {
			cout << endl << i << " Record(s) Found!" << endl;
		}
	}
	else {
		cout << "List is empty!" << endl;
	}
	return l1;
}

list<mobilePhone> searchbyProcessor(const list<mobilePhone>& l) {
	list<mobilePhone> l1;
	cout << endl;
	if (!l.empty()) {
		char temp[30];
		cout << "Enter the name of processor installed in mobiles you want to search: ";
		cin.ignore(30, '\n');
		cin.getline(temp, 30);
		list<mobilePhone>::const_iterator it;
		it = l.begin();
		int i = 0;
		while (it != l.end()) {
			mobilePhone m;
			m = *it;
			it++;
			if (strcmp(temp, m.processor) == 0) {
				cout << endl << "Record " << ++i << ":";
				displayMobile(m);
				l1.push_back(m);
			}
		}
		if (i == 0) {
			cout << endl << "Sorry! No such record found!" << endl;
		}
		else {
			cout << endl << i << " Record(s) Found!" << endl;
		}
	}
	else {
		cout << "List is empty!" << endl;
	}
	return l1;
}

list<mobilePhone> searchbyFrontCamera(const list<mobilePhone>& l) {
	list<mobilePhone> l1;
	cout << endl;
	if (!l.empty()) {
		int min, max;
		cout << "Enter the Resolution Range in MPs of front camera of mobiles you want to search" << endl;
		cout << "MIN: ";
		cin >> min;
		cout << "MAX: ";
		cin >> max;
		list<mobilePhone>::const_iterator it;
		it = l.begin();
		int i = 0;
		while (it != l.end()) {
			mobilePhone m;
			m = *it;
			it++;
			if (m.frontCamera >= min && m.frontCamera <= max) {
				cout << endl << "Record " << ++i << ":";
				displayMobile(m);
				l1.push_back(m);
			}
		}
		if (i == 0) {
			cout << endl << "Sorry! No such record found!" << endl;
		}
		else {
			cout << endl << i << " Record(s) Found!" << endl;
		}
	}
	else {
	cout << "List is empty!" << endl;
	}
	return l1;
}

list<mobilePhone> searchbyRareCamera(const list<mobilePhone>& l) {
	list<mobilePhone> l1;
	cout << endl;
	if (!l.empty()) {
		int min, max;
		cout << "Enter the Resolution Range in MPs of rear camera of mobiles you want to search" << endl;
		cout << "MIN: ";
		cin >> min;
		cout << "MAX: ";
		cin >> max;
		list<mobilePhone>::const_iterator it;
		it = l.begin();
		int i = 0;
		while (it != l.end()) {
			mobilePhone m;
			m = *it;
			it++;
			if (m.rareCamera >= min && m.rareCamera <= max) {
				cout << endl << "Record " << ++i << ":";
				displayMobile(m);
				l1.push_back(m);
			}
		}
		if (i == 0) {
			cout << endl << "Sorry! No such record found!" << endl;
		}
		else {
			cout << endl << i << " Record(s) Found!" << endl;
		}
	}
	else {
		cout << "List is empty!" << endl;
	}
	return l1;
}


list<mobilePhone> searchbyRAM(const  list<mobilePhone>& l) {
	list<mobilePhone> l1;
	cout << endl;
	if (!l.empty()) {
		int min, max;
		cout << "Enter the RAM Range in GBs of mobiles you want to search" << endl;
		cout << "MIN: ";
		cin >> min;
		cout << "MAX: ";
		cin >> max;
		list<mobilePhone>::const_iterator it;
		it = l.begin();
		int i = 0;
		while (it != l.end()) {
			mobilePhone m;
			m = *it;
			it++;
			if (m.ram >= min && m.ram <= max) {
				cout << endl << "Record " << ++i << ":";
				displayMobile(m);
				l1.push_back(m);
			}
		}
		if (i == 0) {
			cout << endl << "Sorry! No such record found!" << endl;
		}
		else {
			cout << endl << i << " Record(s) Found!" << endl;
		}
	}
	else {
		cout << "List is empty!" << endl;
	}
	return l1;
}


list<mobilePhone> searchbyStorage(const list<mobilePhone>& l) {
	list<mobilePhone> l1;
	cout << endl;
	if (!l.empty()) {
		int min, max;
		cout << "Enter the Storage Range in GBs of mobiles you want to search" << endl;
		cout << "MIN: ";
		cin >> min;
		cout << "MAX: ";
		cin >> max;
		list<mobilePhone>::const_iterator it;
		it = l.begin();
		int i = 0;
		while (it != l.end()) {
			mobilePhone m;
			m = *it;
			it++;
			if (m.storage >= min && m.storage <= max) {
				cout << endl << "Record " << ++i << ":";
				displayMobile(m);
				l1.push_back(m);
			}
		}
		if (i == 0) {
			cout << endl << "Sorry! No such record found!" << endl;
		}
		else {
			cout << endl << i << " Record(s) Found!" << endl;
		}
	}
	else {
		cout << "List is empty!" << endl;
	}
	return l1;
}


list<mobilePhone> searchbyBattery(const list<mobilePhone>& l) {
	list<mobilePhone> l1;
	cout << endl;
	if (!l.empty()) {
		int min, max;
		cout << "Enter the Battery Capacity Range in MAh of mobiles you want to search" << endl;
		cout << "MIN: ";
		cin >> min;
		cout << "MAX: ";
		cin >> max;
		list<mobilePhone>::const_iterator it;
		it = l.begin();
		int i = 0;
		while (it != l.end()) {
			mobilePhone m;
			m = *it;
			it++;
			if (m.battery >= min && m.battery <= max) {
				cout << endl << "Record " << ++i << ":";
				displayMobile(m);
				l1.push_back(m);
			}
		}
		if (i == 0) {
			cout << endl << "Sorry! No such record found!" << endl;
		}
		else {
			cout << endl << i << " Record(s) Found!" << endl;
		}
	}
	else {
		cout << "List is empty!" << endl;
	}
	return l1;
}

list<mobilePhone> searchbyOS(const list<mobilePhone>& l) {
	list<mobilePhone> l1;
	cout << endl;
	if (!l.empty()) {
		char temp[30];
		cout << "Enter the name of OS [iOS/Android] installed in mobiles you want to search: ";
		cin.ignore(30, '\n');
		cin.getline(temp, 30);
		list<mobilePhone>::const_iterator it;
		it = l.begin();
		int i = 0;
		while (it != l.end()) {
			mobilePhone m;
			m = *it;
			it++;
			if (strcmp(temp, m.os) == 0) {
				cout << endl << "Record " << ++i << ":";
				displayMobile(m);
				l1.push_back(m);
			}
		}
		if (i == 0) {
			cout << endl << "Sorry! No such record found!" << endl;
		}
		else {
			cout << endl << i << " Record(s) Found!" << endl;
		}
	}
	else {
		cout << "List is empty!" << endl;
	}
	return l1;
}

list<mobilePhone> searchbyPrice(const list<mobilePhone>& l) {
	list<mobilePhone> l1;
	cout << endl;
	if (!l.empty()) {
		int min, max;
		cout << "Enter the Price Range in PKR of mobiles you want to search" << endl;
		cout << "MIN: ";
		cin >> min;
		cout << "MAX: ";
		cin >> max;
		list<mobilePhone>::const_iterator it;
		it = l.begin();
		int i = 0;
		while (it != l.end()) {
			mobilePhone m;
			m = *it;
			it++;
			if (m.price >= min && m.price <= max) {
				cout << endl << "Record " << ++i << ":";
				displayMobile(m);
				l1.push_back(m);
			}
		}
		if (i == 0) {
			cout << endl << "Sorry! No such record found!" << endl;
		}
		else {
			cout << endl << i << " Record(s) Found!" << endl;
		}
	}
	else {
		cout << "List is empty!" << endl;
	}
	return l1;
}
void displayMobile(const mobilePhone& m) {
	cout << endl;
	cout << "\t" << m.company << " " << m.name << endl;
	cout << "\tDisplay: " << m.display << "\"" << endl;
	cout << "\tProcessor: " << m.processor << endl;
	cout << "\tFront Camera:	" << m.frontCamera << "MP" << endl;
	cout << "\tRare Camera: " << m.rareCamera << "MP" << endl;
	cout << "\tRAM: " << m.ram << "GB" << endl;
	cout << "\tStorage: " << m.storage << "GB" << endl;
	cout << "\tBattery: " << m.battery << "mAh" << endl;
	cout << "\tOS: " << m.os << endl;
	cout << "\tPrice: " << m.price << "PKR" << endl;
}

void updateMobile(const char* filename, list<mobilePhone>& l) {
	cout << endl;
	ifstream thefile(filename, ios::binary);
	ofstream newfile("tempfile.bin", ios::binary);
	if (thefile.is_open()) {
		if (newfile.is_open()) {
			char temp[30];
			bool found = 0;
			cout << "Enter the name of mobile you want to update: ";
			cin.ignore(30, '\n');
			cin.getline(temp, 30);
			while (thefile.good()) {
				mobilePhone m;
				thefile.read((char*)&m, sizeof(mobilePhone));
				if (thefile.gcount() > 0) {
					if (strcmp(temp, m.name) == 0) {
						cout << endl << "Previous Values: " << endl;
						displayMobile(m);
						list<mobilePhone>::iterator it;
						it = l.begin();
						while (it != l.end()) {
							mobilePhone x;
							x = *it;
							if (strcmp(temp, x.name) == 0) {
								l.erase(it);
								break;
							}
							it++;
						}
						cout << endl << "Enter NEW Company Name: ";
						//cin.ignore(30, '\n');
						cin.getline(m.company, 30);
						cout << "Enter NEW Model Name: ";
						//cin.ignore(30, '\n');
						cin.getline(m.name, 30);
						cout << "Enter NEW Display Size [Inches]: ";
						cin >> m.display;
						cout << "Enter NEW Processor Name: ";
						cin.ignore(30, '\n');
						cin.getline(m.processor, 30);
						cout << "Enter NEW Front Camera [MP]: ";
						cin >> m.frontCamera;
						cout << "Enter NEW Rare Camera [MP]: ";
						cin >> m.rareCamera;
						cout << "Enter NEW RAM Capacity [GB]: ";
						cin >> m.ram;
						cout << "Enter NEW Storage Capacity [GB]: ";
						cin >> m.storage;
						cout << "Enter NEW Battery Capacity [mAh]: ";
						cin >> m.battery;
						cout << "Enter NEW Operating System [iOS/Android]: ";
						cin.ignore(30, '\n');
						cin.getline(m.os, 30);
						cout << "Enter NEW Price [PKR]: ";
						cin >> m.price;
						l.push_back(m);
						cout << endl << "Record Updated!" << endl;
						displayMobile(m);
					}
					newfile.write((const char*)&m, sizeof(mobilePhone));
				}
			}
			newfile.close();
			thefile.close();
			remove(filename);
			rename("tempfile.bin", filename);
		}
	}
	else {
		cout << "Couldn't Open file" << endl;
	}
}

void deleteMobile(const char* filename, list<mobilePhone>& l) {
	cout << endl;
	ifstream thefile(filename, ios::binary);
	ofstream newfile("tempfile.bin", ios::binary);
	if (thefile.is_open()) {
		if (newfile.is_open()) {
			char temp[30];
			bool found = 0;
			cout << "Enter the name of mobile you want to delete: ";
			cin.ignore(30, '\n');
			cin.getline(temp, 30);
			while (thefile.good()) {
				mobilePhone m;
				thefile.read((char*)&m, sizeof(mobilePhone));
				if (thefile.gcount() > 0) {
					if (strcmp(temp, m.name) != 0) {
						newfile.write((const char*)&m, sizeof(mobilePhone));
					}
					else {
						list<mobilePhone>::iterator it;
						it = l.begin();
						while (it != l.end()) {
							mobilePhone x;
							x = *it;
							if (strcmp(temp, x.name) == 0) {
								l.erase(it);
								break;
							}
							it++;
						}
						cout << "Record Deleted!" << endl;
					}
				}
			}
			newfile.close();
			thefile.close();
			remove(filename);
			rename("tempfile.bin", filename);
		}
	}
	else {
		cout << "Couldn't Open file" << endl;
	}
}

void displayFile(const char* filename) {
	cout << endl;
	int i = 0;
	ifstream thefile(filename, ios::binary);
	if (thefile.is_open()) {
		while (!thefile.eof())
		{
			mobilePhone m;
			thefile.read((char*)&m, sizeof(mobilePhone));
			if (thefile.gcount() > 0) {
				cout << endl << "Record " << ++i << ":";
				displayMobile(m);
			}
		}
		if (i == 0) {
			cout << endl << "Sorry! The file is empty!" << endl;
		}
		else {
			cout << endl << i << " Record(s) Found!" << endl;
		}
		thefile.close();
	}
	else
	{
		cout << "Couldn't open file!" << endl;
	}
}
bool mobilePhone::operator==(const mobilePhone& rhs) const {
	return strcmp(name, rhs.name) == 0;
}