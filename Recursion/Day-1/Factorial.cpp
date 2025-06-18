//Here tail recursion is happening because return statmenet is at last if it was below base case and after RR there's proccesing then it's called head recursion.

#include <iostream>
using namespace std;

int Factorial(int n){
    
    //Base Case. 
    if (n == 0) return 1; //It is manditory because it'll act as our stopping point. Return statmenet is also manitory in base case.
    
    return n * Factorial(n-1); //This is called recurrence relation. f(n) = n * f(n-1)
}

int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<< Factorial(n);

    return 0;
}