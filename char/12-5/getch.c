#include <stdio.h>
#include <conio.h>

int main(void) {
	int ch;
	/*
	while ((ch = _getch()) != 'q') {
		_putch(ch);
	}
	*/

	while ((ch = getchar()) != EOF)
		putchar(ch);
	return 0;
}