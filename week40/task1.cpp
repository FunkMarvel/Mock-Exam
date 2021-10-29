#include "tasks.h"

bool task1() {
	// function performing login. Returns true if logged in, exits program if loggin fails.
	int attempts{};
	int max_attempts{ 5 };
	const string password{ "adminpass" };
	bool logged_in{ false };

	while (max_attempts > attempts++ && !logged_in) { // loops until succesful login or too many attempts.
		string user_input{};

		cout << " Task 1:" << endl << " Enter password: ";
		cin >> user_input;
		
		if (user_input.size() != password.size()) {
			// checks for password size mismatch. 
			cout << " Wrong password." << endl;
			cout << " " << max_attempts - attempts << " attempts remaining." << endl;
			system("pause");
		}
		else {
			for (unsigned int i = 0; i < user_input.size(); i++) {
				// checks password element by element:
				if (!(tolower(user_input[i]) == tolower(password[i]))) {
					cout << " Wrong password." << endl;
					cout << " " << max_attempts - attempts << " attempts remaining." << endl;
					system("pause");
					break;
				}
				else if(i + 1 == user_input.size()) {
					logged_in = true;
				}
			}
		}
		system("cls");
	}
	if (attempts > 4) exit(0);

	return logged_in;
}