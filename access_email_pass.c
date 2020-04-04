#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
void main()
{
char email[3][100];
char password[3][100];
int z=0;
int k=0;
FILE * fptr;
  fptr = fopen ("login.txt", "r");
    if (fptr == NULL){
        printf("Error Reading File\n");
        exit (0);
    }  
for(int i=0;i<6;i++)
{
if(i%2==0)
{
fscanf(fptr,"%s ",email[k]);
k++;
}
else
{fscanf(fptr,"%s ",password[z]);
z++;}
}
    fclose (fptr);
for(int i=0;i<3;i++)
{
printf("%s \n",email[i]);
printf("%s \n",password[i]);
}
}
