#include "stdio.h"
#define MAXLINE 100
#define LONGER_THAN 50
#define LONGER_THAN_MAX_COUNT 100
int getLine(char line[], int maxline);
void copy(char to[], char from[]);
main() {
	int len, longerIndex = 0, c;
	char line[MAXLINE];
	char longers[LONGER_THAN_MAX_COUNT][MAXLINE];
	int longersLength[LONGER_THAN_MAX_COUNT];

	while ((len = getLine(line, MAXLINE)) > 0)
		if (len == MAXLINE - 1) {
			while ((c = getchar()) != EOF && c != '\n') len++;
			longersLength[longerIndex] = len;
			line[MAXLINE - 2] = '\n'; 
			copy(longers[longerIndex], line);
			longerIndex++;
		}
		else if (len > LONGER_THAN) {
			longersLength[longerIndex] = len;
			copy(longers[longerIndex], line);
			longerIndex++;
		}

	printf("Maksymalna długość wiersza: %d\n", MAXLINE);
	printf("Wiersze dłuższe niż %d znaków:\n", LONGER_THAN);
	printf("[Długość]: [Wiersz]\n");
	for (int i = 0; i < longerIndex; i++) {
		printf("%d: ", longersLength[i]);
		printf("%s", longers[i]);		
	}
}
getLine(char line[], int maxline) {
	int c, i;

	for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}
void copy(char to[], char from[]) {
	int i = 0;
	while ((to[i] = from[i]) != '\0') ++i;
}
