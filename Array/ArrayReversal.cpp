#include <iostream>

void ReverseArray(int arr[], int n)
{
    for (int i = 0; i < n/2; i++)
        std::swap(arr[i], arr[(n-1)-i]);
}

int main()
{
    int arr[7] = {3, 4, 7, 9, 2, 1, 5};
    ReverseArray(arr, 7);
    for (int i = 0; i < 7; i++)
        std::cout << arr[i] << " ";
    
    std::cout << std::endl;

    return 0;
}