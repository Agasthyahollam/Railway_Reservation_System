#include<stdio.h>
#include<string.h>
/*make array of different departure times,arrival time,cost in 2ac,3ac,sleeper in different routes
for different costs take the index number of origin and destination in that route and multiply it with a constant value like rs.150*/
int passangers(int x)
{
    printf("enter the number of passengers travelling = ");
    scanf("%d",&x);
    return x;

}
char tier(char x)
{
    printf("enter the class you want to travel = \n ");
    scanf("%s",&x);
    printf("The class you choose = %s",&x);
    return x;


}
int trainno(int x)
{
    printf("enter the train number in which you wish to travel  = ");
    scanf("%d",&x);
    return x;

}
int r1num=12596;
int r2num=82502;
int r3num=40080;
int r4num=12463;
int r5num=12031;
int nopass;
char class[20];
int trno;
int diff_r1;
int diff_r2;
int diff_r3;
int diff_r4;
int diff_r5;

char arr_r1[4][20]={"start","01:50","02:15","07:50"};
char arr_r2[4][20]={"start","16:09","20:35","22:05"};
char arr_r3[4][20]={"start","20:08","01:45","04:20"};
char arr_r4[5][20]={"start","02:49","05:05","10:25","12:45"};
char arr_r5[5][20]={"start","09:55","11:27","12:23","13:40"};

char dep_r1[4][20]={"00:05","01:55","02:25","end"};
char dep_r2[4][20]={"15:35","16:11","20:40","end"};
char dep_r3[4][20]={"19:40","20:10","01:50","end"};
char dep_r4[5][20]={"00:25","02:52","05:15","10:35","end"};
char dep_r5[5][20]={"07:20","09:57","11:30","12:25","end"};

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
char route_3_train[]="Ndls Hwh Special(40080)";
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
printf("Enter Destination\n");
scanf("%s",destination);

for(r1c=r1+1;r1c<4;r1c++)  //route 1
{
if((r1_ctr==1)&&(strcmp(destination,route_1[r1c])==0))
{
diff_r1=r1c-r1;
printf("Train Name: %s\n%s Arrival: %s Departure: %s \n%s Arrival: %s\nFare: sleeper ₹%d AC 3 tier ₹%d AC 2 tier ₹%d\n",route_1_train,origin_station,arr_r1[r1],dep_r1[r1],destination,arr_r1[r1c],diff_r1*150,diff_r1*350,diff_r1*450);
}}
for(r2c=r2+1;r2c<4;r2c++)  //route 2
{
if((r2_ctr==1)&&(strcmp(destination,route_2[r2c])==0))
{
diff_r2=r2c-r2;
printf("Train Name: %s\n%s Arrival: %s Departure: %s \n%s Arrival: %s\nFare: sleeper ₹%d AC 3 tier ₹%d AC 2 tier ₹%d\n",route_2_train,origin_station,arr_r2[r2],dep_r2[r2],destination,arr_r2[r2c],diff_r2*200,diff_r2*400,diff_r2*500);
}}
for(r3c=r3+1;r3c<4;r3c++)  //route 3
{
if((r3_ctr==1)&&(strcmp(destination,route_3[r3c])==0))
{
diff_r3=r3c-r3;
printf("Train Name: %s\n%s Arrival: %s Departure: %s \n%s Arrival: %s\nFare: sleeper ₹%d AC 3 tier ₹%d AC 2 tier ₹%d\n",route_3_train,origin_station,arr_r3[r3],dep_r3[r3],destination,arr_r3[r3c],diff_r3*175,diff_r3*375,diff_r3*575);
}}
for(r4c=r4+1;r4c<5;r4c++)  //route 4
{
if((r4_ctr==1)&&(strcmp(destination,route_4[r4c])==0))
{
diff_r4=r4c-r4;
printf("Train Name: %s\n%s Arrival: %s Departure: %s \n%s Arrival: %s\nFare: sleeper ₹%d AC 3 tier ₹%d AC 2 tier ₹%d\n",route_4_train,origin_station,arr_r4[r4],dep_r4[r4],destination,arr_r4[r4c],diff_r4*250,diff_r4*450,diff_r4*700);
}}
for(r5c=r5+1;r5c<5;r5c++)  //route 5
{
if((r5_ctr==1)&&(strcmp(destination,route_5[r5c])==0))
{
diff_r5=r5c-r5;
printf("Train Name: %s\n%s Arrival: %s Departure: %s \n%s Arrival: %s\nFare: sleeper ₹%d AC 3 tier ₹%d AC 2 tier ₹%d\n",route_5_train,origin_station,arr_r5[r5],dep_r5[r5],destination,arr_r5[r5c],diff_r5*260,diff_r5*500,diff_r5*650);
}}

int pass1 = passangers(nopass);
printf("selected number of passsengers = %d \n",pass1);
int trainno1=trainno(trno);
printf("selected train = %d \n",trainno1);
    if(trainno1==r1num)
    {
        printf("train name = Humsafar Express \n");
    }
    if(trainno1==r2num)
    {
        printf("train name = Tejas Express \n");
    }
    if(trainno1==r3num)
    {
        printf("train name = Ndls Hwh Special\n");
    }
    if(trainno1==r4num)
    {
        printf("train name = Rajasthan Sampark Kranti Express\n");
    }
    if(trainno1==r5num)
    {
        printf("train name = Amritsar Shatabdi Express\n");
    }

tier(*class);
}

