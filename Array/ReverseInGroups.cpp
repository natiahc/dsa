/*
Reverse array in groups
Given an array arr[] of positive integers of size N. Reverse every sub-array of K group elements.

Explanation:
Testcase 1: Reversing groups in size k = 3, first group consists of elements 1, 2, 3. Reversing this group, we have elements in order as 3, 2, 1.
Testcase 2: Our array is 5 6 8 9. The value of k is 3. So we reverse it in groups of 3.  After reversing, it becomes 8 6 5 9.
Testcase 3: Our array is 5 6 8 9. The value of k is 7. After reversing, it becomes 9 8 6 5.
Testcase 4: Our array is 1 2 3 4 5 6 7 8. The value of k is 3. After reversing, it becomes 3 2 1 6 5 4 8 7.

*/

#include <iostream>
#include <vector>
#include <algorithm>

void ReverseInGroups(std::vector<int>& arr, int grpSize)
{
    for ( int i = 0; i < arr.size(); )
    {
        if(i+grpSize < arr.size())
        {
            std::reverse(arr.begin() + i, arr.begin()+i+grpSize);
            i = i + grpSize;
        }
        else
        {
            std::reverse(arr.begin() + i, arr.end());
            i = i + grpSize;
        }
    }
}

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    ReverseInGroups(v, 3);
    for (auto val : v)
        std::cout << val << " ";

    std::cout << std::endl;

    return EXIT_SUCCESS;
}