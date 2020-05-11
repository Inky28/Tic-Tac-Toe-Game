#include <iostream>				
#include <Windows.h>			// ��� ������� SLEEP ��� ���� ������ �����������
#include <cstring>				// ��� �����
#include <ctime>				// ��� ������� 
#include "ALL Function.h"		// ��� ���������� ��������� ��� �������
#define SIZE 100

using namespace std;

char playerName1[SIZE];												// ��'� ������� �Ϊ ��'�
char playerName2[SIZE] = "Computer";								// ��'� ������� ����'����
char cells[9] = { '-', '-', '-', '-', '-', '-', '-', '-', '-' };	// ��� ���������, ������� ������� "-"
char win = '-';														// ������ �������� ("-" - ���� ) �� ��������� �� ������������ ���������� ������ � ������������ 
char X = 'X';
char O = 'O';

int main()
{
	srand(time(nullptr));

	size_t choiseMenu;										// ��� ������ � ����
	size_t opponent = 1, complexity = 1;					// �� ������������� ��������� 1 � ������� ����'����
	char human, computer;
	char turn = X;
	int randNumber = rand() % 2 + 1;						// �������� ����� 1 ��� 2		

	ShowLogo();												// �������� ����
	if (CheckMenu())										// ������� �������� �� ����������� �����. 
	{														// ���� False �� ����� ��� 
		cout << "Goodbye";
		return 0;
	}
	system("cls");											// ������� ������

	do
	{
		ShowTextMenu();
		cout << "Your choise : ";
		cin >> choiseMenu;									// �������� ����� ����
		ClearCin();
		system("cls");

		if (choiseMenu == 1)
		{
			if (opponent == 2)								// ���� ��� ������� ����� ������
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
					swap(playerName1, playerName2);			// ̳����� ������ �����
					human = X;
				}

				char computer = OpponentFunction(human);

				ShowCells();

				for (int move = 1; move <= 9; move++)		// ���� �� 9 ����, �� ������ 9 �������
				{
					if (randNumber == 1)
					{
						if (turn == human)
							MakeMove(1, X);
						else								// ��� ����'�����
							MakeMove(2, O);
					}
					else									// rand == 2
					{
						if (turn == human)					// X==X	���� rand == 2 �� ������ ��� ������ ������� 2 
							MakeMove(2, O);
						else
							MakeMove(1, X);
					}

					turn = OpponentFunction(turn);

					ShowCells();							// �������� ������ ����
					if (move >= 5)							// ���� ��� ������ 5 �� ��������� �������� �� ��������
					{
						win = CheckWinCombination();		// ������� ������ ��������, ���� ������� ������� ������ �� "-", �� ��� ������� ������ 
						if (win != '-')
							break;							// ���� ������� if �� �������� � �����
					}
				}
				ShowResult();								// �������� ��������� ���
				return 0;									// ����� � ��� ���� �������
			}

			if (opponent == 1)								// ���� ��� ������� ����� ����'�����
			{
				cout << "Enter your name: ";
				EnterNamePlayer(playerName1, playerName2);

				char human = FirstMove();
				char computer = OpponentFunction(human);

				ShowCells();								// �������� ������ ����

				for (int move = 1; move <= 9; move++)		// ���� �� 9 ����, �� ������ 9 �������
				{
					if (randNumber == 1)					// ���� rand == 1 ��� 1 ���
					{
						if (turn == human && human == X)
							MakeMove(1, X);
						else if (turn == human && human == O)
							MakeMove(1, O);
						else										// ճ� ���'�����
						{
							if (complexity == 2 && move >= 3)		// ���� ��� ������ ����� 3 �� �������� �������� �� ����
							{
								if (!ChechBlock(computer))
									ComputerMove(computer);
							}
							else if (complexity == 3)				// ���� HARD mode � � � rand == 1 �� � ����� ������
								HardMode(computer, move);
							else
								ComputerMove(computer);
						}
					}
					else											// ���� rand == 2 ��� 2 ���
					{
						if (human == X)
						{
							if (turn == human)
							{
								if (complexity == 2 && move >= 3)	// ���� ��� ������ ����� 3 �� �������� �������� �� ����
								{
									if (!ChechBlock(computer))
										ComputerMove(computer);
								}
								else if (complexity == 3)			// ���� HARD mode � � � rand == 2 �� � ����� ������
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
								if (complexity == 2 && move >= 3)  // ���� ��� ������ ����� 3 �� �������� �������� �� ����
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
					ShowCells();									// �������� ������ ����
					if (move >= 5)									// ���� ��� ������ 5 �� ��������� �������� �� ��������
					{
						win = CheckWinCombination();				// ������� ������ ��������, ���� ������� ������� ������ �� "-", �� ��� ������� ������ 
						if (win != '-')
						{
							if (human == O) swap(playerName1, playerName2);
							break;									// ���� ������� if �� �������� � �����
						}
					}
				}
				ShowResult();										// �������� ��������� ���
				return 0;											// ����� � ��� ���� �������
			}
		}
		if (choiseMenu == 2)										// ���� 2 �� ������ � ������������
		{
			int options;											// ����� ��� ����������� ����
			system("cls");
			cout << "\t\t1. Opponent: ";
			ShowOpponent(opponent);

			if (opponent == 1)										// ���� ������� ����'���� �� ����� ������� ���������
			{
				cout << "\n\t\t2. Complexity: ";
				ShowRank(complexity);								// �� ������������� ��������� EASY
			}

			cout << "\n\t\t3. Back to previous menu.\n\n\t\tYour choise: ";
			cin >> options;

			if (opponent == 2 && options == 2)
			{
				cout << "\t\tERROR\n";								// �������� �� ��������� ���� ��� ������
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

					if (opponent == 2 && options == 2)				//�������� �� ��������� ���� ��� ������ 
					{
						cout << "\t\tERROR\n";
						options = 0;
					}
				} while (!(options == 1 || options == 2 || options == 3));
			}

			if (options == 1)										// ���� � ���� ���� ������ ���������� �� ������ 1 
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
			Sleep(1500), system("cls");								// ��� �� �����������
		}

	} while (choiseMenu != 3);

	cout << "Goodbye";
	return 0;
}