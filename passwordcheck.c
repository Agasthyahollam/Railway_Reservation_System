
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int my_strcmp(char str1[], char str2[]);
void my_strcpy(char dest[], char src[]);
void pass();
int  user();
int phno1();
char name[30], pwd[25], ver[25], usn[30], phno[15];
char com[10] = ".com"; char check[20];
int i, a, digi, up, low, schar, s;




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

	{

		printf("\nError: Password should contain contain minimum 5 characters ");

	}

	else if (a > 12)

	{

		printf("\nError: Password shouldn't exceed 12 characters ");

	}

	else

	{

		for (i = 0; pwd[i] !='\0'; i++)

		{

			if (pwd[i] >= 'A' && pwd[i] <= 'Z')

				up++;

			if (pwd[i] >= 'a' && pwd[i] <= 'z')

				low++;

			if (pwd[i] >= '0' && pwd[i] <= '9')

				digi++;

			if (pwd[i] == '@' || pwd[i] == '#' || pwd[i] == '$')

				schar++;

		}

	}

	if (up == 0)
	{
		printf("\nThere must be at least one Uppercase\n");


		goto renter;
	}

	if (low == 0)
	{
		printf("\nThere must be at least one Lowercase\n");
		goto renter;

	}
	if (digi == 0)
	{
		printf("\nThere must be at least one Digit\n");
		goto renter;
	}
	if (schar == 0)
	{
		printf("\nThere must be at least one Special Character\n");
		goto renter;
	}
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
		{

			printf("Password did not match\n");
			goto renter1;
		}
	}

	
}
int  user()
{
return3:
	printf("Hello %s,Enter your Username(Valid Email ID):\n", name);

	schar = 0;

	scanf("%s", usn);

	//a = strlen(usn);
	for (int j = 0; usn[j] != '\0'; j++)
	{
		if (usn[j] == '@')
			schar++;
		if (usn[j] >= 'A' && usn[j] <= 'Z')
			up++;
	}//printf("%d", schar);
	//printf("a=%d", a);

	my_strcpy(check, usn);
	s = my_strcmp(check, com);


	//printf("%d", s);
	if (s == 0 && schar == 1 && up == 0)

	{
		printf("Valid EMAIL/USERNAME\n");
		return 1;
	}
	else
	{
		printf("Invalid Username\n");
		goto return3;

	}

}
void my_strcpy(char dest[], char src[])
{
	int count;
	int z;
	z = strlen(src);
	for (count = (z - 4); src[count] != '\0'; count++)
		dest[count] = src[count];
	dest[count] = '\0';
}
int   reverse_str(char sub_str[])
{
	char temp_str[60];
	int s_len = strlen(sub_str);
	int i;

	for (i = 0; i < s_len; i++)
		temp_str[s_len - (i + 1)] = sub_str[i];
	temp_str[s_len] = '\0';

	for (i = 0; i < s_len; i++)
		sub_str[i] = temp_str[i];
	sub_str[s_len] = '\0';
	return 0;
}

int my_strcmp(char str1[], char str2[])
{
	int len1 = strlen(str1);	// Use the function written earlier to find the string length
	int len2 = strlen(str2);
	int ret_val = 1, count;

	if (len1 == len2)	// Proceed only if the two strings are of equal length
	{
		for (count = 0; count < len1; count++)
			if (str1[count] != str2[count])
			{
				ret_val = 0;
				break;
			}
	}
	else
		ret_val = 0;
	return ret_val;
}

int phno1()
{
	int count = 0; int i;

	for (i = 0; phno[i] != '\0'; i++)
	{
		count++;
	}
	if (count == 10)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}



void main()

{
	int k; int y;
	printf("Enter your Name: ");


	scanf("%s",name);
system("clear");
	k = user();
	if (k == 1)
	{
		pass();
	}
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
	//printf("check=%s", check);
}


		
	
