#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <fstream>

using namespace std;

class Methods
{
public:
	void Encode(string Input, int Shift)
	{
		char Alphabet[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

		while (true)
		{
			try
			{
				string EncodedText = "";
				cout << "\033[2J\033[1;1H";
				cout << "Enter the text you want to encode: " << endl;
				cout << "Note: Only uppercase letters will be encoded. Spaces and other characters will be ignored." << endl;
				cout << "Input: ";
				getline(cin, Input);
				cout << "" << endl;
				if (Input.empty())
				{
					throw invalid_argument("Input cannot be empty. Please enter a valid word/phrase.");
				}
				else if (Input.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz ") != string::npos)
				{
					throw invalid_argument("Invalid input. Please enter only letters and spaces.");
				}
				cout << "Enter the shift value (up to 24): " << endl;
				cout << "Note: 0 is 1, 1 is 2, ..., 24 is 25." << endl;
				cout << "Shift: ";
				cin >> Shift;
				cin.ignore();
				if (Shift > 24 || Shift < 0)
				{
					throw invalid_argument("Invalid shift value. Please enter a number up to 24.");
				}

				for (char c : Input)
				{
					if (isalpha(c))
					{
						char UpperC = toupper(c);
						int Index = UpperC - 'A';
						int ShiftedIndex = (Index + Shift) % 26;
						EncodedText += Alphabet[ShiftedIndex];
					}
					else
					{
						EncodedText += c;
					}
				}
				break;

				cout << "Encoded Text: " << EncodedText << endl;
				ofstream HistoryFile("History.txt", ios::app);
				HistoryFile << "Encoded: " << Input << " with shift " << Shift << " -> " << EncodedText << endl;
				HistoryFile << "-----------------------------" << endl;


			}
			catch (const exception& e)
			{
				cerr << "something has went wrong." << endl;
				cout << "\033[2J\033[1;1H";
				continue;
			}
			break;

		}

	}

};
