#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
	int age;
    char name[100];
    char roll[100];
    char branch[100];
	struct Node *next;
};
struct Node* insertAtTheBegin(struct Node *head, int age, char *name,char *branch,char *roll)
{
    
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->age = age;
    strcpy(temp->name, name);
    strcpy(temp->roll, roll);
    strcpy(temp->branch, branch);
    temp->next = NULL; 
    if(head==NULL)
    {
        head = temp;    
    }
    else 
    {
        temp->next = head;
        head = temp;
    }    
    return head;
}
void printList(struct Node *start,char *fname1,char *fname2)
{
	struct Node *temp = start;
    if (strcmp(fname2,"")==0){
    FILE *f=fopen("dataout.txt","w");
    char age1[10];
	printf("\n");
	while (temp!=NULL)
	{
    fprintf(f,temp->name);
    fprintf(f,"|");
    fprintf(f,temp->roll);
    fprintf(f,"|");
    fprintf(f,temp->branch);
    fprintf(f,"|");
    sprintf(age1,"%d",temp->age);
    fprintf(f,age1);
    fprintf(f,"\n");
		temp = temp->next;
	}
    printf("\n File successfully sorted based on roll no and added to dataout.txt\n");
    fclose(f);
}
else{
    FILE *f=fopen("data3.txt","w");
    char age1[10];
	printf("\n");
	while (temp!=NULL)
	{
    fprintf(f,temp->name);
    fprintf(f,"|");
    fprintf(f,temp->roll);
    fprintf(f,"|");
    fprintf(f,temp->branch);
    fprintf(f,"|");
    sprintf(age1,"%d",temp->age);
    fprintf(f,age1);
    fprintf(f,"\n");
		temp = temp->next;
	}
    printf("\n File successfully sorted based on roll no and added to data3.txt\n");
    fclose(f);
}}
void swap(struct Node *a, struct Node *b)
{
	int temp = a->age;
	a->age = b->age;
	b->age = temp;
	char t[100];
	strcpy(t,a->branch);
	strcpy(a->branch,b->branch);
	strcpy(b->branch,t);
	strcpy(t,a->roll);
	strcpy(a->roll,b->roll);
	strcpy(b->roll,t);
	strcpy(t,a->name);
	strcpy(a->name,b->name);
	strcpy(b->name,t);	
}
void selectionSort(struct Node *head)
{
	struct Node *current = head, *index = NULL;    
          
        if(head == NULL){  
            return;  
        }  
        else {  
            while(current != NULL) {   
                index = current->next;      
                while(index != NULL) {  
                    if(strcmp(current->roll,index->roll)>0) {  
                        swap(current,index);
                    }  
                    index = index->next;  
                }  
                current = current->next;  
            }      
        }  
}
void append(char *fname){
    FILE *f=fopen(fname,"a");
    char name[100];
    char roll[100];
    char branch[100];
    char age[100];
    int nost;
    char buff[3];
    printf("enter no of students:");
    scanf("%d",&nost);
    gets(buff);
    for(int i=0;i<nost;i++){
    printf("enter name:");
    gets(name);
    printf("enter roll:");
    gets(roll);
    printf("enter branch:");
    gets(branch);
    printf("enter age:");
    gets(age);
    fprintf(f,name);
    fprintf(f,"|");
    fprintf(f,roll);
    fprintf(f,"|");
    fprintf(f,branch);
    fprintf(f,"|");
    fprintf(f,age);
    fprintf(f,"\n");
    }
fclose(f);
printf("successfully appended\n");
}
struct Node *readlist(struct Node *start,char *fname){
    char name[100];
    char roll[100];
    char branch[100];
    int age;
    FILE *f;
    f=fopen(fname,"r");
    char temp[300];
    while(fgets(temp,sizeof(temp),f))
    {int c=0;
        char *token = strtok(temp,"|");
    while (token != NULL)
    {
        if(c==0)
        strcpy(name,token);
        else if(c==1)
        strcpy(roll,token);
        else if(c==2)
        strcpy(branch,token);
        else
        age=atoi(token);
        c++;
       token = strtok(NULL, "|");
    }
    start=insertAtTheBegin(start,age,name,branch,roll);
}
fclose(f);
return start;
}
struct Node *sing(struct Node *start,char *c)
{
    start=readlist(start,c);
    return start;
}
struct Node *merge(struct Node *start,char *c1,char *c2){
    start=readlist(start,c1);
    start=readlist(start,c2);    
    return start;
}
void choice()
{ 
printf("WARNING:unsusal termination of program cause loss of contents in data.txt file\n");
int ch;
struct Node *start=NULL;
char fname[100];
int x=1;
    while(x){
        struct Node *start=NULL;
printf("enter 1 to append values into a file\n");
printf("enter 2 to sort a single file\n");
printf("enter 3 to merge and sort two files\n");
printf("enter 0 to exit\n");
printf("enter choice:\n");
scanf("%d",&ch);
char buff[2];
gets(buff);
switch (ch)
{
    case 0:
    x=0;
    break;
case 1:

printf("enter the file name:");
gets(fname);
append(fname);
break;
case 2:

printf("enter the file name:");
gets(fname);
start=sing(start,fname);
selectionSort(start);
    printList(start,fname,"");
    break;
case 3:
char fname1[100];
printf("enter the file1 name:");
gets(fname1);
char fname2[100];
printf("enter the file2 name:");
gets(fname2);
start=merge(start,fname1,fname2);
selectionSort(start);
    printList(start,fname1,fname2);
break;
default:
printf("invalid");
    break;
}
printf("\n");
}
}
void lsearch(struct Node *start){
    struct Node *current = start;
    
    printf("enter then roll no to be searched:");
    char sroll[100];
    gets(sroll);
    int x=0;
    double time_taken;  
        if(current == NULL){  
            printf("NO data found in file\n");  
        }  
        else {  
    clock_t start,end;
    start=clock();
            while(current != NULL) {   
                    if(strcmp(current->roll,sroll)==0) {  
                        printf("name: %s\n",current->name);
                        printf("roll: %s\n",current->roll);
                        printf("branch: %s\n",current->branch);
                        printf("age: %d\n",current->age);
                        x=1;
                        break;
                    }
                    current = current->next;
                }  
            end=clock();
            time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;      
            }
            if(x==0)
            printf(" given roll no not found\n");   
    printf("time taken= %lf\n",time_taken);
}