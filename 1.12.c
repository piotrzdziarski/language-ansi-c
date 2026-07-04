#include<stdio.h>
#define IN 1
#define OUT 0
main(){int c,state=OUT,isFirstChar=1;while((c=getchar())!=EOF){if(c==' '||c=='\n'||c=='\t')state=OUT;else if(state==OUT){state=IN;if(isFirstChar)isFirstChar=0;else putchar('\n');putchar(c);}else putchar(c);}}
