// A solution with a vertical histogram
#include<stdio.h>
#define IN 1
#define OUT 0
#define MAX_HIST 1000
int power(int b,int n){int p,i;for(p=1,i=1;i<=n;++i)p*=b;return p;} 
// "p" starts at position number 1; returns -1 if position is too large or too small
int digitAtPosition(int n, int p){if(p<=0)return -1;int divider = 1,i,singleN;for(i=1;(n / divider)>=10;i++)divider=power(10,i);if(p>i)return -1;for(;p!=i;i--){singleN=n/divider;n-=singleN*divider;divider/=10;}return n/divider;}
int digitsCount(int n){int i;for(i=0;n!=0;i++)n/=10;return i;}
main(){int c,state=OUT,isFirstChar=1,wl=0,h[MAX_HIST];for(int i=0;i<MAX_HIST;i++)h[i]=0;while((c=getchar())!=EOF){if(c==' '||c=='\n'||c=='\t')state=OUT;else if(state==OUT){state=IN;if(isFirstChar)isFirstChar=0;else h[wl-1]++;wl=1;}else wl++;}h[wl-1]++;
int max=h[0],count=0;for(int i=0;i<MAX_HIST;i++)if(h[i]){count++;if(max<h[i])max=h[i];}
for (int i = max; i > 0; i--) {
	for (int j = 0; j < MAX_HIST; j++) {
		if (h[j] >= i) putchar('*');
		else if (h[j]) putchar(' ');
	}
	printf("\n");
}
int maxIndex=1;for(int i=0;i<MAX_HIST;i++)if(h[i]&&i>maxIndex)maxIndex=i+1;
for (int i = 1; i <= digitsCount(maxIndex); i++) {
	for (int j = 0; j < MAX_HIST; j++) {
		int single_number = digitAtPosition(j + 1, digitsCount(j + 1) - i + 1);
		if (!h[j]) continue;
		if (single_number != -1) printf("%d", single_number);
		else putchar(' ');
	}
	printf("\n");
}
}
