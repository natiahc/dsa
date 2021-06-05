#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>

int MaxNumInArray(const std::vector<int>& arr)
{
    std::vector<int>::const_iterator it = std::max_element(std::begin(arr), std::end(arr));
    return arr[std::distance(std::begin(arr), it)];
}

std::vector<int> minLeftArrIndexes(const std::vector<int>& arr)
{
    std::vector<int> v;
    std::stack<std::pair<int, int>> s;
    int pseudoIndex = -1;
    for(int i = 0; i < arr.size(); i++)
    {
       if (s.empty())
            v.push_back(pseudoIndex);
        else if (!s.empty() && s.top().second < arr[i])
            v.push_back(s.top().first);
        else if (!s.empty() && s.top().second >= arr[i])
        {
            while (!s.empty() && s.top().second >= arr[i])
                s.pop();

            if (s.empty())
                v.push_back(pseudoIndex);
            else
                v.push_back(s.top().first);
        }

        s.push({i, arr[i]});
    }

    return v;
}

std::vector<int> maxRightArrIndexes(const std::vector<int>& arr)
{
    std::vector<int> v;
    std::stack<std::pair<int, int>> s;
    int pseudoIndex = arr.size();
    for(int i = arr.size() - 1; i >= 0; i--)
    {
        if (s.empty())
            v.push_back(pseudoIndex);
        else if (!s.empty() && s.top().second < arr[i])
            v.push_back(s.top().first);
        else if (!s.empty() && s.top().second >= arr[i])
        {
            while (!s.empty() && s.top().second >= arr[i])
                s.pop();

            if (s.empty())
                v.push_back(pseudoIndex);
            else
                v.push_back(s.top().first);
        }

        s.push({i, arr[i]});
    }

    std::reverse(std::begin(v), std::end(v));

    return v;
}

int MaxAreaHistogram(const std::vector<int>& arr)
{
    std::vector<int> minLeftArrInds = minLeftArrIndexes(arr);
    std::vector<int> minRightArrInds = maxRightArrIndexes(arr);

    std::vector<int> widths;
    for(int i = 0; i < minLeftArrInds.size(); i++)
        widths.push_back(minRightArrInds[i] - minLeftArrInds[i] - 1);
 
    std::vector<int> areas;
    for(int i = 0; i < arr.size(); i++)
        areas.push_back(widths[i] * arr[i]);
 
    return MaxNumInArray(areas);
}

int MaxAreaRectBinMat(const std::vector<std::vector<int> >& arry2D)
{
    std::vector<int> maxAreahists;
    std::vector<int> arr1D(4);

    for(int i = 0; i < arry2D.size(); i++)
    {
        for (int j = 0; j<arry2D[i].size(); j++)
        {
            if(arry2D[i][j] == 0)
                arr1D[j] = 0;
            else
            {
                arr1D[j] = arr1D[j] + arry2D[i][j];
            }
        }
        
        maxAreahists.push_back(MaxAreaHistogram(arr1D));
    }

    return MaxNumInArray(maxAreahists);
}

int main()
{
    std::vector<std::vector<int>> arry2D = { { 0, 1, 1, 0 },
                                             { 1, 1, 1, 1 },
                                             { 1, 1, 1, 1 },
                                             { 1, 1, 0, 0 }
                                           };

    int maxAreaRect = MaxAreaRectBinMat(arry2D);
    std::cout << "Maximum Area of Rectangle in Binary Matrix is: " << maxAreaRect << std::endl;

    return 0;
}