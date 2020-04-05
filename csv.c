#include<stdio.h>
#include<string.h>
void main()
{
FILE *fp;
fp=fopen("Booking.csv","w+");
fprintf(fp,"Seat,Train No,Tier,PNR");
fprintf(fp,"\n");
fclose(fp);
fp=fopen("Login1.csv","w+");
fprintf(fp,"Name,Username,Password,Phone No");
fprintf(fp,"\n");
fclose(fp);
}
