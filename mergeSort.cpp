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

//constructor
MERGESORT::MERGESORT(){
    mergeList.resize(MAX_SIZE);
}

//sorts the list using merge sort
void MERGESORT::Sort(apvector<int> &v, ALLEGRO_FONT *font, ALLEGRO_FONT *font2, int &comparisons, int &moves){
    //store the length of the array in another integer variable
    int n = v.length();
    //resize the private array to the same size as the array that is being sorted
    mergeList.resize(n);
    //recursively sorts the array using merge sort
    recursiveSort(v, 0, n-1, font, font2, comparisons, moves);
    //clear the private array
    mergeList.resize(0);
}

//recursively sorts the array using merge sort
void MERGESORT::recursiveSort(apvector<int> &v, int i1, int i2, ALLEGRO_FONT *font, ALLEGRO_FONT *font2, int &comparisons, int &moves){
    //declare a variable for the middle index
    int m;

    //base case: when there is only one element in one half of a list
    //swaps the elements if the first is greater than the next element
    if (i2 - i1 <= 1){
        comparisons++;
        if ( v[i2] < v[i1]){
            Swap(v[i2], v[i1]);
            //increment number of moves after every swap
            moves++;
            //print the updated array in the console
            system("CLS");
            for (int i = 0; i < v.length(); i++)
                cout << v[i] << "\t";
            //draw the updated list
            draw(v, font, font2, comparisons, moves);
        }
    }
    //recursively sorts the list by merging
    else{
        m = (i1 + i2)/2;
        //sorts the first half of the list
        recursiveSort(v, i1, m, font, font2, comparisons, moves);
        //sorts the second half of the list
        recursiveSort(v, m + 1, i2, font, font2, comparisons, moves);
        //merges the two lists together
        Merge(v, i1, m, i2, font, font2, comparisons, moves);
    }
}

//merges the sorted segments of array v
//merge elements between i1 and m and between m+1 and i2 into one sorted segment between i1 to i2
//Note: every time a segment is merged, there are n moves when n elements are merged
void MERGESORT::Merge(apvector<int> &v, int i1, int m, int i2, ALLEGRO_FONT *font, ALLEGRO_FONT *font2, int &comparisons, int &moves){
    //declare variables
    int j1 = i1;
    int j2 = m + 1;

    //merge the 2 sorted segments of array v into the private array
    for (int j = i1; j <= i2; j++){
        //increment the number of comparisons each time the list is merged
        comparisons++;
        if (j1 <= m && j2 <= i2){
            if (v[j1] < v[j2]){
                mergeList[j] = v[j1];
                j1++;
            }
            else{
                mergeList[j] = v[j2];
                j2++;
            }
        }
        else if (j1 <= m){
            mergeList[j] = v[j1];
            j1++;
        }
        else if (j2 <= i2){
            mergeList[j] = v[j2];
            j2++;
        }
    }
    //copy the elements of the private array  back into the array that is being sorted
    //the number of moves increments every time an element gets copied back to the original array
    //draws the list every time the list gets an element copied to it
    for (int j = i1; j <= i2; j++){
        v[j] = mergeList[j];
        //increment the number of moves every time the private list gets copied back to the list being sorted
        moves++;
        //draw the updated array v
        draw(v, font, font2, comparisons, moves);
        //print the updated array v to the console
        system("CLS");
        for (int i = 0; i < v.length(); i++)
            cout << v[i] << "\t";
    }

}
