#include <stdio.h>
//#include <termios.h>
#include <unistd.h>
//#include <fcntl.h>
#include <iostream>
#include "../3rd/cmdline/cmdline.h"
//http://viget.com/extend/game-programming-in-c-with-the-ncurses-library
//#include <curses.h>
#include <ncurses.h>

int main(int argc, char *argv[]) {
  cmdline::parser cp;

  cp.add<int>("screenWidth", 'w', "screen width", true, 50);
  cp.add<int>("screenHeight", 'h', "screen height", true, 50);

  cp.parse_check(argc, argv);

  initscr();
  noecho();
  curs_set(FALSE);
  sleep(1);
  endwin(); // Restore normal terminal behavior
  
  /*
  while(true) {
	int ch = getch();
	std::cout << ch << std::endl;
	usleep(100000);
  }
  */
  
  /*
  while (true) {
	struct termios oldt, newt;
	int ch;
	int oldf;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);

	if(ch != EOF) {
	  ungetc(ch, stdin);
	  return 1;
	}

	usleep(10000);
  }
  */  
  return 0;
}
