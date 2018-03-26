/*Zane Partain
10/25/17
Morse Code Conversion
*/
#pragma once
#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;

class BSTNode
{
public:
	//constructor
	BSTNode(const char &newChar = '\0', const string &newMorse = " ");

	//getters
	string getMorseCode() const;
	char getCharacter() const;
	BSTNode* &getpLeft();
	BSTNode* &getpRight();

	//setters
	void setData(const char &newChar = '\0', const string &newMorse = " ");
	void setLeft(BSTNode * const pNewLeft);
	void setRight(BSTNode * const pNewRight);


private:
	string morseCode;
	char character;
	BSTNode *pLeft;
	BSTNode *pRight;

};
