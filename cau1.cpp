#include <iostream>
#include <math.h>
using namespace std;

void inputInt(float& a, float& b, float& c);
void tinhPt(float& a, float& b, float& c);

int main()
{
	float a, b, c;
	inputInt(a, b, c);
	tinhPt(a, b, c);
	return 0;
}

void inputInt(float& a, float& b, float& c)
{
	cout << "Nhap lan luot he so a, b, c cho phuong trinh bac 2 (ax^2 + bx + c = 0):\n";
	cin >> a >> b >> c;
}

void tinhPt(float& a, float& b, float& c)
{
	float x;
	if (a == 0)
	{
		x = -c / b;
		cout << "Phuong trinh co nghiem duy nhat x = " << x << endl;
		return;
	}
	int delta = (b * b) - (4 * a * c);
	if (delta < 0)
	{
		cout << "Phuong trinh vo nghiem!" << endl;
		return;
	}
	if (delta == 0)
	{
		x = -b / (2 * a);
		cout << "Phuong trinh co nghiem kep x = " << x << endl;
		return;
	}
	cout << "Phuong trinh co 2 nghiem phan biet ";
	x = (-b + sqrt(delta)) / (2 * a);
	cout << "x1 = " << x << ", ";
	x = (-b - sqrt(delta)) / (2 * a);
	cout << "x2 = " << x;
}
