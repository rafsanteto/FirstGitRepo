#include<stdio.h>

int main()
{
    char hello[]={"Hello"};
    char *world="World";

    printf("*%d*\n",printf("Hello World %d",66555455));
    printf("%d %d\n",sizeof(hello),sizeof(world));
    printf("%c %c\n",hello[6],world[6]);
    printf("%d %d\n",hello[6],world[6]);

    return 0;
}
