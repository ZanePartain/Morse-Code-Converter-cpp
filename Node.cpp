/*Zane Partain
10/25/17
Morse Code Conversion
*/
#include "Node.h"

//construct the node
BSTNode::BSTNode(const char & newChar, const string & newMorse)
{
	this->character = newChar;
	this->morseCode = newMorse;
	this->pLeft = nullptr;
	this->pRight = nullptr;

}

//getters
string BSTNode::getMorseCode() const
{
	return morseCode;
}

char BSTNode::getCharacter() const
{
	return character;
}

BSTNode * &BSTNode::getpLeft()
{
	return this->pLeft;
}

BSTNode * &BSTNode::getpRight()
{
	return this->pRight;
}

//setters
void BSTNode::setData(const char & newChar, const string & newMorse)
{

	this->character = newChar;
	this->morseCode = newMorse;
}

void BSTNode::setLeft(BSTNode * const pNewLeft)
{
	this->pLeft = pNewLeft;
}

void BSTNode::setRight(BSTNode * const pNewRight)
{
	this->pRight = pNewRight;
}
