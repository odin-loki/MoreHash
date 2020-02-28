// Header.cpp : This file contains the functions to draw Console Header UI
//

#include "Header.h"

#include <iostream>

using namespace std;

///Returns an MenuHeader Object from a Private Constructor.
Header Header::DrawHeader(const wstring* _title, const wstring* _statement, const wstring* _author, const wstring* _licence)
{
	return Header(_title, _statement, _author, _licence);
}

///Assigns to Private Values. In case of Change Later or Redraw.
void Header::AssignHeaderValues(const wstring* _title, const wstring* _statement, const wstring* _author, const wstring* _licence)
{
	title = *_title;
	statement = *_statement;
	author = *_author;
	licence = *_licence;
}

///Draws Border for Header.
void Header::DrawTopOrBottom()
{
	for (size_t i = 0; i < width; i++)
	{
		wcout << side;
	}
	wcout << endl;
}

///Draws Menu Text on Centre.
void Header::DrawString(const wstring* _text)
{
	int txtLength = (int)_text->begin.length();
	int offSetToDrawTextCentre = halfwidth - txtLength / 2;
	int drawlength = width - txtLength;

	for (size_t i = 0; i <= drawlength; i++)
	{
		if (i == 0 || i == drawlength)
		{
			wcout << side;
		}
		else if (i == offSetToDrawTextCentre)
		{
			wcout << *_text;
		}
		else
		{
			wcout << fill;
		}
	}
	wcout << endl;
}

///Constructor that builds header object and draws it.
Header::Header(const wstring* _title, const wstring* _statement, const wstring* _author, const wstring* _licence)
{
	AssignHeaderValues(_title, _statement, _author, _licence);
	DrawTopOrBottom();
	DrawString(_title);
	DrawString(_statement);
	DrawString(_author);
	DrawString(_licence);
	DrawTopOrBottom();
}