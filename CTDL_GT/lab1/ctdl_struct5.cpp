#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <math.h>
#define MAX 50
using namespace std;

//Struct NTN & functions
struct NTN
{
	int ngay, thang, nam;
	//methods
	void input();
	void print();
};

void NTN::input()
{
	cin >> ngay >> thang >> nam;
}

void NTN::print()
{
	cout << ngay << "/" << thang << "/" << nam;
}

//Struct Sach & functions
struct Sach
{
	char tensach[20];
	char tacgia[20];
	NTN timexuatban;
	//methods
	void input();
	void print();
};

void Sach::input()
{
	cout << "Ten sach: "; cin.getline(tensach, 20);
	cout << "Ten tac gia: "; cin.getline(tacgia, 20);
	cout << "Ngay xuat ban: "; timexuatban.input();
}

void Sach::print()
{
	cout << "Ten sach: " << tensach;
	cout << "\nTen tac gia: " << tacgia;
	cout << "\nNgay xuat ban: "; timexuatban.print();
	cout << endl;
}

//Struct ListSach & functions
struct ListSach
{
	Sach list[MAX];
	int n = 0;
	//methods
	void inputList();
	void printCustom();
};

void ListSach::inputList()
{
	int currentindex = 0;
	do
	{
		cout << "Nhap thong tin sach thu " << ++n << ":\n";
		list[currentindex++].input();
		cout << "Tiep tuc? (1/0): ";
		int select;
		cin >> select;
		cin.ignore();
		if (!select)
			break;
	} while (n != MAX);
}

void ListSach::printCustom()
{
	char tacgia[20];
	cout << "Nhap ten tac gia can tim: ";
	cin.getline(tacgia, 20);
	bool isfound = false;
	cout << "-----Ket qua-----\n";
	for(int i =0;i<n;i++)
		if (strcmp(list[i].tacgia, tacgia) == 0)
		{
			list[i].print();
			isfound = true;
		}
	if (!isfound)
		cout << "Khong tim thay!\n";
}

int main()
{
	ListSach list;
	cout << "-----Nhap thong tin sach-----\n";
	list.inputList();
	//Xuat thong tin sach theo ten tac gia
	list.printCustom();

	system("pause");
	return 0;
}