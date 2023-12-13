#include <iostream>
using namespace std;

void nhapArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}

int main()
{
	int x, a, b, m = 0, n = 0;
	int cl[100], pr[100];
	cout << "Nhap so du: ";
	cin >> x;
	cout << "Nhap so mon trong thuc don Classic: ";
	cin >> a;
	cout << "Nhap so mon trong thuc don Premium: ";
	cin >> b;
	cout << "Khoi tao gia tien cua tung mon trong thuc don Classic: ";
	nhapArr(cl, a);
	cout << "Khoi tao gia tien cua tung mon trong thuc don Premium: ";
	nhapArr(pr, b);
	m = cl[0];
	n = pr[0];
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			if ((cl[i] + pr[j]) > (m + n))
			{
				if ((cl[i] + pr[j]) <= x)
				{
					m = cl[i];
					n = pr[j];
				}
			}
		}
	}
	if (m + n <= x)
	{
		cout << "Mon ban co the mua trong thuc don Classic: " << m << endl;
		cout << "Mon ban co the mua trong thuc don Premium: " << n << endl;
		cout << "So tien phai tra: " << m + n << endl;
	}
	else 
	{
		cout << -1 << endl;
	}

	return 0;
}