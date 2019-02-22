//recursion to calculate factorial
#include <bits/stdc++.h>

using namespace std;

int factorial(int n) {

    if (n <=1) return 1;
    //Here is the special sauce!
    else return n*factorial(n-1);
}

int main()
{
    int n;
    cout << "Enter a number to find the factorial." <<endl;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = factorial(n);
    //print out the result....is it right?
    cout << "The factorial of ["<<n<<"] is "<<result << "\n";


    return 0;
}
