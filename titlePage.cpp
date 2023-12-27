#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "sorting.h"
#include "mergeSort.h"
#include "APVECTOR.H"

//this function draws the main title page
void titlePage(ALLEGRO_FONT *font, ALLEGRO_FONT *font2){

    //clear background
    al_clear_to_color(TAN);
    //draw title
    al_draw_text(font, BLACK, SCREEN_WIDTH/2, SCREEN_HEIGHT/4, ALLEGRO_ALIGN_CENTER, "GRAPHICAL SORTING");
    //tell user to click start
    al_draw_text(font2, BLACK, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, ALLEGRO_ALIGN_CENTER, "Press Start to Begin");
    //draw start button
    al_draw_filled_rounded_rectangle(SCREEN_WIDTH/2 - 100, 3.0*SCREEN_HEIGHT/4, SCREEN_WIDTH/2 + 100, 3.0*SCREEN_HEIGHT/4 + 50, 10, 10, PALE_GREEN);
    al_draw_rounded_rectangle(SCREEN_WIDTH/2 - 100, 3.0*SCREEN_HEIGHT/4, SCREEN_WIDTH/2 + 100, 3.0*SCREEN_HEIGHT/4 + 50, 10, 10, WHITE, 3);
    al_draw_text(font2, BLACK, SCREEN_WIDTH/2, 3.0*SCREEN_HEIGHT/4, ALLEGRO_ALIGN_CENTER, "Start");
    //draw author's name
    al_draw_text(font2, BLACK, 0, SCREEN_HEIGHT - 100, ALLEGRO_ALIGN_LEFT, "By: Joe Zhang");
    //show display
    al_flip_display();
}

//This function waits for the user to click the start button
int clickStart(ALLEGRO_EVENT_QUEUE *event_queue){

    bool select = false;

    while(!select){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        //exit with no errors if display is closed
        if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
            return 1;
        }
        //proceed if user clicks continue
        else if (ev.mouse.x >= SCREEN_WIDTH/2 - 100 && ev.mouse.y >= 3.0*SCREEN_HEIGHT/4 && ev.mouse.x <= SCREEN_WIDTH/2 + 100 && ev.mouse.y <= 3.0*SCREEN_HEIGHT/4 + 50
                 && ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            select = true;
        }
    }
    return 0;
}
