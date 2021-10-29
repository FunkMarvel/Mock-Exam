#include "tasks.h"
#include <algorithm> 

void task4() {
	// function adding, sorting and printing students.
	int num_students{};
	vector<Student> students{};

	cout << " How many students will you input info of? type number: ";
	cin >> num_students;

	for (int i = 0; i < num_students; i++) { // inputting student data and pushing to vector
		string name{}; string answers{};
		cout << " Student nr. " << i + 1 << endl;
		cout << " Enter name (no space): ";
		cin >> name;

		cout << " Enter answers (0 to 8 characters, no space): ";
		cin >> answers;
		transform(answers.begin(), answers.end(), answers.begin(), ::toupper);  // converting answer string to upper case

		students.push_back(Student(name, answers));
		system("cls");
	}

	vector<Student> sorted_students{}; // new vector for students from highest score to lowest.
	for (int i = 0; i < num_students; i++) {  // iterating through number of students.
		int max_index{};
		for (int i = 0; i < students.size(); i++) {  // finding highest score among students in old vector.
			if (students[i].getScore() >= students[max_index].getScore()) { 
				max_index = i;
			}
		}
		// adding current highest to new vector and removing from old vector:
		sorted_students.push_back(students[max_index]);
		students.erase(students.begin() + max_index);
	}

	// summing up total score, and printing table of student and score:
	double total_score{};
	cout << " Name: \t" << " Score" << endl;
	for (int i = 0; i < num_students; i++) {
		int temp_score{ int(sorted_students[i].getScore()) };
		cout << " " << sorted_students[i].getName() << "\t\t" << temp_score << endl;

		total_score += temp_score;
	}

	// printing max, min and average score:
	cout << "---------------" << endl;
	cout << " Average score: " << total_score / num_students << endl;
	cout << " Max score: " << sorted_students[0].getScore() << endl;
	cout << " Min score: " << sorted_students[sorted_students.size() - 1].getScore() << endl;
}