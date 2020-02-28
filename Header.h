// Header.h : This file contains the libaries and prototypes for Header.cpp
//

#pragma once


class Header
{
public:
	///Returns an MenuHeader Object from a Private Constructor.
	static Header DrawHeader(const wstring* _title, const wstring* _statement, const wstring* _author, const wstring* _licence);

private:
	wstring title;
	wstring statement;
	wstring author;
	wstring licence;
	wchar_t side = '-';
	wchar_t fill = ' ';
	int width = 100;
	int halfwidth = width / 2;

	///Assigns to Private Values. In case of Change Later or Redraw.
	void AssignHeaderValues(const wstring* _title, const wstring* _statement, const wstring* _author, const wstring* _licence);

	///Draws Border for Header.
	void DrawTopOrBottom();

	///Draws Menu Text on Centre.
	void DrawString(const wstring* _text);

	///Constructor that builds header object and draws it.
	Header(const wstring* _title, const wstring* _statement, const wstring* _author, const wstring* _licence);
};



