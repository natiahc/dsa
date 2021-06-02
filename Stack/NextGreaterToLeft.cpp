#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

std::vector<int> NextGreaterToLeft(int arr[], int n)
{
    std::vector<int> v;
    std::stack<int> s;
    for (int i = 0; i<n; i++)
    {        
        if(s.size() == 0)
        {
            v.push_back(-1);
        }        
        else if(s.size() > 0 && s.top() > arr[i])
        {
            v.push_back(s.top());
        }
        else if(s.size() > 0 && s.top() <= arr[i])
        {
            while(s.size() > 0 && s.top() <= arr[i])
            {
                s.pop();
            }

            if(s.size() == 0)
            {
                v.push_back(-1);
            }
            else
            {
                v.push_back(s.top());
            }
        }

        s.push(arr[i]);
    }

    return v;
}

int main()
{
    int elems[4] = { 1, 3, 2, 4 };
    std::vector<int> nxtGretElems = NextGreaterToLeft(elems, 4);
    for (auto val : nxtGretElems)
    {
        std::cout << val << " ";
    }

    std::cout << std::endl;

    return EXIT_SUCCESS;
}