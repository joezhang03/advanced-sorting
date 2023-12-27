#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

//check display setup
int checkDisplaySetup(ALLEGRO_DISPLAY *display){

    if(!display){
        al_show_native_message_box(display, "Error", "Error", "Failed to load display", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    //set window title
    al_set_window_title(display, "Graphical Sorting");
    return 0;
}

//check if primitives are added on properly
int initializePrimitives(ALLEGRO_DISPLAY *display){

    if(!al_init_primitives_addon()){
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize primitive addons", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }
    return 0;
}

//install font addons
void installFont(){
    al_init_font_addon();
    al_init_ttf_addon();
}

//check if font is added and initialized
int initializeFont(ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font, ALLEGRO_FONT *font2, ALLEGRO_FONT *font3, ALLEGRO_FONT *font4){

    if(!font){
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize font", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    if(!font2){
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize font", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    if(!font3){
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize font", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    if(!font4){
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize font", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }
    return 0;
}

//install mouse
int installMouse(ALLEGRO_DISPLAY *display){

    al_install_mouse();

    if(!al_install_mouse()){
        al_show_native_message_box(display, "Error", "Error", "Failed to install mouse", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }
    return 0;
}

//check if event queue is created
int createEventQueue(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue){

    if(!event_queue){
        al_show_native_message_box(display, "Error", "Error", "Failed to install event queue", nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }
    return 0;
}
