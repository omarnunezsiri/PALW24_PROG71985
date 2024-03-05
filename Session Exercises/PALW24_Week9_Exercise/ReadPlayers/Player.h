#pragma once

#define MAXSTR 30 // Maximum string length

typedef struct Player
{
	int id;
	char username[MAXSTR];
	char password[MAXSTR];
	float exp;
}PLAYER;

void ReadPlayersFromStream(PLAYER[], int, char*);

void DisplayPlayers(PLAYER[], int);

// EXTRA NOTES:
// DisplayPlayers would call DisplayPlayer
// ReadPlayersFromStream would call ReadPlayerFromStream