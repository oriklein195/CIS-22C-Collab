#include <iostream>
#include <fstream>

const int SORT_MAX_SIZE = 32;

using namespace std;
/*
printArray
- prints an array of integers.
- both to standard io and file io
**/
void printArray(int arr[], int length, ofstream& outfile){
	for (int i = 0; i < length; i++){
		cout << arr[i] << ", ";
		outfile << arr[i] << ", ";
	}
	cout << endl;
	outfile << endl;
	return;
};
/*
quickSort
- sorts an algorithm with the quicksort logic
**/
void quickSort(int arr[], int left, int right, int size, ofstream& outfile){
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
			printArray(arr, size, outfile);
		}
	}
	if (left < j)
		quickSort(arr, left, j, size, outfile);
	if (i < right)
		quickSort(arr, i, right, size, outfile);
	return;
};
/*
insertSort
- sorts an array with the insert sort logic
**/
void insertSort(int arr[], int length, ofstream& outfile){
	int i, j, tmp;
	for (i = 1; i < length; i++){
		j = i;
		while (arr[j] < arr[j - 1]){
			tmp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = tmp;
			j--;
		}
		printArray(arr, length, outfile);
	}
	return;
};
/*
merge
- sorts the seperated sections of the array
- merges the sections again into larger array
**/
void merge(int arr[], int size, int low, int mid, int high){
	int i, j, k, c[SORT_MAX_SIZE];
	i = low;
	k = low;
	j = mid + 1;
	while (i <= mid && j <= high){
		if (arr[i] < arr[j]){
			c[k] = arr[i];
			k++;
			i++;
		}
		else{
			c[k] = arr[j];
			k++;
			j++;
		}
	}
	while (i <= mid){
		c[k] = arr[i];
		i++;
		k++;
	}
	while (j <= high){
		c[k] = arr[j];
		k++;
		j++;
	}
	for (i = low; i < k; i++){
		arr[i] = c[i];
	}
};
/*
mergeSort
- seperates an array into seperate sections
- calls function to sort and merge together the array
**/
void mergeSort(int arr[],int size, int low, int high, ofstream& outfile){
	if (low < high){
		int mid = (high + low) / 2;
		mergeSort(arr, size, low, mid, outfile);
		mergeSort(arr, size, mid + 1, high, outfile);
		merge(arr, size, low, mid, high);
		printArray(arr, size, outfile);
	}
	return;
};
/*
main
- creates two dynamic sized arrays
- one will be populated by the users input directly
- the other will be popluted by the same data three times
**/
int main(){
	int userSize = 0, h = 0;
	ofstream outfile;
	outfile.open("SortedArrays.txt");

	cout << "please enter the number of elements you would like" << endl;
	do {
		cin >> userSize;
		if (userSize > SORT_MAX_SIZE)
			cout << "too many elements try again please" << endl;
	} while (userSize > SORT_MAX_SIZE);

	int* userArr = new int[userSize];
	int* temp = new int[userSize];

	for (int i = 0; i < userSize; i++){
		cout << "input a number for element number " << i + 1 << " in the array" << endl;
		cin >> userArr[i];
	}

	outfile << "Now printing unsorted" << endl;
	cout << "Now printing unsorted" << endl;
	printArray(userArr, userSize, outfile);

	while (h < 3){
		for (int g = 0; g < userSize; g++){
			temp[g] = userArr[g];
		}
		if (h == 0){
			cout << "Now sorting with insertion sort" << endl;
			outfile << "Now sorting with insertion sort" << endl;
			insertSort(temp, userSize, outfile);
		}
		if (h == 1){
			cout << "Now sorting with quick sort" << endl;
			outfile << "Now sorting with quick sort" << endl;
			quickSort(temp, 0, userSize - 1, userSize, outfile);
		}
		if (h == 2){
			cout << "Now sorting with merge sort" << endl;
			outfile << "Now sorting with merge sort" << endl;
			mergeSort(temp, userSize, 0, userSize - 1, outfile);
		}
		h++;
	}

	
	delete userArr, temp;
	outfile.close();

	system("pause");
	return 0;
}
