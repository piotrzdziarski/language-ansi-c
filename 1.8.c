#include"stdio.h"
#include"limits.h"
main(){int c,nl=0,tb=0,sp=0;while((c=getchar())!=EOF){if(c=='\n')++nl;if(c=='\t')tb++;if(c==' ')sp++;}printf("Spacje: %d, Tabulacje: %d, Nowe linie: %d\n",sp,tb,nl);}
