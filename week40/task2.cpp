#include "tasks.h"

void task2() {
	// function printing names with initial and final character.
	vector<string> names{ "Jonathan", "Suzan", "Lucy", "John" };

	cout << " Task 2:" << endl;
	for (int i = 0; i < names.size(); i++) {
		cout << " " << names[i] << ": " << " Initial is '" << names[i][0]
			<< "', and final char is: '" << names[i][names[i].size() - 1] << "'." << endl;
	}
}