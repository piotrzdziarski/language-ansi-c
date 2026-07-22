#include "stdio.h"
#define BREAK 20
#define TAB 8
main() {
	char line[BREAK], c, /*Previous character*/pc = 0;
	for (int j = 0; j < BREAK; j++) line[j] = 0;
	short 
		i = 0,
		/*Tab point*/tp = 0,
		/*Non-Tab character*/ntc = 0,
		/*Index of last character different than Tab or Space*/li;
	while ((c = getchar()) != EOF) {
		line[i] = c;
		if (c == '\t' || c == ' ') {
			if (pc != '\t' && pc != ' ')
				li = i - 1;
			if (c == '\t') {
				/*for (int j = i; j < i + TAB - tp; j++)
					line[j] = 0;*/
				i += TAB - tp;
				if (i >= BREAK) i = BREAK - 1;
				tp = 0;
			} else {
				tp++; if (tp == TAB) tp = 0;
			}
		}
		else if (c == '\n') {
			for (int j = 0; j <= i; j++)
				if (line[j])
					putchar(line[j]);
			for (int j = 0; j < BREAK; j++) line[j] = 0;
			i = 0;
			continue;
		}
		else {
			tp++; if (tp == TAB) tp = 0;
		}
		pc = c;
		i++;
		if (i == BREAK) {
			if (li) {
				for (int j = 0; j <= li; j++)
					if (line[j])
						putchar(line[j]);
				putchar('\n');
				int k = 0;
				for (int j = li + 1; j < BREAK; ++j) {
					if (line[j] != '\t' && line[j] != ' ') {
						line[k] = line[j];
						++k;
					}
				}
				i = k;
				for (; k < BREAK; k++)
					line[k] = 0;
				li = 0;
			} else {
				for (int j = 0; j < BREAK; j++) {
					putchar(line[j]);
					line[j] = 0;
				}
				putchar('\n');
				i = 0;
			}
		}
	}
}
