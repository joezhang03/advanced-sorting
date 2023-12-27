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

int differentSorts(ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_FONT *font, ALLEGRO_FONT *font2, apvector<int> &v, int &comparisons, int &moves, apvector<int> &v2){

    //declare variables
    MERGESORT mergeSort;
    bool select = false;

    while(!select){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        //exit program is the user closes the display
        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            select = true;
        }
        //resets the list and do bubble sort if the user clicks the bubble sort button
        else if (ev.mouse.x >= SCREEN_WIDTH - 290 && ev.mouse.y >= 150 && ev.mouse.x <= SCREEN_WIDTH - 25 && ev.mouse.y <= 200
                 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            comparisons = 0;
            moves = 0;
            unSort(v, v2);
            bubbleSort(v, font, font2, comparisons, moves);
        }
        //resets the list and do selection sort if the user clicks the selection sort button
        else if (ev.mouse.x >= SCREEN_WIDTH - 290 && ev.mouse.y >= 250 && ev.mouse.x <= SCREEN_WIDTH - 25 && ev.mouse.y <= 300
                 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            comparisons = 0;
            moves = 0;
            unSort(v, v2);
            selectionSort(v, font, font2, comparisons, moves);
        }
        //resets the list and do merge sort if the user clicks the merge sort button
        else if (ev.mouse.x >= SCREEN_WIDTH - 290 && ev.mouse.y >= 350 && ev.mouse.x <= SCREEN_WIDTH - 25 && ev.mouse.y <= 400
                 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            comparisons = 0;
            moves = 0;
            unSort(v, v2);
            mergeSort.Sort(v, font, font2, comparisons, moves);
        }
        //resets the list if the user clicks the reset button
        else if (ev.mouse.x >= SCREEN_WIDTH - 290 && ev.mouse.y >= 450 && ev.mouse.x <= SCREEN_WIDTH - 25 && ev.mouse.y <= 500
                 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            unSort(v, v2);
            comparisons = 0;
            moves = 0;
            draw(v, font, font2, comparisons, moves);
            system("CLS");
            for (int i = 0; i < v.length(); i++)
                cout << v[i] << "\t";
        }
        //exit program if user clicks quit
        else if (ev.mouse.x >= SCREEN_WIDTH - 290 && ev.mouse.y >= 550 && ev.mouse.x <= SCREEN_WIDTH - 25 && ev.mouse.y <= 600
                 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            select = true;
        }
    }
    return 0;
}
