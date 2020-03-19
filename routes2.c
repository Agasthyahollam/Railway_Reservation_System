#include<stdio.h>
#include<string.h>
int destination_ctr=0;
int origin_ctr=0;
int r1_ctr=0;
int r2_ctr=0;
int r3_ctr=0;
int r4_ctr=0;
int r5_ctr=0;
int r1,r2,r3,r4,r5,r1c,r2c,r3c,r4c,r5c;
void main()
{
char route_1[4][20]={"Delhi","Kanpur","Lucknow","Gorakhpur"},origin_station[20],destination[20];
char route_2[4][20]={"Delhi","Ghaziabad","Kanpur","Lucknow"};
char route_3[4][20]={"Delhi","Ghaziabad","Kanpur","Allahabad"};
char route_4[5][20]={"Delhi","Alwar","Jaipur","Jodhpur","Bikaner"};
char route_5[5][20]={"Delhi","Ambala","Ludhiana","Jalandhar","Amritsar"};
char route_1_train[]="Humsafar Express(12596)";
char route_2_train[]="Tejas Express(82502)";
char route_3_train[]="Ndls Hwh Special(04008)";
char route_4_train[]="Rajasthan Sampark Kranti Express(12463)";
char route_5_train[]="Amritsar Shatabdi Express(12031)";
char stations[14][20]={"Delhi","Kanpur","Lucknow","Gorakhpur","Ghaziabad","Allahabad","Alwar","Jaipur","Jodhpur","Bikaner","Ambala","Ludhiana","Jalandhar","Amritsar"};
printf("The Available Stations are:");
for(int j=0;j<14;j++)
{
printf("%s ",stations[j]);
}
printf("\n");
repeat:
printf("Enter Origin\n");
scanf("%s",origin_station);
for(int i=0;i<14;i++)
{
if(strcmp(origin_station,stations[i])==0)
{
origin_ctr=1;
break;
}
}
if(origin_ctr==0)
{
printf("Station Not Found\n");
goto repeat;
}
else
{printf("Enter Destination\n");
}
for(r1=0;r1<4;r1++)  //route 1
{
if(strcmp(origin_station,route_1[r1])==0)
{
r1_ctr=1;
break;
} 
}
for(r2=0;r2<4;r2++) //route 2
{
if(strcmp(origin_station,route_2[r2])==0)
{
r2_ctr=1;
break;
} 
}
for( r3=0;r3<4;r3++) //route 3
{
if(strcmp(origin_station,route_3[r3])==0)
{
r3_ctr=1;
break;
} 
}
for(r4=0;r4<5;r4++) //route 4
{
if(strcmp(origin_station,route_4[r4])==0)
{
r4_ctr=1;
break;
} 
}
for(r5=0;r5<5;r5++) //route 5
{
if(strcmp(origin_station,route_5[r5])==0)
{
r5_ctr=1;
break;
} 
}
if(r1_ctr==1)      //route 1
{
printf("Train Name: %s Available Destinations: ",route_1_train);
for(r1c=r1+1;r1c<4;r1c++)
printf("%s ",route_1[r1c]);
printf("\n");
}
if(r2_ctr==1)    //route 2
{
printf("Train Name: %s Available Destinations: ",route_2_train);
for(r2c=r2+1;r2c<4;r2c++)
printf("%s ",route_2[r2c]);
printf("\n");
}
if(r3_ctr==1)    //route 3
{
printf("Train Name: %s Available Destinations: ",route_3_train);
for(r3c=r3+1;r3c<4;r3c++)
printf("%s ",route_3[r3c]);
printf("\n");
}
if(r4_ctr==1)   //route 4
{
printf("Train Name: %s Available Destinations: ",route_4_train);
for(r4c=r4+1;r4c<5;r4c++)
printf("%s ",route_4[r4c]);
printf("\n");
}
if(r5_ctr==1)   //route 5
{
printf("Train Name: %s Available Destinations: ",route_5_train);
for(r5c=r5+1;r5c<5;r5c++)
printf("%s ",route_5[r5c]);
printf("\n");
}
}

