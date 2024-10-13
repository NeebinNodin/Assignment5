// Assignment 5 - Math Quiz
// Neebinnodin Buswa
/*
*******************
Wrote my code first in the main function, then I broke it up into functions.
Did get stuck a few times but I figured it out.

Commented out code is what I had originally before.
*/


#include <iostream>
#include <conio.h>
#include <fstream>
#include <vector>
#include <string>

// Function Prototypes
std::vector<std::string> loadQuestions(const std::string &filepath);
void askQuestions(const std::vector<std::string> &questions, std::vector<double> &answers, int numQuestions);
void saveResults(const std::string &filepath2, const std::vector<std::string> &questions, const std::vector<double> &answers);

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
	/*srand(time(NULL));
	int randomNumber;
	double answer;*/

	/*std::string line;
	std::ifstream ifsQuestions(filepath);
	while (getline(ifsQuestions, line))
	{
		questions.push_back(line);
	}
	ifsQuestions.close();*/

	questions = loadQuestions(filepath);
	askQuestions(questions, answers, numQuestions);
	saveResults(filepath2, questions, answers);

	// Ask 3 questions and answer, save to file Results.txt

	/*std::cout << "Welcome to the Math Quiz\n\n";

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
	ofsResults.close();*/

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
	
void askQuestions(const std::vector<std::string> &questions, std::vector<double> &answers, int numQuestions)
{
	//const int numQuestions = 3;
	srand(time(NULL));
	int randomNumber;
	double answer;
	//std::ofstream ofsResults(filepath2);
	for (int i = 0; i < numQuestions; i++)
	{
		randomNumber = rand() % 10 + 1;
		std::cout << "Question " << (i + 1) << ": " << questions[randomNumber] << "\n";
		std::cout << "Enter your answer: ";
		std::cin >> answer;
		answers.push_back(answer);

		//ofsResults << questions[i] << " = " << answer << "\n";
	}
	//std::cout << "\nResults saved to Results.txt\n";
	//ofsResults.close();
}
void saveResults(const std::string &filepath2, const std::vector<std::string> &questions, const std::vector<double> &answers)
{
	std::ofstream ofsResults(filepath2);
	for (size_t i = 0; i < answers.size(); i++) // didn't know if I should of used size_t or int. it gave suggension of
		// size_t.. I looked it up and it seems to make sense, so I used it.
		// seems to work...
	{
		ofsResults << questions[i] << " = " << answers[i] << "\n";
	}
	ofsResults.close();
	std::cout << "\nResults saved to Results.txt\n";
}