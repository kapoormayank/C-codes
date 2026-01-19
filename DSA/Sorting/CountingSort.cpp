// Counting Sort Algorithm in C++
#include<iostream>
using namespace std;

// Function to perform Counting Sort Algorithm
void CountSort(int arr[],int n){
    int max=arr[0];
    int min=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<min){
            min=arr[i];
        }
    }
    int count[max-min+1]={0};
    int k=sizeof(count)/sizeof(count[0]);
    for(int i=0;i<n;i++){
        count[arr[i]-min]++;
    }
    int index=0;
    for(int i=0;i<k;i++){
        while(count[i]>0){
            arr[index]=i+min;
            index++;
            count[i]--;
        }
    }
}

// Function to print the array
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n"<<endl;
}

// Main function
int main(){
    cout<<"Enter number of terms: ";
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter Elemnts: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Original Array: ";
    // Function to print the array
    printArray(arr,n);
    CountSort(arr,n);
    cout<<"After Sorting An Array: ";
    // Function to print the array
    printArray(arr,n);
    return 0;
}
