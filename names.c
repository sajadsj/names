/*
Title: Names
Project aim: Learning loops using C
by: SajadSojoudi@gmail.com
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void repeated_names(char str[20][33])

{

	printf("\n repeated name is runing... \n\n");
	int n = 1;

	int i, j,r, count = 0;
/*
	for (i = 1; i <= 20; i++)
	{
			printf("%s\n", str[i]);
	}
	printf("\n\n");
*/



	for (i = 1; i <= 20; i++)
	{
		count = 0;
		for (j = 1; j <= 20; j++)
		{
			if (strcmp(str[i], str[j]) == 0)
			{
				count++;	
			
			}

		}

		int p = 0;
		for (r = 1; r < i; r++)
		{
			if (strcmp(str[i], str[r]) == 0)
				p = 1;
		}

		if (count > 1 && p==0)
		printf("%s repeated %d times\n", str[i], count);
	}


}

void getstr(char str[20][33])
{
	printf("\n getstr is runing... \n\n");
	int n = 0;

	int i, j,r;


	char* s[33];
	printf("Enter a string:");
	scanf("%s", s);





	for (i = 1; i <= 20; i++)
	{
		char* ptr = strstr(str[i], s);

		int p = 0;
		for (r = 1; r < i; r++)
		{
			if (strcmp(str[i], str[r]) == 0)
				p = 1;
		}

		if (ptr != NULL && p==0) /* Substring found */
		{
			printf("'%s' contains '%s'\n", str[i], s);
		}

	}


}

void under(char str[20][33])
{
	printf("\n under is runing... \n\n");
	int n = 0;

	int i, j, k,r;

	for (i = 1; i <= 20; i++)
	{
		for (k =  1; k <= 20; k++)
		{

			char* ptr = strstr(str[i], str[k]);

			int p = 0;
			for (r = 1; r < i; r++)
			{
				if (strcmp(str[i], str[r]) == 0)
					p = 1;
			}

			if (ptr != NULL && strcmp(str[i], str[k]) != 0 && p==0 )
			{
				printf("'%s' contains '%s'\n", str[i], str[k]);
			}


		}
	}



}

void sort(char str[20][33])
{
	printf("\n sort is runing... \n\n");
	int n = 0;
	int i, j, k;
	char temp[33];
	char names[20][33];

	for (i = 0; i < 20; i++)
	{
		strcpy(names[i], str[i]);
	}

	for (i = 1; i <= 20; i++)
	{
		for (k = i + 1; k <= 20; k++)
		{

			if (strcmp(names[i], names[k]) > 0)
			{
				strcpy(temp, names[i]);
				strcpy(names[i], names[k]);
				strcpy(names[k], temp);
			}

		}		

	}

	for (i = 1; i < 20; i++)
		printf("%s\t\t\t%s\n", names[i], str[i]);



}



int main()
{


	// daryafte file
	FILE* fileobj = fopen("./names.txt", "r");

	if (fileobj == NULL)
	{
		printf("fopen failed\n");
		exit(-1);
	}


	char names[21][33];
	int n = 1;


	while (!feof(fileobj))
	{
		fscanf(fileobj, "%s", &names[n]);
		n++;

	}
	int fclose(FILE * fileobject);


	repeated_names(names);
	printf("------------------------------------------\n");
	getstr(names);
	printf("------------------------------------------\n");
	under(names);
	printf("------------------------------------------\n");
	sort(names);

	return 0;
}
