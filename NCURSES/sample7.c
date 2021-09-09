# Source https://stackoverflow.com/questions/32088603/how-to-keep-stdin-at-bottom-the-terminal-in-c
#include <curses.h>

int
main(void)
{
    bool done = FALSE;
    WINDOW *input, *output;
    char buffer[1024];
    
    initscr();
    cbreak();
    echo();
    input = newwin(1, COLS, LINES - 1, 0);
    output = newwin(LINES - 1, COLS, 0, 0);
    wmove(output, LINES - 2, 0);    /* start at the bottom */
    scrollok(output, TRUE);
    while (!done) {
      mvwprintw(input, 0, 0, "> ");
      if (wgetnstr(input, buffer, COLS - 4) != OK) {
        break;
      }
      werase(input);
      waddch(output, '\n');   /* result from wgetnstr has no newline */
      waddstr(output, buffer);
      wrefresh(output);
      done = (*buffer == 4);  /* quit on control-D */
    }
    endwin();
    return 0;
}
