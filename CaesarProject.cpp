#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <fstream>
#include "Methods.h"
#include "conio.h"
#include <chrono>
#include <thread>



using namespace std;

int main()
{
	Methods methods;

	int Input; 

	while (true)
	{
		
		cout << "" << endl;
		cout << "Caesar Cipher Encoder/Decoder" << endl;
		cout << "" << endl;
		cout << "-----------------------------" << endl;
		cout << "" << endl;
		cout << " 1. Encode" << endl;
		cout << " 2. Decode" << endl;
		cout << " 3. List History" << endl;
		cout << " 4. Exit" << endl;
		cout << "" << endl;
		cout << "-----------------------------" << endl;
		cout << "" << endl;
		cout << "Enter your choice: " << endl;

		Input = _getch();

		switch (Input)
		{
			case 49:
				cout << "Entered Option 1: Encode" << endl;
				this_thread::sleep_for(chrono::seconds(5));
				methods.Encode();
				break;

			case 50:
				cout << "Entered Option 2: Decode" << endl;
				this_thread::sleep_for(chrono::seconds(5));
				methods.Decode();
				break;

			case 51:
				cout << "Entered Option 3: List the history" << endl;
				this_thread::sleep_for(chrono::seconds(5));
				methods.ListHistory();
				break;

			case 52:
				cout << "Entered Option 4: Exting" << endl;
				this_thread::sleep_for(chrono::seconds(5));
				return 0;
				break;
			default:
				cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
				this_thread::sleep_for(chrono::seconds(5));
				break;
		}
		

	}
	
	
	





}
