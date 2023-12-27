#include <iostream>

using namespace std;

//This function swaps the elements of the array whenever needed
void Swap(int &n1, int &n2){
    //declare a temporary variable
    int temp;

    //swap the numbers
    temp = n1;
    n1 = n2;
    n2 = temp;
}
