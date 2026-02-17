#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <fstream>
#include <cctype>

using namespace std;

class Methods
{
public:
	void Encode()
	{
		const string Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

		while (true)
		{
			try
			{
				string Input;
				int Shift = 0;
				string EncodedText;

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
				if (!(cin >> Shift))
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw invalid_argument("Shift must be a number.");
				}
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				if (Shift > 24 || Shift < 0)
				{
					throw invalid_argument("Invalid shift value. Please enter a number up to 24.");
				}

				for (char c : Input)
				{
					if (isalpha(static_cast<unsigned char>(c)))
					{
						char UpperC = static_cast<char>(toupper(static_cast<unsigned char>(c)));
						int Index = UpperC - 'A';
						int ShiftedIndex = (Index + Shift) % 26;
						EncodedText += Alphabet[ShiftedIndex];
					}
					else
					{
						EncodedText += c;
					}
				}

				cout << "Encoded Text: " << EncodedText << endl;
				cout << "-----------------------------" << endl;
				ofstream HistoryFile("History.txt", ios::app);
				if (HistoryFile.is_open())
				{
					HistoryFile << "Encoded: " << Input << " with shift " << Shift << " -> " << EncodedText << endl;
					HistoryFile << "-----------------------------" << endl;
					HistoryFile.close();
				}


				break;
			}
			catch (const exception& e)
			{
				cerr << "Errore: " << e.what() << endl;
				cout << "\033[2J\033[1;1H";

				continue;
			}
			
		}
	}

	void Decode()
	{
		const string Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		while (true)
		{
			try
			{
				string Input;
				int Shift = 0;
				string DecodedText;
				cout << "\033[2J\033[1;1H";
				cout << "Enter the text you want to decode: " << endl;
				cout << "Note: Only uppercase letters will be decoded. Spaces and other characters will be ignored." << endl;
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
				if (!(cin >> Shift))
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					throw invalid_argument("Shift must be a number.");
				}
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				if (Shift > 24 || Shift < 0)
				{
					throw invalid_argument("Invalid shift value. Please enter a number up to 24.");
				}
				for (char c : Input)
				{
					if (isalpha(static_cast<unsigned char>(c)))
					{
						char UpperC = static_cast<char>(toupper(static_cast<unsigned char>(c)));
						int Index = UpperC - 'A';
						int ShiftedIndex = (Index - Shift + 26) % 26;
						DecodedText += Alphabet[ShiftedIndex];
					}
					else
					{
						DecodedText += c;
					}
				}
				cout << "Decoded Text: " << DecodedText << endl;
				cout << "-----------------------------" << endl;
				ofstream HistoryFile("History.txt", ios::app);
				if (HistoryFile.is_open())
				{
					HistoryFile << "Decoded: " << Input << " with shift " << Shift << "-> " << DecodedText << endl;
					HistoryFile << "-----------------------------" << endl;
					HistoryFile.close();
				}
				break;

			}
			catch (const exception& e)
			{
				cerr << "Errore: " << e.what() << endl;
				cout << "\033[2J\033[1;1H";

				continue;
			}
			
		}
	}

	void ListHistory()
	{
		ifstream HistoryFile("History.txt");
		if (HistoryFile.is_open())
		{
			string Line;
			cout << "\033[2J\033[1;1H";
			cout << "History of Encodings and Decodings:" << endl;
			cout << "-----------------------------------" << endl;
			while (getline(HistoryFile, Line))
			{
				cout << Line << endl;
			}
			HistoryFile.close();
			
		}
		else
		{
			cerr << "Unable to open history file." << endl;
		}
	}
};
