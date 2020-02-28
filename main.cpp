// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "main.h"

using namespace std;

int main(const int argc, const wchar_t * const * const argv)
{
	try
	{
		wcout << "Hello World!\n";
	}
	catch (const exception e)
	{
		wcerr << "Error: " << e.what() << endl;
	}

}