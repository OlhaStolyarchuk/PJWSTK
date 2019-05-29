
#include <stdio.h>
#include <string.h>
#include<iostream>


struct Tree;
char lastSentences[50]; 
char availableSentences[50];
Tree* availableElement;

struct Tree
{
public:
	char  value;
	Tree* right;
	Tree* left;
	Tree* parent;
	Tree() {
	 value = 0;
		right = NULL;
		left = NULL;
		parent = NULL;
	}
	void recursion()
	{
		//if we have left son in the tree
		if (this->left)
		{
			this->left->recursion();
		}
		// if we have right son in the tree
		if (this->right)
		{
			this->right->recursion();
		}
		// if we have niether left nor right,so it is leaf of tree
		else if (this->left == NULL)
		{
			// if is is leaf,we check if element have created from leaf to root is old from available element,if it is true,we write as new element
			// we write available element(from letters from leaf to root) to variable
			availableElement = this;
			int i = 0;
			for (i; availableElement->parent; ++i) {
				availableSentences[i] = availableElement->value;
				availableElement = availableElement->parent;
			}
			//at the end of loop left on letter,which we must addc
			availableSentences[i] = availableElement->value;
			// add NULL at the end of sentence
			availableSentences[i + 1] = 0;
			// if available sentence is old lexicographical			
			if (strncmp(lastSentences, availableSentences, 50) < 0)//the first character that does not match has a lower value in lastSentences than in availableSentences
			{
				memcpy(lastSentences, availableSentences, 50);//copy from availableSentences to lastSentences
			}
		}
	}
};


int main()
{
	char value = fgetc(stdin);//input
	char numberOfOutput;
	int count = 0;
	for (int i = 0; i <50; ++i)// delete element ,which have the oldest lexicog
	{
		lastSentences[i] = 0;
	}
	Tree* root = new Tree();
	if (count == 0)
	{
		availableElement = root;
	}
	while (!feof(stdin))
	{
		numberOfOutput = fgetc(stdin);//input
									  //leetters from a to z
		if (numberOfOutput >= 97 && numberOfOutput <= 122) {
			// we write the latest remember letter on the element,where has stopped pointer
			availableElement->value = value;
			//back pointer at the beginning of tree
			availableElement = root;
			//remember new letter
			value = numberOfOutput;
			count++;
		}
		else {
			switch (numberOfOutput) {
			case 76:
				// if element on the left side doesnt exist,we will create it
				if (availableElement->left == NULL)
					availableElement->left = new Tree();
				availableElement->left->parent = availableElement;
				availableElement = availableElement->left;
				count++;
				break;
			case 82:
				if (availableElement->right == NULL)
					availableElement->right = new Tree();
				availableElement->right->parent = availableElement;
				count++;
				// go to right side
				availableElement = availableElement->right;
				break;
			}
		}
	}
	// the end of input,pointer come to some element,we need to write the last remember value to this element
	availableElement->value = value;
	// transform tree and wite us the oldest sentences to variable
	root->recursion();
	count++;
	printf(lastSentences, "\n");
	std::cout << count;
	//	system("pause");
	//	return 0;
}
