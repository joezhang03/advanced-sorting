#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "sorting.h"
#include "mergeSort.h"
#include "APVECTOR.H"

//This function writes down the instructions for the user
void instructions(ALLEGRO_FONT *font){

    //clear background
    al_clear_to_color(TAN);
    //write down instructions
    al_draw_text(font, BLACK, 0, 50, ALLEGRO_ALIGN_LEFT, "Click the red Bubble Sort button to visualize bubble sort");
    al_draw_text(font, BLACK, 0, 100, ALLEGRO_ALIGN_LEFT, "Click the green Selection Sort button to visualize selection sort");
    al_draw_text(font, BLACK, 0, 150, ALLEGRO_ALIGN_LEFT, "Click the yellow Merge Sort button to visualize merge sort");
    al_draw_text(font, BLACK, 0, 200, ALLEGRO_ALIGN_LEFT, "Click the blue Reset button to revert the list back to how it was before it was sorted");
    al_draw_text(font, BLACK, 0, 250, ALLEGRO_ALIGN_LEFT, "Click the purple Quit button to quit");
    //draw continue button
    al_draw_filled_rounded_rectangle(SCREEN_WIDTH/2 - 100, 3.0*SCREEN_HEIGHT/4, SCREEN_WIDTH/2 + 100, 3.0*SCREEN_HEIGHT/4 + 50, 10, 10, PALE_GREEN);
    al_draw_rounded_rectangle(SCREEN_WIDTH/2 - 100, 3.0*SCREEN_HEIGHT/4, SCREEN_WIDTH/2 + 100, 3.0*SCREEN_HEIGHT/4 + 50, 10, 10, WHITE, 3);
    al_draw_text(font, BLACK, SCREEN_WIDTH/2, 3.0*SCREEN_HEIGHT/4, ALLEGRO_ALIGN_CENTER, "Continue");
    //show display
    al_flip_display();
}

//This function waits for the user to click continue
int clickContinue(ALLEGRO_EVENT_QUEUE *event_queue){

    //declare variables
    bool select = false;

    while(!select){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        //exit with no errors if display is closed
        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            return 1;
        }
        //proceed if continue is clicked
        else if (ev.mouse.x >= SCREEN_WIDTH/2 - 100 && ev.mouse.y >= 3.0*SCREEN_HEIGHT/4 && ev.mouse.x <= SCREEN_WIDTH/2 + 100
                 && ev.mouse.y <= 3.0*SCREEN_HEIGHT/4 + 50 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            select = true;
        }
    }
    return 0;
}
