#include<iostream>
using namespace std;
int main(){
     
    // //how to get out of switch case inside an infinite loop 

    // int count = 0;
    // while (1)
    // {
    //     switch (1){
    //         case 1: cout<< "Loop iteration: "<< ++count <<endl;
    //         if (count == 100)
    //         {
    //             exit(0); // indicates a succesfull termination of the program if we want to see how a program is terminated exit is used like exit with 5 if this test case runs.
    //         }
            
    //         }
        
    // }

    int num = 2;
    switch(num){
            while(1){
            case 1: cout<<"This will not execute" <<endl;
            case 2: cout<<"This will execute" <<endl; 
            continue;
            case 3: cout<<"This will not execute" <<endl;
        }

    }
    
}