#include <iostream>		
#include "ALL Function.h"
using namespace std;

extern char playerName1[];					// �������� �����								
extern char playerName2[];					// �������� �����				
extern char cells[];						// �������� �����	
extern char win;							// �������� �����	
extern char X;								// �������� �����
extern char O;								// �������� �����

void ShowLogo()
{
	cout << "\t\t\t\t\tWELCOME TO THE GAME TIC TAC TOE \n\n";

	cout << "\t\t\t\t\\\\  ** **     " << "+ " << "**         ** " << "+ " << "**         **\n";
	cout << "\t\t\t\t  \\\\     **   " << "+ " << "  **     **   " << "+ " << "  **     **\n";
	cout << "\t\t\t\t**  \\\\     ** " << "+ " << "    ** **     " << "+ " << "    ** **\n";
	cout << "\t\t\t\t**    \\\\   ** " << "+ " << "    ** **     " << "+ " << "    ** **\n";
	cout << "\t\t\t\t  **    \\\\*   " << "+ " << "  **     **   " << "+ " << "  **     **\n";
	cout << "\t\t\t\t    ** ** \\\\  " << "+ " << "**         ** " << "+ " << "**         **\n";
	cout << "\t\t\t\t+ + + + + + + + + + + + + + + + + + + + + + +\n";
	cout << "\t\t\t\t**         ** " << "+ " << "\\\\  ** **     " << "+ " << "    ** **\n";
	cout << "\t\t\t\t  **     **   " << "+ " << "  \\\\     **   " << "+ " << "  **     **\n";
	cout << "\t\t\t\t    ** **     " << "+ " << "**  \\\\     ** " << "+ " << "**         **\n";
	cout << "\t\t\t\t    ** **     " << "+ " << "**    \\\\   ** " << "+ " << "**         **\n";
	cout << "\t\t\t\t  **     **   " << "+ " << "  **    \\\\*   " << "+ " << "  **     **\n";
	cout << "\t\t\t\t**         ** " << "+ " << "    ** ** \\\\  " << "+ " << "    ** **\n";
	cout << "\t\t\t\t+ + + + + + + + + + + + + + + + + + + + + + +\n";
	cout << "\t\t\t\t    ** **     " << "+ " << "**         ** " << "+ " << "\\\\  ** **\n";
	cout << "\t\t\t\t  **     **   " << "+ " << "  **     **   " << "+ " << "  \\\\     **\n";
	cout << "\t\t\t\t**         ** " << "+ " << "    ** **     " << "+ " << "**  \\\\     **\n";
	cout << "\t\t\t\t**         ** " << "+ " << "    ** **     " << "+ " << "**    \\\\   **\n";
	cout << "\t\t\t\t  **     **   " << "+ " << "  **     **   " << "+ " << "  **    \\\\*\n";
	cout << "\t\t\t\t    ** **     " << "+ " << "**         ** " << "+ " << "    ** ** \\\\\n";

	cout << endl;

	cout << "\t\t***                 ***\t" << "\t\t\t" << "\t\t        *** ***\n";
	cout << "\t\t  ***             ***  \t" << "\t\t\t" << "\t\t      ***     ***\n";
	cout << "\t\t    ***         ***    \t" << "\t\t\t" << "\t\t    ***         ***\n";
	cout << "\t\t     ***     ***      \t\t" << "|\\     /||  ____ \\" << "\t\t  ***             ***\n";
	cout << "\t\t        *** ***        \t\t" << "| |   | || |    \\/ " << "\t\t***                 ***\n";
	cout << "\t\t        *** ***        \t\t" << "| |   | || |_____   " << "\t\t***                 ***\n";
	cout << "\t\t      ***     ***      \t\t" << "\\ \\   / /|_____  |" << "\t\t  ***             ***\n";
	cout << "\t\t    ***         ***    \t\t" << " \\ \\_/ /       | |" << "\t\t    ***         ***\n";
	cout << "\t\t  ***             ***  \t\t" << "  \\   /  /\\____| |" << "\t\t      ***     ***\n";
	cout << "\t\t***                 ***\t\t" << "   \\_/   \\_______|" << "\t\t        *** ***\n";

}

bool CheckMenu()
{
	char tempMenu;

	for (size_t i = 0; i <= 30; i++)
	{
		char tempMenu;
		if (i >= 10)
		{
			cout << "\n\t\t\t\t\tPress 0 to see the menu or 9 to exit ";
			cin >> tempMenu;
			ClearCin();
			if (tempMenu == '9')
				return true;
		}
		else
		{
			cout << "\n\t\t\t\t\tPress 0 to see the menu ";
			cin >> tempMenu;
			ClearCin();
		}

		if (tempMenu == '0')
			break;

		if (i == 30)
		{
			cout << "\n\t\t\t\t\tToo many mistakes. ";
			return true;
		}
	}
	return false;
}

void ShowTextMenu()
{
	cout << "\tTIC-TAC-TOE\n";
	cout << "  MENU\n";
	cout << "1. Play\n";
	cout << "2. Settings\n";
	cout << "3. Exit\n";
}

void ShowCells()
{
	system("cls");										// ��� ������� ������

	cout << "Numbers of cells:\n\n";					// ϳ������ ��� �����

	cout << "-" << 1 << "-" << '|' << "-" << 2 << "-" << '|' << "-" << 3 << "-\n";
	cout << "-" << 4 << "-" << '|' << "-" << 5 << "-" << '|' << "-" << 6 << "-\n";
	cout << "-" << 7 << "-" << '|' << "-" << 8 << "-" << '|' << "-" << 9 << "-\n\n";

	cout << "Current situation (--- is empty):\n\n";	// ������� �������� (--- - ����� �������)

	cout << "-" << cells[0] << "-" << '|' << "-" << cells[1] << "-" << '|' << "-" << cells[2] << "-\n";
	cout << "-" << cells[3] << "-" << '|' << "-" << cells[4] << "-" << '|' << "-" << cells[5] << "-\n";
	cout << "-" << cells[6] << "-" << '|' << "-" << cells[7] << "-" << '|' << "-" << cells[8] << "-\n\n";
}

void ClearCin()
{
	cin.clear();
	while (cin.get() != '\n');
}

void MakeMove(int number, char symb)
{
	int cell;		// ����� ��� ���� �������

	number == 1 ? cout << playerName1 : cout << playerName2; // ���� �������� == 1 �� ��'� ������� ������ ���������� (�� �� ���� ���) ���� � �� �������
	cout << ", enter a cell's number to make move: ";
	cin >> cell;

	while (cell > 9 || cell < 1 || cells[cell - 1] == O || cells[cell - 1] == X)  // ���������� ����������� �����
	{
		cout << "Enter a CORRECT (1-9) and EMPTY (---) cell's number to make move: ";
		ClearCin();		// Գ����� Cin � ������� �����
		cin >> cell;	// ������� ��� �� ��� (�� ���� ��� �� ������ �������)
	}
	ClearCin();			// ������� �����
	// � ��������� �� ������� (���� ������� ������ ������ � ���� ��������) �� ������� �������� �������� �� ������� �������� ���� (� ��� �)
	if (number == 1 && symb == X)	// ���� ������� 1 � � �� ������� �
		cells[cell - 1] = X;
	else
		cells[cell - 1] = O;
}

char CheckWinCombination()
{
	if (cells[0] == cells[1] && cells[1] == cells[2])		// 0 1 2
		return cells[0];
	else if (cells[3] == cells[4] && cells[4] == cells[5])	// 3 4 5
		return cells[3];
	else if (cells[6] == cells[7] && cells[7] == cells[8])	// 6 7 8
		return cells[6];

	else if (cells[0] == cells[3] && cells[3] == cells[6])	// 0 3 6
		return cells[0];
	else if (cells[1] == cells[4] && cells[4] == cells[7])	// 1 4 7
		return cells[1];
	else if (cells[2] == cells[5] && cells[5] == cells[8])	// 2 5 8
		return cells[2];

	else if (cells[0] == cells[4] && cells[4] == cells[8])	// 0 4 8
		return cells[0];
	else if (cells[2] == cells[4] && cells[4] == cells[6])	// 2 4 6
		return cells[2];

	return '-'; // ���� ���� ��������� ��������� ������� "-", ������� �������� ������� Ͳ��� 
}

void ShowResult()
{
	if (win == X)
		cout << playerName1 << " win! Congratulations! " << playerName2 << " is looser!\n";
	else if (win == O)
		cout << playerName2 << " win! Congratulations! " << playerName1 << " is looser!\n";
	else
		cout << "DRAW!!!\n";
}

void ShowOpponent(int tempOpponent)
{
	tempOpponent == 1 ? cout << "Computer" : cout << "Human";
}

void ShowRank(int tempComplexity)
{
	if (tempComplexity == 1)
		cout << "Easy";
	else if (tempComplexity == 2)
		cout << "Hard";
	else
		cout << "Impossible";
}

char AskYesNo()
{
	char response;
	do						// ��� ���������� ����� 
	{
		cout << "Do you want X ? (y/n): ";
		cin >> response;
		ClearCin();
	} while (response != 'y' && response != 'n');
	return response;
}

char FirstMove()
{
	cout << playerName1 << ". ";	// ������� ������� ������ �� ������ � �� �
	char goFirst = AskYesNo();
	return goFirst == 'y' ? X : O;
}

char OpponentFunction(char symbol)
{
	return (symbol == X) ? O : X;
}

char ComputerMove(char symb)
{
	while (true)
	{
		int randCompNumber = rand() % 9 + 1; // �� 1 �� 9 �������� �����

		if (!(cells[randCompNumber - 1] == O || cells[randCompNumber - 1] == X))
			return cells[randCompNumber - 1] = symb;
	}
}

char ChechBlock(char symb)		// ��� ������� ��������� ����� (���� 2 �������� � ���� ��� � �������� ���� �� ������ ����)(��������� � ������)
{
	char tempSymb = OpponentFunction(symb); // ������ ��� �������� (��� ��������� � �����������)

	if ((((cells[0] == cells[1]) && cells[1] == tempSymb) || ((cells[8] == cells[5]) && cells[5] == tempSymb)
		|| ((cells[6] == cells[4]) && cells[4] == tempSymb)) && cells[2] == win)	// (0=1 i 1=(���������� �������) / 8=5 � 5=(���������� �������) / 6=4 � 4=(���������� �������)) i ������� �������
		return cells[2] = symb;

	if ((((cells[2] == cells[5]) && cells[5] == tempSymb) || ((cells[6] == cells[7]) && cells[7] == tempSymb)
		|| ((cells[0] == cells[4]) && cells[4] == tempSymb)) && cells[8] == win)	// (2=5 i 5=(���������� �������) / 6=7 i 7=(���������� �������) / 0=4 i 4=(���������� �������)) i ������� �������
		return cells[8] = symb;

	if ((((cells[1] == cells[2]) && cells[2] == tempSymb) || ((cells[3] == cells[6]) && cells[6] == tempSymb)
		|| ((cells[4] == cells[8]) && cells[8] == tempSymb)) && cells[0] == win)	// (1=2 i 2=(���������� �������) / 3=6 i 6=(���������� �������) / 4=8 i 8=(���������� �������)) i ������� �������
		return cells[0] = symb;

	if ((((cells[0] == cells[3]) && cells[3] == tempSymb) || ((cells[2] == cells[4]) && cells[4] == tempSymb)
		|| ((cells[7] == cells[8]) && cells[8] == tempSymb)) && cells[6] == win)	// (0=3 i 3=(���������� �������) / 2=4 i 4=(���������� �������) / 7=8 i 8=(���������� �������)) i ������� �������
		return cells[6] = symb;

	if ((((cells[1] == cells[4]) && cells[4] == tempSymb) || ((cells[6] == cells[8]) && cells[8] == tempSymb)) && cells[7] == win)	// (1=4 i 4=(���������� �������) / 6=8 i 8=(���������� �������) i ������� �������
		return cells[7] = symb;

	if ((((cells[0] == cells[2]) && cells[2] == tempSymb) || ((cells[4] == cells[7]) && cells[7] == tempSymb)) && cells[1] == win)	// (0=2 i 2=(���������� �������) / 4=7 i 7=(���������� �������) i ������� �������
		return cells[1] = symb;

	if ((((cells[4] == cells[5]) && cells[5] == tempSymb) || ((cells[0] == cells[6]) && cells[6] == tempSymb)) && cells[3] == win)	// (4=5 i 5=(���������� �������) / 0=6 i 6=(���������� �������) i ������� �������
		return cells[3] = symb;

	if ((((cells[2] == cells[8]) && cells[8] == tempSymb) || ((cells[3] == cells[4]) && cells[4] == tempSymb)) && cells[5] == win)	// (2=8 i 8=(���������� �������) / 3=4 i 4=(���������� �������) i ������� �������
		return cells[5] = symb;

	if ((((cells[2] == cells[6]) && cells[6] == tempSymb) || ((cells[0] == cells[8]) && cells[8] == tempSymb) ||
		((cells[1] == cells[7]) && cells[7] == tempSymb) || ((cells[3] == cells[5]) && cells[5] == tempSymb)) && cells[4] == win)	// (2=6 i 6=(���������� �������) / 0=8 i 8=(���������� �������) i ������� ������� / 1=7 i 7=(���������� �������) i ������� ������� / 3=5 i 5=(���������� �������) i ������� �������
		return cells[4] = symb;

	return 0;
}

char CheckGoodChoise(char symb)   // ����� ���������� �� ���� ������������ ����� �� ����� ������� ��� // �� ��������������� ��� ����� �� ��� ������� ������� �� �������	 
{
	if (((cells[0] == cells[3] && cells[3] == symb) || (cells[7] == cells[8] && cells[8] == symb)
		|| (cells[2] == cells[4] && cells[4] == symb)) && cells[6] == win) // ���� 0=3 ��� 7=8 ��� 2=4 � 6 ������� �� � 6 ���������� ������
		return cells[6] = symb;

	if (((cells[0] == cells[1] && cells[1] == symb) || (cells[8] == cells[5] && cells[5] == symb)
		|| (cells[6] == cells[4] && cells[4] == symb)) && cells[2] == win) // ���� 0=1 ��� 8=5 ��� 6=4 � 2 ������� �� � 2 ���������� ������
		return cells[2] = symb;

	if (((cells[3] == cells[6] && cells[6] == symb) || (cells[1] == cells[2] && cells[2] == symb)
		|| (cells[4] == cells[8] && cells[8] == symb)) && cells[0] == win) // ���� 3=6 ��� 1=2 ��� 4=8 � 0 ������� �� � 0 ���������� ������
		return cells[0] = symb;

	if (((cells[2] == cells[5] && cells[5] == symb) || (cells[6] == cells[7] && cells[7] == symb)
		|| (cells[0] == cells[4] && cells[4] == symb)) && cells[8] == win) // ���� 2=5 ��� 6=7 ��� 0=4 � 8 ������� �� � 8 ���������� ������
		return cells[8] = symb;

	if (((cells[0] == cells[6] && cells[6] == symb) || (cells[4] == cells[5] && cells[5] == symb)) && cells[3] == win) // ���� 0=6 ��� 4=5 � 3 ������� �� � 3 ���������� ������
		return cells[3] = symb;

	if (((cells[6] == cells[8] && cells[8] == symb) || (cells[1] == cells[4] && cells[4] == symb)) && cells[7] == win) // ���� 6=8 ��� 1=4 � 7 ������� �� � 7 ���������� ������
		return cells[7] = symb;

	if (((cells[2] == cells[8] && cells[8] == symb) || (cells[3] == cells[4] && cells[4] == symb)) && cells[5] == win) // ���� 2=8 ��� 3=4 � 5 ������� �� � 5 ���������� ������
		return cells[5] = symb;

	if (((cells[0] == cells[2] && cells[2] == symb) || (cells[4] == cells[7] && cells[7] == symb)) && cells[1] == win) // ���� 0=2 ��� 4=7 � 1 ������� �� � 1 ���������� ������
		return cells[1] = symb;

	return 0;
}

char ChecDiagonalMove(char symb)
{
	char tempSymb = OpponentFunction(symb);  // ��� ���������� ��������

	if (tempSymb == cells[1] && tempSymb == cells[5])
		return cells[2] = symb;
	if (tempSymb == cells[1] && tempSymb == cells[3])
		return cells[0] = symb;
	if (tempSymb == cells[7] && tempSymb == cells[5])
		return cells[8] = symb;
	if (tempSymb == cells[3] && tempSymb == cells[7])
		return cells[6] = symb;

	return 0;
}

char CheckAlternativeMove(char symb)
{
	char tempSymb = OpponentFunction(symb);

	if ((tempSymb == cells[2] && tempSymb == cells[3]) || (tempSymb == cells[1] && tempSymb == cells[6]))
		return cells[0] = symb;
	if ((tempSymb == cells[0] && tempSymb == cells[7]) || (tempSymb == cells[3] && tempSymb == cells[8]))
		return cells[6] = symb;
	if ((tempSymb == cells[2] && tempSymb == cells[7]) || (tempSymb == cells[5] && tempSymb == cells[6]))
		return cells[8] = symb;
	if ((tempSymb == cells[0] && tempSymb == cells[5]) || (tempSymb == cells[1] && tempSymb == cells[8]))
		return cells[2] = symb;

	return 0;
}

void HardMode(char computer, int move)
{
	char tempSymb = OpponentFunction(computer);							// ����� ������ ������ ����������

	// ����'���� ���� 1 - 3 - 5 - 7 - 9  ----- ����'���� ������ ������
	// ����'���� ���� 2 - 4 - 6 - 8		 ----- ����'���� ������ ������

	/////////////// 1 ��� ///////////////////
	if (move == 1 || move == 2)											// ���� ������ ��� - �� � ��������, ���� 2 � ����� �������� �� � ��������. ���� 3 ��� � �������� ������� �� � 1 [0] 
	{
		cells[4] == win ? cells[4] = computer : cells[0] = computer;	// ���� ����� �������� 5 ��� [4] �� �������� ���� ����'�����											
		return;															// ���� �������� 5 ��� [4] ������� �� ������� ���� ����'����� � ��������
	}

	//////////////// 2 ��� /////////////////
	switch (move)
	{
	case 3:																// ճ� 3 �� ���� ����'���� ������ ������
		if (tempSymb == cells[0] || tempSymb == cells[8]) cells[2] = computer;
		else if (tempSymb == cells[2] || tempSymb == cells[6]) cells[0] = computer;
		else if (tempSymb == cells[1] || tempSymb == cells[5]) cells[6] = computer;
		else if (tempSymb == cells[3] || tempSymb == cells[7]) cells[2] = computer;
		return;
	case 4:																// ճ� 4, ���� ����'���� ������ ������ ����� � � � (� ��������� O)
		if (!ChechBlock(computer))										// ������� ������� ��������� ��������� (����������) 
		{
			if (cells[4] == tempSymb)
			{
				cells[2] = computer;									// ���� �� ������� ���� �� �������� � 3 [2] ��������
				return;
			}

			if (!ChecDiagonalMove(computer))							// �����Բ���� ղ�
				if (!CheckAlternativeMove(computer))					// �����Բ���� ղ�
				{														// �������� ���� 1 - 9 [0] - [8] ��� 3 - 7 [2] - [6] ��� 2 - 8 [1] - [7] ��� 4 - 6 [3] - [5] 
					if ((cells[0] == win) && ((cells[2] == cells[6]) && cells[6] != win))
						cells[1] = computer;
					else if (cells[0] != win)
						cells[1] = computer;
					else
						cells[0] = computer;							// ����� ����� �� �����ު �� ��������� � 1 [0]
				}
		}
		return;
		//////////////// 3 ��� /////////////////
	case 5:																// ճ� 5 �� ���� ����'���� ������ ������
		if (!CheckGoodChoise(computer))									// �������� �� �������� ������
			ChechBlock(computer);										// ������� ������� ��������� ��������� (����������) 
		return;
	case 6:																// ճ� 6, ���� ����'���� ������ ������ ����� � � � O X (� ��������� O)
		if (!CheckGoodChoise(computer))									// �������� �� �������� ������
			if (!ChechBlock(computer))									// ������� ������� ��������� ��������� (����������) 
				(cells[3] == cells[6]) && cells[0] == computer ? cells[6] = computer : cells[2] = computer; // ��� ����� ���� ��� ������ �� ��������, �������� 100 % ������
		return;
		//////////////// 4 ��� /////////////////
	case 7:																// ճ� 7 �� ���� ����'���� ������ ������
		if (!CheckGoodChoise(computer))									// �������� �� �������� ������ // ���� ����� 2 4 6 8 � ������� ��� �� ��� ��� ������
			cells[1] == win ? cells[1] = computer : cells[3] = computer;// ����� ������ 2 ��� 4 ((����� � ������) ��� � ��������� �������)
		return;
	case 8:																// ճ� 8, ���� ����'���� ������ ������ ����� � � � O X O X (� ��������� O)
		if (!CheckGoodChoise(computer))									// �������� �� �������� ������
			if (!ChechBlock(computer))									// ������� ������� ��������� ��������� (����������) 
				ComputerMove(computer);									// ������ // ��� ����� ������ ����������� 2 ������ ���� ��� ���� �� ������������ ���� ����
		return;
		//////////////// 5 ��� /////////////////
	case 9:																// ճ� 9 �� ���� ����'���� ������ ������
		if (!CheckGoodChoise(computer))									// �������� �� �������� ������
			ComputerMove(computer);										// ���� ��� ���� ������� �� ������ ��������� ���
		return;
	}
}

void EnterNamePlayer(char playerName1[], char playerName2[])
{
	cin.getline(playerName1, 100, '\n');

	if (!strcmp(playerName1, playerName2) || !strcmp(playerName1, "computer"))
	{
		do
		{
			cout << "Wrong input. Same names.\n";
			cout << "Enter your name: ";
			cin.getline(playerName1, 100, '\n');

		} while (!strcmp(playerName1, playerName2) || !strcmp(playerName1, "computer"));
	}
}