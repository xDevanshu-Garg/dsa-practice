//READ this document
//https://www.geeksforgeeks.org/macros-and-its-types-in-c-cpp/
#include <iostream>
using namespace std;

#define PI 3.14 //No need of '=' and ';' 
// 1) It is better then a variable because no user can change this value by accident.
// 2) #define is a preprocessor directive, which means it's processed before the actual compilation of your code. The replaced values are directly embedded into the code, so there's no need to allocate additional memory for the constant itself wheras an variable would take memory at compile time.

int main()
{
    // Macro: A peice of code in program whoes value is replaced by macro

    cout<< PI;

    return 0;
}