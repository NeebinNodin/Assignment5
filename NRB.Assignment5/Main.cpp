
// Assignment 5 - Math Quiz
// Neebinnodin Buswa

#include <iostream>
#include <conio.h>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	// Math quiz that opens a set of three questions from a Questions.txt
	vector<string> questions;
	vector<double> answers;

	// Open the file
	string filepath = "Questions.txt";

	
	string line;
	ifstream ifsQuestions(filepath);
	while (getline(ifsQuestions, line))
	{
		questions.push_back(line);
	}
	ifsQuestions.close();

	// Ask 3 questions and answer, save to file Results.txt

	string filepath2 = "Results.txt";

	const int numQuestions = 10;
	srand(time(NULL));
	int randomNumber; 
	double answer;
	ofstream ofsResults(filepath2);
	for (int i = 0; i < numQuestions; i++)
	{
		randomNumber = rand() % 10 + 1;
		cout << "Question " << (i + 1) << ": " << questions[randomNumber] << "\n";
		cout << "Enter your answer: ";
		cin >> answer;
		answers.push_back(answer);

		ofsResults << questions[randomNumber] << "\n";
	}
	cout << "\nResults saved to Results.txt\n";
	ofsResults.close();

	(void)_getch();
	return 0;
}
