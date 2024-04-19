#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

void inputIntArr(int* &arr, int size);
void inputRandIntArr(int* &arr, int size);
void printArr(int* arr, int size);
bool hasCondition(int* arr, int size, bool(*condition)(int));
bool isCP(int n);
int  countCondition(int* arr, int size, bool(*condition)(int));
bool isSohoanthien(int n);
bool isNeg(int n);
bool isPos(int n);
bool isPrime(int n);
int* findIndex(int* arr, int size, bool(*condition)(int), int x); //x = 1: xuat hien dau tien. x = 0: xuat hien cuoi cung
int  findMin(int* arr, int size);
int* findIndex(int* arr, int size, int(*condition)(int*, int), int x); //x = 1: xuat hien dau tien. x = 0: xuat hien cuoi cung
void removeElement(int*& arr, int& size);
bool asc(int a, int b);
bool desc(int a, int b);
void sort(int* arr, int begin, int end, bool(*condition)(int, int));
void concat(int* &arrA, int &sizeA, int* arrB, int &sizeB);

int main()
{
	int size;
	cout << "Nhap so phan tu cua mang: ";
	cin >> size;
	int* arr = new int[size];
	//Nhap mang
	cout << "Nhap mang:\n";
	inputIntArr(arr, size);
	//Xuat mang
	printArr(arr, size);
	//Dem so CP
	cout << "\nTong so chinh phuong xuat hien trong mang: " << countCondition(arr, size, isCP);
	//So hoan thien
	if (hasCondition(arr, size, isSohoanthien))
		cout << "\nMang co so hoan thien.";
	else
		cout << "\nMang khong co so hoan thien.";
	//So am
	if (hasCondition(arr, size, isNeg))
		cout << "\nMang co so am.";
	else
		cout << "\nMang khong co so am.";
	//So duong
	if (hasCondition(arr, size, isPos))
		cout << "\nMang co so duong.";
	else
		cout << "\nMang khong co so duong.";
	//So nguyen to
	if (hasCondition(arr, size, isPrime))
		cout << "\nMang co so nguyen to.";
	else
		cout << "\nMang khong co so nguyen to.";
	//Dia chi so CP dau tien
	int* firstCP = findIndex(arr, size, isCP, 1);
	cout << "\nDia chi so CP dau tien trong mang: " << firstCP;
	//Dia chi so hoan thien cuoi cung
	int* lastSohoanthien = findIndex(arr, size, isSohoanthien, 0);
	cout << "\nDia chi so hoan thien cuoi cung trong mang: " << lastSohoanthien;
	//Dia chi so nho nhat dau tien
	int* firstMin = findIndex(arr, size, findMin, 1);
	cout << "\nDia chi so nho nhat dau tien trong mang: " << firstMin;
	//Dia chi so nho nhat cuoi cung
	int* lastMin = findIndex(arr, size, findMin, 0);
	cout << "\nDia chi so nho nhat cuoi cung trong mang: " << lastMin;
	//Sap xep
	cout << "\nMang sap xep giam dan: ";
	sort(arr, 0, size - 1, desc);
	printArr(arr, size);
	cout << "\nMang sap xep tang dan: ";
	sort(arr, 0, size - 1, asc);
	printArr(arr, size);
	cout << "\nMang sap xep nua dau tang dan, nua sau giam dan: ";
	sort(arr, 0, size / 2, asc);
	sort(arr, size / 2, size - 1, desc);
	printArr(arr, size);
	//Xoa 1 phan tu ra khoi mang
	removeElement(arr, size);
	cout << "\nMang sau khi xoa 1 phan tu: "; printArr(arr, size);
	//Tao mang ngau nhien n phan tu
	int sizeB;
	cout << "\nNhap so phan tu cho mang ngau nhien: ";
	cin >> sizeB;
	int* arrB = new int[sizeB];
	inputRandIntArr(arrB, sizeB);
	//Gop mang
	concat(arr, size, arrB, sizeB);
	cout << "Mang ngau nhien duoc tao: "; printArr(arrB, sizeB);
	cout << "\nMang sau khi gop: "; printArr(arr, size);
	//Gop mang va tang dan
	sort(arr, 0, size - 1, asc);
	cout << "\nMang sau khi gop va tang dan: "; printArr(arr, size);

	delete[] arr;
	delete[] arrB;
	arr = arrB = nullptr;
	return 0;
}

void inputIntArr(int* &arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
}

void inputRandIntArr(int*& arr, int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
}

void printArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

bool hasCondition(int* arr, int size, bool(*condition)(int))
{
	for (int i = 0; i < size; i++)
	{
		if (condition(arr[i])) return true;
	}
	return false;
}

bool isCP(int n)
{
	if (n < 1) return false;
	int r = sqrt(n);
	return n == r * r;
}

int countCondition(int* arr, int size, bool(*condition)(int))
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (condition(arr[i]))
			count++;
	}
	return count;
}

bool isSohoanthien(int n)
{
	if (n < 2) return false;
	int s = 1;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0) s += i;
	}
	if (s == n) return true;

	return false;
}

bool isNeg(int n)
{
	return n < 0;
}

bool isPos(int n)
{
	return n > 0;
}

bool isPrime(int n)
{
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}

int* findIndex(int* arr, int size, bool(*condition)(int), int x) //x = 1: xuat hien dau tien. x = 0: xuat hien cuoi cung
{
	if(x)
		for (int i = 0; i < size; i++)
		{
			if (condition(arr[i]))
			{
				return &arr[i];
			}	
		}
	else
		for (int i = size - 1; i >= 0; i--)
		{
			if (condition(arr[i]))
			{
				return &arr[i];
			}
		}
	return nullptr;
}

int findMin(int* arr, int size)
{
	int min = arr[0];
	for (int i = 1; i < size; i++)
	{
		min = min < arr[i] ? min : arr[i];
	}
	return min;
}

int* findIndex(int* arr, int size, int(*condition)(int*, int), int x) //x = 1: xuat hien dau tien. x = 0: xuat hien cuoi cung
{
	int value = condition(arr, size);
	if (x)
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == value)
			{
				return &arr[i];
			}
		}
	else
		for (int i = size - 1; i >= 0; i--)
		{
			if (arr[i] == value)
			{
				return &arr[i];
			}
		}
}

void removeElement(int* &arr, int& size)
{
	//Create new array using pointer
	int new_size = size - 1;
	int* new_array = new int[new_size];
	//Copy current array to new array
	for (int i = 0; i < new_size; i++)
	{
		new_array[i] = arr[i];
	}
	//Assign new array to current array
	delete[] arr;
	arr = new_array;
	//Assign new size to current size
	size = new_size;
}

bool asc(int a, int b)
{
	return a > b;
}

bool desc(int a, int b)
{
	return a < b;
}

void sort(int* arr, int begin, int end, bool(*condition)(int, int))
{
	for (int i = begin; i < end; i++)
	{
		for(int j = i + 1; j <= end; j++)
		if (condition(arr[i], arr[j]))
		{
			int tmp = arr[j];
			arr[j] = arr[i];
			arr[i] = tmp;
		}
	}
}

void concat(int* &arrA, int &sizeA, int* arrB, int &sizeB)
{
	int i = 0, count = 0;
	int new_size = sizeA + sizeB;
	int* new_arr = new int[new_size];
	while (count < new_size)
	{
		while (count < sizeA)
			new_arr[count++] = arrA[i++];
		i = 0;
		while (count < new_size)
			new_arr[count++] = arrB[i++];
	}
	delete[] arrA;
	arrA = new_arr;
	sizeA = new_size;
}