#include<stdio.h>
#define LOWER -140
#define UPPER 140
#define STEP 20
float celsius(int fahr){return(5.0/9.0)*(fahr-32);}
main(){int f;for(f=LOWER;f<=UPPER;f+=STEP)printf("%3d %6.1f\n",f,celsius(f));}
