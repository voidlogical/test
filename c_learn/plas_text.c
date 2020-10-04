#include <stdio.h>

 int main() {
    int a;
    int i;
    a = 10;
    int length;
    int x[] = {2,4,5,1,24,24,};
    length = sizeof(x)/sizeof(x[0]);
    for (i=0; i<length; i++)
    {
      printf("%d ", x[i]);
    }
    printf("\na++=%d\n", a++);
    printf("a=%d\n", a);
    printf("++a=%d\n", ++a);
    printf("a=%d\n", a);
    getchar();
    return 0;
 }
