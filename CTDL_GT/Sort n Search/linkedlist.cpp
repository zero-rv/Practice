#include <iostream>
using namespace std;

//Node
struct Node
{
	int info;
	Node* next, *prev;
};
//Init
void init(Node*& head, Node*& tail)
{
	head = NULL;
	tail = NULL;
}
//Methods
Node* createNode(int info)
{
	Node* p = new Node;
	p->info = info;
	p->next = NULL;
	p->prev = NULL;
	return p;
}
void printListHead(Node* head)
{
	Node* p = head;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->next;
	}
}
void printListTail(Node* tail)
{
	Node* p = tail;
	while (p!=NULL)
	{
		cout << p->info << " ";
		p = p->prev;
	}
}
Node* search(Node* head, int x)
{
	Node* p = head;
	while (p != NULL && p->info != x)
		p = p->next;
	return p;
}
void insertFirst(Node*& head, Node*& tail, int info)
{
	Node* p = createNode(info);
	if (head == NULL)
		tail = p;
	else
	{
		head->prev = p;
		p->next = head;
	}
	head = p;
}
void deleteFirst(Node*& head, Node*& tail)
{
	if (head != NULL)
	{
		Node* p = head;
		head = head->next;
		delete p;
		if (head != NULL)
			head->prev = NULL;
		else
			tail = NULL;
	}
}
void insertLast(Node*& head, Node*& tail, int info)
{
	Node* p = createNode(info);
	if (tail == NULL)
		head = p;
	else
	{
		tail->next = p;
		p->prev = tail;
	}
	tail = p;
}
void deleteLast(Node*& head, Node*& tail)
{
	if (tail != NULL)
	{
		Node* p = tail;
		tail = tail->prev;
		delete p;
		if (tail != NULL)
			tail->next = NULL;
		else
			head = NULL;
	}
}
Node* searchDelete(Node*& head, Node*& tail, int x)
{
	Node* p = head;
	Node* q = NULL; //Node lien truoc p
	if (p != NULL)
	{
		if (head->info == x)
		{
			deleteFirst(head, tail);
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
Node* searchClosestGreater(Node* head, Node* tail, int x)
{
	Node* p = head;
	Node* min = NULL;
	while (p!=NULL)
	{
		if (p->info >= x)
		{
			if (min == NULL || p->info < min->info)
				min = p;
		}
		p = p->next;
	}
	return min;
}
void insertPrevGreater(Node*& head, Node*& tail, int x)
{
	Node* p = head, * q = tail;
	Node* t = NULL; //node lien truoc p
	Node* result = searchClosestGreater(p, q, x);
	if (result != NULL)
	{
		while (p != NULL && p->info != result->info)
		{
			t = p;
			p = p->next;
		}
		if (p == head)
			insertFirst(head, tail, x);
		else
		{
			Node* result = createNode(x);
			result->next = p;
			result->prev = t;
			t->next = result;
			p->prev = result;
		}
	}
}
void destructList(Node*& head, Node*& tail)
{
	while (head != NULL)
		deleteFirst(head, tail);
}
//Main
int main()
{
	Node* head, * tail;
	init(head, tail);
	//Them 1 node moi
	while (true)
	{
		int x, insert, iscont;
		cout << "Nhap gia tri moi cho danh sach: ";
		cin >> x;
		cout << "Them vao dau/cuoi danh sach? (1/0): ";
		cin >> insert;
		if (insert)
			insertFirst(head, tail, x);
		else
			insertLast(head, tail, x);
		cout << "Done! Tiep tuc? (1/0): ";
		cin >> iscont;
		if (!iscont)
			break;
	}
	cout << "Danh sach: "; printListHead(head);
	cout << "\nDanh sach dao nguoc: "; printListTail(tail);
	//Tim 1 node
	int find;
	cout << "\nNhap gia tri can tim: ";
	cin >> find;
	if (search(head, find))
		cout << "Tim thay!\n";
	else
		cout << "Khong tim thay!\n";
	//Tim 1 node va xoa node do
	int finddelete;
	cout << "Nhap gia tri can tim va xoa gia tri do: ";
	cin >> finddelete;
	if (searchDelete(head, tail, finddelete))
	{
		cout << "Danh sach sau khi xoa: ";
		printListHead(head);
		cout << endl;
	}
	else
		cout << "Khong tim thay!\n";
	//Tim 1 node va them node do vao truoc node co gia tri >=
	int findinsert;
	cout << "Nhap gia tri x can them: ";
	cin >> findinsert;
	if (searchClosestGreater(head, tail, findinsert))
	{
		cout << "Danh sach sau khi them x vao truoc node gan nhat va >= x: ";
		insertPrevGreater(head, tail, findinsert); printListHead(head);
	}
	else
		cout << "Khong co gia tri >= x trong danh sach!";
	//Xoa 1 node dau/cuoi
	cout << "\nDanh sach sau khi xoa 1 node dau: ";
	deleteFirst(head, tail); printListHead(head);
	cout << "\nDanh sach sau khi xoa 1 node cuoi: ";
	deleteLast(head, tail); printListHead(head);
	//Huy danh sach
	cout << "\nDanh sach sau khi huy: ";
	destructList(head, tail); printListHead(head);
	cout << endl;

	system("pause");
	return 0;
}