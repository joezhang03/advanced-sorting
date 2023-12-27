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

//Function for bubble sort
void bubbleSort(apvector<int> &v, ALLEGRO_FONT *font, ALLEGRO_FONT *font2, int &comparisons, int &moves){

    //store the array length into a new variable n
    int n = v.length();

    for (int i = 0; i < n-1; i++){
        for (int j = 0; j < n-i-1; j++){
            //increment the number of comparisons
            comparisons++;
            //swap the elements if the first element is greater than the next element
            if (v[j] > v[j+1]){
                Swap(v[j], v[j+1]);
                //increment the number of moves every time a swap is made
                moves++;
                //draw the updated array
                draw(v, font, font2, comparisons, moves);
                //print the updated array to the console
                system("CLS");
                for (int i = 0; i < v.length(); i++)
                    cout << v[i] << "\t";
            }
        }
    }
}
