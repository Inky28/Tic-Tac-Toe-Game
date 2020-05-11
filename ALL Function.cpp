#include <iostream>		
#include "ALL Function.h"
using namespace std;

extern char playerName1[];					// Оголошую змінну								
extern char playerName2[];					// Оголошую змінну				
extern char cells[];						// Оголошую змінну	
extern char win;							// Оголошую змінну	
extern char X;								// Оголошую змінну
extern char O;								// Оголошую змінну

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
	system("cls");										// Для очистки екрану

	cout << "Numbers of cells:\n\n";					// Підказка для вводу

	cout << "-" << 1 << "-" << '|' << "-" << 2 << "-" << '|' << "-" << 3 << "-\n";
	cout << "-" << 4 << "-" << '|' << "-" << 5 << "-" << '|' << "-" << 6 << "-\n";
	cout << "-" << 7 << "-" << '|' << "-" << 8 << "-" << '|' << "-" << 9 << "-\n\n";

	cout << "Current situation (--- is empty):\n\n";	// Поточна ситуація (--- - пуста клітинка)

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
	int cell;		// Змінна для ходу гравців

	number == 1 ? cout << playerName1 : cout << playerName2; // Якщо аргумент == 1 то ім'я першого гравця виводиться (то це його хід) якщо ні то другого
	cout << ", enter a cell's number to make move: ";
	cin >> cell;

	while (cell > 9 || cell < 1 || cells[cell - 1] == O || cells[cell - 1] == X)  // Перевіряємо правильність вводу
	{
		cout << "Enter a CORRECT (1-9) and EMPTY (---) cell's number to make move: ";
		ClearCin();		// Фіксимо Cin і очищаємо буфер
		cin >> cell;	// Вводимо дані ще раз (до поки дані не будуть коректні)
	}
	ClearCin();			// Очищаємо буфер
	// В залежності від рандому (який гравець ходить першим і яким символом) то завдяки наступній перевірці ми ставимо відповіний знак (Х або О)
	if (number == 1 && symb == X)	// Якщо Гравець 1 і Х то ставить Х
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

	return '-'; // Якщо немає виграшних комбінацій повертає "-", остання перевірка поверну НІЧИЮ 
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
	do						// Для коректності вводу 
	{
		cout << "Do you want X ? (y/n): ";
		cin >> response;
		ClearCin();
	} while (response != 'y' && response != 'n');
	return response;
}

char FirstMove()
{
	cout << playerName1 << ". ";	// Запитую першого гравця за варіант Х чи О
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
		int randCompNumber = rand() % 9 + 1; // від 1 до 9 рандомне числа

		if (!(cells[randCompNumber - 1] == O || cells[randCompNumber - 1] == X))
			return cells[randCompNumber - 1] = symb;
	}
}

char ChechBlock(char symb)		// для перевірк можливого блоку (якщо 2 опоненти в один ряд і можливий блок то робимо блок)(аналогічно з іншими)
{
	char tempSymb = OpponentFunction(symb); // символ для опонента (для порівняння і знаходження)

	if ((((cells[0] == cells[1]) && cells[1] == tempSymb) || ((cells[8] == cells[5]) && cells[5] == tempSymb)
		|| ((cells[6] == cells[4]) && cells[4] == tempSymb)) && cells[2] == win)	// (0=1 i 1=(оберненому символу) / 8=5 і 5=(оберненому символу) / 6=4 і 4=(оберненому символу)) i порожня клітинка
		return cells[2] = symb;

	if ((((cells[2] == cells[5]) && cells[5] == tempSymb) || ((cells[6] == cells[7]) && cells[7] == tempSymb)
		|| ((cells[0] == cells[4]) && cells[4] == tempSymb)) && cells[8] == win)	// (2=5 i 5=(оберненому символу) / 6=7 i 7=(оберненому символу) / 0=4 i 4=(оберненому символу)) i порожня клітинка
		return cells[8] = symb;

	if ((((cells[1] == cells[2]) && cells[2] == tempSymb) || ((cells[3] == cells[6]) && cells[6] == tempSymb)
		|| ((cells[4] == cells[8]) && cells[8] == tempSymb)) && cells[0] == win)	// (1=2 i 2=(оберненому символу) / 3=6 i 6=(оберненому символу) / 4=8 i 8=(оберненому символу)) i порожня клітинка
		return cells[0] = symb;

	if ((((cells[0] == cells[3]) && cells[3] == tempSymb) || ((cells[2] == cells[4]) && cells[4] == tempSymb)
		|| ((cells[7] == cells[8]) && cells[8] == tempSymb)) && cells[6] == win)	// (0=3 i 3=(оберненому символу) / 2=4 i 4=(оберненому символу) / 7=8 i 8=(оберненому символу)) i порожня клітинка
		return cells[6] = symb;

	if ((((cells[1] == cells[4]) && cells[4] == tempSymb) || ((cells[6] == cells[8]) && cells[8] == tempSymb)) && cells[7] == win)	// (1=4 i 4=(оберненому символу) / 6=8 i 8=(оберненому символу) i порожня клітинка
		return cells[7] = symb;

	if ((((cells[0] == cells[2]) && cells[2] == tempSymb) || ((cells[4] == cells[7]) && cells[7] == tempSymb)) && cells[1] == win)	// (0=2 i 2=(оберненому символу) / 4=7 i 7=(оберненому символу) i порожня клітинка
		return cells[1] = symb;

	if ((((cells[4] == cells[5]) && cells[5] == tempSymb) || ((cells[0] == cells[6]) && cells[6] == tempSymb)) && cells[3] == win)	// (4=5 i 5=(оберненому символу) / 0=6 i 6=(оберненому символу) i порожня клітинка
		return cells[3] = symb;

	if ((((cells[2] == cells[8]) && cells[8] == tempSymb) || ((cells[3] == cells[4]) && cells[4] == tempSymb)) && cells[5] == win)	// (2=8 i 8=(оберненому символу) / 3=4 i 4=(оберненому символу) i порожня клітинка
		return cells[5] = symb;

	if ((((cells[2] == cells[6]) && cells[6] == tempSymb) || ((cells[0] == cells[8]) && cells[8] == tempSymb) ||
		((cells[1] == cells[7]) && cells[7] == tempSymb) || ((cells[3] == cells[5]) && cells[5] == tempSymb)) && cells[4] == win)	// (2=6 i 6=(оберненому символу) / 0=8 i 8=(оберненому символу) i порожня клітинка / 1=7 i 7=(оберненому символу) i порожня клітинка / 3=5 i 5=(оберненому символу) i порожня клітинка
		return cells[4] = symb;

	return 0;
}

char CheckGoodChoise(char symb)   // можна розглянути як блок протилежного знака не тільки хороший хід // не використовувати для блоку бо тут спрацює пріорітет по рядково	 
{
	if (((cells[0] == cells[3] && cells[3] == symb) || (cells[7] == cells[8] && cells[8] == symb)
		|| (cells[2] == cells[4] && cells[4] == symb)) && cells[6] == win) // якщо 0=3 або 7=8 або 2=4 і 6 порожня то в 6 запишеться символ
		return cells[6] = symb;

	if (((cells[0] == cells[1] && cells[1] == symb) || (cells[8] == cells[5] && cells[5] == symb)
		|| (cells[6] == cells[4] && cells[4] == symb)) && cells[2] == win) // якщо 0=1 або 8=5 або 6=4 і 2 порожня то в 2 запишеться символ
		return cells[2] = symb;

	if (((cells[3] == cells[6] && cells[6] == symb) || (cells[1] == cells[2] && cells[2] == symb)
		|| (cells[4] == cells[8] && cells[8] == symb)) && cells[0] == win) // якщо 3=6 або 1=2 або 4=8 і 0 порожня то в 0 запишеться символ
		return cells[0] = symb;

	if (((cells[2] == cells[5] && cells[5] == symb) || (cells[6] == cells[7] && cells[7] == symb)
		|| (cells[0] == cells[4] && cells[4] == symb)) && cells[8] == win) // якщо 2=5 або 6=7 або 0=4 і 8 порожня то в 8 запишеться символ
		return cells[8] = symb;

	if (((cells[0] == cells[6] && cells[6] == symb) || (cells[4] == cells[5] && cells[5] == symb)) && cells[3] == win) // якщо 0=6 або 4=5 і 3 порожня то в 3 запишеться символ
		return cells[3] = symb;

	if (((cells[6] == cells[8] && cells[8] == symb) || (cells[1] == cells[4] && cells[4] == symb)) && cells[7] == win) // якщо 6=8 або 1=4 і 7 порожня то в 7 запишеться символ
		return cells[7] = symb;

	if (((cells[2] == cells[8] && cells[8] == symb) || (cells[3] == cells[4] && cells[4] == symb)) && cells[5] == win) // якщо 2=8 або 3=4 і 5 порожня то в 5 запишеться символ
		return cells[5] = symb;

	if (((cells[0] == cells[2] && cells[2] == symb) || (cells[4] == cells[7] && cells[7] == symb)) && cells[1] == win) // якщо 0=2 або 4=7 і 1 порожня то в 1 запишеться символ
		return cells[1] = symb;

	return 0;
}

char ChecDiagonalMove(char symb)
{
	char tempSymb = OpponentFunction(symb);  // Для позначення опонента

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
	char tempSymb = OpponentFunction(computer);							// Змінна отримує символ противника

	// КОМП'ЮТЕР ходи 1 - 3 - 5 - 7 - 9  ----- КОМП'ЮТЕР ходить першим
	// КОМП'ЮТЕР ходи 2 - 4 - 6 - 8		 ----- КОМП'ЮТЕР ходить другим

	/////////////// 1 хід ///////////////////
	if (move == 1 || move == 2)											// Якщо перший хід - то в середину, якщо 2 і вільна середина то в середину. Якщо 3 хід і середина зайнята то в 1 [0] 
	{
		cells[4] == win ? cells[4] = computer : cells[0] = computer;	// Якщо вільна середина 5 або [4] то записуємо знак КОМП'ЮТЕРА											
		return;															// Якщо середина 5 або [4] зайнята то ставимо знак комп'ютера в діагональ
	}

	//////////////// 2 хід /////////////////
	switch (move)
	{
	case 3:																// Хід 3 це якщо КОМП'ЮТЕР ходить першим
		if (tempSymb == cells[0] || tempSymb == cells[8]) cells[2] = computer;
		else if (tempSymb == cells[2] || tempSymb == cells[6]) cells[0] = computer;
		else if (tempSymb == cells[1] || tempSymb == cells[5]) cells[6] = computer;
		else if (tempSymb == cells[3] || tempSymb == cells[7]) cells[2] = computer;
		return;
	case 4:																// Хід 4, якщо КОМП'ЮТЕР ходить другим тобто Х О Х (і наступний O)
		if (!ChechBlock(computer))										// Блокуємо можливу виграшнку комбінація (ПРОТИВНИКА) 
		{
			if (cells[4] == tempSymb)
			{
				cells[2] = computer;									// Якщо не спрацює БЛОК то записати в 3 [2] діагональ
				return;
			}

			if (!ChecDiagonalMove(computer))							// СПЕЦИФІЧНИЙ ХІД
				if (!CheckAlternativeMove(computer))					// СПЕЦИФІЧНИЙ ХІД
				{														// ЗДАЄТЬСЯ ходи 1 - 9 [0] - [8] або 3 - 7 [2] - [6] або 2 - 8 [1] - [7] або 4 - 6 [3] - [5] 
					if ((cells[0] == win) && ((cells[2] == cells[6]) && cells[6] != win))
						cells[1] = computer;
					else if (cells[0] != win)
						cells[1] = computer;
					else
						cells[0] = computer;							// ЖОДНА УМОВА НЕ СПРАЦЮЄ то записуюмо в 1 [0]
				}
		}
		return;
		//////////////// 3 хід /////////////////
	case 5:																// Хід 5 це якщо КОМП'ЮТЕР ходить першим
		if (!CheckGoodChoise(computer))									// Перевірка на можливий виграш
			ChechBlock(computer);										// Блокуємо можливу виграшнку комбінація (ПРОТИВНИКА) 
		return;
	case 6:																// Хід 6, якщо КОМП'ЮТЕР ходить другим тобто Х О Х O X (і наступний O)
		if (!CheckGoodChoise(computer))									// Перевірка на можливий виграш
			if (!ChechBlock(computer))									// Блокуємо можливу виграшнку комбінація (ПРОТИВНИКА) 
				(cells[3] == cells[6]) && cells[0] == computer ? cells[6] = computer : cells[2] = computer; // при певній умові цей варіант не підходить, можливий 100 % виграш
		return;
		//////////////// 4 хід /////////////////
	case 7:																// Хід 7 це якщо КОМП'ЮТЕР ходить першим
		if (!CheckGoodChoise(computer))									// Перевірка на можливий виграш // якщо числа 2 4 6 8 в першому ході то тут вже виграш
			cells[1] == win ? cells[1] = computer : cells[3] = computer;// можна ходити 2 або 4 ((можна і рандом) але є можливість виграти)
		return;
	case 8:																// Хід 8, якщо КОМП'ЮТЕР ходить другим тобто Х О Х O X O X (і наступний O)
		if (!CheckGoodChoise(computer))									// Перевірка на можливий виграш
			if (!ChechBlock(computer))									// Блокуємо можливу виграшнку комбінація (ПРОТИВНИКА) 
				ComputerMove(computer);									// Рандом // або можна просто прорахувати 2 можливі ходи щоб цикл не спрацьовував зайві рази
		return;
		//////////////// 5 хід /////////////////
	case 9:																// Хід 9 це якщо КОМП'ЮТЕР ходить першим
		if (!CheckGoodChoise(computer))									// Перевірка на можливий виграш
			ComputerMove(computer);										// Якщо вже немає варіантів то просто рандомний хід
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