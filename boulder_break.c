/*Boulder Break */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define CAVE_SIZE 5

void InitialiseStory(char* paragraph)
{
	char temp[] = "After finally finishing the project 'Boulder Break', it is\ntime to take a well-deserved nap... only to wake up in your\n\
own creation but this time, not as the coder, but as the\nadventurer!\nWhile frantically trying to recall where you placed all\n\
the holes and treasure, you realise that in order to truly\ntest if your game works, you must escape as the adventurer!";

	strcpy(paragraph, temp);
}

void PrintCave(int cave[CAVE_SIZE][CAVE_SIZE])
{
	int i, j;

	for (i = 0; i < CAVE_SIZE; i++) {
		for (j = 0; j < CAVE_SIZE; j++) {
			if ((cave[i][j] == 0) && (j != CAVE_SIZE - 1)) {
				printf(" ");
			}
			else if ((cave[i][j] == 0) && (j == CAVE_SIZE - 1)) {
				printf(" \n");
			}
			else if ((cave[i][j] == 1) && (j != CAVE_SIZE - 1)) {
				printf("#");
			}
			else if ((cave[i][j] == 1) && (j == CAVE_SIZE - 1)) {
				printf("#\n");
			}
			else if ((cave[i][j] == 'E') && (j != CAVE_SIZE - 1)) {
				printf(" ");
			}
			else if ((cave[i][j] == 'E') && (j == CAVE_SIZE - 1)) {
				printf(" \n");
			}
			else if ((cave[i][j] == 'X') && (j != CAVE_SIZE - 1)) {
				printf("X");
			}
			else if ((cave[i][j] == 'X') && (j == CAVE_SIZE - 1)) {
				printf("X\n");
			}
			else if (cave[i][j] == '*') {
				printf("*");
			}
			else if (cave[i][j] == '+') {
				printf("+");
			}
			else if (cave[i][j] == 'O') {
				printf("O");
			}
		}
	}
}

void InitialiseCave(int cave[CAVE_SIZE][CAVE_SIZE], char* layout)
{
	int i, j;
	int k = 0; // where k is the indexing for the layout

	for (i = 0; i < CAVE_SIZE; i++) {
		for (j = 0; j < CAVE_SIZE; j++) {
			if (layout[k] == '1') {
				cave[i][j] = 1;
			}
			else if (layout[k] == '0') {
				cave[i][j] = 0;
			}
			else if (layout[k] == 'E') {
				cave[i][j] = 'E';
			}
			k++;
		}
	}
}

int IsBorderComplete(int cave[CAVE_SIZE][CAVE_SIZE])
{
	int i;

	for (i = 0; i < CAVE_SIZE; i++) {
		if (cave[0][i] == 0) {
			return 0;
		}
		else if (cave[CAVE_SIZE - 1][i] == 0) {
			return 0;
		}
		else if (cave[i][0] == 0) {
			return 0;
		}
		else if (cave[i][CAVE_SIZE - 1] == 0) {
			return 0;
		}
	}

	return 1;
}

int IsExitUnique(int cave[CAVE_SIZE][CAVE_SIZE])
{
	int i, j;
	int nExit = 0;

	for (i = 0; i < CAVE_SIZE; i++) {
		for (j = 0; j < CAVE_SIZE; j++) {
			if (cave[i][j] == 'E') {
				nExit++;
			}
		}
	}

	if (nExit == 1) {
		return 1;
	}
	else {
		return 0;
	}
}

int IsExitAccessible(int cave[CAVE_SIZE][CAVE_SIZE])
{
	int i;

	for (i = 0; i < CAVE_SIZE; i++) {
		if ((cave[0][0] == 'E') || (cave[0][CAVE_SIZE - 1] == 'E') || (cave[CAVE_SIZE - 1][0] == 'E') || (cave[CAVE_SIZE - 1][CAVE_SIZE - 1] == 'E')) {
			return 0; // if exit is at a corner
		}
		else if ((cave[0][i] == 'E') || (cave[CAVE_SIZE - 1][i] == 'E') || (cave[i][0] == 'E') || (cave[i][CAVE_SIZE - 1] == 'E')) {
			return 1;
		}
	}

	return 0;
}

void AddItem(int cave[CAVE_SIZE][CAVE_SIZE], int row, int col, char* element)
{
	int i, j;
	int nPlayer = 0;

	if ((row < CAVE_SIZE) && (col < CAVE_SIZE) && (row >= 0) && (col >= 0)) {

		for (i = 0; i < CAVE_SIZE; i++) { // checking if there is already a player
			for (j = 0; j < CAVE_SIZE; j++) {
				if (cave[i][j] == 'X') {
					nPlayer++;
				}
			}
		}

		if ((cave[row][col] == 0) && (strcmp("player", element) == 0) && (nPlayer == 0)) {
			cave[row][col] = 'X';
		}
		else if ((cave[row][col] == 0) && (strcmp("hole", element) == 0)) {
			cave[row][col] = '*';
		}
		else if ((cave[row][col] == 0) && (strcmp("treasure", element) == 0)) {
			cave[row][col] = '+';
		}
		else if ((cave[row][col] == 0) && (strcmp("boulder", element) == 0)) {
			cave[row][col] = 'O';
		}
	}
}

void RotateCave(int cave[CAVE_SIZE][CAVE_SIZE])
{
	int i, j;
	int temp[CAVE_SIZE][CAVE_SIZE] = { 0 };

	for (i = 0; i < CAVE_SIZE; i++) { // change all row elements into all column elements
		for (j = 0; j < CAVE_SIZE; j++) {
			temp[j][CAVE_SIZE - 1 - i] = cave[i][j];
		}
	}
	for (i = 0; i < CAVE_SIZE; i++) { // turn all elements of temp into all elements of cave
		for (j = 0; j < CAVE_SIZE; j++) {
			cave[i][j] = temp[i][j];
		}
	}
}

int MakeMove(int cave[CAVE_SIZE][CAVE_SIZE], char move)
{
	int i, j;
	int row = 0;
	int col = 0;
	int temp;
	int boulderRow = 0;


	if (move == 'w') {
		for (i = 0; i < CAVE_SIZE; i++) { // find location of player
			for (j = 0; j < CAVE_SIZE; j++) {
				if (cave[i][j] == 'X') {
					row = i;
					col = j;
				}
			}
		}
		if (cave[row - 1][col] == 0) { // player location at cave[row][col]
			temp = cave[row][col];
			cave[row][col] = cave[row - 1][col];
			cave[row - 1][col] = temp;
		}
		else if (cave[row - 1][col] == '+') { // treasure
			cave[row - 1][col] = cave[row][col];
			cave[row][col] = 0;
		}
		else if (cave[row - 1][col] == '*') { // player falls into hole
			cave[row][col] = 0;
			return 1;
		}
		else if (cave[row - 1][col] == 'E') { // player escapes
			cave[row - 1][col] = cave[row][col];
			cave[row][col] = 0;
			return 2;
		}
		else if (cave[row - 1][col] == 'O') { // boulder mechanics
			if (cave[row - 2][col] != 0) {
				return 0;
			}
			
			for (i = row - 2; ((cave[i][col] == 0) || (cave[i][col] == '*')); i--) {
				boulderRow = i; // find the furthest row with empty space
				if (cave[i][col] == '*') {
					cave[row - 1][col] = 0;
					cave[i][col] = 0;
				}
			}
			if (cave[row - 1][col] != 0) { // if boulder did not go in hole, boulder is at furthest row
				cave[row - 1][col] = 0;
				cave[boulderRow][col] = 'O';
			}
		}
		return 0;
	}

	if (move == 'a') {
		RotateCave(cave);
		for (i = 0; i < CAVE_SIZE; i++) { // find location of player
			for (j = 0; j < CAVE_SIZE; j++) {
				if (cave[i][j] == 'X') {
					row = i;
					col = j;
				}
			}
		}
		if (cave[row - 1][col] == 0) {
			temp = cave[row][col];
			cave[row][col] = cave[row - 1][col];
			cave[row - 1][col] = temp;
		}
		else if (cave[row - 1][col] == '+') { // treasure
			cave[row - 1][col] = cave[row][col];
			cave[row][col] = 0;
		}
		else if (cave[row - 1][col] == '*') { // player falls into hole
			cave[row][col] = 0;
			RotateCave(cave);
			RotateCave(cave);
			RotateCave(cave);
			return 1;
		}
		else if (cave[row - 1][col] == 'E') { // player escapes
			cave[row - 1][col] = cave[row][col];
			cave[row][col] = 0;
			RotateCave(cave);
			RotateCave(cave);
			RotateCave(cave);
			return 2;
		}
		else if (cave[row - 1][col] == 'O') { // boulder mechanics
			if ((cave[row - 2][col] != 0) && (cave[row - 2][col] != '*')) {
				RotateCave(cave);
				RotateCave(cave);
				RotateCave(cave);
				return 0;
			}
			
			for (i = row - 2; ((cave[i][col] == 0) || (cave[i][col] == '*')); i--) {
				boulderRow = i; // find the furthest row with empty space
				if (cave[i][col] == '*') {
					cave[row - 1][col] = 0;
					cave[i][col] = 0;
				}
			}
			if (cave[row - 1][col] != 0) { // if boulder did not go in hole, boulder is at furthest row
				cave[row - 1][col] = 0;
				cave[boulderRow][col] = 'O';
			}
		}
		RotateCave(cave);
		RotateCave(cave);
		RotateCave(cave);
		return 0;
	}

	if (move == 's') {
		RotateCave(cave);
		RotateCave(cave);
		for (i = 0; i < CAVE_SIZE; i++) { // find location of player
			for (j = 0; j < CAVE_SIZE; j++) {
				if (cave[i][j] == 'X') {
					row = i;
					col = j;
				}
			}
		}
		if (cave[row - 1][col] == 0) {
			temp = cave[row][col];
			cave[row][col] = cave[row - 1][col];
			cave[row - 1][col] = temp;
		}
		else if (cave[row - 1][col] == '+') { // treasure
			cave[row - 1][col] = cave[row][col];
			cave[row][col] = 0;
		}
		else if (cave[row - 1][col] == '*') { // player falls into hole
			cave[row][col] = 0;
			RotateCave(cave);
			RotateCave(cave);
			return 1;
		}
		else if (cave[row - 1][col] == 'E') { // player escapes
			cave[row - 1][col] = cave[row][col];
			cave[row][col] = 0;
			RotateCave(cave);
			RotateCave(cave);
			return 2;
		}
		else if (cave[row - 1][col] == 'O') { // boulder mechanics
			if ((cave[row - 2][col] != 0) && (cave[row - 2][col] != '*')) {
				RotateCave(cave);
				RotateCave(cave);
				return 0;
			}
			
			for (i = row - 2; ((cave[i][col] == 0) || (cave[i][col] == '*')); i--) {
				boulderRow = i; // find the furthest row with empty space
				if (cave[i][col] == '*') {
					cave[row - 1][col] = 0;
					cave[i][col] = 0;
				}
			}
			if (cave[row - 1][col] != 0) { // if boulder did not go in hole, boulder is at furthest row
				cave[row - 1][col] = 0;
				cave[boulderRow][col] = 'O';
			}
		}
		RotateCave(cave);
		RotateCave(cave);
		return 0;
	}

	if (move == 'd') {
		RotateCave(cave);
		RotateCave(cave);
		RotateCave(cave);
		for (i = 0; i < CAVE_SIZE; i++) { // find location of player
			for (j = 0; j < CAVE_SIZE; j++) {
				if (cave[i][j] == 'X') {
					row = i;
					col = j;
				}
			}
		}
		if (cave[row - 1][col] == 0) {
			temp = cave[row][col];
			cave[row][col] = cave[row - 1][col];
			cave[row - 1][col] = temp;
		}
		else if (cave[row - 1][col] == '+') { // treasure
			cave[row - 1][col] = cave[row][col];
			cave[row][col] = 0;
		}
		else if (cave[row - 1][col] == '*') { // player falls into hole
			cave[row][col] = 0;
			RotateCave(cave);
			return 1;
		}
		else if (cave[row - 1][col] == 'E') { // player escapes
			cave[row - 1][col] = cave[row][col];
			cave[row][col] = 0;
			RotateCave(cave);
			return 2;
		}
		else if (cave[row - 1][col] == 'O') { // boulder mechanics
			if ((cave[row - 2][col] != 0) && (cave[row - 2][col] != '*')) {
				RotateCave(cave);
				return 0;
			}
			
			for (i = row - 2; ((cave[i][col] == 0) || (cave[i][col] == '*')); i--) {
				boulderRow = i; // find the furthest row with empty space
				if (cave[i][col] == '*') {
					cave[row - 1][col] = 0;
					cave[i][col] = 0;
				}
			}
			if (cave[row - 1][col] != 0) { // if boulder did not go in hole, boulder is at furthest row
				cave[row - 1][col] = 0;
				cave[boulderRow][col] = 'O';
			}
		}
		RotateCave(cave);
		return 0;
	}
	return 0;
}

/* GetMove() returns the entered character. Invalid characters ignored */
char GetMove(void)
{
	char move;
	printf("\nEnter move: ");
	scanf("%c", &move);
	// Ignore any characters that are invalid
	while ((move != 'w') && (move != 'a') && (move != 's') && (move != 'd')) {
		scanf("%c", &move);
	}
	return move;
}

/* The Boulder Break simulation */
int main(void)
{
	printf("ENGGEN131 - C Project 2022\n");
	printf("                          ... presents ...\n");
	printf("______   _____  _     _        ______  _______  ______\n");
	printf("|_____] |     | |     | |      |     \\ |______ |_____/\n");
	printf("|_____] |_____| |_____| |_____ |_____/ |______ |    \\_\n");
	printf("______   ______ _______ _______ _     _\n");
	printf("|_____] |_____/ |______ |_____| |____/ \n");
	printf("|_____] |    \\_ |______ |     | |    \\_\n");
	printf("\n");
	printf("%s\n", story);
	printf("\nMove the player (X) using the keys 'w', 'a', 's', 'd'\n");
	printf("Good luck!\n\n\n"); */

	char layout[200] = "111111000110001100011E111";
	int cave[CAVE_SIZE][CAVE_SIZE];
	int gameOver = 0;

	InitialiseCave(cave, layout);
	AddItem(cave, 1, 1, "player");
	AddItem(cave, 2, 2, "boulder");
	AddItem(cave, 3, 1, "hole");

	MakeMove(cave, 'd');
	MakeMove(cave, 'd');
	MakeMove(cave, 's');
	MakeMove(cave, 'a');
	MakeMove(cave, 'a');
	MakeMove(cave, 'w');
	MakeMove(cave, 'a');
	MakeMove(cave, 's');
	MakeMove(cave, 's');
	MakeMove(cave, 's');

	PrintCave(cave);

	/* Main game loop */
	PrintCave(cave);
	while (!gameOver) {
		gameOver = MakeMove(cave, GetMove());
		PrintCave(cave);
		if (gameOver == 1) {
			printf("\n\nGAME OVER!! \nYou died!\n\n");
		} else if (gameOver == 2) {
			printf("\n\nCONGRATULATIONS!! \nYou escaped!\n\n");
		}
	}

	return 0;
}