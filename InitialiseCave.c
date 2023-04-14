#include <stdio.h>
#include <string.h>

#define CAVE_SIZE 10

void InitialiseCave(int cave[CAVE_SIZE][CAVE_SIZE], char *layout)
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

void PrintCave(int cave[CAVE_SIZE][CAVE_SIZE])
{
	int i, j;

	for (i = 0; i < CAVE_SIZE; i++) {
		for (j = 0; j < CAVE_SIZE; j++) {
			if (cave[i][j] == 0) {
				printf(" ");
			}
			else if ((cave[i][j] == 1) && (j != CAVE_SIZE - 1)) {
				printf("#");
			}
			else if (cave[i][CAVE_SIZE - 1] == 1) {
				printf("#\n");
			}
			else if ((cave[i][j] == 'E') && (j != CAVE_SIZE - 1)) {
				printf(" ");
			}
			else if (cave[i][CAVE_SIZE - 1] == 'E') {
				printf(" \n");
			}
		}
	}
}

int main(void)
{
	char layout[200] = "1111111111111000001111000000111000000001100000000E10010000011100000011111000001111111001111111111111"; 
	int cave[CAVE_SIZE][CAVE_SIZE] = { 0 };

	InitialiseCave(cave, layout);
	PrintCave(cave);
}