// A solution with a vertical histogram
#include<stdio.h>
#define MAX_HIST 255
main(){int c,h[MAX_HIST];for(int i=0;i<MAX_HIST;i++)h[i]=0;while((c=getchar())!=EOF){h[c]++;}
int max=h[0],count=0;for(int i=0;i<MAX_HIST;i++)if(h[i]){count++;if(max<h[i])max=h[i];}
for (int i = max; i > 0; i--) {
	for (int j = 0; j < MAX_HIST; j++) {
		if (h[j] >= i) putchar('*');
		else if (h[j]) putchar(' ');
	}
	printf("\n");
}
for (int i = 0; i < MAX_HIST; i++)
	if (h[i]) if (i == '\n' || i == '\t') putchar('\\'); else putchar(i);
printf("\n");
for (int i = 0; i < MAX_HIST; i++)
	if (h[i]) if (i == '\n') putchar('n'); else if (i == '\t') putchar('t'); else putchar(' ');
printf("\n");
}
