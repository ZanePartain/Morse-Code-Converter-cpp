/*Zane Partain
10/25/17
Morse Code Conversion
*/
#include "BST.h"

//constructor
BST::BST(BSTNode * pNewRoot)
{
	this->pRoot = nullptr;
}

//opens the file for reading and closes it
void BST::readFile(string file)
{
	//openning / reading the file
	ifstream inputFileMorse, inputFileConvert;
	inputFileMorse.open(file, ifstream::in);


	//grabbing char and code line by line
	while (inputFileMorse)
	{
		char newChar;
		string newMorse;
		inputFileMorse >> newChar;
		inputFileMorse >> newMorse;
		//call insert
		insert(newChar, newMorse);
	}

	inputFileMorse.close();

}
//insert the characters and corresponding morse code into the the nodes and into the tree
bool BST::insert(const char & newData,const string &morseCode)
{
	//calling the Helper Function (behind the scenes insert)
	return insert(this->pRoot, newData, morseCode);
}

//HELPER FUNCTION because it knows the location of itself in the tree
bool BST::insert(BSTNode *& pTree, const char & newData,const string &morseCode)
{
	bool success = false;

	if (pTree == nullptr) // if there is an empty leaf node
	{
		BSTNode *pMem = nullptr;
		pMem = new BSTNode(newData, morseCode);

		if (pMem != nullptr) //if new operation was successful
		{
			//assign pMem as the new Root Node of the BST
			success = true;
			pTree = pMem;
		}
	}
	else if (newData > (pTree)->getCharacter()) //recursive step
	{
		//go down right subtree
		success = insert(((pTree)->getpRight()), newData, morseCode);
	}
	else if (newData < (pTree)->getCharacter()) //recursive step
	{
		//go down left subtree
		success = insert(((pTree)->getpLeft()), newData, morseCode);
	}
	else
	{
		//duplicate
		success = false;
	}
	return success;
}

//print out the nodes contents in order
void BST::inorderTraversal()
{
	inorderTraversal(this->pRoot);
}
//Helper function
void BST::inorderTraversal(BSTNode *pTree)
{
	// algorithm: 1. go as far left as possible 
	// 2. process the node (print)
	// 3. go as far right as possible
	if (pTree != nullptr)
	{
		inorderTraversal(pTree->getpLeft());
		cout << pTree->getCharacter() << "-->";
		inorderTraversal(pTree->getpRight());
	}
}

BSTNode * BST::search(char key)
{
	return search(this->pRoot, key);
}

//finds and return the Node in the tree that matches  the letter in a recieved string
BSTNode * BST::search(BSTNode *& pTree, char key)
{
	int success = 0;
	BSTNode *pCur = pTree;
	if (pTree != NULL)
	{
		if (key == pCur->getCharacter())
		{
			//if the current leaf character matches the key
			return pCur;
			success = 1;
		}
		else if (key < pCur->getCharacter())
		{
			//if you need to traverse left through the list more
			search(pCur->getpLeft(), key);
		}
		else if (key > pCur->getCharacter())
		{
			//if you need to traverse right through the list more
			search(pCur->getpRight(), key);
		}
	}

}


//convert the string recieved by the user into morsecode 
string stringConversion(BST &tree)
{
    string newStr;
	string convertedStr;
	BSTNode* key;
	int opt;

	cout << "1. Enter a sentence to convert to morse code.\n2. Read from Converter.txt File.\n" << endl;
	cin >> opt;
	system("cls");
	switch (opt)
	{
	case 1:
	{
		
		cout << "Enter a sentence: " << endl;
		getline(cin, newStr);
		getline(cin, newStr); // accounts for whitespace 

		for (int i = 0; i < newStr.size(); i++)
		{
			//pass in each character and returns a BSTNode
			//key, is storing Morse Code of String
			//store the morse code into 

			if (newStr[i] != ' ')
			{
				key = tree.search(toupper(newStr[i]));
				convertedStr.append(key->getMorseCode());
				convertedStr += " ";

			}
			else
			{
				//account for space between words
				convertedStr.append("   ");
			}

		}
		break;
	}
	case 2:
	{
		ifstream inputFileConvert;
		inputFileConvert.open("Converter.txt", ifstream::in);
		string fromFile;
		while (inputFileConvert)
		{
			getline(inputFileConvert, fromFile);
			for (int i = 0; i < fromFile.size(); i++)
			{
				//pass in each character and returns a BSTNode
				//key, is storing Morse Code of String
				//store the morse code into 

				if (fromFile[i] != ' ')
				{
					key = tree.search(toupper(fromFile[i]));
					convertedStr.append(key->getMorseCode());
					convertedStr += " ";
				}
				else if (fromFile[i] == ' ')
				{ 
					//account for space between words
					convertedStr.append(" ");
				}

			}
			
		}
		break;
	}
	}
	
	return convertedStr;
}
