#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

void b6();
void b8();

int main()
{
	_back:
	cout << "Switch: ";
	int x;
	cin >> x;
	switch (x)
	{
	case 6:
		b6();
		goto _back;
	case 8:
		b8();
		goto _back;
	case 0:
		break;
	default:
		goto _back;
	}
	return 0;
}

int reverse(int n, int reverse_n = 0)
{
	if (n == 0) return reverse_n;

	return reverse(n / 10, (reverse_n * 10) + (n % 10));
}

void b6()
{
	int n;
	do
	{
		cout << "n = ";
		cin >> n;
	} while (n <= 0);
	int result = reverse(n);
	cout << "So dao nguoc: " << result << endl;
}

void dec_to_bin(int x)
{
	if (x < 2)
		cout << x;
	else
	{
		dec_to_bin(x / 2);
		cout << x % 2;
	}
}

void b8()
{
	int n;
	do
	{
		cout << "n = ";
		cin >> n;
	} while (n <= 0);
	cout << "So nhi phan: "; dec_to_bin(n);
	cout << endl;
}