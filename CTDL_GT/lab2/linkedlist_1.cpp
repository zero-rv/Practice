#include <iostream>
#define MAX 100
using namespace std;

//Node
struct Node
{
	int info;
	Node* next;
};
//Init
void init(Node*& head)
{
	head = NULL;
}
//Methods
Node* createNode(int info)
{
	Node* p = new Node;
	p->info = info;
	p->next = NULL;
	return p;
}
void printList(Node* head)
{
	Node* p = head;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->next;
	}
}
Node* search(Node* head, int x)
{
	Node* p = head;
	while (p != NULL && p->info != x)
		p = p->next;
	return p;
}
void insertLast(Node*& head, int info)
{
	Node* q = createNode(info);
	if (head != NULL)
	{
		Node* p = head;
		while (p->next != NULL)
			p = p->next;
		p->next = q;
	}
	else
		head = q;
}
void deleteLast(Node*& head)
{
	Node* p = head;
	Node* q = NULL; //Node ap cuoi
	if (head != NULL)
	{
		while (p->next != NULL)
		{
			q = p;
			p = p->next;
		}
		if (p == head)
			head = NULL;
		else
			q->next = NULL;
		delete p;
	}
}
Node* searchDelete(Node*& head, int x)
{
	Node* p = head;
	Node* q = NULL;
	if (p != NULL)
	{
		if (head->info == x)
		{
			Node* del = head;
			head = head->next;
			del->next = NULL;
			delete del;
			return p;
		}
		while (p != NULL && p->info != x)
		{
			q = p;
			p = p->next;
		}
		if (p != NULL && p->info == x)
		{
			//Xoa Node p
			Node* del = p;
			p = p->next;
			q->next = p;
			delete del;
			return q;
		}
	}
	return NULL;
}
Node* searchDeleteIndex(Node*& head, int index)
{
	Node* p = head;
	Node* q = NULL;
	if (p != NULL)
	{
		if (index == 0)
		{
			Node* del = head;
			head = head->next;
			del->next = NULL;
			delete del;
			return p;
		}
		int currentindex = 0;
		while (p != NULL && currentindex != index)
		{
			q = p;
			p = p->next;
			currentindex++;
		}
		if (p != NULL && currentindex == index)
		{
			//Xoa Node p
			Node* del = p;
			p = p->next;
			q->next = p;
			delete del;
			return q;
		}
	}
	return NULL;
}
//Destructor
void destructList(Node*& head)
{
	while (head != NULL)
	{
		deleteLast(head);
	}
}
//Main
int main()
{
	int count = 1;
	Node* head;
	init(head);
	//Them 1 node moi
	while (true && count <= MAX)
	{
		int x, iscont;
		cout << "Nhap gia tri moi cho danh sach: ";
		cin >> x;
		insertLast(head, x);
		cout << "Tiep tuc? (1/0): ";
		cin >> iscont;
		if (!iscont)
			break;
		count++;
	}
	cout << "Danh sach: "; printList(head);
	//Tim 1 node
	int x;
	cout << "\nNhap gia tri can tim: ";
	cin >> x;
	if (search(head, x))
		cout << "Tim thay!\n";
	else
		cout << "Khong tim thay!\n";
	//Tim gia tri 1 node va xoa node do
	int y;
	cout << "Nhap gia tri can tim va xoa gia tri do: ";
	cin >> y;
	if (searchDelete(head, y))
	{
		cout << "Danh sach sau khi xoa: ";
		printList(head);
		cout << endl;
	}
	else
		cout << "Khong tim thay!\n";
	//Tim vi tri 1 node va xoa node tai vi tri do
	int z;
	cout << "Nhap vi tri can xoa: ";
	cin >> z;
	if (searchDeleteIndex(head, z))
	{
		cout << "Danh sach sau khi xoa vi tri " << z << ": ";
		printList(head);
		cout << endl;
	}
	else
		cout << "Khong tim thay vi tri can xoa!\n";
	//Xoa 1 node cuoi
	cout << "Danh sach sau khi xoa 1 node cuoi: ";
	deleteLast(head); printList(head);
	//Huy danh sach
	cout << "\nDanh sach sau khi huy: ";
	destructList(head); printList(head);
	cout << endl;

	system("pause");
	return 0;
}