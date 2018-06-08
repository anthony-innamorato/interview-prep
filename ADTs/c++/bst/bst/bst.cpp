// bst.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <random>
#include <vector>
using namespace std;

struct Node
{
	Node(int data, Node* left, Node* right) : data(data), left(left), right(right) {}
	Node(int data) : data(data) {}
	int data;
	Node* left = nullptr;
	Node* right = nullptr;
};

void insert(Node* root, int data)
{
	if (data == root->data) { cout << "Node replicated" << endl;}
	else if (data < root->data)
	{
		if (root->left == nullptr) { root->left = new Node(data); }
		else { insert(root->left, data); }
	}
	else //data > root->data
	{
		if (root->right == nullptr) { root->right = new Node(data); }
		else { insert(root->right, data); }
	}
}

bool valInTree(Node* root, int data)
{
	if (root == nullptr) { return false; }
	if (root->data == data) { return true; }
	else
	{
		if (valInTree(root->left, data) or valInTree(root->right, data)) { return true; }
		return false;
	}
}

int bstCount(Node* root)
{
	if (root == nullptr) { return 0; }
	return 1 + bstCount(root->left) + bstCount(root->right);
}

vector<int> minMax(Node* root)
{
	if (root == nullptr) { return { INT_MAX, INT_MIN }; }
	vector<int> leftMinMax = minMax(root->left);
	vector<int> rightMinMax = minMax(root->right);
	vector<int> finalRes = { min(leftMinMax[0], rightMinMax[0]), max(leftMinMax[1], rightMinMax[1]) };
	finalRes[0] = min(finalRes[0], root->data);
	finalRes[1] = max(finalRes[1], root->data);
	return finalRes;
}

void printMinMax(Node* root)
{
	vector<int> result = minMax(root);
	cout << "min: " << result[0] << "\t max: " << result[1] << endl;
}

int sum(Node* root)
{
	if (root == nullptr) { return 0; }
	return root->data + sum(root->left) + sum(root->right);
}

int height(Node* root)
{
	if (root == nullptr) { return 0; }
	return 1 + max(height(root->left), height(root->right));
}

struct twoValReturn
{
	twoValReturn(bool balancedSoFar, int currHeight) : balancedSoFar(balancedSoFar), currHeight(currHeight) {}
	bool balancedSoFar;
	int currHeight;
};

twoValReturn isBalanced(Node* root)
{
	if (root == nullptr) { return twoValReturn(true, 0); }
	twoValReturn leftPrev = isBalanced(root->left);
	twoValReturn rightPrev = isBalanced(root->right);
	if (leftPrev.balancedSoFar && rightPrev.balancedSoFar && abs(leftPrev.currHeight - rightPrev.currHeight) < 2)
	{ 
		return twoValReturn(true, 1 + max(leftPrev.currHeight, rightPrev.currHeight)); 
	}
	return twoValReturn(false, 1 + max(leftPrev.currHeight, rightPrev.currHeight));
}

//LDR
void inorder(Node* root)
{
	if (root->left != nullptr) {inorder(root->left); }
	cout << root->data << ' ';
	if (root->right != nullptr) { inorder(root->right); }
}

//DLR
void preorder(Node* root)
{
	cout << root->data << ' ';
	if (root->left != nullptr) { preorder(root->left); }
	if (root->right != nullptr) { preorder(root->right); }
}

//LRD
void postorder(Node* root)
{
	if (root->left != nullptr) { postorder(root->left); }
	if (root->right != nullptr) { postorder(root->right); }
	cout << root->data << ' ';
}

//make reading a bit better
void printTraversal(string trav, Node* root)
{
	if (trav == "inorder") 
	{
		cout << "Printing Inorder: ";
		inorder(root); 
		cout << endl;
	}
	else if (trav == "preorder") 
	{ 
		cout << "Printing Preorder: ";
		preorder(root); 
		cout << endl; 
	}
	else if (trav == "postorder")
	{ 
		cout << "Printing Postorder: ";
		postorder(root); 
		cout << endl; 
	}
}


int main()
{
	cout << "========================EXAMPLE A========================" << endl << endl;
	Node* a = new Node(70);
	insert(a, 100);
	insert(a, 23);
	insert(a, 5);
	insert(a, 4);
	insert(a, 6);

	cout << "===========Testing Tree Traversals===========" << endl;
	printTraversal("inorder", a);
	printTraversal("preorder", a);
	printTraversal("postorder", a);
	cout << endl << endl;

	cout << "===========Testing Val In Tree ===========" << endl;
	cout << valInTree(a, 70) << '\t';
	cout << valInTree(a, 100) << '\t';
	cout << valInTree(a, 23) << '\t';
	cout << valInTree(a, 5) << '\t';
	cout << valInTree(a, 4) << '\t';
	cout << valInTree(a, 6) << '\t';
	cout << valInTree(a, 54) << endl << endl << endl;

	cout << "===========Testing BSTCount ===========" << endl;
	cout << bstCount(a) << endl << endl << endl;


	cout << "===========Testing MinMax ===========" << endl;
	printMinMax(a);
	cout << endl << endl;


	cout << "===========Testing Sum ===========" << endl;
	cout << sum(a) << endl << endl << endl;


	cout << "===========Testing Height ===========" << endl;
	cout << height(a) << endl << endl << endl;


	cout << "===========Testing isBalanced ===========" << endl;
	cout << isBalanced(a).balancedSoFar << endl << endl << endl;
    return 0;
}

