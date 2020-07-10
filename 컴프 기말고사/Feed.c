#include "Feed.h"
#include <stdio.h>
#include <stdlib.h>

Location setfeed(player* p) {
	int overlap, x, y;

	do { //ºóÀÚ¸®°ªÀ» ÀÐ¾î¿È 
		overlap = 0;

		x = rand() % (boardx - 2) + 1;
		y = rand() % (boardy - 2) + 1;

		ListNode* head = p->last->right;

		do {
			if (head->location.x == x && head->location.y == y) {
				overlap = 1;
				break;
			}

			head = head->right;
		} while (head != p->last->right);
	} while (overlap);

	feed.x = x;
	feed.y = y;

	printfeed(&feed);

	return feed;
}

void printfeed(Location* feed) {
	gotonode(*feed);
	printf("¡Ú");
}