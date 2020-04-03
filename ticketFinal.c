#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void payment();
void passname(int seat);
void ticket();
int seat_num;
char passenger[20][20];
char origin_station[20],destination[20];
char r_no_choice[10];
char choice1[15];
/*make array of different departure times,arrival time,cost in 2ac,3ac,sleeper in different routes
for different costs take the index number of origin and destination in that route and multiply it with a constant value like rs.150*/
int diff_r1=0;
int diff_r2=0;
int diff_r3=0;
int diff_r4=0;
int diff_r5=0;
int total_fare;
float total;
char name[12];
int seat[5][3];
char trname[40];
char arr_origin[10];
char dep_dest[10];
char arr_dest[10];
char pay[3][20]={"Paytm","Debit Card","Credit Card"};
int fare[5][3]={{150,350,450},{200,400,500},{175,375,575},{250,450,700},{260,500,650}};

char class_choice[5];
char class[3][5]={"SL","AC3","AC2"};
int class_ctr=0;

void display(int n)
{
printf("Number of seats avaiable\n");
printf("%s - %d\n",class[0],seat[n][0]);
printf("%s - %d\n",class[1],seat[n][1]);
printf("%s - %d\n",class[2],seat[n][2]);
}

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
void main(){
printf("Enter Customer Name\n");
scanf("%s",name);


FILE * fptr;
  fptr = fopen ("seat.txt", "r");
    if (fptr == NULL){
        printf("Error Reading File\n");
        exit (0);
    }  
	for(int i=0;i<5;i++)
	{
	for(int j=0;j<3;j++)
		fscanf(fptr,"%d ",&seat[i][j]);
	}
    fclose (fptr);


char r_no[5][10]={"12596","82502","04008","12463","12031"};
int r_no_ctr=0;

char route_1[4][20]={"Delhi","Kanpur","Lucknow","Gorakhpur"};
char route_2[4][20]={"Delhi","Ghaziabad","Kanpur","Lucknow"};
char route_3[4][20]={"Delhi","Ghaziabad","Kanpur","Allahabad"};
char route_4[5][20]={"Delhi","Alwar","Jaipur","Jodhpur","Bikaner"};
char route_5[5][20]={"Delhi","Ambala","Ludhiana","Jalandhar","Amritsar"};

char route_train[5][100]={"Humsafar Express(12596)","Tejas Express(82502)","Ndls Hwh Special(04008)","Rajasthan Sampark Kranti Express(12463)","Amritsar Shatabdi Express(12031)"};

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
printf("Train Name: %s Available Destinations: ",route_train[0]);
for(r1c=r1+1;r1c<4;r1c++)
printf("%s ",route_1[r1c]);
printf("\n");
}
if(r2_ctr==1)    //route 2
{
printf("Train Name: %s Available Destinations: ",route_train[1]);
for(r2c=r2+1;r2c<4;r2c++)
printf("%s ",route_2[r2c]);
printf("\n");
}
if(r3_ctr==1)    //route 3
{
printf("Train Name: %s Available Destinations: ",route_train[2]);
for(r3c=r3+1;r3c<4;r3c++)
printf("%s ",route_3[r3c]);
printf("\n");
}
if(r4_ctr==1)   //route 4
{
printf("Train Name: %s Available Destinations: ",route_train[3]);
for(r4c=r4+1;r4c<5;r4c++)
printf("%s ",route_4[r4c]);
printf("\n");
}
if(r5_ctr==1)   //route 5
{
printf("Train Name: %s Available Destinations: ",route_train[4]);
for(r5c=r5+1;r5c<5;r5c++)
printf("%s ",route_5[r5c]);
printf("\n");
}
printf("Enter Destination\n");
scanf("%s",destination);
system("clear");


for(r1c=r1+1;r1c<4;r1c++)  //route 1
{
if((r1_ctr==1)&&(strcmp(destination,route_1[r1c])==0))    
{
diff_r1=r1c-r1;
printf("Train Name: %s\n%s Arrival: %s Departure: %s \n%s Arrival: %s\nFare: sleeper ₹%d\n AC 3 tier ₹%d\n AC 2 tier ₹%d\n",route_train[0],origin_station,arr_r1[r1],dep_r1[r1],destination,arr_r1[r1c],diff_r1*fare[0][0],diff_r1*fare[0][1],diff_r1*fare[0][2]);
display(0);

strcpy(arr_origin,arr_r1[r1]);
strcpy(dep_dest,dep_r1[r1]);
strcpy(arr_dest,arr_r1[r1c]);
}
}
for(r2c=r2+1;r2c<4;r2c++)  //route 2
{
if((r2_ctr==1)&&(strcmp(destination,route_2[r2c])==0))    
{
diff_r2=r2c-r2;
printf("Train Name: %s\n%s Arrival: %s Departure: %s \n%s Arrival: %s\nFare: sleeper ₹%d\n AC 3 tier ₹%d\n AC 2 tier ₹%d\n",route_train[1],origin_station,arr_r2[r2],dep_r2[r2],destination,arr_r2[r2c],diff_r2*fare[1][0],diff_r2*fare[1][1],diff_r2*fare[1][2]);
display(1);

strcpy(arr_origin,arr_r2[r2]);
strcpy(dep_dest,dep_r2[r2]);
strcpy(arr_dest,arr_r2[r2c]);
}}
for(r3c=r3+1;r3c<4;r3c++)  //route 3
{
if((r3_ctr==1)&&(strcmp(destination,route_3[r3c])==0))    
{
diff_r3=r3c-r3;
printf("Train Name: %s\n%s Arrival: %s Departure: %s \n%s Arrival: %s\nFare: sleeper ₹%d\n AC 3 tier ₹%d\n AC 2 tier ₹%d\n",route_train[2],origin_station,arr_r3[r3],dep_r3[r3],destination,arr_r3[r3c],diff_r3*fare[2][0],diff_r3*fare[2][1],diff_r3*fare[2][2]);
display(2);

strcpy(arr_origin,arr_r3[r3]);
strcpy(dep_dest,dep_r3[r3]);
strcpy(arr_dest,arr_r3[r3c]);
}}
for(r4c=r4+1;r4c<5;r4c++)  //route 4
{
if((r4_ctr==1)&&(strcmp(destination,route_4[r4c])==0))    
{
diff_r4=r4c-r4;
printf("Train Name: %s\n%s Arrival: %s Departure: %s \n%s Arrival: %s\nFare: sleeper ₹%d\n AC 3 tier ₹%d\n AC 2 tier ₹%d\n",route_train[3],origin_station,arr_r4[r4],dep_r4[r4],destination,arr_r4[r4c],diff_r4*fare[3][0],diff_r4*fare[3][1],diff_r4*fare[3][2]);
display(3);

strcpy(arr_origin,arr_r4[r4]);
strcpy(dep_dest,dep_r4[r4]);
strcpy(arr_dest,arr_r4[r4c]);
}}
for(r5c=r5+1;r5c<5;r5c++)  //route 5
{
if((r5_ctr==1)&&(strcmp(destination,route_5[r5c])==0))    
{
diff_r5=r5c-r5;
printf("Train Name: %s\n%s Arrival: %s Departure: %s \n%s Arrival: %s\nFare: sleeper ₹%d\n AC 3 tier ₹%d\n AC 2 tier ₹%d\n",route_train[4],origin_station,arr_r5[r5],dep_r5[r5],destination,arr_r5[r5c],diff_r5*fare[4][0],diff_r5*fare[4][1],diff_r5*fare[4][2]);
display(4);

strcpy(arr_origin,arr_r5[r5]);
strcpy(dep_dest,dep_r5[r5]);
strcpy(arr_dest,arr_r5[r5c]);
}}
int diff_r[5]={diff_r1,diff_r2,diff_r3,diff_r4,diff_r5};
int i;
repeat2:
printf("Enter Train number you wish to travel\n");
scanf("%s",r_no_choice);
system("clear");
for(i=0;i<5;i++)
{
if(strcmp(r_no_choice,r_no[i])==0)
{strcpy(trname,route_train[i]);
r_no_ctr=1;
break;
}
}
if(r_no_ctr==0)
{
printf("Invalid Selection\nSelect Again\n");
goto repeat2;
}
int j;
repeat3:
printf("Enter the Tier SL/AC2/AC3\n");
scanf("%s",class_choice);
for(j=0;j<3;j++)
{
if(strcmp(class_choice,class[j])==0)
{
class_ctr=1;
break;
}}
if(class_ctr==0)
{
printf("Invalid Class chosen\nPlease try again\n");
goto repeat3; 
}
repeat4:
printf("Enter Number of seats\n");
scanf("%d",&seat_num);
if(seat_num<=seat[i][j])
{//Total fare calculation
 total_fare=diff_r[i]*fare[i][j]*seat_num;
float GST=(total_fare * 5)/100;
total=total_fare+GST;
seat[i][j]=seat[i][j]-seat_num;
printf(" Fare = %d \n",total_fare);
printf("Total Fare Inclusive of GST= %f\n",total);

}
else
{printf("Number of seats chosen exceeds the available seats\nPlease Try Again\n");
goto repeat4;}
printf("Number of seats left\n");
system("clear");
payment();
  

for(int i=0;i<5;i++)
{
for(int j=0;j<3;j++)
{
printf("Train Number %s ",r_no[i]);
printf("%s - %d ",class[j],seat[i][j]);
}
printf("\n");
}
FILE * fptr2;
  fptr2 = fopen ("seat.txt", "w");  

	for(int i=0;i<5;i++)
	{
	for(int j=0;j<3;j++)
		fprintf(fptr2,"%d ",seat[i][j]);
	}
    fclose (fptr2);

passname(seat_num);
ticket();
}

void payment()
{
int choice;

char debit[20];
char cvv[20];
char Credit[20];
char ph[20];
printf("The amount to be paid is:%f\n",total);
return17:
printf("Choose ur prefered Payment Mode\n");

printf("1.Paytm\n 2.Debit Card \n 3.Credit Card\n");
scanf("%d",&choice);
if (choice ==1)
{strcpy(choice1,pay[0]);
printf("You have chosen Paytm\n");
return20:
printf("enter the Phone number linked to Paytm\n");
scanf("%s",ph);

if (strlen(ph)==10)
{
printf("Valid Phone Number\n");
return19:
printf("enter PIN\n");
scanf("%s",cvv);
if (strlen(cvv)==6)
{
printf("Payment Sucessful\n");
}
else
{
printf("enter PIN again\n");
goto return19;
}
}
else 
{
printf("Invalid phno\n Enter phno again\n");
goto return20;
}}
else if (choice ==2)
{strcpy(choice1,pay[1]);
printf("you have chosen to pay through Debit Card\n");
return14:
printf("Enter Card Number\n");
scanf("%s",debit);
int q=strlen(debit);
if(q==16)
{
printf("Valid Debit Card Number\n");
return13:
printf("enter CVV\n");
scanf("%s",cvv);
if (strlen(cvv)==3)
{
printf("Payment Sucessful\n");
choice=0;
}
else
{
printf("invalid CVV\n pls enter CVV again\n");
goto return13;
}
}
else
{
printf("INVALID DEBIT CARD NUMBER\n");
goto return14;
}
}

else if (choice ==3)
{strcpy(choice1,pay[2]);
printf("you have chosen to pay through Credit Card\n");

return15:
printf("Enter Card Number\n");
scanf("%s",debit);
int q=strlen(debit);
if(q==16)
{
printf("Valid Credit Card Number\n");
return16:
printf("enter CVV\n");
scanf("%s",cvv);
if (strlen(cvv)==3)
{
printf("Payment Sucessful\n");

}
else
{
printf("Invalid CVV\n pls enter CVV\n");
goto return16;
}
}
else
{
printf("INVALID CREDIT CARD NUMBER");
goto return15;

}
}
else 
{
printf("INVALID CHOICE\n pls enter again\n");
goto return17;
}
}
void passname(int seat)
{
for(int i=0;i<seat_num;i++)
{
printf("enter passenger name\n");
scanf("%s",&passenger[i][20]);//this makes it warning free in my system if it shows errors pls change

}}

void ticket()
{


FILE * fptr1;
fptr1 = fopen ("ticket.txt", "w");
fprintf(fptr1,"*******************************************************TICKET*******************************************************\n");
fprintf(fptr1,"Customer Name - %s\n ",name);
fprintf(fptr1,"Train name: %s\t\t\t\t Train number: %s\n",trname,r_no_choice);
fprintf(fptr1,"Origin: %s \t\t\t Destination :%s \n" ,origin_station,destination);
fprintf(fptr1,"Arrival at Origin: %s \t Departure from Origin: %s \t Arrival at Destination:%s \n",arr_origin,dep_dest,arr_dest);
fprintf(fptr1,"No of Seats Booked: %d",seat_num);
fprintf(fptr1,"\t\t\t\t\t\t\tTier Booked : %s\n",class_choice);

fprintf(fptr1,"PASSENGER NAMES\n");
for(int j=0;j<seat_num;j++)
{
fprintf(fptr1,"%s\n",&passenger[j][20]);//this makes it warning free in my system if it shows errors pls change(remove &)

}
fprintf(fptr1,"Total Cost(Inclsive Of GST) =%f\t\t\t\t",total);
fprintf(fptr1,"Payment Mode:%s\n",choice1);

	
    fclose (fptr1);
}






