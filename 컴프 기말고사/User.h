#pragma once
#include "Public_data.h"
#include "Replay.h"
#include "Feed.h"
#define direction_up 72
#define direction_down 80
#define direction_left 75
#define direction_right 77

void initialize(player* p);

void moving(player* p);

int getfeed(player* p, int x, int y);

void printsnake(player* p);