#include "stdio.h"
#define MAXLINE 1000
int getLine(char line[], int maxline);
void copy(char to[], char from[]);
main() {
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = getLine(line, MAXLINE)) > 0)
		if (len == MAXLINE - 1) {
			char c;
			while ((c = getchar()) != EOF && c != '\n')
				len++;
			if (len > max) {
				max = len;
				copy(longest, line);
			}
		}
		else if (len > max) {
			max = len;
			copy(longest, line);
		}

			printf("Długość najdłuższego wiersza: %d\n", max);	
	printf("Najdłuższy wiersz:\n");
	if (max > 0)
		printf("%s", longest);
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
