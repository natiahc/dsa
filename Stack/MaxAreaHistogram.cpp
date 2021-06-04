#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

std::vector<int> nrstSmllstLeftIndex(int arr[], int n)
{
    std::stack<std::pair<int, int>> indexValueStack;
    std::vector<int> v;
    int pseudoIndex = -1;
    for(int i = 0; i <= n-1; i++)
    {
        if(indexValueStack.empty())
        {
            v.push_back(pseudoIndex);
        }
        else if (!indexValueStack.empty() && indexValueStack.top().second < arr[i])
        {
            v.push_back(indexValueStack.top().first);
        }
        else if (!indexValueStack.empty() && indexValueStack.top().second >= arr[i])
        {
            while (!indexValueStack.empty() && indexValueStack.top().second >= arr[i])
            {
                indexValueStack.pop();
            }

            if(indexValueStack.empty())
            {
                v.push_back(pseudoIndex);
            }
            else
            {
                v.push_back(indexValueStack.top().first);
            }
        }

        indexValueStack.push({i, arr[i]});
    }

    return v;
}

std::vector<int> nrstSmllstRightIndex(int arr[], int n)
{
    std::stack<std::pair<int, int>> indexValueStack;
    std::vector<int> v;
    int pseudoIndex = n;
    for(int i = n-1; i >= 0; i--)
    {
        if(indexValueStack.empty())
        {
            v.push_back(pseudoIndex);
        }
        else if (!indexValueStack.empty() && indexValueStack.top().second < arr[i])
        {
            v.push_back(indexValueStack.top().first);
        }
        else if (!indexValueStack.empty() && indexValueStack.top().second >= arr[i])
        {
            while (!indexValueStack.empty() && indexValueStack.top().second >= arr[i])
            {
                indexValueStack.pop();
            }

            if(indexValueStack.empty())
            {
                v.push_back(pseudoIndex);
            }
            else
            {
                v.push_back(indexValueStack.top().first);
            }
        }

        indexValueStack.push({i, arr[i]});
    }

    std::reverse(std::begin(v), std::end(v));

    return v;    
}

int MaxAreaHistogram(int arr[], int n)
{
    std::vector<int> smllLeftIndxs = nrstSmllstLeftIndex(arr, n);
    std::vector<int> smllRghtIndxs = nrstSmllstRightIndex(arr, n);
    std::vector<int> widths;
    std::cout << "widths\n";
    for(int i = 0; i < n; i++)
    {
        int width = smllRghtIndxs[i] - smllLeftIndxs[i] -1;
        widths.push_back(width);
        std::cout << width << " ";
    }

    std::cout << std::endl;

    std::vector<int> areas;
    std::cout << "areas\n";
    for(int i = 0; i < n; i++)
    {
        int area = widths[i] * arr[i];
        areas.push_back(area);  
        std::cout << area << " ";
    }

    std::cout << std::endl;

    std::vector<int>::iterator it = std::max_element(std::begin(areas), std::end(areas));
    int maxIndex = std::distance(std::begin(areas), it);

    return areas[maxIndex];
}

int main()
{
    int elems[7] = { 6, 2, 5, 4, 5, 1, 6 };
    int maxArea = MaxAreaHistogram(elems, 7);
    std::cout << maxArea << std::endl;

    return EXIT_SUCCESS;
}