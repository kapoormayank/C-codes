// Quick Sort Algorithm in C++
#include<iostream>
using namespace std;

// Function to partiton the array
int partiton(int arr[],int low,int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(arr[j]<=pivot){
            i++;
            int temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }
    i++;
    int temp=arr[i];
    arr[i]=arr[high];
    arr[high]=temp;
    return i;
}

// Function to perform the Quick Sort Algorithm
void QuickSort(int arr[],int low,int high){
    if(low<high){
        int index=partiton(arr,low,high);
        QuickSort(arr, low, index-1); // For left subarray
        QuickSort(arr, index+1, high); // For right subarray
    }
}

// Function to print an array
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n"<<endl;
}

// Main function
int main(){
    cout<<"Enter Number of terms: ";
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Original Array: ";
    // Function to print the array
    printArray(arr,n);
    QuickSort(arr,0,n-1);
    cout<<"After Sorting An Array: ";
    // Function to print the array
    printArray(arr,n);
    return 0;
}

