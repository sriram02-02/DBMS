#include"storeandsort.h"
int main()
{struct Node *start=NULL;
    char fname[100];
    printf("enter the file name which is to be searched:");
    gets(fname);
    start=sing(start,fname);
    lsearch(start);
       
    return 0;
}