#include <iostream>
#include <string>
#include <cmath>

using namespace std;

enum enChose { stone = 1, paper = 2, scissor = 3 };

enum enHowWinner { Player1 = 1, Computer = 2, Draw = 3 };

int ReadNumber()
{
	int number;
	cout << "\n enter a number : ";
	cin >> number;


	return number;
}
int RandomNumber(int From, int To)
{

	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}
short HowManyRouds()
{
	short Rounds = 0;
	cout << "HOW MANY ROUNDS FROM 1 TO 10 DO YOU WANT : \n";
	cin >> Rounds;
	cout << endl;
	return Rounds;
}
enChose ReadPlayerChoice(int number)
{
	switch (number)
	{
	case 1:
		return enChose::stone;
	case 2:
		return enChose::paper;
	case 3:
		return enChose::scissor;
	
	}
}
enChose ReadComputerChoice(int number)
{
	switch (number)
	{
	case 1:
		return enChose::stone;
	case 2:
		return enChose::paper;
	case 3:
		return enChose::scissor;
	
	}
}
string WhatDoYouChoice(enChose Choice)
{
	if (Choice == enChose::stone)
	{
		return "[STONE]";
	}
	if (Choice == enChose::paper)
	{
		return "[PAPER]";
	}
	if (Choice == enChose::scissor)
	{
		return "[SCISSOR]";
	}


}
enHowWinner HowIsTheWiner(enChose Player, enChose Computer)
{
	if (Player == enChose::stone && Computer == enChose::paper)
		return enHowWinner::Computer;

	 if (Player == enChose::stone && Computer == enChose::scissor)
		return enHowWinner::Player1;

 if (Player == enChose::paper && Computer == enChose::scissor)
		return enHowWinner::Computer;

 if (Player == enChose::paper && Computer == enChose::stone)
		return enHowWinner::Player1;

 if (Player == enChose::scissor && Computer == enChose::stone)
		return enHowWinner::Computer;

	 if (Player == enChose::scissor && Computer == enChose::paper)
		return enHowWinner::Player1;


		return enHowWinner::Draw;
}
void GetColorForWin(enHowWinner HowIsWiner)
{
	if (HowIsWiner == enHowWinner::Computer)
		system("color 4F ");
	else if (HowIsWiner == enHowWinner::Player1)
		system("color 2F ");
	else if (HowIsWiner == enHowWinner::Draw)
		system("color 6F ");
}
void EndOfGame()
{
	cout << "---------------------------------------\n\n";

	cout << "             +++ Game Over +++              \n\n";

	cout << "---------------------------------------\n\n";

	cout << "--------------- [Game Result] ---------\n";
}
string WriterHowIsWinner(enHowWinner tybe)
{
	if (tybe == enHowWinner::Computer)
		return "Computer";
	else if (tybe == enHowWinner::Player1)
		return "Player1";
	else if (tybe == enHowWinner::Draw)
		return "Draw";
}

bool RoundTable(short CountRound)
{


	int Player = 0;
	int Computer = 0;
	int Draw = 0;
	string FinalWiner = "";
	
	int number = 0;



	for (int counter = 1; counter <= CountRound; counter++)
	{
		int NumberOfComputer = RandomNumber(1, 3);


		cout << "Round [" << counter << "] begins : \n\n";

		cout << "Your choice :[1] Stone , [2] Paper , [3] scissor ? ";
		cin >> number;

		cout << "\n\n-------------- Round [" << counter << "]" << " --------------\n\n";
		cout << "Player Choice   : " << WhatDoYouChoice(ReadPlayerChoice(number));

		cout << "\nComputer Choice : " << WhatDoYouChoice(ReadComputerChoice(NumberOfComputer));




		cout << "\nRound Winer     : ";

		enHowWinner HowIsWin = (HowIsTheWiner((ReadPlayerChoice(number)), ReadComputerChoice(NumberOfComputer)));

		GetColorForWin(HowIsWin);
		cout << WriterHowIsWinner(HowIsWin);

		cout << "\n\n---------------------------------------\n\n";



		if (HowIsWin == enHowWinner::Computer)
			Computer++;
		else if (HowIsWin == enHowWinner::Player1)
			Player++;
		else if (HowIsWin == enHowWinner::Draw)
			Draw++;
	}
	EndOfGame();

	string M = "";
	if (Computer > Player)
		M = "Computer";
	else if (  Player > Computer)
		M = "Player1";
	else 
		M = "Draw";


	cout << "Game Round         :" << CountRound;
	cout << "\nPlayer1 won times  :" << Player;
	cout << "\nComputer won times :" << Computer;
	cout << "\nDraw times         :" << Draw;
	cout << "\nFinal winner       :" << M;
	
	cout << "\n---------------------------------------\n\n";

	char PlayAgain;
	cout << "do you want to Play again ? Y/N " << endl;
	cin >> PlayAgain;
	if (PlayAgain == 'Y' || PlayAgain == 'y')
		return true;
	else if ((PlayAgain == 'N' || PlayAgain == 'n'))
		return false;
}

	int main()
	{
		
		while (RoundTable(HowManyRouds()))
		{
			
		}

		return 0;
	}