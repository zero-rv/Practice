#include <iostream>
#include <math.h>
using namespace std;

void inputDathuc(double* heso, int size);
void printDathuc(double* heso, int size);
double tinhDathuc(double* heso, int size, double x);
double* tong_2_Dathuc(double* heso1, int size1, double* heso2, int size2);
double* tich_2_Dathuc(double* heso1, int size1, double* heso2, int size2);

int main()
{
	int n1, n2;
	//Da thuc 1
	cout << "Nhap so bac cua da thuc 1: ";
	cin >> n1;
	int size1 = n1 + 1;
	double* heso1 = new double[size1];
	//Nhap he so da thuc bac n1
	cout << "Nhap he so cua da thuc 1:\n";
	inputDathuc(heso1, size1);
	//Da thuc 2
	cout << "Nhap so bac cua da thuc 2: ";
	cin >> n2;
	int size2 = n2 + 1;
	double* heso2 = new double[size2];
	//Nhap he so da thuc bac n2
	cout << "Nhap he so cua da thuc 2:\n";
	inputDathuc(heso2, size2);
	cout << "\nDa thuc 1 co dang: "; printDathuc(heso1, size1);
	cout << "\nDa thuc 2 co dang: "; printDathuc(heso2, size2);
	//Tinh da thuc
	int x1, x2;
	cout << "\nNhap gia tri x can tinh cua da thuc 1: ";
	cin >> x1;
	double result1 = tinhDathuc(heso1, size1, x1);
	cout << "Nhap gia tri x can tinh cua da thuc 2: ";
	cin >> x2;
	double result2 = tinhDathuc(heso2, size2, x2);
	cout << "\nGia tri cua da thuc 1 voi x = " << x1 << ": " << result1;
	cout << "\nGia tri cua da thuc 2 voi x = " << x2 << ": " << result2;
	//Tong 2 da thuc
	int tongSize = size1 > size2 ? size1 : size2;
	cout << "\n\nTong cua 2 da thuc co dang: "; printDathuc(tong_2_Dathuc(heso1, size1, heso2, size2), tongSize);
	//Tich 2 da thuc
	int tichSize = size1 + size2;
	cout << "\nTich cua 2 da thuc co dang: "; printDathuc(tich_2_Dathuc(heso1, size1, heso2, size2), tichSize);

	delete[] heso1;
	delete[] heso2;
	heso1 = heso2 = nullptr;
	return 0;
}

void inputDathuc(double* heso, int size)
{
	for (int i = size - 1; i >= 0; i--)
	{
		cout << "x^" << i << ": ";
		cin >> heso[i];
	}
}

void printDathuc(double* heso, int size)
{
	for (int i = size - 1; i >= 0; i--)
	{
		if (heso[i] != 0)
		{
			if (heso[i] > 0 && i != size - 1)
				cout << " + ";
			else
				cout << "  ";
			cout << heso[i];
			if (i > 0)
			{
				cout << "x";
				if (i > 1)
					cout << "^" << i;
				
			}
		}
	}
}

double tinhDathuc(double* heso, int size, double x)
{
	double result = 0;
	for (int i = 0; i < size; i++)
		result += heso[i] * pow(x, i);

	return result;
}

double* tong_2_Dathuc(double* heso1, int size1, double* heso2, int size2)
{
	int maxSize = size1 > size2 ? size1 : size2;
	double* result = new double[maxSize] {0};
	for (int i = 0; i < maxSize; i++)
	{
		double x1 = (i < size1) ? heso1[i] : 0;
		double x2 = (i < size2) ? heso2[i] : 0;
		result[i] = x1 + x2;
	}

	return result;
}

double* tich_2_Dathuc(double* heso1, int size1, double* heso2, int size2)
{
	int maxSize = size1 + size2;
	double* result = new double[maxSize] {0};
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			result[i + j] += heso1[i] * heso2[j];
		}
	}
	return result;
}

