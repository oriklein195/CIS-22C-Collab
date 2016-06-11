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
	int userSize = 0, h = 0;			//variable for the number of element the user wants, and a counter.
	ofstream outfile;					//output object for file io
	outfile.open("SortedArrays.txt");	//opening the file for file io

	cout << "please enter the number of elements you would like" << endl;
	do {
		cin >> userSize;								//ask user how many elements they would like
		if (userSize > SORT_MAX_SIZE || userSize < 0)	//check to make sure the number of elements is not negative or lrger than max
			cout <<"invald try again please" << endl;	
	} while (userSize > SORT_MAX_SIZE || userSize < 0);	//loop until input is valid

	int* userArr = new int[userSize];					//dynamicly sized array that will have userinput
	int* temp = new int[userSize];						//temp array that will be sorted and then repopulated with unsorted data

	for (int i = 0; i < userSize; i++){
		cout << "input a number for element number " << i + 1 << " in the array" << endl;
		cin >> userArr[i];
	}													//loop for user input

	outfile << "Now printing unsorted" << endl;
	cout << "Now printing unsorted:" << endl;
	printArray(userArr, userSize, outfile);				//print the unsorted array to standard and file io

	while (h < 3){										//loop to sort temp and then replace temp with the unsorted data repeat twice for other algorithms
		for (int g = 0; g < userSize; g++){
			temp[g] = userArr[g];
		}												//loop to populate temp
		if (h == 0){
			cout << "Now sorting with insertion sort:" << endl;
			outfile << "Now sorting with insertion sort:" << endl;
			insertSort(temp, userSize, outfile);		//sort temp using the insertion logic
		}
		if (h == 1){
			cout << "Now sorting with quick sort:" << endl;
			outfile << "Now sorting with quick sort:" << endl;
			quickSort(temp, 0, userSize - 1, userSize, outfile);	//sort temp using the quick sort logic
		}
		if (h == 2){
			cout << "Now sorting with merge sort:" << endl;
			outfile << "Now sorting with merge sort:" << endl;
			mergeSort(temp, userSize, 0, userSize - 1, outfile);	//sort temp using the merge sort logic
		}
		h++;
	}

	
	delete userArr, temp;											//delete the objects in the heap
	outfile.close();												//close output file

	system("pause");
	return 0;
}
