
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Global Variables
typedef struct{
	char name[50];
	int train_num;
	int num_of_seats;
}



//function prototypes to be used
void reservation(void);							//main reservation function
void details(void);							//view details of all the trains
void cancel(void);								
void ticket(char name[], int num_of_seats, int train_num, float charges);	//print ticket 
void train(int);
float charge(int train_num, int num_of_seats);
void login();






//Gives the list of trains available to book.

void details(void)
{
	system("cls");
	printf("\nTr.No\tName\t\t\tDestinations\t\tCharges\t\tTime\n");
	printf("\n12953\tRajdhani Express\tDelhi to Ranchi\tRs.5000\t\t9am");
	printf("\n12957\tDuronto Express\tDelhi To Bengaluru\tRs.5000\t\t12pm");
	printf("\n12784\tSampark Kranti Express\t\tDelhi To Kolkata\t\tRs.4500\t\t8am");
	printf("\n12846\tHumsafar Express\t\tDelhi To Mumbai\t\tRs.4500\t\t11am");
	printf("\n12674\tVande Bharat Express\tDelhi To Lucknow\tRs.4000\t\t7am");
	printf("\n12976\tTejas Express\tDelhi To Patna\tRs.4000\t\t9.30am");
    printf("\n12643\tGatiman Express\tDelhi To Raipur\tRs.3500\t\t1pm");	
    printf("\n12698\tVivek Express\tDelhi To VIzag\tRs.3500\t\t4pm");
    printf("\n12487\tMahamana Express\t\tDelhi To Jaipur\t\tRs.6000\t\t3.35pm");
    printf("\n12475\tYuva Express\t\tDelhi To Chennai\t\tRs.6000\t\t4.15pm");
    
}


void reservation(void)   //not done
{

}

//calculating charges

float charge(int train_num,int num_of_seats)
{
		if (train_num==12953)
	{
		return(5000.0*num_of_seats);
	}
	if (train_num==12957)
	{
		return(5000.0*num_of_seats);
	}
	if (train_num==12784)
	{
		return(4500.0*num_of_seats);
	}
	if (train_num==12846)
	{
		return(4500.0*num_of_seats);
	}
	if (train_num==12674)
	{
		return(4000.0*num_of_seats);
	}
	if (train_num==12976)
	{
		return(4000.0*num_of_seats);
	}
	if (train_num==12643)
	{
		return(3500.0*num_of_seats);
	}
	if (train_num==12698)
	{
		return(3500.0*num_of_seats);
	}
	if (train_num==12487)
	{
		return(6000.0*num_of_seats);
	}
	if (train_num==12475)
	{
		return(6000.0*num_of_seats);
	}
}


//printing ticket

void ticket(char name[],int num_of_seats,int train_num,float charges)
{
	system("cls");
	printf("\tTICKET\n");
	printf("Name:\t%s",name);
	printf("\nNumber Of Seats:\t%d",num_of_seats);
	printf("\nTrain Number:\t%d",train_num);
	train(train_num);
	printf("\nCharges:\t%.2f",charges);
}


void train(int train_num)
{
	
	if (train_num==12953)
	{
		printf("\nTrain:\t\t\ttRajdhani Express");
		printf("\nDestination:\t\tRanchi");
		printf("\nDeparture:\t\t9am ");
	}
	if (train_num==12957)
	{
		printf("\nTrain:\t\t\tDuronto Express");
		printf("\nDestination:\t\tBengaluru");
		printf("\nDeparture:\t\t12pm");
	}
	if (train_num==12784)
	{
		printf("\nTrain:\t\t\tSampark Kranti Express");
		printf("\nDestination:\t\tKolkata");
		printf("\nDeparture:\t\t8am");
	}
	if (train_num==12846)
	{
		printf("\nTrain:\t\t\tHumsafar Express ");
		printf("\nDestination:\t\tMumbai");
		printf("\nDeparture:\t\t11am ");
	}
	if (train_num==12674)
	{
		printf("\nTrain:\t\t\tVande Bharat Express");
		printf("\nDestination:\t\tLucknow");
		printf("\nDeparture:\t\t7am");
	}
	if (train_num==12976)
	{
		printf("\ntrain:\t\t\tTejas Express");
		printf("\nDestination:\t\tPatna");
		printf("\nDeparture:\t\t9.30am ");
	}
	if (train_num==12643)
	{
		printf("\ntrain:\t\t\tGatiman Express");
		printf("\nDestination:\t\tRaipur");
		printf("\nDeparture:\t\t1pm ");
	}
	if (train_num==12698)
	{
		printf("\ntrain:\t\t\tVivek Express");
		printf("\n Destination:\t\tVIzag");
		printf("\nDeparture:\t\t4pm ");
	}
	if (train_num==12487)
	{
		printf("\ntrain:\t\t\tMahamana Express ");
		printf("\nDestination:\t\tJaipur");
		printf("\nDeparture:\t\t3.35pm ");
	}
	if (train_num==12475)
	{
		printf("\ntrain:\t\t\tYuva Express");
		printf("\nDestination:\t\tChennai");
		printf("\nDeparture:\t\t1.15 ");
	}
}

void login()        //not done
{	
}

void cancel(void)   //not done
{

}

int main()

{
	system("cls");
	printf("\t\t           TRAIN TICKET RESERVATION SYSTEM           \n");
	printf(" \n Press any key to continue:");
	getch();
	system("cls");
	login();
	int choice, choice_return;
start:
	system("cls");
	printf("    TRAIN RESERVATION SYSTEM");
	printf("\n1>> Reserve A Ticket");
	printf("\n2>> View All Available Trains");
	printf("\n3>> Cancel Reservation");
	printf("\n4>> Exit");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		reservation();		//Function  not added
		break;
	case 2:
		viewdetails();
		printf("\n\nPress any key to go to Main Menu..");
		getch();
		break;
	case 3:
		cancel();
		//function not added.
		break;
	case 4:
		return(0);
	default:
		printf("\nInvalid choice");
	}
	goto start;
	return(0);
}

              


