#include <iostream>
#include <stack>
#include <vector>
#define MAX 100
using namespace std;

//Struct Node
struct Node
{
	int data;
	Node* left, * right;
};
//init
void initTree(Node*& root)
{
	root = NULL;
}
//func
Node* createNode(int data)
{
	Node* p = new Node;
	p->data = data;
	p->left = p->right = NULL;
	return p;
}
void insertNode(Node*& root, int data)
{
	if (root == NULL)
	{
		root = createNode(data);
	}
	else
	{
		if (root->data == data)
			return;
		else if (data < root->data)
			insertNode(root->left, data);
		else
			insertNode(root->right, data);
	}
}
Node* searchTree(Node* root, int x)
{
	if (root != NULL)
	{
		if (root->data == x)
			return root;
		else
			if (x < root->data)
				return searchTree(root->left, x);
			else
				return searchTree(root->right, x);
	}
	return NULL;
}
void printNLR(Node* root)
{
	stack<Node*> s;
	Node* p = root;
	int i = 0;
	while (p != NULL || !s.empty())
	{
		while (p != NULL)
		{
			s.push(p);
			cout << p->data << " ";
			p = p->left;
		}
		p = s.top();
		s.pop();
		p = p->right;
	}
}
void printLNR(Node* root)
{
	Node* current = root;
	while (current != NULL) {
		if (current->left == NULL) {
			cout << current->data << " ";
			current = current->right;
		}
		else {
			Node* prev = current->left;
			while (prev->right != NULL && prev->right != current)
				prev = prev->right;
			if (prev->right == NULL) {
				prev->right = current;
				current = current->left;
			} 
			else {
				prev->right = NULL;
				cout << current->data << " ";
				current = current->right;
			}
		}
	}
}
vector<int> printLRN_vector(Node* root)
{
	vector<int> res;
	Node* current = root;
	while (current != NULL) {
		if (current->right == NULL) {
			res.push_back(current->data);
			current = current->left;
		}
		else {
			Node* prev = current->right;
			while (prev->left != NULL && prev->left != current)
				prev = prev->left;
			if (prev->left == NULL) {
				res.push_back(current->data);
				prev->left = current;
				current = current->right;
			}
			else {
				prev->left = NULL;
				current = current->left;
			}
		}
	}
	vector<int> res_reverse(res.size());
	for (int i = 0; i < res.size(); i++)
		res_reverse[i] = res[res.size() - 1 - i];
	return res_reverse;
}
void printLRN_recursion(Node* root)
{
	if (root != NULL)
	{
		printLRN_recursion(root->left);
		printLRN_recursion(root->right);
		cout << root->data << " ";
	}
}
//Main
int main()
{
	Node* root;
	initTree(root);
	insertNode(root, 13);
	insertNode(root, 7);
	insertNode(root, 11);
	insertNode(root, 22);
	insertNode(root, 19);
	insertNode(root, 15);
	insertNode(root, 26);
	insertNode(root, 24);
	insertNode(root, 9);
	insertNode(root, 30);
	insertNode(root, 33);
	insertNode(root, 5);
	insertNode(root, 12);

	cout << "Duyet NLR: "; printNLR(root);
	cout << "\nDuyet LNR: "; printLNR(root);
	cout << "\nDuyet LRN vector: ";
	vector<int> lrn = printLRN_vector(root);
	for (auto x : lrn) cout << x << " ";
	cout << "\nDuyet LRN de quy: "; printLRN_recursion(root);
	//Tim node
	int x;
	cout << "\nNhap gia tri muon tim trong cay: "; cin >> x;
	if (searchTree(root, x))
		cout << "Tim thay " << x << " trong cay NPTK";
	else
		cout << "Khong tim thay " << x << " trong cay NPTK!";

	cout << endl;
	system("pause");
	return 0;
}