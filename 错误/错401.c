#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {
	int q;
	scanf ("%d",&q);
	int p;
	p=q+2;
	int a[p];
	a[p]=(1,1);
	
	int i;	
	a=&a[1];
	int *a;

	float x=1.0;
    float y=0;
    for(i=2;i<=p-1;i++){
    	a[i]=a[i-1]+a[i-2];
    	*a++;
		printf("%d",*a);
	}
}
