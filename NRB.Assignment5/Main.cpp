
// Assignment 5 - Math Quiz
// Neebinnodin Buswa

#include <iostream>
#include <conio.h>
#include <fstream>
#include <vector>
#include <string>

// Function Prototypes
std::vector<std::string> loadQuestions(const std::string &filepath);

int main()
{
	
	
	// Math quiz that opens a set of three questions from  Questions.txt
	// saves the results of three questions to Results.txt
	// question = answer

	// Variables
	std::vector<std::string> questions;
	std::vector<double> answers;

	std::string filepath = "Questions.txt";
	std::string filepath2 = "Results.txt";
	
	const int numQuestions = 3;
	srand(time(NULL));
	int randomNumber; 
	double answer;

	/*std::string line;
	std::ifstream ifsQuestions(filepath);
	while (getline(ifsQuestions, line))
	{
		questions.push_back(line);
	}
	ifsQuestions.close();*/
	questions = loadQuestions(filepath);

	// Ask 3 questions and answer, save to file Results.txt

	std::cout << "Welcome to the Math Quiz\n\n";

	std::ofstream ofsResults(filepath2);
	for (int i = 0; i < numQuestions; i++)
	{
		randomNumber = rand() % 10 + 1;
		std::cout << "Question " << (i + 1) << ": " << questions[randomNumber] << "\n";
		std::cout << "Enter your answer: ";
		std::cin >> answer;
		answers.push_back(answer);

		ofsResults << questions[i] << " = " << answer << "\n";
	}
	std::cout << "\nResults saved to Results.txt\n";
	ofsResults.close();


	
	(void)_getch();
	return 0;
}

// Functions
std::vector<std::string> loadQuestions(const std::string &filepath)
{
	std::vector<std::string> questions;
	std::string line;
	std::ifstream ifsQuestions(filepath);
	while (getline(ifsQuestions, line))
	{
		questions.push_back(line);
	}
	ifsQuestions.close();
	return questions;
}
