#include<stdio.h>
#include<string.h>
void main()
{
char route_1[5][20]={"Ranchi","Bokaro","Dhanbad","Durgapur","Kolkata"},origin_station[20],destination[20];
int destination_ctr=0;
int origin_ctr=0;
char route_1_train[]="Shatabdi Express(12020)";
repeat:
printf("Enter Origin");
scanf("%s",origin_station);
printf("Enter Destination");
scanf("%s",destination);
int station_num=strlen(route_1);
for(int i=0;i<5;i++)
{
if ((strcmp(origin_station,route_1[i]) == 0)&& (strcmp(origin_station,route_1[4])!=0))
origin_ctr=1;
}
for(int j=0;j<5;j++)
{
if ((strcmp(destination,route_1[j]) == 0)&& (strcmp(destination,origin_station)!=0))
destination_ctr=1;
}
if (origin_ctr==0)
{
printf("invalid origin station");
goto repeat;
}
if (destination_ctr==0)
{
printf("invalid destination station");
goto repeat;
}
printf("The ticket is from%s to %s",origin_station,destination);
}
