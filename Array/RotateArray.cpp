/*

Rotate Array
Given an unsorted array arr[] of size N, rotate it by D elements (counter-clockwise). 

Explanation :
Testcase 1: 1 2 3 4 5  when rotated by 2 elements, it becomes 3 4 5 1 2.
Testcase 2: 2 4 6 8 10 12 14 16 18 20  when rotated by 3 elements, it becomes 8 10 12 14 16 18 20 2 4 6.

*/

#include <iostream>
#include <vector>
#include <algorithm>

void RotateArray(std::vector<int>& arr, int rotateBy)
{
    // rotate D elements
    std::reverse(arr.begin(), arr.begin() + rotateBy);

    // rotate N-D elements
    std::reverse(arr.begin() + rotateBy, arr.end());

    // rotate all elements
    std::reverse(arr.begin(), arr.end());
}

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    RotateArray(v, 3);
    for (auto val : v)
        std::cout << val << " ";

    std::cout << std::endl;

    return EXIT_SUCCESS;
}