#include <stdio.h>

#define CAVE_SIZE 10

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