//This file will contain all of the function prototypes, constants, structures, and definitions
#include "APVECTOR.H"

const int SCREEN_WIDTH = 1500;
const int SCREEN_HEIGHT = 1000;

#define MAX_SIZE 100

#define RED al_map_rgb (255, 0, 0)
#define GREEN al_map_rgb(0, 255, 0)
#define BLUE al_map_rgb(0, 0, 255)
#define BLACK al_map_rgb(0, 0, 0)
#define WHITE al_map_rgb(255, 255, 255)
#define YELLOW al_map_rgb(255, 255, 0)
#define ORANGE al_map_rgb(255, 159, 0)
#define PURPLE al_map_rgb(255, 0, 255)
#define GREY al_map_rgb (200, 200, 200)
#define BROWN al_map_rgb(151, 75, 0)
#define TAN al_map_rgb(228, 202, 177)
#define PALE_GREEN al_map_rgb(198, 219, 210)
#define PALE_RED al_map_rgb(254, 189, 173)

struct POINT{
    int x;
    int y;
};

//function prototypes
void Swap(int &n1, int &n2);
void randomNumbers(apvector<int> &v, apvector<int> &v2);
int checkDisplaySetup(ALLEGRO_DISPLAY *display);
int initializePrimitives(ALLEGRO_DISPLAY *display);
void draw(apvector<int> &v, ALLEGRO_FONT *font, ALLEGRO_FONT *font2, int &comparisons, int &moves);
void installFont();
int initializeFont(ALLEGRO_DISPLAY *display, ALLEGRO_FONT *font, ALLEGRO_FONT *font2, ALLEGRO_FONT *font3, ALLEGRO_FONT *font4);
void bubbleSort(apvector<int> &v, ALLEGRO_FONT *font, ALLEGRO_FONT *font2, int &comparisons, int &moves);
void selectionSort(apvector<int> &v, ALLEGRO_FONT *font, ALLEGRO_FONT *font2, int &comparisons, int &moves);
int installMouse(ALLEGRO_DISPLAY *display);
int createEventQueue(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *event_queue);
int differentSorts(ALLEGRO_EVENT_QUEUE *event_queue, ALLEGRO_FONT *font, ALLEGRO_FONT *font2, apvector<int> &v, int &comparisons, int &moves, apvector<int> &v2);
void unSort(apvector<int> &v, apvector<int> &v2);
void titlePage(ALLEGRO_FONT *font, ALLEGRO_FONT *font2);
int clickStart(ALLEGRO_EVENT_QUEUE *event_queue);
void instructions(ALLEGRO_FONT *font);
int clickContinue(ALLEGRO_EVENT_QUEUE *event_queue);
