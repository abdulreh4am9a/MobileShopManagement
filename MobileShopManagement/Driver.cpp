#include"Mobile.h"
int main(int argc, char* argv[]) { //we have to pass the name of the binary file as a command line argument so that the file can be used through out the program
	list<mobilePhone> listofMobiles;
	ifstream thefile(argv[1], ios::binary | ios::ate);
	if (thefile.is_open()) {
		int nbytes = thefile.tellg();
		int n = nbytes / sizeof(mobilePhone);
		mobilePhone* arr = new mobilePhone[n];
		thefile.seekg(0, ios::beg);
		thefile.read((char*)arr, nbytes);
		thefile.close();
		for (int i = 0;i < n;i++) {
			listofMobiles.push_back(arr[i]);
		}
		delete[]arr;
	}
	else {
		ofstream thefile(argv[1], ios::binary);
		thefile.close();
	}
	cout << "\tM O B I L E \t S H O P \t S A L E S \t S Y S T E M" << endl;
	systemMenu(argv[1], listofMobiles); //we pass the name of file taken as a command line argument to this function so that all the functions called inside this function can use it and evaluate it in their own way wether to open in read or write, app, truncate or in or out mode
	return 0;
}