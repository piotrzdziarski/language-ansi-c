#include<stdio.h>
#define IN 1
#define OUT 0
#define MAX_HIST 1000
main(){int c,state=OUT,isFirstChar=1,wl=0,h[MAX_HIST];for(int i=0;i<MAX_HIST;i++)h[i]=0;while((c=getchar())!=EOF){if(c==' '||c=='\n'||c=='\t')state=OUT;else if(state==OUT){state=IN;if(isFirstChar)isFirstChar=0;else h[wl-1]++;wl=1;}else wl++;}h[wl-1]++;
int max=h[0],count=0;for(int i=0;i<MAX_HIST;i++)if(h[i]){count++;if(max<h[i])max=h[i];}
for (int i = max; i > 0; i--) {
	for (int j = 0; j < MAX_HIST; j++) {
		if (h[j] >= i) putchar('*');
		else if (h[j]) putchar(' ');
	}
	printf("\n");
}
for (int i = 0; i < MAX_HIST; i++) {
	if (h[i]) printf("%d", i + 1);
}
}
