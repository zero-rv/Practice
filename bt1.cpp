#include <iostream>
using namespace std;

int main()
{
	int a;
	do
	{
		cout << "Nhap so nguyen duong le 'a', hinh duoc in ra co do lon bang (axa): ";
		cin >> a;
	} while (a <= 0 || a % 2 == 0);

	int n = a / 2 + 1;

	// Ve chu X
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
			cout << "  ";
		for (int j = i; j <= n; j++)
		{
			if (j == i || j == n)
				cout << "*   ";
			else
				cout << "    ";
		}
		cout << endl;
	}

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= n - i; j++)
		{
			cout << "  ";
		}
		for (int j = 1; j <= i; j++)
		{
			if (j == 1 || j == i)
				cout << "*   ";
			else
				cout << "    ";
		}
		cout << endl;
	}

	cout << endl;
	//Ve hinh thoi
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n - i; j++)
		{
			cout << "  ";
		}
		for (int j = 1; j <= i; j++)
		{
			if (j == 1 || j == i)
				cout << "*   ";
			else
				cout << "    ";
		}
		cout << endl;
	}

	for (int i = 1; i <= n; i++)
	{
		if (i != 1)
		{
			for (int j = 1; j < i; j++)
				cout << "  ";
			for (int j = i; j <= n; j++)
			{
				if (j == i || j == n)
					cout << "*   ";
				else
					cout << "    ";
			}
			cout << endl;
		}
	}

	cout << endl;
	// Ve 2 hinh vuong long vao nhau
	// Nua tren
	for (int i = n; i >= 1; i--)
	{
		// Ve tam giac ben trai
		for (int j = i; j >= 1; j--)
		{
			if (i == n || j == 1 || j == i)
			{
				cout << "* ";
			}
			else
			{
				cout << "  ";
			}
		}
		// Tao khoang trong
		for (int j = 1; j <= ((2 * n) - 1) - (2 * i); j++)
		{
			cout << "  ";
		}
		// Ve tam giac ben phai
		for (int j = i; j >= 1; j--)
		{
			if (j == 1 || j == i || i == n)
			{
				if (i == n && j == 1)
					cout << "";
				else
					cout << "* ";
			}
			else
			{
				cout << "  ";
			}
		}

		cout << endl;
	}
	// Nua duoi
	for (int i = 1; i <= n; i++)
	{
		if (i != 1)
		{
			// Ve tam giac ben trai
			for (int j = 1; j <= i; j++)
			{
				if (i == n || j == 1 || j == i)
				{
					cout << "* ";
				}
				else
				{
					cout << "  ";
				}
			}
			// Tao khoang trong
			for (int j = 1; j <= ((2 * n) - 1) - (2 * i); j++)
			{
				cout << "  ";
			}
			// Ve tam giac ben phai
			for (int j = 1; j <= i; j++)
			{
				if (j == 1 || j == i || i == n)
				{
					if (i == n && j == 1)
						cout << "";
					else
						cout << "* ";
				}
				else
				{
					cout << "  ";
				}
			}
			cout << endl;
		}
	}
	return 0;
}