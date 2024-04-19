#include <iostream>
#include <math.h>
using namespace std;

bool defaultCondition(int n);
bool isPrime(int n);
bool isOdd(int n);
bool isEven(int n);
void inputArr(int** &arr, int r, int c);
void printArr(int* arr, int size);
void print_2D_Arr(int** arr, int r, int c, bool(*condition)(int));
int  sumArr(int** arr, int r, int c);
int* findIndex(int** arr, int r, int c, bool(*condition)(int));
int* specific_RC_Arr(int** arr, int r, int c, int &new_size, bool(*condition)(int), char rc);
int* change_per_index(int* arr, int size, int change_value);

int main()
{
	int r, c;
	cout << "Nhap so dong: "; cin >> r;
	cout << "Nhap so cot: "; cin >> c;
	int** arr = new int* [r];
	for (int i = 0; i < r; i++)
		arr[i] = new int[c];
	//Nhap mang
	cout << "Nhap mang:\n";
	inputArr(arr, r, c);
	//Xuat mang
	cout << "Mang 2 chieu duoc tao:\n"; print_2D_Arr(arr, r, c, defaultCondition);
	//Tong mang
	int sum = sumArr(arr, r, c);
	cout << "Tong gia tri mang 2 chieu: " << sum;
	//Xuat mang co so nguyen to
	cout << "\nCac so nguyen to trong mang:\n"; print_2D_Arr(arr, r, c, isPrime);
	//Dia chi pt le dau tien
	int* firstOdd = findIndex(arr, r, c, isOdd);
	if (firstOdd)
		cout << "Dia chi phan tu le dau tien trong mang: " << firstOdd;
	else
		cout << "Mang khong co phan tu le.";
	//Tra ve mang voi dong/cot cu the
	cout << "\nNhap so cot, tra ve mang cac phan tu tren cot:\n";
	int sizeC = 0;
	int* specificC = specific_RC_Arr(arr, r, c, sizeC, defaultCondition, 'c');
	cout << "Cac phan tu tren cot da nhap: "; printArr(specificC, sizeC);

	cout << "\nNhap so dong, tra ve mang cac phan tu tren dong:\n";
	int sizeR = 0;
	int* specificR = specific_RC_Arr(arr, r, c, sizeR, defaultCondition, 'r');
	cout << "Cac phan tu tren dong da nhap: "; printArr(specificR, sizeR);
	
	cout << "\nNhap so cot, tra ve mang cac phan tu la so chan tren cot:\n";
	int sizeC_even = 0;
	int* specificC_even = specific_RC_Arr(arr, r, c, sizeC_even, isEven, 'c');
	if (specificC_even)
	{
		cout << "Cac phan tu la so chan tren cot da nhap: "; printArr(specificC_even, sizeC_even);
	}
	else
		cout << "Cot da nhap khong co so chan.";
	
	cout << "\nNhap so cot, tra ve mang cac phan tu tren cot giam di 1:\n";
	int sizeC_change = 0, change_value = -1;
	int* specificC_change = change_per_index(specific_RC_Arr(arr, r, c, sizeC_change, defaultCondition, 'c'), sizeC_change, change_value);
	cout << "Cac phan tu : "; printArr(specificC_change, sizeC_change);
	//Giai phong
	for (int i = 0; i < r; i++)
		delete[] arr[i];
	delete[] arr;
	arr = nullptr;
	return 0;
}

bool defaultCondition(int n) { return true; };

bool isPrime(int n)
{
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}

bool isOdd(int n)
{
	return n % 2 != 0;
}

bool isEven(int n)
{
	return n % 2 == 0;
}

void inputArr(int** &arr, int r, int c)
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> *(*(arr + i) + j);
}

void printArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << "  ";
}

void print_2D_Arr(int** arr, int r, int c, bool(*condition)(int))
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			if(condition(*(*(arr + i) + j)))
				cout << *(*(arr + i) + j) << "  ";
		cout << endl;
	}
}

int sumArr(int** arr, int r, int c)
{
	int result = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			result += *(*(arr + i) + j);
	return result;
}

int* findIndex(int** arr, int r,int c, bool(*condition)(int))
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			if (condition(arr[i][j]))
				return &arr[i][j];
	}
	return nullptr;
}

int* specific_RC_Arr(int** arr, int r, int c, int &new_size, bool(*condition)(int), char rc)
{
	int specific, index = 0, count = 0;
	int* result = new int[1] {0};
	if (rc == 'r')
	{
		do
		{
			cout << "Nhap so dong can lay tu 1 den " << r << ": ";
			cin >> specific;
		} while (specific < 1 || specific > r);
		specific--;

		for (int j = 0; j < c; j++)
			if (condition(arr[specific][j]))
				new_size++;

		delete[] result;
		result = new int[new_size] {0};

		for (int j = 0; j < c; j++)
		{
			if (condition(arr[specific][j]))
			{
				result[index++] = arr[specific][j];
				count++;
			}
		}
	}
	if (rc == 'c')
	{
		do
		{
			cout << "Nhap so cot can lay tu 1 den " << c << ": ";
			cin >> specific;
		} while (specific < 1 || specific > c);
		specific--;

		for (int i = 0; i < r; i++)
			if (condition(arr[i][specific]))
				new_size++;

		delete[] result;
		result = new int[new_size] {0};

		for (int i = 0; i < r; i++)
		{
			if (condition(arr[i][specific]))
			{
				result[index++] = arr[i][specific];
				count++;
			}
		}
	}

	if (count > 0)
		return result;
	else
	{
		delete[] result;
		return nullptr;
	}
}

int* change_per_index(int* arr, int size, int change_value)
{
	int* new_arr = new int[size];
	for (int i = 0; i < size; i++)
		new_arr[i] = arr[i] + change_value;
	return new_arr;
}



