#include <stdio.h>
#include <string.h>

#define CAVE_SIZE 10

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
	int caveA[CAVE_SIZE][CAVE_SIZE] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	int caveB[CAVE_SIZE][CAVE_SIZE] = {
	  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	  {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	printf("Printing Cave A:\n");
	PrintCave(caveA);

	printf("Printing Cave B:\n");
	PrintCave(caveB);
}