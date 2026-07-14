#include"stdio.h"
#define TAB 8
main(){char c;int tabPoint=0;while((c=getchar())!=EOF){if(c=='\t'){for(int i=0;i<TAB-tabPoint;i++)putchar(' ');tabPoint=0;}else{putchar(c);tabPoint++;if(tabPoint==8)tabPoint=0;if(c=='\n')tabPoint=0;}}}
