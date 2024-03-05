#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

void b10();
void b11();
void b12();
void input(string s, int& n);

int main()
{
	back:
	cout << "Switch: ";
	int x;
	cin >> x;
	switch (x)
	{
	case 10: 
		b10();
		goto back;
	case 11:
		b11();
		goto back;
	case 12:
		b12();
		goto back;
	case 0:
		break;
	default:
		goto back;
	}
	return 0;
}

void input(string s, int& n)
{
	cout << s;
	cin >> n;
}

void b10()
{
	int n, arr[10][10] = {0}, value = 1;
	do
	{
		input("Nhap do dai mang nxn (2 <= n <= 10): ", n);
	} while (n <= 2 || n >= 10);
	int tmp = n - 1;
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (j == 0 || j % 2 == 0)
			{
				arr[i][j] = value;
				value++;
			}
			if (j % 2 != 0)
			{
				arr[tmp - i][j] = value;
				value++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void b11()
{
	int size, arr[10][10], value = 1, count = 0;
	do
	{
		input("Nhap do dai mang nxn (2 <= n <= 10): ", size);
	} while (size <= 2 || size >= 10);
	int left = 0, right = size - 1, top = 0, bottom = size - 1;
	//Matrix
	while (true)
	{
		//Tren: trai -> phai
		for (int j = left; j <= right; j++)
		{
			arr[top][j] = value;
			value++;
		}
		top++;
		if (top > bottom) { break; }

		//Phai: tren -> duoi
		for (int i = top; i <= bottom; i++)
		{
			arr[i][right] = value;
			value++;
		}
		right--;
		if (right < left) { break; }

		//Duoi: phai -> trai
		for (int j = right; j >= left; j--)
		{
			arr[bottom][j] = value;
			value++;
		}
		bottom--;
		if (bottom < top) { break; }

		//Trai: duoi -> tren
		for (int i = bottom; i >= top; i--)
		{
			arr[i][left] = value;
			value++;
		}
		left++;
		if (left > right) { break; }
	}

	//Print Array
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void b12()
{
	char seats[13][6];
	int row = -1, col = -1;
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			seats[i][j] = 'X';
		}
	}
	//MENU
_menu1:
	system("cls");
	cout << "|--------- Dat ve may bay ---------|" << endl;
	cout << "|1. Dat cho ngoi                   |" << endl;
	cout << "|2. Xem cho ngoi                   |" << endl;
	cout << "|3. Kiem tra ve                    |" << endl;
	cout << "|                                  |" << endl;
	cout << "|0. Thoat                          |" << endl;
	cout << "|----------------------------------|" << endl;
	cout << "Select: ";
	int select;
	cin >> select;
	system("cls");

	switch (select)
	{
	case 1: //Dat cho ngoi
		_menu2:
		system("cls");
		cout << "|---------- Chon loai ve ----------|" << endl;
		cout << "|1. Thuong gia                     |" << endl;
		cout << "|2. Pho thong                      |" << endl;
		cout << "|3. Tiet kiem                      |" << endl;
		cout << "|                                  |" << endl;
		cout << "|0. Thoat                          |" << endl;
		cout << "|----------------------------------|" << endl;
		cout << "Select: ";
		cin >> select;
		switch(select)
		{
		case 1:
			cout << endl << "         A  B  C  D  E  F" << endl;
			for (int i = 0; i < 2; i++)
			{
				if (i + 1 < 10)
					cout << "Hang  " << i + 1 << "  ";
				else
					cout << "Hang " << i + 1 << "  ";

				for (int j = 0; j < 6; j++)
				{
					cout << seats[i][j] << "  ";
				}
				cout << endl;
			}
			cout << endl;
			break;
		case 2:
			cout << endl << "         A  B  C  D  E  F" << endl;
			for (int i = 2; i < 7; i++)
			{
				if (i + 1 < 10)
					cout << "Hang  " << i + 1 << "  ";
				else
					cout << "Hang " << i + 1 << "  ";

				for (int j = 0; j < 6; j++)
				{
					cout << seats[i][j] << "  ";
				}
				cout << endl;
			}
			cout << endl;
			break;
		case 3:
			cout << endl << "         A  B  C  D  E  F" << endl;
			for (int i = 7; i < 13; i++)
			{
				if (i + 1 < 10)
					cout << "Hang  " << i + 1 << "  ";
				else
					cout << "Hang " << i + 1 << "  ";

				for (int j = 0; j < 6; j++)
				{
					cout << seats[i][j] << "  ";
				}
				cout << endl;
			}
			cout << endl;
			break;
		case 0:
			goto _menu1;
		default:
			goto _menu2;
		}

		_input_seat_again:
		cout << "Chon cho ngoi: " << endl;
		cout << "_Chon cot (1 -> A ... 6 -> F): ";
		cin >> col;
		cout << "_Chon hang: ";
		cin >> row;
		
		switch (select)
		{
		case 1:
			if (row < 1 || row > 2 || col < 1 || col > 6)
			{
				cout << "Cho ngoi khong hop le! Chon lai!" << endl;
				goto _input_seat_again;
			}
			break;
		case 2:
			if (row < 3 || row > 7 || col < 1 || col > 6)
			{
				cout << "Cho ngoi khong hop le! Chon lai!" << endl;
				goto _input_seat_again;
			}
			break;
		case 3:
			if (row < 8 || row > 13 || col < 1 || col > 6)
			{
				cout << "Cho ngoi khong hop le! Chon lai!" << endl;
				goto _input_seat_again;
			}
			break;
		}
		seats[row - 1][col - 1] = '*';
		cout << "Dat cho thanh cong!" << endl;
		system("pause");
		goto _menu1;
	case 2: //Xem cho ngoi
		cout << "         A  B  C  D  E  F" << endl;
		for (int i = 0; i < 13; i++)
		{
			if (i + 1 < 10)
				cout << "Hang  " << i + 1 << "  ";
			else
				cout << "Hang " << i + 1 << "  ";

			for (int j = 0; j < 6; j++)
			{
				cout << seats[i][j] << "  ";
			}
			cout << endl;
		}
		cout << endl;
		system("pause");
		goto _menu1;
	case 3:
		goto _menu1;
	case 0:
		return;
	default:
		goto _menu1;
	}
	
}

