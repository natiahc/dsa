#include <iostream>
#include <vector>
#include <numeric>

int GetTrappedRainWaterInBlocks(int arr[], int n)
{
    std::vector<int> maxRightArr(n);
    maxRightArr[0] = arr[0];
    for(int i = 1; i < n; i++)
        maxRightArr[i] = std::max(arr[i], maxRightArr[i-1]);

    std::vector<int> maxLeftArr(n);
    maxLeftArr[n-1] = arr[n-1];
    for(int i = n-2; i >= 0; i--)
        maxLeftArr[i] = std::max(arr[i], maxLeftArr[i+1]);

    std::vector<int> trappedArr(n);
    for(int i = 0; i < n; i++)
        trappedArr[i] = std::min(maxRightArr[i], maxLeftArr[i]) - arr[i];

    return std::accumulate(trappedArr.begin(), trappedArr.end(), 0);
}

int main()
{
    int elems[7] = { 3, 0, 0, 2, 0, 4 };
    int maxArea = GetTrappedRainWaterInBlocks(elems, 6);
    std::cout << maxArea << std::endl;

    return EXIT_SUCCESS;
}