// PAL Week 9 - Exercise:
//					Read a file of players and display the players
// 
// PROG71985W24
// Authors: PAL Attendees
// 
// 
// revision history:
// 1.0			2024-03-04		initial
#define MAX_PLAYERS 4
#define FILENAME "players.txt"

#include <stdio.h>
#include "Color.h" // to beautify output (extra)
#include "Player.h"

int main(void)
{
	// Example of a player (use as reference)
	//PLAYER p1 = { 1, "player1", "averygoodpassword;)", 15963.3181239f };

	//MintGreen();
	//printf("EXAMPLE: Player ID: %d\n", p1.id);
	//printf("Username: %s\n", p1.username);
	//printf("Password: %s\n", p1.password);
	//printf("Experience: %.2f\n", p1.exp);
	//Reset();

	/* WRITE THE MAIN PROGRAM HERE */
	PLAYER players[MAX_PLAYERS];
	ReadPlayersFromStream(players, MAX_PLAYERS, FILENAME);
	DisplayPlayers(players, MAX_PLAYERS);

	return 0;
}