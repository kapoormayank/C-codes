// Leetcode Problem 1051: Height Checker
#include<iostream>
using namespace std;

// Function to perform Count Sort and calculate the number of indices where the height differs
int CountSort(int arr[],int n){
    int max=arr[0];
    int min=arr[0];
    int arr1[n];
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<min){
            min=arr[i];
        }
    }
    int count[max-min+1]={0};
    for(int i=0;i<n;i++){
        count[arr[i]-min]++;
    }
    int k=sizeof(count)/sizeof(count[0]);
    int index=0;
    for(int i=0;i<k;i++){
        while(count[i]>0){
            arr1[index]=i+min;
            index++;
            count[i]--;
        }
    }
    int total=0;
    for(int i=0;i<n;i++){
        if(arr[i]!=arr1[i]){
            total++;
        }
    }
    return total; // Placeholder return statement
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
    cout<<"Enter Elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Print An Array: ";
    printArray(arr,n);
    int result=CountSort(arr,n);
    cout<<"Number of indices where height differs: "<<result;
    return 0;
}

