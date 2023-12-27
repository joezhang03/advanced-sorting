#include <iostream>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "sorting.h"
#include "mergeSort.h"
#include "APVECTOR.H"

using namespace std;
void draw(apvector<int> &v, ALLEGRO_FONT *font, ALLEGRO_FONT *font2, int &comparisons, int &moves){

    //declare variables
    float width = (SCREEN_WIDTH - 250)/v.length();
    float length;
    POINT up;
    POINT down;
    char printString[200];

    al_clear_to_color(ORANGE);

    //draw button panel
    al_draw_filled_rectangle(SCREEN_WIDTH - 300, 100, SCREEN_WIDTH, SCREEN_HEIGHT, PALE_GREEN);
    al_draw_rectangle(SCREEN_WIDTH - 300, 100, SCREEN_WIDTH, SCREEN_HEIGHT, BROWN, 1);

    //draw button for bubble sort
    al_draw_filled_rectangle(SCREEN_WIDTH - 290, 150, SCREEN_WIDTH - 25, 200, RED);
    al_draw_text(font2, BLACK, SCREEN_WIDTH - 290/2, 150, ALLEGRO_ALIGN_CENTER, "Bubble Sort");

    //draw button for selection sort
    al_draw_filled_rectangle(SCREEN_WIDTH - 290, 250, SCREEN_WIDTH - 25, 300, GREEN);
    al_draw_text(font2, BLACK, SCREEN_WIDTH - 290/2, 250, ALLEGRO_ALIGN_CENTER, "Selection Sort");

    //draw button for merge sort
    al_draw_filled_rectangle(SCREEN_WIDTH - 290, 350, SCREEN_WIDTH - 25, 400, YELLOW);
    al_draw_text(font2, BLACK, SCREEN_WIDTH - 290/2, 350, ALLEGRO_ALIGN_CENTER, "Merge Sort");

    //draw reset button
    al_draw_filled_rectangle(SCREEN_WIDTH - 290, 450, SCREEN_WIDTH - 25, 500, BLUE);
    al_draw_text(font2, BLACK, SCREEN_WIDTH - 290/2, 450, ALLEGRO_ALIGN_CENTER, "Reset");

    //draw quit button
    al_draw_filled_rectangle(SCREEN_WIDTH - 290, 550, SCREEN_WIDTH - 25, 600, PURPLE);
    al_draw_text(font2, BLACK, SCREEN_WIDTH - 290/2, 550, ALLEGRO_ALIGN_CENTER, "Quit");

    //draw the number of comparisons
    sprintf(printString, "%d", comparisons);
    al_draw_text(font2, BLACK, SCREEN_WIDTH - 290, 700, ALLEGRO_ALIGN_LEFT, "Comparisons: ");
    al_draw_text(font2, BLACK, SCREEN_WIDTH - 150, 700, ALLEGRO_ALIGN_LEFT, printString);

    //draw the number of moves
    sprintf(printString, "%d", moves);
    al_draw_text(font2, BLACK, SCREEN_WIDTH - 290, 750, ALLEGRO_ALIGN_LEFT, "Moves: ");
    al_draw_text(font2, BLACK, SCREEN_WIDTH - 200, 750, ALLEGRO_ALIGN_LEFT, printString);

    //draw bars that represents the array
    for (int i = 0; i < v.length(); i++){
        length = (1.0*(SCREEN_HEIGHT-100)/100)*v[i];
        up.x = i*width;
        up.y = SCREEN_HEIGHT - length;
        down.x = (i+1)*width;
        down.y = SCREEN_HEIGHT;
        al_draw_filled_rectangle(up.x, up.y, down.x, down.y, GREY);
        al_draw_rectangle(up.x, up.y, down.x, down.y, BLACK, 1);
    }

    al_flip_display();
    al_rest(0.01);
}
