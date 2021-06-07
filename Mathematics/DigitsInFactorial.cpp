/*
Digits In Factorial
Given an integer N. The task is to find the number of digits that appear in its factorial, where factorial is defined as, factorial(n) = 1*2*3*4……..*N and factorial(0) = 1.

best sol.

We know,
log(a*b) = log(a) + log(b)

Therefore
log( n! ) = log(1*2*3....... * n) 
          = log(1) + log(2) + ........ +log(n)

Now, observe that the floor value of log base 
10 increased by 1, of any number, gives the
number of digits present in that number.

Hence, output would be : floor(log(n!)) + 1.

*/

#include <iostream>
#include <cmath>

int DigitsInfactorial(int n)
{
    double fact = 0.0;
    for (int i = 1; i <= n; i++)
        fact += std::log10(i);

    return fact + 1;
}

int main()
{
    int digitsInFact = DigitsInfactorial(120);
    std::cout << "Digits in factorial: " << digitsInFact << std::endl;
    return 0;
}