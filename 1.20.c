#include"stdio.h"
#define TAB 4
main(){char c;while((c=getchar())!=EOF)if(c=='\t')for(int i=0;i<TAB;i++)putchar(' ');else putchar(c);}
