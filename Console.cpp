// console.h : This file contains the functions for Console UI.
//

#include "console.h"
#include "Header.h"
#include "StringConv.h"

#include <iostream>
#include <vector>
#include <cwchar>
#include <fstream>
#include <string>
#include <unordered_set>

using namespace std;

///Matrix of Language Values. Remember Arrays go across and then down.
const vector<const wstring> Language = 
{
	L"Arabic",
	L"Bulgarian",
	L"Chinese",
	L"English",
	L"Fillipino",
	L"French",
	L"German",
	L"Greek",
	L"Hindi",
	L"Italian",
	L"Japanese",
	L"Korean",
	L"Persian",
	L"Russian",
	L"Thai",
	L"Turkish",
	L"Vietnamese"
};

void PrintLanguageSelection()
{
	wcout << "Select a Language from the following options:" << endl;
	for (size_t i = 1; i <= Language.size(); i++)
	{
		wcout << i << ". " << Language.data() << endl;
	}
}

uint16_t InputLanguageChoice(wchar_t userChoice)
{
	bool test = false;

	do
	{
		wcin >> userChoice;

		if (!iswdigit(userChoice) || userChoice < 1)
		{
			wcout << "Enter a single number between " << 1 << " and " << Language.size() << "." << endl;
		}
		else
		{
			return (uint16_t)userChoice;
		}
	} while (test != true);
}

unordered_set<wstring, wstring> GetLanguageData(uint16_t userChoice)
{
	wstring langChoice = Language.at(userChoice);
	fstream file = OpenFile(langChoice);

	//Collect Data.
	const wstring data;
	file.read(StringToWchar(data), file.gcount());

	//Map Menu Options to Object.
	//Search for menu objects and assign.
	//Pass out.
	
}

bool MatchLanguage(wstring input)
{
	for (auto i : Language)
	{
		if (i.data == input)
		{
			return true;
		}
	}
	wcout << "Input does not match Language file names." << endl;
	return false;
}

wstring MakeFileName(wstring userChoice)
{
	return userChoice.append(L".txt");
}

fstream OpenFile(wstring fileName)
{
	fstream file;
	uint16_t i = 0;

	do
	{
		file.open(MakeFileName(fileName), fstream::in);
		if (!file.is_open())
		{
			wcout << "Language File not found. Enter a filename the same as listed in options." << endl;
			do
			{
				wcin >> fileName;
			} while (!MatchLanguage(fileName));
		}
		else if( i == 3)
		{
			throw exception("Create a language file. It is missing.");
		}
	} while (!file.is_open() || i < 3);
	return file;
}






