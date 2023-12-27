/****************************************
* Joe Zhang                             *
* Mr. Kronberg                          *
* ICS 4U                                *
* Graphical sorting assignment          *
* November 2nd, 2020                    *
* This program uses Merge Sort, Bubble  *
* Sort and Selection Sort               *
*****************************************/

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

int main(){

    //initialize allegro
    al_init();

    //declare and initialize display
    ALLEGRO_DISPLAY *display = nullptr;
    display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    //set up display
    //exit with an error if the display is not created
    if (checkDisplaySetup(display) == -1)
        return 1;

    //initialize primitives
    //exit with an error if primitives are not installed
    if (initializePrimitives(display) == -1)
        return 1;

    //declare and initialize font
    ALLEGRO_FONT *font;
    ALLEGRO_FONT *font2;
    ALLEGRO_FONT *titleFont;
    ALLEGRO_FONT *startFont;
    installFont();
    font = al_load_font("Lemon_Juice.ttf", 18, 0);
    font2 = al_load_font("Lemon_Juice.ttf", 36, 0);
    titleFont = al_load_font("FunSized.ttf", 72, 0);
    startFont = al_load_font("Pineapple Party.ttf", 36, 0);
    //check if the font is properly installed
    //exit with an error if font does not exist
    if (initializeFont(display, font, font, titleFont, startFont) == -1)
        return 1;

    //declare event queue
    ALLEGRO_EVENT_QUEUE *event_queue;
    event_queue = al_create_event_queue();

    //check if the event queue is created properly
    //exit with an error if event queue does not exist
    if (createEventQueue(display, event_queue) == -1)
        return 1;

    //install mouse
    //exit with an error if the mouse is not installed
    if (installMouse(display) == 1)
        return 1;

    //register event queue
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_mouse_event_source());

    //declare variables
    apvector <int> sortList(MAX_SIZE);
    apvector <int> unsortedList(MAX_SIZE);
    int comparisons = 0;
    int moves = 0;

    //draw title page
    titlePage(titleFont, startFont);

    //wait for user to click start
    //exit with no errors if the display is closed
    if (clickStart(event_queue) == 1)
        return 0;

    //write down instructions for the user
    instructions(font2);

    //wait for user to click continue
    //exit with no errors if the display is closed
    if (clickContinue(event_queue) == 1)
        return 0;

    //assign a random number to each element in the vector
    randomNumbers(sortList, unsortedList);

    //draw the original un-sorted list
    draw(sortList, font, font2, comparisons, moves);

    //print the original list to the console
    for (int i = 0; i < sortList.length(); i++){
        cout << sortList[i] << "\t";
    }

    //wait for user to pick a sorting algorithm
    //This function also calls the sorting functions depending on the sort picked by the user
    differentSorts(event_queue, font, font2, sortList, comparisons, moves, unsortedList);

    //clear screen
    system("CLS");

    //free up memory
    al_destroy_display(display);

    //exit with no errors
    return 0;
}
