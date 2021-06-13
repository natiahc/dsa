/*

Input : arr[] = {10, 12, 13, 15, 10} 
Output : 0
Explanation: |10 - 10| = 0 which is the 
minimum possible.

Input : arr[] = {10, 20, 30, 40}
Output : 10
Explanation: |10 - 20| = 10 which is the 
minimum, 2 3 or 3 4 can be the answers also.  


*/
#include <iostream>

int MinAdjacentDiffInCirArr(int arr[], int arr_size)
{
    // Your code here
    
    int res = abs(arr[0]-arr[1]); //Store difference of arr[0], arr[1]
    for(int i=2; i<arr_size; i++)
        res = std::min(res, abs(arr[i]-arr[i-1]));
    
    res = std::min(res, abs(arr[0] - arr[arr_size-1]));
    
    return res;
}

int main()
{
    int arr[7] = {16, 17, 18,  19, 21, 23, 4};
    int minAdjDiffCirArr = MinAdjacentDiffInCirArr(arr, 7);
    std::cout << "minimum Adjacent Difference in Circular Array: " << minAdjDiffCirArr << std::endl;
    return 0;
}