
#include<stdio.h>
#include<string.h>

void pass();
int  user();
char name[30], pwd[25], ver[25], usn[30],  check[30], com[10]=".com";

int i, a, digi, up, low, schar, s;




	void pass() 
	{
	renter:
		digi = 0;
		up = 0;
		low = 0;
		schar = 0;
		printf("Hello %s, Enter your password:\n", name);
		printf("PASSWORD RULES :\n *Password should consist of minimum 5 characters\n *Maximum number of characters are 12\n *Password should consist of atleast 1 upper case and atleast 1 lowercase character\n *Password should consist of atleast 1 spl character ('@','#','$')\n *Password should consist of atleast 1 digit\n");
		gets(pwd);

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

			for (i = 0; pwd[i] != NULL; i++)

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

			gets(ver);

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

		getch();
	}
	int  user()
	{return3:
		printf("Hello %s,Enter your Username(Valid Email ID):\n", name);
	
		schar = 0;

		gets(usn);

		a = strlen(usn);
		for (int j = 0; usn[j] != '\0'; j++)
		{
			if (usn[j] == '@')
				schar++;
			if (usn[j] >= 'A' && usn[j] <= 'Z')
				up++;
		}//printf("%d", schar);
		//printf("a=%d", a);
		
		for (i = (a - 4); usn[i] != NULL; i++)
		{
			check[i] = usn[i];
		}
		check[i] = "\0";
		s =strcmp(check, com);
		//printf("%d", s);
		if (s == -1 && schar == 1 && up==0)

		{
			printf("Valid EMAIL/USERNAME\n");
			return 1;
		}
		else
		{
			printf("Invalid Username");
			goto return3;
			
		}

	}
	void main()

	{
		int k;
		printf("Enter your Name: ");

		gets(name);
		
		k = user();
		if (k == 1)
		{
			pass();
		}
		
	}
