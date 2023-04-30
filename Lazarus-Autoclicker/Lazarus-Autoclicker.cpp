#include <iostream>
#include <Windows.h>
#include<conio.h>
#include<stdio.h>
#include<string>

HANDLE hConsole;

enum ColorConsole {
	Black = 0,
	Blue = 1,
	Green = 2,
	Cayan = 3,
	Red = 4,
	Magenta = 5,
	lightGray = 7,
	White = 15,
	Yellow = 14,
	LightRed = 12,
};

std::string key;

// Set default state to false
bool bState = false;

bool bStateZ = false;

bool isBeta = true;

std::string mouseButton = "";

int autoclickerType = 1;

void menu(bool bState)
{
	// Clears and prints to the console
	system("cls");

	std::cout << "Silver Bullet Lazarus autoclicker v1.0\n";
	std::cout << "-------------------------------------- \n";

	if (bState)
	{
		SetConsoleTextAttribute(hConsole, Green);
		std::cout << "Status: ON\n";
		SetConsoleTextAttribute(hConsole, White);
	}
	else
	{
		SetConsoleTextAttribute(hConsole, Red);
		std::cout << "Status: OFF\n";
		SetConsoleTextAttribute(hConsole, White);
	}



	if (autoclickerType == 3)
	{
		if (bStateZ)
		{
			SetConsoleTextAttribute(hConsole, Green);
			std::cout << "Status: ON\n";
			SetConsoleTextAttribute(hConsole, White);
		}
		else
		{
			SetConsoleTextAttribute(hConsole, Red);
			std::cout << "Status: OFF\n";
			SetConsoleTextAttribute(hConsole, White);
		}
	}

}

int main()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTitleA("Autoclicker by Silver Bullet || V1.0 {beta}");

	if (isBeta == true)
	{
		std::cout << "Lazarus Autoclicker is in beta version" << std::endl;
	}
	else
	{
		std::cout << "Lazarus Autoclicker is in release version" << std::endl;
	}


	Sleep(3000);

menu:

	system("color B");

	system("cls");
	std::cout << "Chouse option of autoclicker type:\n";
	std::cout << "1 PvP \n";
	std::cout << "2 Build \n";
	std::cout << "3 Mixed(Z/X)\n";

	SetConsoleTextAttribute(hConsole, White);

	std::cin >> autoclickerType;

	switch (autoclickerType)
	{
	case 1:
		menu(bState);
		while (true)
		{
			// Check if 'X' is pressed
			if (GetAsyncKeyState(0x58) & 1)
			{
				// Switch bState value
				bState = !bState;
				// Print menu to console
				menu(bState);
			}
			if (bState)
			{
				// Simulate mouse click
				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			}
			Sleep(5);
		}
		break;
	case 2:
		menu(bState);
		while (true)
		{
			// Check if 'X' is pressed
			if (GetAsyncKeyState(0x58) & 1)
			{
				// Switch bState value
				bState = !bState;
				// Print menu to console
				menu(bState);
			}
			if (bState)
			{
				// Simulate mouse click
				mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
			}
			Sleep(5);
		}
		break;
	case 3:
		menu(bState);
		while (true)
		{
			if (GetAsyncKeyState(0x58) & 1)
			{
				bState = !bState;
				menu(bState);
			}
			if (GetAsyncKeyState(0x5A) & 1)
			{
				bStateZ = !bStateZ;
				menu(bState);
			}
			if (bState)
			{
				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			}
			if (bStateZ)
			{
				mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
			}
			Sleep(10);
		}
		break;
	default:
		std::cout << "not existing option \n";
		Sleep(1000);
		system("cls");
		goto menu;
		break;
	}
}