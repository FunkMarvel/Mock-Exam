#include "tasks.h"

void start_task(int position) {
	// function starting the chosen menu item.
	switch (position) {
	case 0:
		task2();
		break;
	case 1:
		task4();
		break;
	case 2:
		task5();
		break;
	case 3:
		exit(0);
	default:
		break;
	}
}

void task3() {
	// function displaying menu and allowing menu navigation.
	int position{};
	vector<string> menu_options{
		"Print names' Initials and Lasts (Task 2)",
		"Students'exam result (Task4)",
		"Typing a sentence (Task5)",
		"Terminate the program (Quit)"
	};
	char input{};

	while (true) { // menu loop
		system("cls");

		for (int i = 0; i < menu_options.size(); i++) {
			// prints current state of menu.
			if (i == position) {
				cout << " - >";
			}
			cout << " | " << i + 1 << ": " << menu_options[i] << endl;
		}

		// first ever attempt at getting arrow key input.
		// key is pressed if high bit of return-value is 1:
		short key_up{ GetAsyncKeyState(VK_UP) };
		short key_down{ GetAsyncKeyState(VK_DOWN) };

		// extract high-bit to check if key is pressed:
		if (key_up >> 15) {
			input = 'w';
		}
		else if (key_down >> 15) {
			input = 's';
		}
		else { // gets key if arrow keys are not used.
			input = _getch();
		}

		switch (tolower(input)) {  // changes menu position according to input.
		case 'w':
			position--;
			break;
		case 's':
			position++;
			break;
		case 13:  // selects current menu item on press of enter key.
			system("cls");
			start_task(position);
			system("pause");
			break;
		default:
			break;
		}

		// loops position around if out of menu range.
		if (position < 0) { position = menu_options.size() - 1; }
		else if (position >= menu_options.size()) { position = 0; }
		Sleep(20);  // added to avoid ghosting when using arrow-keys.
	}
}