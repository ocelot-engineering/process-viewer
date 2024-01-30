#include <ncurses.h>

void printTestWindow()
{
    // init screen and sets up screen
    initscr();

    // print to screen
    printw("Hello, world!");

    // refreshes the screen
    refresh();

    // pause the screen output
    getch();

    // deallocate memory and ends ncurses
    endwin();
}
