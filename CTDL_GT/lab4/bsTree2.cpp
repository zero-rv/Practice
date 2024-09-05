#include <iostream>
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
void printLNR(Node* root)
{
	if (root != NULL)
	{
		printLNR(root->left);
		cout << root->data << " ";
		printLNR(root->right);
	}
}
int sumTree(Node* root)
{
	if (root == NULL)
		return 0;
	return root->data + sumTree(root->left) + sumTree(root->right);
}
int countTreeNodes(Node* root)
{
	if (root == NULL)
		return 0;
	return 1 + countTreeNodes(root->left) + countTreeNodes(root->right);
}
Node* leftNode(Node* root)
{
	return root->left;
}
Node* rightNode(Node* root)
{
	return root->right;
}
int find_MaxMin_Tree(Node* root, Node*(*condition)(Node*))
{
	if (root == NULL)
		return -999;
	if (condition(root) == NULL)
		return root->data;
	return find_MaxMin_Tree(condition(root), condition);
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
	cout << "Duyet LNR: "; printLNR(root);
	//Tong cac nut tren cay
	cout << "\nTong gia tri cac nut tren cay: " << sumTree(root);
	//Dem so nut tren cay
	cout << "\nSo luong cac nut tren cay: " << countTreeNodes(root);
	//Tim Node nho nhat, lon nhat
	cout << "\nNode co gia tri nho nhat: " << find_MaxMin_Tree(root, leftNode);
	cout << "\nNode co gia tri lon nhat: " << find_MaxMin_Tree(root, rightNode);

	cout << endl;
	system("pause");
	return 0;
}