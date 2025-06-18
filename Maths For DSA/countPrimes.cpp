// https://leetcode.com/problems/count-primes/

#include <iostream>
#include <vector>
using namespace std;

bool checkPrime(int n){
    if (n<=1)
    {
        return false;
    }
    for (int i = 2; i < n; i++)
    {
        if (n%i == 0)
        {
            return false;
        }
    }
    return true;
}

int countPrimes(int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (checkPrime(i))
        {
            count++;
        }
    }
    return count;
}

// This will result in TLE so We're going to use Sieve of Eratosthenes Algorithm

// int countPrimes(int n)
// {
//     int count = 0;
//     // for starting numbers
//     if (n <= 1)
//     {
//         return 0;
//     }

//     // Now making a vector with size n
//     vector<bool> prime(n+1, true);  //1 based indexing because 0 pr khud 0 h 1 pr 1 h 2 pr 2 h.

//     // now applying Sieve of Eratosthenes

//     for (int i = 2; i < n; i++)
//     {
//         if (prime[i])
//         {
//             count++;

//             for (int j = 2*i; j < n; j+=i)
//             {
//                 prime[j] = false;
//             }
//         }
//     }
//     return count;
// }

int main()
{
    int n;
    cout << "Enter a number to check the number of prime numbers that are strictly less than n: ";
    cin >> n;

    cout << "There are " << countPrimes(n) << " prime numbers less than " << n;

    return 0;
}