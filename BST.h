/*Zane Partain
10/25/17
Morse Code Conversion
*/
#pragma once
#include "Node.h"

class BST
{
public:
	//constructor
	BST(BSTNode *pNewRoot = nullptr);
	void readFile(string fileName); // populate file [POPULATES THE TREE] (for a balanced tree)
	bool insert(const char &newData,const string &morseCode);
	BSTNode* search(char key);//make search
	void inorderTraversal();

private:
	BSTNode *pRoot;
	BSTNode* search(BSTNode *&pTree, char key);//make search
	void inorderTraversal(BSTNode *pTree);
	bool insert(BSTNode *&pTree, const char &newData,const string &morseCode);
};

/*
Grab a string from the user and convert it into binary
Capitalizes the character of the string
*/
string stringConversion(BST &tree);
