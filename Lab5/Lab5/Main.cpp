#include <iostream>
#include <fstream>

using namespace std;

void printArray(int arr[], int length){
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << endl;
	return;
};

void quickSort(int arr[], int left, int right){
	int i = left;
	int j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];
	while (i <= j){
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j){
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
			printArray(arr, (sizeof(arr) + 1));
		}
	}
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
	return;
};

void insertSort(int arr[], int length){
	int i, j, tmp;
	for (i = 1; i < length; i++){
		j = i;
		while (arr[j] < arr[j - 1]){
			tmp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = tmp;
			j--;
		}
		printArray(arr, length);
	}
	return;
};

int main(){
	const int SORT_MAX_SIZE = 32;
	int userSize = 0;
	cout << "please enter the number of elements you would like" << endl;
	do {
		cin >> userSize;
		if (userSize > SORT_MAX_SIZE)
			cout << "too many elements try again please" << endl;
	} while (userSize > SORT_MAX_SIZE);

	int* userArr = new int[userSize];

	for (int i = 0; i < userSize; i++){
		cout << "input a number for element number " << i + 1 << " in the array" << endl;
		cin >> userArr[i];
	}

	printArray(userArr, userSize);
	quickSort(userArr, 0, userSize - 1);

	delete userArr;

	system("pause");
	return 0;
}
