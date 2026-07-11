#include "stdio.h"
#define MAX_LINE_LENGTH 100
#define MAX_LINES 100
int getLine(char line[], int maxline);
void copy(char to[], char from[]);
void reverse(char s[], int len);
main() {
	int len, lineIndex = 0, c;
	char line[MAX_LINE_LENGTH];
	char lines[MAX_LINES][MAX_LINE_LENGTH];
	int linesLength[MAX_LINES];
	while ((len = getLine(line, MAX_LINE_LENGTH)) > 0)
		if (len == MAX_LINE_LENGTH - 1) {
			while ((c = getchar()) != EOF && c != '\n') len++;
			linesLength[lineIndex] = len;
			line[MAX_LINE_LENGTH - 2] = '\n'; 
			copy(lines[lineIndex], line);
			lineIndex++;
		}
		else if (len == 1 && line[0] == '\n');
		else {
			// len - 1 so as to not include the '\n' character
			reverse(line, len - 1);
			copy(lines[lineIndex], line);
			lineIndex++;
		}

	printf("Maksymalna długość wiersza: %d\n", MAX_LINE_LENGTH);
	printf("Przy za długim wierszu wypisuje się długość wiersza i tylko tyle tekstu ile możliwe; bez odwracania kolejno wszystkich znaków.\n");
	for (int i = 0; i < lineIndex; i++) {
		if (linesLength[i] > MAX_LINE_LENGTH)
			printf("%d: ", linesLength[i]);
		printf("%s", lines[i]);		
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
void reverse(char s[], int len) {
	for (int i = 0, j = len - 1; i < j; i++, j--) {
		char t = s[i];
		s[i] = s[j];
		s[j] = t;
	}
}
