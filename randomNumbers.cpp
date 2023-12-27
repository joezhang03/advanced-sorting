#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "sorting.h"
#include "mergeSort.h"
#include "APVECTOR.H"

using namespace std;

//This function assigns random integers to the list
void randomNumbers(apvector<int>&v, apvector<int> &v2){

    //seed random number generator
    srand(time(0));

    //generate random number for each element in the vector
    for (int i = 0; i < v.length(); i++){
        v[i] = rand() % MAX_SIZE + 1;
    }

    //store the generated list into another list that keeps the original values
    v2 = v;

    //store the random numbers in another function
    unSort(v, v2);
}

//This function resets the list after the list is sorted
//It reverts the list back to the original values before it was sorted
void unSort(apvector<int> &v, apvector<int> &v2){
    //copy the randomly generated numbers back into the array v
    v = v2;
}
