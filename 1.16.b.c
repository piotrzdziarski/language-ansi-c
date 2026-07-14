#include "stdio.h"
#define MAXLINE 100
int max;
char line[MAXLINE];
char longest[MAXLINE];
int getLine(void);
void copy(void);
main() {
	int len;
	extern int max;
	extern char longest[], line[];

	max = 0;
	while ((len = getLine()) > 0)
		if (len == MAXLINE - 1) {
			char c;
			while ((c = getchar()) != EOF && c != '\n')
				len++;
			if (len > max) {
				max = len;
				line[MAXLINE - 1] = '\n';
				copy();
			}
		}
		else if (len > max) {
			max = len;
			copy();
		}

	printf("Długość najdłuższego wiersza: %d\n", max);	
	printf("Najdłuższy wiersz:\n");
	if (max > 0)
		printf("%s", longest);
}
getLine() {
	int c, i;
	extern char line[];

	for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		line[i] = c;
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}
void copy(void) {
	int i = 0;
	extern char line[], longest[];
	while ((longest[i] = line[i]) != '\0') ++i;
}
