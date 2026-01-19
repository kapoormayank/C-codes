// LeetCode Problem 912: Sort an Array using Merge Sort
#include<iostream>
using namespace std;

// Function to merge two halves
void merge(int arr[], int low, int mid, int high) {
    int p=mid-low+1;
    int q=high-mid;
    int left[p];
    int right[q];
    // Copy the data to temporary arrays left[] and right[]
    for(int i=0;i<p;i++){
        left[i]=arr[low+i];
    }
    for(int j=0;j<q;j++){
        right[j]=arr[mid+1+j];
    }
    int i=low,j=0,k=0;
    while(j<p && k<q){
        if(left[j]<=right[k]){
            arr[i++]=left[j++];
        }else{
            arr[i++]=right[k++];
        }
    }
    while(j<p){
        arr[i++]=left[j++];
    }
    while(k<q){
        arr[i++]=right[k++];
    }
}

// Function to implement merge sort
void mergeSort(int arr[], int low, int high) {
    if(low<high){
        int mid=(low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// Main function
int main() {
    cout << "Enter number of terms: ";
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter Elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout<<"Print Array Elements: ";
    printArray(arr, n);
    // Call merge sort function here (to be implemented)
    mergeSort(arr, 0, n - 1);
    cout << "Sorted Array Elements: ";
    printArray(arr, n);
    cout << "\n";
    return 0;
}
