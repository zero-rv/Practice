#include <iostream>
#include <string>
using namespace std;

//Struct Film
struct Film
{
	string name;
	string type;
	string director;
	int year_sx;
	//methods
	void input();
	void print();
};
void Film::input()
{
	cin.ignore();
	cout << "Ten phim: "; getline(cin, name);
	cout << "The loai phim: "; getline(cin, type);
	cout << "Ten dao dien: "; getline(cin, director);
	cout << "Nam san xuat phim: "; cin >> year_sx;
}
void Film::print()
{
	cout << "*-------------------------------------*\n";
	cout << "Ten phim: " << name << endl;
	cout << "The loai: " << type << endl;
	cout << "Dao dien: " << director << endl;
	cout << "Nam san xuat: " << year_sx << endl;
	cout << "*-------------------------------------*\n";
}
//Node
struct Node
{
	Film info;
	Node* next;
};
//Init
void init(Node*& head)
{
	head = NULL;
}
//Methods
Node* createNode(Film info)
{
	Node* p = new Node;
	p->info = info;
	p->next = NULL;
	return p;
}
void insertLast(Node*& head, Film info)
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
void inputList(Node*& head)
{
	int n;
	do
	{
		cout << "Nhap so bo phim: ";
		cin >> n;
		if (n <= 0)
			cout << "Khong hop le!\n";
	} while (n <= 0);
	for (int i = 1; i <= n; i++)
	{
		cout << "Nhap thong tin bo phim thu " << i << endl;
		Film film;
		film.input();
		insertLast(head, film);
	}
}
void printList(Node* head)
{
	Node* p = head;
	while (p != NULL)
	{
		p->info.print();
		p = p->next;
	}
}
Node* search(Node* head, string director)
{
	Node* p = head;
	while (p != NULL && p->info.director != director)
		p = p->next;
	return p;
}
void mapByDirector(Node* head, string director) //Tim ten dao dien va xuat cac bo phim cua dao dien do
{
	Node* p = head;
	while (p != NULL)
	{
		if (p->info.director == director)
			p->info.print();
		p = p->next;
	}
}
void swap(Film& x, Film& y)
{
	Film tmp = y;
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
				if (p->info.year_sx > q->info.year_sx)
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
	while (head != NULL)
	{
		Node* p = head;
		head = head->next;
		p->next = NULL;
		delete p;
	}
}
//Main
int main()
{
	Node* head;
	init(head);
	//Nhap thong tin n phim
	inputList(head);
	cin.ignore();
	//Xuat thong tin n phim
	printList(head);
	//Tim ten dao dien va xuat cac bo phim cua dao dien do
	string director;
	cout << "\nNhap ten dao dien can tim: "; getline(cin, director);
	if (search(head, director))
	{
		cout << "Cac bo phim do dao dien " << director << " dan dung:\n";
		mapByDirector(head, director);
	}
	else
		cout << "Tim khong thay!\n";
	//Sap xep cac bo phim tang dan theo nam san xuat
	cout << "\nDanh sach cac bo phim tang dan theo nam san xuat:\n";
	sortASC(head); printList(head);

	destructList(head);
	system("pause");
	return 0;
}