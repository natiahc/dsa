#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

std::vector<int> StockSpan(int arr[], int n)
{
    std::stack<std::pair<int, int>> indexValueStack;
    std::vector<int> v;
    for(int i = 0; i <= n-1; i++)
    {
        if(indexValueStack.empty())
        {
            v.push_back(-1);
        }
        else if (!indexValueStack.empty() && indexValueStack.top().second > arr[i])
        {
            v.push_back(indexValueStack.top().first);
        }
        else if (!indexValueStack.empty() && indexValueStack.top().second <= arr[i])
        {
            while (!indexValueStack.empty() && indexValueStack.top().second <= arr[i])
            {
                indexValueStack.pop();
            }

            if(indexValueStack.empty())
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(indexValueStack.top().first);
            }
        }

        indexValueStack.push({i, arr[i]});
    }

    std::vector<int> lst;
    for (int i = 0; i < v.size(); i++)
    {
        lst.push_back(i - v[i]);
    }

    return lst;
}

int main()
{
    int elems[7] = { 100, 80, 60, 70, 60, 75, 85 };
    std::vector<int> lst = StockSpan(elems, 7);
    for (auto val : lst)
    {
        std::cout << val << " ";
    }

    std::cout << std::endl;

    return EXIT_SUCCESS;
}