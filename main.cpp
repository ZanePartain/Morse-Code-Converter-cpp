/*Zane Partain
10/25/17
Morse Code Conversion

This program will either prompt the user for a snetence to convert into morse code,
  or it will read from a txt file then convert the txt file into morse code.
  The program does not use an STL tree method such as set and map.
  The morse code representation of the alphabet and numbers are read in from a txt file and stored into a BST according to their ascii values.
*/

#include "BST.h"

int main(void)
{
	BST okay;
	string morseCode;
	//prompt user for file name
	//in this case it's hard coded
	//populate the binary search tree
	string file = "MorseTable.txt";
	okay.readFile(file);
	
	morseCode = stringConversion(okay); //populate the string with the morse code representation
	cout << morseCode;  
	cout << endl;

	return 0;
}
