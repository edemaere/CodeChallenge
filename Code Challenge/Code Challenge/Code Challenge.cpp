#include <iostream>
#include <string>
using namespace std;

int main()
{
	// menu navigation 
	const int menu_option1 = 1;
	const int menu_option2 = 2;
	const int menu_option3 = 3;
	int menuNum = 0;

	// decimal number variables
	int decimalInput = 0;
	int decimalOutput = 0;

	// numerals/subtractive pairs and their values 
	const int M = 1000;
	const int D = 500;
	const int C = 100;
	const int L = 50;
	const int X = 10;
	const int V = 5;
	const int I = 1;
	const int iv = 4;
	const int ix = 9;
	const int xl = 40;
	const int xc = 90;
	const int cd = 400;
	const int cm = 900;

	// keeps track of how many times a certain numeral appears
	int mCount = 0;
	int dCount = 0;
	int cCount = 0;
	int lCount = 0;
	int xCount = 0;
	int vCount = 0;
	int iCount = 0;

	// determines whether a certain numeral can appear in the current calculation
	bool mFinished = false;
	bool dFinished = false;
	bool cFinished = false;
	bool lFinished = false;
	bool xFinished = false;
	bool vFinished = false;

	// string variables
	string IV = "IV";
	string IX = "IX";
	string XL = "XL";
	string XC = "XC";
	string CD = "CD";
	string CM = "CM";
	string numeralInput;
	string numeralOutput;

	cout << "Welcome to the Roman Numeral Converter! Options:" << endl;
	cout << " 1 - Convert a roman numeral" << endl;
	cout << " 2 - Convert a decimal number" << endl;
	cout << " 3 - Quit the program" << endl;
	cout << "Please select an option: ";
	cin >> menuNum;
	cout << endl;

	while (menuNum != menu_option3)
	{
		while (menuNum == menu_option1) // convert roman numerals to decimal number
		{
			cout << "Please enter a valid roman numeral or type 'EXIT' to return to the menu: ";
			cin >> numeralInput;
			cout << endl;
			if (numeralInput == "EXIT")
			{
				break;
			}
			cout << "You entered: " << numeralInput << endl;

			// This section removes subtractive numeral pairs from the input (IV or IX, XL or XC, CD or CM) and adds their value to decimalOutput
			// Checks for incorrect ordering of subtractive pairs (e.g. IV can't come after I, XL can't come before X, etc.)
			// IV and IX can't both exist in the same numeral. Same with XL and XC, CD and CM
			if (numeralInput.find(IV) != string::npos) // Looks for the 'IV' pair
			{
				if (numeralInput.size() - 2 > 0) // results in true if the pair ('IV') isn't the only numeral entered
				{
					if (numeralInput.find(IV) > 0) // results in true if the pair ('IV') isn't the first numeral
					{
						if ((numeralInput[numeralInput.find(IV) - 1] == 'I') || (numeralInput[numeralInput.find(IV) - 1] == 'V')) // checks the numeral before the pair
						{
							cout << "Invalid numeral ('IV' cannot come after 'I' or 'V')" << endl;
						}
						else // The pair ordering is valid; it will be erased from the string and the value will be added to decimalOutput
						{
							numeralInput.erase(numeralInput.find(IV), 2);
							decimalOutput = decimalOutput + iv;
						}
					}
					else
					{
						cout << "Invalid numeral ('IV' cannot be followed by any numeral)" << endl;
					}
				}
				else // The pair is the only numeral entered; it will be erased from the string and the value will be added to decimalOutput
				{
					numeralInput.erase(numeralInput.find(IV), 2);
					decimalOutput = decimalOutput + iv;
				}
			}
			else if (numeralInput.find(IX) != string::npos) // Looks for the 'IX' pair
			{
				if (numeralInput.size() - 2 > 0)
				{
					if (numeralInput.find(IX) > 0)
					{
						if ((numeralInput[numeralInput.find(IX) - 1] == 'I') || (numeralInput[numeralInput.find(IX) - 1] == 'V'))
						{
							cout << "Invalid numeral ('IX' cannot come after 'I' or 'V')" << endl;
						}
						else
						{
							numeralInput.erase(numeralInput.find(IX), 2);
							decimalOutput = decimalOutput + ix;
						}
					}
					else
					{
						cout << "Invalid numeral ('IX' cannot be followed by any numeral)" << endl;
					}
				}
				else
				{
					numeralInput.erase(numeralInput.find(IX), 2);
					decimalOutput = decimalOutput + ix;
				}
			}

			if (numeralInput.find(XL) != string::npos) // Looks for the 'XL' pair
			{
				if (numeralInput.size() - 2 > 0)
				{
					if (numeralInput.find(XL) > 0)
					{
						if ((numeralInput[numeralInput.find(XL) - 1] == 'I') || (numeralInput[numeralInput.find(XL) - 1] == 'V') ||
							(numeralInput[numeralInput.find(XL) - 1] == 'X') || (numeralInput[numeralInput.find(XL) - 1] == 'L'))
						{
							cout << "Invalid numeral ('XL' cannot come after 'I', 'V', 'X', or 'L')" << endl;
						}
						else
						{
							numeralInput.erase(numeralInput.find(XL), 2);
							decimalOutput = decimalOutput + xl;
						}
					}
					else
					{
						if ((numeralInput[numeralInput.find(XL) + 2] == 'M') || (numeralInput[numeralInput.find(XL) + 2] == 'D') ||
							(numeralInput[numeralInput.find(XL) + 2] == 'C') || (numeralInput[numeralInput.find(XL) + 2] == 'L') ||
							(numeralInput[numeralInput.find(XL) + 2] == 'X')) // checks the numeral after the pair
						{
							cout << "Invalid numeral ('XL' cannot be followed by 'X', 'L', 'C', 'D', or 'M')" << endl;
						}
						else
						{
							numeralInput.erase(numeralInput.find(XL), 2);
							decimalOutput = decimalOutput + xl;
						}
					}
				}
				else
				{
					numeralInput.erase(numeralInput.find(XL), 2);
					decimalOutput = decimalOutput + xl;
				}
			}
			else if (numeralInput.find(XC) != string::npos) // Looks for the 'XC' pair
			{
				if (numeralInput.size() - 2 > 0)
				{
					if (numeralInput.find(XC) > 0)
					{
						if ((numeralInput[numeralInput.find(XC) - 1] == 'I') || (numeralInput[numeralInput.find(XC) - 1] == 'V') ||
							(numeralInput[numeralInput.find(XC) - 1] == 'X') || (numeralInput[numeralInput.find(XC) - 1] == 'L'))
						{
							cout << "Invalid numeral ('XC' cannot come after 'I', 'V', 'X', or 'L')" << endl;
						}
						else
						{
							numeralInput.erase(numeralInput.find(XC), 2);
							decimalOutput = decimalOutput + xc;
						}
					}
					else
					{
						if ((numeralInput[numeralInput.find(XC) + 2] == 'M') || (numeralInput[numeralInput.find(XC) + 2] == 'D') ||
							(numeralInput[numeralInput.find(XC) + 2] == 'C') || (numeralInput[numeralInput.find(XC) + 2] == 'L') ||
							(numeralInput[numeralInput.find(XC) + 2] == 'X'))
						{
							cout << "Invalid numeral ('XC' cannot be followed by 'X', 'L', 'C', 'D', or 'M')" << endl;
						}
						else
						{
							numeralInput.erase(numeralInput.find(XC), 2);
							decimalOutput = decimalOutput + xc;
						}
					}
				}
				else
				{
					numeralInput.erase(numeralInput.find(XC), 2);
					decimalOutput = decimalOutput + xc;
				}
			}


			if (numeralInput.find(CD) != string::npos) // Looks for the 'CD' pair
			{
				if (numeralInput.size() - 2 > 0)
				{
					if (numeralInput.find(CD) > 0)
					{
						if ((numeralInput[numeralInput.find(CD) - 1] == 'I') || (numeralInput[numeralInput.find(CD) - 1] == 'V') ||
							(numeralInput[numeralInput.find(CD) - 1] == 'X') || (numeralInput[numeralInput.find(CD) - 1] == 'L') ||
							(numeralInput[numeralInput.find(CD) - 1] == 'C') || (numeralInput[numeralInput.find(CD) - 1] == 'D'))
						{
							cout << "Invalid numeral ('CD' cannot come after 'I', 'V', 'X', 'L', 'C', or 'D')" << endl;
						}
						else
						{
							numeralInput.erase(numeralInput.find(CD), 2);
							decimalOutput = decimalOutput + cd;
						}
					}
					else
					{
						if ((numeralInput[numeralInput.find(CD) + 2] == 'M') || (numeralInput[numeralInput.find(CD) + 2] == 'D') ||
							(numeralInput[numeralInput.find(CD) + 2] == 'C'))
						{
							cout << "Invalid numeral ('CD' cannot be followed by 'C', 'D', or 'M')" << endl;
						}
						else
						{
							numeralInput.erase(numeralInput.find(CD), 2);
							decimalOutput = decimalOutput + cd;
						}
					}
				}
				else
				{
					numeralInput.erase(numeralInput.find(CD), 2);
					decimalOutput = decimalOutput + cd;
				}
			}
			else if (numeralInput.find(CM) != string::npos) // Looks for the 'CM' pair
			{
				if (numeralInput.size() - 2 > 0)
				{
					if (numeralInput.find(CM) > 0)
					{
						if ((numeralInput[numeralInput.find(CM) - 1] == 'I') || (numeralInput[numeralInput.find(CM) - 1] == 'V') ||
							(numeralInput[numeralInput.find(CM) - 1] == 'X') || (numeralInput[numeralInput.find(CM) - 1] == 'L') ||
							(numeralInput[numeralInput.find(CM) - 1] == 'C') || (numeralInput[numeralInput.find(CM) - 1] == 'D'))
						{
							cout << "Invalid numeral ('CM' cannot come after 'I', 'V', 'X', 'L', 'C', or 'D')" << endl;
						}
						else
						{
							numeralInput.erase(numeralInput.find(CM), 2);
							decimalOutput = decimalOutput + cm;
						}
					}
					else
					{
						if ((numeralInput[numeralInput.find(CM) + 2] == 'M') || (numeralInput[numeralInput.find(CM) + 2] == 'D') ||
							(numeralInput[numeralInput.find(CM) + 2] == 'C'))
						{
							cout << "Invalid numeral ('CM' cannot be followed by 'C', 'D', or 'M')" << endl;
						}
						else
						{
							numeralInput.erase(numeralInput.find(CM), 2);
							decimalOutput = decimalOutput + cm;
						}
					}
				}
				else
				{
					numeralInput.erase(numeralInput.find(CM), 2);
					decimalOutput = decimalOutput + cm;
				}
			}

			// Assuming the previous statements removed all of the subtractive numeral pairs, calculating the final value is simple; just add the remaining numerals
			// The remaining numerals should be in order from highest to lowest, otherwise the input is invalid (e.g. XXVX is invalid because X can't come after V)
			// 'M', 'C', 'X', and 'I' can only appear 3 consecutive times. 'D', 'L', and 'V' can only appear once
			for (int i = 0; i < numeralInput.size(); i++)
			{
				if ((numeralInput[i] == 'M') && (mCount < 3) && (mFinished == false))
				{
					decimalOutput = decimalOutput + M;
					mCount++; // keeps track of how many 'M's there are in the numeral
				}
				else if ((numeralInput[i] == 'D') && (dCount < 1) && (dFinished == false))
				{
					decimalOutput = decimalOutput + D;
					dCount++;
					mFinished = true; // Once there is a 'D', there cannot be any more 'M's in the numeral
				}
				else if ((numeralInput[i] == 'C') && (cCount < 3) && (cFinished == false))
				{
					decimalOutput = decimalOutput + C;
					cCount++;
					mFinished = true;
					dFinished = true;
				}
				else if ((numeralInput[i] == 'L') && (lCount < 1) && (lFinished == false))
				{
					decimalOutput = decimalOutput + L;
					lCount++;
					mFinished = true;
					dFinished = true;
					cFinished = true;
				}
				else if ((numeralInput[i] == 'X') && (xCount < 3) && (xFinished == false))
				{
					decimalOutput = decimalOutput + X;
					xCount++;
					mFinished = true;
					dFinished = true;
					cFinished = true;
					lFinished = true;
				}
				else if ((numeralInput[i] == 'V') && (vCount < 1) && (vFinished == false))
				{
					decimalOutput = decimalOutput + V;
					vCount++;
					mFinished = true;
					dFinished = true;
					cFinished = true;
					lFinished = true;
					xFinished = true;
				}
				else if ((numeralInput[i] == 'I') && (iCount < 3))
				{
					decimalOutput = decimalOutput + I;
					iCount++;
					mFinished = true;
					dFinished = true;
					cFinished = true;
					lFinished = true;
					xFinished = true;
					vFinished = true;
				}
				else
				{
					cout << "Invalid input. Please double check your characters!" << endl;
					decimalOutput = 0;
					break;
				}
			}
			cout << "Result: " << decimalOutput << endl << endl;
			// Clears inputs and resets conditions
			decimalOutput = 0;
			numeralInput.clear();
			mFinished = false;
			dFinished = false;
			cFinished = false;
			lFinished = false;
			xFinished = false;
			vFinished = false;
			mCount = 0;
			dCount = 0;
			cCount = 0;
			lCount = 0;
			xCount = 0;
			vCount = 0;
			iCount = 0;
		}

		while (menuNum == menu_option2) // convert decimal number to roman numeral
		{
			cout << "Sorry, this function isn't available yet!" << endl << endl;
			break;
			/* I didn't have time to get to this section of the program. It would be very straightforward:
			I have all of the numerals/numeral pairs and their values declared. The user would enter decimalInput, which I would check to make sure isn't
			larger than 3999. I would then use a series of if/else statements to find the next biggest numeral that could be subtracted from the input, and
			that numeral or pair would be appended to numeralOutput. Example:
				If decimalInput = 961: CM (900) is the largest value that can be subtracted. Append 'CM' to numeralOutput. decimalInput is now 61. L (50)
				is the next largest, then X (10), then I (1). decimalInput would equal 0, and numeralOutput would contain 'CMLXI'
			After calculating and outputting the result, numeralOutput would be cleared. */
		}

		if ((menuNum != menu_option1) && (menuNum != menu_option2) && (menuNum != menu_option3))
		{
			cout << "Invalid selection" << endl;
			break;
		}

		cout << "Options:" << endl;
		cout << " 1 - Convert a roman numeral" << endl;
		cout << " 2 - Convert a decimal number" << endl;
		cout << " 3 - Quit the program" << endl;
		cout << "Please select an option: ";
		cin >> menuNum;
		cout << endl;
	}

	cout << "Program exited successfully. Goodbye!" << endl;
	return 0;
}

/* Given more time, I could have made a few more improvements to my code: 
- A lot of my code repeats itself, so I could have created functions to make things neater.
- I could improve the menu code and how it responds to different inputs (e.g. allowing the user to try again instead of exiting the program).
- I could create more detailed "Invalid input" responses so that the user knows exactly where they went wrong. This part would probably require a lot more coding, but would be useful.
- More time for troubleshooting and testing would be nice, to make sure I didn't miss any rules or exceptions. */
