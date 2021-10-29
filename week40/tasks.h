#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <windows.h>

using std::cout; using std::cin; using std::string;
using std::endl; using std::vector;

bool task1();
void task2();
void task3();
void task4();
void task5();

class Student {
	// student class used for task 4.
private:
	string name{};
	string answers{};
	string correct_answers{ "ABDCABDA" };
	int score{ -1 };

	void calcScore();

public:
	Student();
	Student(string, string);

	void setCorrectAnswers(string);
	string getName();
	string getAnswers();
	int getScore();
};