#include <iostream>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "sorting.h"
#include "mergeSort.h"
#include "APVECTOR.H"

using namespace std;

//Function for selection sort
void selectionSort(apvector<int> &v, ALLEGRO_FONT *font, ALLEGRO_FONT *font2, int &comparisons, int &moves){

    //store the size of the array in another variable n
    int n = v.length();

    //declare a variable for the index of the minimum value of the list
    int minIndex = 0;

    for (int i = 0; i < n-1; i++){
        //assign the minimum index to the index of the current element
        minIndex = i;

        //move through the list and find the smallest element
        for (int j = i+1; j < n; j++){
            //increment the number of comparisons
            comparisons++;
            //assign the minimum index to the index of the smallest element
            if(v[j] < v[minIndex]){
                minIndex = j;
            }
        }
        //make a swap between the smallest element and the current element that is being processed
        Swap(v[i], v[minIndex]);
        moves++;
        //draw the updated array
        draw(v, font, font2, comparisons, moves);
        //print the updated array to the console
        system("CLS");
        for (int i = 0; i < v.length(); i++)
            cout << v[i] << "\t";
    }
}
