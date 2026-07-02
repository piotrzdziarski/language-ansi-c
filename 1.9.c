#include"stdio.h"
main(){int c,b=0;while((c=getchar())!=EOF){if(b==0){putchar(c);}else if(c!=' '){b=0;putchar(c);}if(c==' ')b=1;}}
