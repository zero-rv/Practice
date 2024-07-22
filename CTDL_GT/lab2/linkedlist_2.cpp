#include <iostream>
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
Node *search(Node* head, int x)
{
	Node* p = head;
	while (p !=NULL && p->info != x)
		p = p->next;
	return p;
}
void insertFirst(Node* &head, int info)
{
	Node* p = createNode(info);
	if (head == NULL)
		head = p;
	else
	{
		p->next = head;
		head = p;
	}
}
void deleteFirst(Node* &head)
{
	if (head != NULL)
	{
		Node* p = head;
		head = head->next;
		p->next = NULL;
		delete p;
	}
}
void insertLast(Node* &head, int info)
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
void deleteLast(Node* &head)
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
			deleteFirst(head);
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
void swap(int &x, int &y)
{
	int tmp = y;
	y = x;
	x = tmp;
}
void sortASC(Node*& head)
{
	Node* p, * q;
	p = head;
	if (p != NULL)
	{
		while (p->next != NULL)
		{
			q = p->next;
			while (q != NULL)
			{
				if (p->info > q->info)
					swap(q->info, p->info);
				q = q->next;
			}
			p = p->next;
		}
	}
}
//Destructor
void destructList(Node*& head)
{
	while (head!=NULL)
	{
		deleteFirst(head);
	}
}
//Main
int main()
{
	Node* head;
	init(head);
	//Them 1 node moi
	while(true)
	{
		int x, insert, iscont;
		cout << "Nhap gia tri moi cho danh sach: ";
		cin >> x;
		cout << "Them vao dau/cuoi danh sach? (1/0): ";
		cin >> insert;
		if (insert)
			insertFirst(head, x);
		else
			insertLast(head, x);
		cout << "Done! Tiep tuc? (1/0): ";
		cin >> iscont;
		if (!iscont)
			break;
	}
	cout << "Danh sach: "; printList(head);
	//Chuyen thanh danh sach co thu tu
	cout << "\nDanh sach co thu tu: ";
	sortASC(head); printList(head);
	//Tim 1 node
	int x;
	cout << "\nNhap gia tri can tim: ";
	cin >> x;
	if (search(head, x))
		cout << "Tim thay!\n";
	else
		cout << "Khong tim thay!\n";
	//Tim 1 node va xoa node do
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
	//Xoa 1 node dau/cuoi
	cout << "Danh sach sau khi xoa 1 node dau: ";
	deleteFirst(head); printList(head);
	cout << "\nDanh sach sau khi xoa 1 node cuoi: ";
	deleteLast(head); printList(head);
	//Huy danh sach
	cout << "\nDanh sach sau khi huy: ";
	destructList(head); printList(head);
	cout << endl;

	system("pause");
	return 0;
}