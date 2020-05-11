#include <iostream>				
#include <Windows.h>			// ƒл€ функц≥њ SLEEP дл€ часу показу пов≥домленн€
#include <cstring>				// ƒл€ р€дк≥в
#include <ctime>				// ƒл€ рандому 
#include "ALL Function.h"		// ƒл€ п≥дключенн€ прототип≥в моњх функц≥й
#define SIZE 100

using namespace std;

char playerName1[SIZE];												// ≤м'€ гравц≥€ ћќ™ ≥м'€
char playerName2[SIZE] = "Computer";								// ≤м'€ гравц≥в  ќћѕ'ё“≈–
char cells[9] = { '-', '-', '-', '-', '-', '-', '-', '-', '-' };	// ƒл€ кл≥тиночок, порожн€ кл≥тинка "-"
char win = '-';														// —имвол перемоги ("-" - н≥чи€ ) не константа бо присвоюЇтьс€ переможний символ ≥ перев≥р€Їтьс€ 
char X = 'X';
char O = 'O';

int main()
{
	srand(time(nullptr));

	size_t choiseMenu;										// ƒл€ вибору в меню
	size_t opponent = 1, complexity = 1;					// «а замовчуванн€м складн≥сть 1 ≥ опонент комп'ютер
	char human, computer;
	char turn = X;
	int randNumber = rand() % 2 + 1;						// –андомне число 1 або 2		

	ShowLogo();												// показати лого
	if (CheckMenu())										// ‘ункц≥€ перев≥р€Ї на правильн≥сть вводу. 
	{														// якщо False то йдемо дал≥ 
		cout << "Goodbye";
		return 0;
	}
	system("cls");											// ќчистка екрану

	do
	{
		ShowTextMenu();
		cout << "Your choise : ";
		cin >> choiseMenu;									// ¬ибираЇмо пункт меню
		ClearCin();
		system("cls");

		if (choiseMenu == 1)
		{
			if (opponent == 2)								// якщо гра √–ј¬≈÷№ проти √–ј¬÷я
			{
				cout << "Enter the name of the 1st player: ";
				EnterNamePlayer(playerName1, playerName2);

				cout << "Enter the name of the 2st player: ";
				EnterNamePlayer(playerName2, playerName1);

				cout << "Name 1st player - " << playerName1 << endl;
				cout << "Name 2st player - " << playerName2 << endl;

				char human = FirstMove();
				if (human == O)
				{
					swap(playerName1, playerName2);			// ћ≥н€Їмо м≥сц€ми ≥мена
					human = X;
				}

				char computer = OpponentFunction(human);

				ShowCells();

				for (int move = 1; move <= 9; move++)		// ÷икл на 9 ход≥в, бо всього 9 кл≥тинок
				{
					if (randNumber == 1)
					{
						if (turn == human)
							MakeMove(1, X);
						else								// х≥д комп'ютера
							MakeMove(2, O);
					}
					else									// rand == 2
					{
						if (turn == human)					// X==X	€кщо rand == 2 то перший х≥д робить гравець 2 
							MakeMove(2, O);
						else
							MakeMove(1, X);
					}

					turn = OpponentFunction(turn);

					ShowCells();							// ѕоказуЇмо ≥грове поле
					if (move >= 5)							// якщо х≥д б≥льший 5 то проводимо перев≥рку на перемогу
					{
						win = CheckWinCombination();		// ѕовертаЇ символ перемоги, €кщо поверне ≥дм≥нний символ в≥д "-", то цей гравець виграв 
						if (win != '-')
							break;							// якщо спрацюЇ if то виходимо з циклу
					}
				}
				ShowResult();								// ѕоказуЇмо результат гри
				return 0;									// ¬их≥д з гри п≥сл€ виграшу
			}

			if (opponent == 1)								// якщо гра √–ј¬≈÷№ проти  ќћѕ'ё“≈–ј
			{
				cout << "Enter your name: ";
				EnterNamePlayer(playerName1, playerName2);

				char human = FirstMove();
				char computer = OpponentFunction(human);

				ShowCells();								// ѕоказуЇмо ≥грове поле

				for (int move = 1; move <= 9; move++)		// ÷икл на 9 ход≥в, бо всього 9 кл≥тинок
				{
					if (randNumber == 1)					// якщо rand == 1 тод≥ 1 х≥д
					{
						if (turn == human && human == X)
							MakeMove(1, X);
						else if (turn == human && human == O)
							MakeMove(1, O);
						else										// ’≥д ком'ютера
						{
							if (complexity == 2 && move >= 3)		// якщо х≥д б≥льший р≥вний 3 то виконуЇмо перев≥рку на блок
							{
								if (!ChechBlock(computer))
									ComputerMove(computer);
							}
							else if (complexity == 3)				// €кщо HARD mode € ’ ≥ rand == 1 то € ходжу першим
								HardMode(computer, move);
							else
								ComputerMove(computer);
						}
					}
					else											// якщо rand == 2 тод≥ 2 х≥д
					{
						if (human == X)
						{
							if (turn == human)
							{
								if (complexity == 2 && move >= 3)	// якщо х≥д б≥льший р≥вний 3 то виконуЇмо перев≥рку на блок
								{
									if (!ChechBlock(computer))
										ComputerMove(computer);
								}
								else if (complexity == 3)			// €кщо HARD mode € ’ ≥ rand == 2 то € ходжу другим
									HardMode(computer, move);
								else
									ComputerMove(computer);
							}
							else
								MakeMove(1, X);
						}
						else
						{
							if (turn == human)
							{
								if (complexity == 2 && move >= 3)  // якщо х≥д б≥льший р≥вний 3 то виконуЇмо перев≥рку на блок
								{
									if (!ChechBlock(computer))
										ComputerMove(computer);
								}
								else if (complexity == 3)
									HardMode(computer, move);
								else
									ComputerMove(computer);
							}
							else
								MakeMove(1, O);
						}
					}
					turn = OpponentFunction(turn);
					ShowCells();									// ѕоказуЇмо ≥грове поле
					if (move >= 5)									// якщо х≥д б≥льший 5 то проводимо перев≥рку на перемогу
					{
						win = CheckWinCombination();				// ѕовертаЇ символ перемоги, €кщо поверне ≥дм≥нний символ в≥д "-", то цей гравець виграв 
						if (win != '-')
						{
							if (human == O) swap(playerName1, playerName2);
							break;									// якщо спрацюЇ if то виходимо з циклу
						}
					}
				}
				ShowResult();										// ѕоказуЇмо результат гри
				return 0;											// ¬их≥д з гри п≥сл€ виграшу
			}
		}
		if (choiseMenu == 2)										// якщо 2 то входжу в налаштуванн€
		{
			int options;											// «м≥нна дл€ налаштувань меню
			system("cls");
			cout << "\t\t1. Opponent: ";
			ShowOpponent(opponent);

			if (opponent == 1)										// якщо опонент комп'ютер то можна вибрати складн≥сть
			{
				cout << "\n\t\t2. Complexity: ";
				ShowRank(complexity);								// «а замовчуванн€м складн≥сть EASY
			}

			cout << "\n\t\t3. Back to previous menu.\n\n\t\tYour choise: ";
			cin >> options;

			if (opponent == 2 && options == 2)
			{
				cout << "\t\tERROR\n";								// ѕерев≥рка на складн≥сть коли граЇ людина
				options = 0;
			}

			if (!(options == 1 || options == 2 || options == 3))
			{
				ClearCin();
				do
				{
					cout << "\t\tIncorrect input\n\t\tYour choise: ";
					cin >> options;
					ClearCin();

					if (opponent == 2 && options == 2)				//ѕерев≥рка на складн≥сть коли граЇ людина 
					{
						cout << "\t\tERROR\n";
						options = 0;
					}
				} while (!(options == 1 || options == 2 || options == 3));
			}

			if (options == 1)										// якщо € хочу щось зм≥нити противника то вводжу 1 
			{
				system("cls");
				cout << "\t\t\t\tOpponent:\n\t\t\t\t1. Human vs Computer\n\t\t\t\t2. Human vs Human\n\t\t\t\tYour choise: ";
				cin >> opponent;
				if (!(opponent == 1 || opponent == 2))
				{
					ClearCin();
					do
					{
						cout << "\t\t\t\tIncorrect input\n\t\t\t\tYour choise: ";
						cin >> opponent;
						ClearCin();
					} while (!(opponent == 1 || opponent == 2));
				}
				system("cls"), choiseMenu = 0;
			}
			else if (options == 2)
			{
				system("cls");
				cout << "\t\t\t\tComplexity:\n\t\t\t\t1. Easy\n\t\t\t\t2. Hard\n\t\t\t\t3. Impossible\n\t\t\t\tYour choise: ";
				cin >> complexity;

				if (!(complexity == 1 || complexity == 2 || complexity == 3))
				{
					ClearCin();
					do
					{
						cout << "\t\t\t\tIncorrect input\n\t\t\t\tYour choise: ";
						cin >> complexity;
						ClearCin();

					} while (!(complexity == 1 || complexity == 2 || complexity == 3));
				}
				system("cls"), choiseMenu = 0;
			}
			else
				system("cls");
		}
		else if (choiseMenu > 3 || choiseMenu < 1)
		{
			system("cls");
			cout << "\n\tIncorrect input. Try againn.";
			Sleep(1500), system("cls");								// „ас на пов≥домленн€
		}

	} while (choiseMenu != 3);

	cout << "Goodbye";
	return 0;
}