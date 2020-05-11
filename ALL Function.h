#pragma once

void ShowOpponent(int tempOpponent);
void ShowRank(int tempComplexity);
void ClearCin();							// Фіксить Cin (очищає буфер)
void ShowLogo();							// Показати логотим
void ShowTextMenu();						// Для показу тексту меню
void ShowCells();							// Для показу ігрового поля
void MakeMove(int number, char symb);		// Для ходу ГРАВЦІВ 
void ShowResult();							// Показує переможця
void HardMode(char computer, int move);		// Максимальна складність
bool CheckMenu();							// Для меню (не важливий)
char AskYesNo();							// Даю відповідь
char FirstMove();							// Запитую чи Х чи О
char OpponentFunction(char symbol);			// Повертає обернений знак (знак ОПОНЕНТА)
char CheckWinCombination();					// Для перевірки виграшних комбінацій
char ComputerMove(char symb);				// Хід комп'ютера (РАНДОМНИЙ)
char ChechBlock(char symb);					// Для перевірки можливого блоку (якщо 2 опоненти в один ряд і можливий блок то робимо блок)(аналогічно з іншими)
char CheckGoodChoise(char symb);			// Для перевірки на найкращий (ВИГРАШНИЙ) хід
char ChecDiagonalMove(char symb);			// Для перевірки на діагональний хід (СПЕЦИФІЧНИЙ ВИПАДОК)
char CheckAlternativeMove(char symb);		// Для перевірки правильності ходу (СПЕЦИФІЧНИЙ ВИПАДОК)
void EnterNamePlayer(char playerName1[], char playerName2[]); // Вводимо ім'я ГРАВЦЯ