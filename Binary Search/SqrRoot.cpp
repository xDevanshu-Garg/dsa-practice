#include <iostream>
using namespace std;

int sqrRoot(float x)
{
    // //This has time complexity O(√n) but we need O(logn) so we'll not use this
    // if (x < 0)
    // {
    //     return -1;
    // }
    // float a = 1, b = 1;
    // while (a != x)
    // {
    //     if ((x / a) == a)
    //     {
    //         return a;
    //     }
    //     else if ((x / a) > a)
    //     {
    //         b = a;
    //         a *= 2;
    //     }
    //     else
    //     {
    //         a = (a + b) / 2;
    //     }
    // }
    // return -1;
    float low = 0, high = x, ans;
    while (low <= high)
    {
        float mid = (low + high) / 2;
        if ((mid * mid) == x)
        {
            return mid;
        }
        else if ((mid * mid) > x)
        {
            high = mid - 1;
        }
        else
        {
            ans = mid;
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    float x;
    cout << "Enter the element of which you wanna find sqr root: ";
    cin >> x;

    cout << sqrRoot(x);

    return 0;
}