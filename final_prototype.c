#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
void payment();
void passname(int seat);
void display(int n);
long ticket();
long pnr();
void booking();
void register1();
void available_tickets();
void create_marks_csv();
void create();
int seat_num;
char passenger[20][20];
char origin_station[20],destination[20];
char r_no_choice[10];
char choice1[15];
long pnr_no;
int r_ctr[5]={0,0,0,0,0};
int orig_index[5]={0,0,0,0,0};
int dest_index[5]={0,0,0,0,0};

int total_fare;
float total;
char name[100];
int seat[5][3];
char pay[3][20]={"Paytm","Debit Card","Credit Card"};
int fare[5][3]={{150,350,450},{200,400,500},{175,375,575},{250,450,700},{260,500,650}};
char route [5][5][20]={{"Delhi","Kanpur","Lucknow","Gorakhpur"},{"Delhi","Ghaziabad","Kanpur","Lucknow"},{"Delhi","Ghaziabad","Kanpur","Allahabad"},{"Delhi","Alwar","Jaipur","Jodhpur","Bikaner"},{"Delhi","Ambala","Ludhiana","Jalandhar","Amritsar"}};

char class_choice[5];
char class[3][5]={"SL","AC3","AC2"};
int class_ctr=0;

char arr[5][5][20]={{"start","01:50","02:15","07:50"},{"start","16:09","20:35","22:05"},{"start","20:08","01:45","04:20"},{"start","02:49","05:05","10:25","12:45"},{"start","09:55","11:27","12:23","13:40"}};

char dep[5][5][20]={{"00:05","01:55","02:25","end"},{"15:35","16:11","20:40","end"},{"19:40","20:10","01:50","end"},{"00:25","02:52","05:15","10:35","end"},{"07:20","09:57","11:30","12:25","end"}};


int f_route_index=0;
int tier_index=0;

int r,rc;
char r_no[5][10]={"12596","82502","04008","12463","12031"};
char route_train[5][100]={"Humsafar Express(12596)","Tejas Express(82502)","Ndls Hwh Special(04008)","Rajasthan Sampark Kranti Express(12463)","Amritsar Shatabdi Express(12031)"};
void create_marks_csv1();
void create1();
void pass();
int  user();
int phno1();
char *substr(const char *src ,int m,int n);
char name[100], pwd[50], ver[25], usn[30], phno[15];
char com[10] = ".com"; char check[20];
int i, a, digi, up, low, schar, s, m, n;
char c=';';


void main()

{int a;
printf("press 1 for booking\n press 2 for registration\n");
printf("enter your choice\n");
scanf("%d",&a);

if (a==1)
{
printf("booking\n");
booking();
}
else if (a==2)
{
printf("register\n");
register1();
}
else
printf("wrong choice");
}
void booking()
{

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
printf("Enter Customer Name\n");                              //to be replaced with login and registration
scanf("%s",name);
system("clear");



int destination_ctr=0;
int origin_ctr=0;

int r_no_ctr=0;
int no_of_sta[5]={4,4,4,5,5};
int diff_r[5]={0,0,0,0,0};
char stations[14][20]={"Delhi","Kanpur","Lucknow","Gorakhpur","Ghaziabad","Allahabad","Alwar","Jaipur","Jodhpur","Bikaner","Ambala","Ludhiana","Jalandhar","Amritsar"};
printf("The Available Stations are:\n");
for(int j=0;j<14;j++)
{
printf("%s\n",stations[j]);
}
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
for(int i=0;i<5;i++)
{
for(r=0;r<no_of_sta[i];r++)  //route 1
{
if(strcmp(origin_station,route[i][r])==0)
{
r_ctr[i]=1;
orig_index[i]=r;
break;
}} 
}
for(int i=0;i<5;i++)
{if(r_ctr[i]==1)      //route 1
{
printf("Train Name: %s Available Destinations: ",route_train[i]);
for(rc=orig_index[i]+1;rc<no_of_sta[i];rc++)
printf("%s ",route[i][rc]);
printf("\n");
}}

printf("Enter Destination\n");
scanf("%s",destination);
system("clear");

for(int i=0;i<5;i++)
{
for(rc=orig_index[i]+1;rc<no_of_sta[i];rc++)  //route 1
{
if((r_ctr[i]==1)&&(strcmp(destination,route[i][rc])==0))    
{
diff_r[i]=rc-orig_index[i];
printf("Train Name: %s\n%s Arrival: %s Departure: %s \n%s Arrival: %s\nFare: sleeper ₹%d\n AC 3 tier ₹%d\n AC 2 tier ₹%d\n",route_train[i],origin_station,arr[i][orig_index[i]],dep[i][orig_index[i]],destination,arr[i][rc],diff_r[i]*fare[i][0],diff_r[i]*fare[i][1],diff_r[i]*fare[i][2]);
dest_index[i]=rc;
display(i);
break;
}
}}

repeat2:
printf("Enter Train number you wish to travel\n");
scanf("%s",r_no_choice);
for(int i=0;i<5;i++)
{
if(strcmp(r_no_choice,r_no[i])==0)
{
r_no_ctr=1;
f_route_index=i;
break;
}
}
if(r_no_ctr==0)
{
printf("Invalid Selection\nSelect Again\n");
goto repeat2;
}
repeat3:
printf("Enter the Tier SL/AC2/AC3\n");
scanf("%s",class_choice);
for(int j=0;j<3;j++)
{
if(strcmp(class_choice,class[j])==0)
{
class_ctr=1;
tier_index=j;
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
if(seat_num<=seat[f_route_index][tier_index])
{//Total fare calculation
 total_fare=diff_r[f_route_index]*fare[f_route_index][tier_index]*seat_num;
float GST=(total_fare * 5)/100;
total=total_fare+GST;
seat[f_route_index][tier_index]=seat[f_route_index][tier_index]-seat_num;
printf(" Fare = %d \n",total_fare);
printf("Total Fare Inclusive of GST= %f\n",total);

}
else
{printf("Number of seats chosen exceeds the available seats\nPlease Try Again\n");
goto repeat4;}
system("clear");
payment();
  
FILE * fptr2;
  fptr2 = fopen ("seat.txt", "w");  

	for(int i=0;i<5;i++)
	{
	for(int j=0;j<3;j++)
		fprintf(fptr2,"%d ",seat[i][j]);
	}
    fclose (fptr2);
passname(seat_num);
pnr_no=ticket();
	available_tickets();
 create_marks_csv();
 create();
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
printf("Press 1 for Paytm\nPress 2 for Debit Card \nPress 3 for Credit Card\n");
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
printf("enter your 6 digit PIN\n");
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

void display(int n)
{
printf("Number of seats avaiable\n");
printf("%s - %d\n",class[0],seat[n][0]);
printf("%s - %d\n",class[1],seat[n][1]);
printf("%s - %d\n",class[2],seat[n][2]);
}

long ticket()
{
FILE * fptr1;
char fname[100];
long pnr1=pnr();
printf("Save file as\n");
scanf("%s",fname);
fptr1 = fopen (fname, "w");
fprintf(fptr1,"*******************************************************TICKET*******************************************************\n");
fprintf(fptr1,"Customer Name - %s\n ",name);
fprintf(fptr1,"PNR - %ld\n",pnr1);
fprintf(fptr1,"Train name: %s\t\t\t\t Train number: %s\n",route_train[f_route_index],r_no_choice);
fprintf(fptr1,"Origin: %s \t\t\t Destination :%s \n" ,origin_station,destination);
fprintf(fptr1,"Arrival at Origin: %s \t Departure from Origin: %s \t Arrival at Destination:%s \n",arr[f_route_index][orig_index[f_route_index]],dep[f_route_index][orig_index[f_route_index]],arr[f_route_index][dest_index[f_route_index]]);
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
return pnr1;
}
long pnr()
{
//calculation of pnr which will be unique for everyone who accesses ticket()  
    time_t seconds; // Stores time seconds 
    long pnr_uniq=time(&seconds);      
    return pnr_uniq; 

}
void available_tickets()
{
printf("Number of seats left\n");
for(int i=0;i<5;i++)
{
for(int j=0;j<3;j++)
{
printf("Train Number %s ",r_no[i]);
printf("%s - %d ",class[j],seat[i][j]);
}
printf("\n");
}
}

/*void cancellation()
{
long pnr_can;
int seat_can;
int trno_index;
int tier_index;
printf("Enter you PNR:\n");
scanf("%ld",&pnr_can);
//retrive trno and tier from file
for(int i=0;i<5;i++)
{
if(r_no[i]==trno)
{
trno_index=i;
break;
}
}
for(int i=0;i<3;i++)
{
if(class[i]==tier)
{
tier_index=i;
break;
}
}
repeat5:
printf("Enter number of Seats You wish to cancel\n");  //need train number,train tier,number of seats booked
scanf("%d",&seat_can);
if(seat_can>seat_num)
{
printf("Number of seats chosen exceeds the number of seats booked");
goto repeat5;
}
//open seat.txt
FILE * fptr3;
  fptr3 = fopen ("seat.txt", "w");  

	for(int i=0;i<5;i++)
	{
	for(int j=0;j<3;j++)
	{
	fprintf(fptr3,"%d ",seat[i][j]);
	if(i==trno_index && j==tier_index)
	fprintf(fptr3,"%d ",seat[i][j]+seat_can);
	}}
    fclose (fptr3);

} */
void create_marks_csv()
{
FILE *fp4;
int i,j;
fp4=fopen("booking.csv","a");
fprintf(fp4,"\n");
fprintf(fp4,"%d,%s,%s,%ld",seat_num,r_no_choice,class_choice,pnr_no);
fclose(fp4);
}
void create()
{
FILE *fp5;
fp5=fopen("booking.txt","a");
fprintf(fp5,"\n");
fprintf(fp5,"%d,%s,%s,%ld",seat_num,r_no_choice,class_choice,pnr_no);
fclose(fp5);
}
void pass()
{
renter:
	digi = 0;
	up = 0;
	low = 0;
	schar = 0;
	
	printf("PASSWORD RULES :\n *Password should consist of minimum 5 characters\n *Maximum number of characters are 12\n *Password should consist of atleast 1 upper case and atleast 1 lowercase character\n *Password should consist of atleast 1 spl character ('@','#','$')\n *Password should consist of atleast 1 digit\n");
	scanf("%s", pwd);
	a = strlen(pwd);

	if (a < 5)

	{printf("\nError: Password should contain contain minimum 5 characters ");}

	else if (a > 12)

	{printf("\nError: Password shouldn't exceed 12 characters ");}

	else

	{for (i = 0; pwd[i] !='\0'; i++)

		{if (pwd[i] >= 'A' && pwd[i] <= 'Z')
			up++;
		if (pwd[i] >= 'a' && pwd[i] <= 'z')
			low++;
		if (pwd[i] >= '0' && pwd[i] <= '9')
			digi++;
		if (pwd[i] == '@' || pwd[i] == '#' || pwd[i] == '$')
			schar++;}
}

	if (up == 0)
	{printf("\nThere must be at least one Uppercase\n");
goto renter;
	}

	if (low == 0)
	{printf("\nThere must be at least one Lowercase\n");
		goto renter;

	}
	if (digi == 0)
	{printf("\nThere must be at least one Digit\n");
		goto renter;
	}
	if (schar == 0)
	{printf("\nThere must be at least one Special Character\n");
		goto renter;}
	else
	{
	renter1:
		printf("Confirm your Password\n");
	scanf("%s",ver);
		if (strcmp(pwd, ver) == 0)
		{
		printf("Welcome %s, your is Password Verified", name);
		}
		else
		{printf("Password did not match\n");
		goto renter1;
		}}
}
int  user()
{
return3:
	printf("Hello %s,Enter your Username(Valid Email ID):\n", name);
	schar = 0;
	up=0;
	scanf("%s", usn);

		for (i = 0; usn[i] !='\0'; i++)
		if (usn[i] == '@')
		schar++;
a=strlen(usn);
m=a-4;
n=a;
strcpy(check,substr(usn,m,n));
s=strcmp(check,com);
//printf("%d",s);
//printf("%d",schar);
//printf("%d",up);
if (s == 0 && schar == 1 )

	{printf("Valid EMAIL/USERNAME\n");
	return 1;}
	else
	{printf("Invalid Username\n");
	goto return3;}
}

char *substr(const char *src ,int m,int n)
{
int len=n-m;
char *dest =(char*)malloc(sizeof(char) *(len+1));
for (int i=m ;i< n && (*(src+i)!='\0');i++)
{
*dest =*(src+i);
dest++;
}
*dest ='\0';
return dest-len;
}
int phno1()
{int count = 0; int i;
for (i = 0; phno[i] != '\0'; i++)
count++;
if (count == 10)
	{return 0;}
	else
	{return 1;}
}
void register1()
{
	int k; int y;
	printf("Enter your Name: ");
scanf("%s",name);
system("clear");
	k = user();
	if (k == 1)
	{pass();}
system("clear");
return4:
	printf("\nPls enter your Contact No\n");
	scanf("%s",phno);
	y = phno1();
	if (y == 0)
		printf("\nSUCESSFULLY REGISTERED");
	else
	{
		printf("\nInvalid phone number\n");
		goto return4;
	}
//char a[9][3][100]={{name,usn,pwd,phno}};
create_marks_csv1();
create1();
}
	//printf("check=%s", check);


void create_marks_csv1()
{
FILE *fp;
int i,j;
fp=fopen("login.csv","a");
fprintf(fp,"\n");
fprintf(fp,"%s,%s,%s,%s",name,usn,pwd,phno);
fclose(fp);
}

void create1()
{
FILE *fp2;
fp2=fopen("login.txt","a");
fprintf(fp2,"\n");
fprintf(fp2,"%s,%s%c",usn,pwd,c);
fclose(fp2);
}		
