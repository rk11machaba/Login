#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class User {
	// data members
private:
	string firstname, lastname, username, password;
	// function members
public:
	User(); //default constructor
	//setter
	void setUser();
	//getters
	string getFirstname() { return firstname; }
	string getLastname() { return lastname; }
	string getUsername() { return username; }
	string getPassword() { return password; }
};

User::User() {
	firstname = "";
	lastname = "";
	username = "";
	password = "";
}

// setter method
void User::setUser() {
	cout << "Firstname: ";
	cin >> firstname;
	cout << "Lastname: ";
	cin >> lastname;
	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;
}

void displayUser(User Ur) {
	cout << Ur.getFirstname() << endl;
}

void StoreUser(User Ur) {
	string fileName = Ur.getUsername();

	ofstream outFile;
	outFile.open(fileName + ".txt");

	outFile << Ur.getPassword() << "," << Ur.getLastname() << " " << Ur.getFirstname() << "," << Ur.getUsername() << endl;
}

void Login() {
	string filename, pass;

	cout << "Username: ";
	cin >> filename;

	ifstream inFile;
	inFile.open(filename + ".txt");

	string line = "";
	string password, firstname, lastname, username;
	int pos = 0;

	if (inFile.good()) {
		getline(inFile, line);

		//getting password
		pos = line.find(",");
		password = line.substr(0, pos);
		line = line.erase(0, pos + 1);

		//getting lastname
		pos = line.find(" ");
		lastname = line.substr(0, pos);
		line = line.erase(0, pos + 1);

		//getting firstname
		pos = line.find(",");
		firstname = line.substr(0, pos);
		line = line.erase(0, pos + 1);

		cout << "Password: ";
		cin >> pass;

		if (pass == password) {
			cout << "Welcome Back!\n*************" << endl;
			cout << "Firstname: " << firstname << endl;
			cout << "Lastname: " << lastname << endl;
			cout << "Username: " << filename << endl;
		}
		else {
			cout << "Incorrect Password!" << endl;
		}
	}
	else {
		cout << "User Not Found!" << endl;
	}
}

int main() {

	//declare variables
	User Ur;
	int menu;

	cout << "***Welcome to rk11 Login System***" << endl;
	cout << "\nMENU\n********************" << endl;
	cout << "1: Login" << endl;
	cout << "2: Register" << endl;
	cout << "Any other key to exit!" << endl;
	cin >> menu;

	if (menu == 1) {
		Login();
	}else
	if (menu == 2) {
		Ur.setUser();
		StoreUser(Ur);
	}
	else
	{
		exit(1);
	}
	displayUser(Ur);

	system("pause");
}