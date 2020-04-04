#include <stdio.h>
#define len 100
int person=0;
void dataSliceLogin(char *details){
    int i=0;
    int x=0;
    int y=0;
    char LOGINDATA[20][20];
    //int length=0;
    while(details[i]!=';'){
        if(details[i]==','){
            printf("\n");
            LOGINDATA[x][y]='\0';
            x++;
            y=0;
        }
        else{
            printf("%c",details[i]);
            LOGINDATA[x][y]=details[i];
            y++;
        }
        i++;

    }
    printf("\n");
    i=0;
    printf("data slicing over for line \n");

}
void LoginDetails()
{
    FILE* fp1=fopen("login.txt","r");
    if (fp1==NULL)
    {
        printf("unable to open the file \n");
    }
    else
    {
        printf("file has been opened \n ");
        char buf[len];
        while((fgets(buf, len, fp1)!=NULL)){
            dataSliceLogin(buf);
        }

    }

}


int main()
{
    printf("Hello World!\n");
    LoginDetails();
    return 0;
}
