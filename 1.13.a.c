#include<stdio.h>
#define IN 1
#define OUT 0
#define MAX_HIST 1000
main(){int c,state=OUT,isFirstChar=1,wl=0,h[MAX_HIST];for(int i=0;i<MAX_HIST;i++)h[i]=0;while((c=getchar())!=EOF){if(c==' '||c=='\n'||c=='\t')state=OUT;else if(state==OUT){state=IN;if(isFirstChar)isFirstChar=0;else h[wl-1]++;wl=1;}else wl++;}h[wl-1]++;for(int i=0;i<MAX_HIST;i++)if(h[i]){printf("%4d:",i+1);for(int j=0;j<h[i];j++)putchar('*');printf("\n");}}
