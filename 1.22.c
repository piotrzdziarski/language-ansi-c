#include "stdio.h"
#include "limits.h"
#define BREAK 50
#define TAB 8
main() {
	char line[BREAK], c, /*Previous character*/pc = 0;
	short 
		i = 0;
		/*Tab point*/tp = 0,
		/*Non-Tab character*/ntc = 0,
		/*Index of last character different than Tab or Space*/pi;
	while ((c = getchar()) != EOF) {
		line[i] = c;
		if (c == '\t' || c == ' ') {
			if (pc != '\t' && pc != ' ')
				pi = i - 1;
			if (c != '\t') {
				tp++;
			}
		}
		else {
			ntc++;
			tp++;	
		}
		pc = c;
	}
}
