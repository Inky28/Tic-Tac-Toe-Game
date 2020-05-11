#pragma once

void ShowOpponent(int tempOpponent);
void ShowRank(int tempComplexity);
void ClearCin();							// Գ����� Cin (����� �����)
void ShowLogo();							// �������� �������
void ShowTextMenu();						// ��� ������ ������ ����
void ShowCells();							// ��� ������ �������� ����
void MakeMove(int number, char symb);		// ��� ���� ����ֲ� 
void ShowResult();							// ������ ���������
void HardMode(char computer, int move);		// ����������� ���������
bool CheckMenu();							// ��� ���� (�� ��������)
char AskYesNo();							// ��� �������
char FirstMove();							// ������� �� � �� �
char OpponentFunction(char symbol);			// ������� ��������� ���� (���� ��������)
char CheckWinCombination();					// ��� �������� ��������� ���������
char ComputerMove(char symb);				// ճ� ����'����� (���������)
char ChechBlock(char symb);					// ��� �������� ��������� ����� (���� 2 �������� � ���� ��� � �������� ���� �� ������ ����)(��������� � ������)
char CheckGoodChoise(char symb);			// ��� �������� �� ��������� (���������) ���
char ChecDiagonalMove(char symb);			// ��� �������� �� ����������� ��� (�����Բ���� �������)
char CheckAlternativeMove(char symb);		// ��� �������� ����������� ���� (�����Բ���� �������)
void EnterNamePlayer(char playerName1[], char playerName2[]); // ������� ��'� ������