#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void InitialiseStory(char *paragraph)
{
	char temp[] = "After finally finishing the project 'Boulder Break', it is\ntime to take a well-deserved nap... only to wake up in your\n\
own creation but this time, not as the coder, but as the\nadventurer!\nWhile frantically trying to recall where you placed all\n\
the holes and treasure, you realise that in order to truly\ntest if your game works, you must escape as the adventurer!";

	strcpy(paragraph, temp);
}

int main(void)
{
	char story[2000];
	InitialiseStory(story);
	printf("%s\n", story);

	return 0;
}