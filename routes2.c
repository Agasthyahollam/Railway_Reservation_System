#include<stdio.h>
#include<string.h>
int destination_ctr=0;
int origin_ctr=0;
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
char total_routes[5][5][20]={{"Delhi","Kanpur","Lucknow","Gorakhpur"},{"Delhi","Ghaziabad","Kanpur","Lucknow"},{"Delhi","Ghaziabad","Kanpur","Allahabad"},{"Delhi","Alwar","Jaipur","Jodhpur","Bikaner"},{"Delhi","Ambala","Ludhiana","Jalandhar","Amritsar"}};
int ctr=0;
repeat:
printf("Enter Origin");
scanf("%s",origin_station);
printf("Enter Destination");
scanf("%s",destination);
for(int k=0;k<6;k++)
{printf("%s",total_routes[k]+k);
ctr=checking_validity(total_routes+k,origin_station,destination);}
if(ctr==0)
{
printf("Invalid Option Chosen,please try again");
goto repeat;
}
printf("The ticket is from%s to %s",origin_station,destination);
}
int checking_validity(char route[5][20],char orig[20],char desti[20])
{
int station_num=strlen(route);
for(int i=0;i<station_num;i++)
{
if ((strcmp(orig,route[i]) == 0)&& (strcmp(orig,route[station_num-1])!=0))
origin_ctr=1;
break;
}
for(int j=0;j<station_num;j++)
{
if ((strcmp(desti,route[j]) == 0)&& (strcmp(desti,orig)!=0))
destination_ctr=1;
break;
}
return (destination_ctr&&origin_ctr);
}
