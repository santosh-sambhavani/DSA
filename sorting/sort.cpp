#include <iostream>
#include <vector>
#include <limits.h>
#include <cmath>
using namespace std;

void printVector(vector<int>& arr, int n) {
    cout << "Sorted array is: ";
    for(int i = 0; i < n; i++) {
		cout<< arr[i]  << " ";
	}
	cout << "\n";
}

void selectionSort(vector<int>& v, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(v[i] > v[j])
                swap(v[i], v[j]);
        }
    }
}

void bubbleSort(vector<int>& v, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(v[j] > v[j+1]) 
                swap(v[j], v[j+1]);
        }
    }
}

void insertionSort(vector<int>& v, int n) {
    for(int i = 1; i < n; i++) {
        int temp = v[i];
        for(int j = i - 1; j >= 0; j--) {
            // cout << "\n i: " << i  << " j: " << j << " temp: " << temp;
            if(v[j] > temp) {
                // cout << " if ";
                v[j+1] = v[j];
            }
            else {
                // cout << " else ";
                v[j+1] = temp;
                break;
            }
            if (j == 0) 
                v[j] = temp;
        }
        // printVector(v, n);
    }
}

int main() {
	
	int k, n;
		
	cin >>n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++) {
		cin>>arr[i];
	}
// 	selectionSort(arr, n);
// 	bubbleSort(arr, n);
    insertionSort(arr, n);
    printVector(arr, n);
	return 0;
}



