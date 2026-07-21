#include "stdio.h"
#define TAB 8
main(){
	int c, /*Tab point*/tp = 0, /*Spaces' count*/sc = 0, /*Other characters' count*/oc = 0;
	while ((c=getchar()) != EOF) {
		if (c == ' ') {
			++sc;
			++tp;
			if (tp == TAB) {
				if (sc + oc == tp) {
					putchar('\t');
					tp = sc = oc = 0;
				}
			} else {
				putchar(' ');
			}
		} else if (c == '\t' || c == '\n') {
			putchar(c);
			tp = sc = oc = 0;
		} else {
			putchar(c);
			++oc;
			++tp;
			if (tp == TAB)
				tp = sc = oc = 0;
		}
	}
}
