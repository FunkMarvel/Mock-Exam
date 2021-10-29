#include "tasks.h"

void task5() {
	// function running task 5 letter array.
	int num_characters{};
	int position{};
	char current_char{ 'A'};  // current char starts with ascii decimal value of 'A'
	bool sentence_complete{ false };

	cout << " How many characters do you want in your sentence? Type a number: ";
	cin >> num_characters;
	system("cls");

	// dynamically allocating array of chars:
	char* sentence = new char[num_characters];
	for (int i = 0; i < num_characters; i++) {  // starting all chars as space.
		sentence[i] = ' ';
	}
	
	while (!sentence_complete) {  // loops until enter key is pressed.
		char input{};
		system("cls");

		for (int i = 0; i < num_characters; i++) {  // prints current array.
			cout << " [" << sentence[i];
			if (position == i) {
				cout << "*";
			}
			cout << "] ";
		}
		cout << endl;
		
		// key is pressed if high bit of return-value is 1:
		short key_up{ GetAsyncKeyState(VK_UP) };
		short key_down{ GetAsyncKeyState(VK_DOWN) };
		short key_left{ GetAsyncKeyState(VK_LEFT) };
		short key_right{ GetAsyncKeyState(VK_RIGHT) };

		// extract high-bit to check if key is pressed:
		if (key_left >> 15) {
			input = 'a';
		}
		else if (key_right >> 15) {
			input = 'd';
		}
		else if (key_up >> 15) {
			input = 'w';
		}
		else if (key_down >> 15) {
			input = 's';
		}
		else{
			input = tolower(_getch());
		}

		// performs selected action:
		switch (input) {
		case 'a':
			position--;
			break;
		case 'd':
			position++;
			break;
		case ' ':  // space bar resets current character. 
			sentence[position] = ' ';
			break;
		case 'w':
			current_char--;
			break;
		case 's':
			current_char++;
			break;
		case 13:  // breaks input loop when enter key is pressed.
			sentence_complete = true;
			break;
		default:
			break;
		}
		
		// loops around left or right when left of first char or right of final char:
		if (position < 0) { position = num_characters - 1; }
		else if (position >= num_characters) { position = 0; }

		// looping alphabet around if befor 'A' or after 'Z':
		if (current_char < 'A') { current_char = 'Z'; }
		else if (current_char > 'Z') { current_char = 'A'; }

		// sets current char to selection:
		if (input == 'w' || input == 's') sentence[position] = current_char;

		Sleep(20);  // added to avoid ghosting when using arrow-keys.
	}

	// prints the complete sentence:
	system("cls");
	cout << " ";
	for (int i = 0; i < num_characters; i++) {
		cout << sentence[i];
	}
	cout << endl;

	delete[] sentence;  // deletes dynamic array.
}