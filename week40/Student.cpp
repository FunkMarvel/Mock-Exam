#include "tasks.h"
// logic for Student class.

// constructors:
Student::Student() {
	name = "Ola";
	answers = "ABDCABDA";
}

Student::Student(string iname, string ianswers) {
	name = iname;
	answers = ianswers;
}

// private methods:
void Student::calcScore() {
	int sum{};
	for (int i = 0; i < correct_answers.size(); i++) {
		if (answers[i] == correct_answers[i]) sum++;
	}
	score = sum;
}

// public methods:
void Student::setCorrectAnswers(string ianswers) {
	correct_answers = ianswers;
}

string Student::getName() {
	return name;
}

string Student::getAnswers() {
	return answers;
}

int Student::getScore() {
	if (score < 0) { calcScore(); }
	return score;
}
