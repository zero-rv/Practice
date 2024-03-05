//#include <iostream>
//using namespace std;
//
//void nhapArr(int arr[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//}
//
//POINTER ARRAY
//void addElement(int* &arr, int& size, int new_value)
//{
//	//Create new array using pointer
//	int new_size = size + 1;
//	int* new_array = new int[new_size];
//	//Copy current array to new array
//	for (int i = 0; i < size; i++)
//	{
//		new_array[i] = arr[i];
//	}
//	//Add a new element to the last index of new array
//	new_array[new_size - 1] = new_value;
//	//Assign new array to current array
//	delete[] arr;
//	arr = new_array;
//	//Assign new size to current size
//	size = new_size;
//}
// 
// 
//int main()
//{
//	int x, a, b, m = 0, n = 0;
//	int cl[100], pr[100];
//	cout << "Nhap so du: ";
//	cin >> x;
//	cout << "Nhap so mon trong thuc don Classic: ";
//	cin >> a;
//	cout << "Nhap so mon trong thuc don Premium: ";
//	cin >> b;
//	cout << "Khoi tao gia tien cua tung mon trong thuc don Classic: ";
//	nhapArr(cl, a);
//	cout << "Khoi tao gia tien cua tung mon trong thuc don Premium: ";
//	nhapArr(pr, b);
//	m = cl[0];
//	n = pr[0];
//	for (int i = 0; i < a; i++)
//	{
//		for (int j = 0; j < b; j++)
//		{
//			if (((cl[i] + pr[j]) > (m + n)) && ((cl[i] + pr[j]) <= x))
//			{
//				m = cl[i];
//				n = pr[j];
//			}
//		}
//	}
//	if (m + n <= x)
//	{
//		cout << "Mon ban co the mua trong thuc don Classic: " << m << endl;
//		cout << "Mon ban co the mua trong thuc don Premium: " << n << endl;
//		cout << "So tien phai tra: " << m + n << endl;
//	}
//	else 
//	{
//		cout << -1 << endl;
//	}
//
//	return 0;
//}