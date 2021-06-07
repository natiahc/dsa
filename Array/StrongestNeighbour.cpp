/*
Strongest Neighbour
Given an array arr[] of N positive integers. The task is to find the maximum for every adjacent pairs in the array.
inp: 1 2 2 3 4 5
out: 2 2 3 4 5

inp: 5 5
out: 5
*/

#include <iostream>

// Function to find maximum of all subarray of size two
void MaximumAdjacent(int arr[], int n)
{
    for(int i = 0, j = 1; 
            i < n-1 && j < n; 
            i++, j++)
        std::cout << std::max(arr[i], arr[j]) << " ";
    
    std::cout << std::endl;
}

int main()
{
    int arr[6] = {3, 2, 2, 3, 4, 5};
    MaximumAdjacent(arr, 6);
    return 0;
}