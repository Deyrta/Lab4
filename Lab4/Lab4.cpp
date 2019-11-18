#include "pch.h"
#include <stdio.h>
#include <string.h>

int find_for(int c, FILE *file1, FILE *file2);

void main()
{
	int k;
	char c;
	int literas = 0; // К-СТЬ ПРИГОЛОСНИХ
	char str[43] = "bcdfghjklmnpqrstvxzwyBCDFGHJKLMNPQRSTVXZWY";
	char *ach;
	int nl = 0; // ТУТ К-СТЬ РЯДКІВ У ФАЙЛІ (СПОЧАТКУ 0, А ПОТІМ ПОРАХУЄМ)
	int i;
	char string[51];

	FILE *file1;
	FILE *file2;

	file1 = fopen("lab3.txt", "r");
	file2 = fopen("outputFILE.txt", "w");

	if (file1 == NULL || file2 == NULL)
		perror("Error opening file\n");


	while ((c = fgetc(file1)) != EOF) // ТУТ
		if (c == '\n')              // РАХУЄМ
			nl++;                   // РЯДКИ

	rewind(file1);
	i = nl;

	for (nl = 1; nl <= i; nl++)
	{
		while ((c = fgetc(file1)) != '\n')
		{
			ach = strchr(str, c);
			if (ach != NULL)
				literas++;
		}
		if (literas == 0)
			continue;
		else if ((literas % 2) == 0)
			printf("Literas on row num %d: %d\n", nl, literas);
		else
			continue;
		literas = 0;
	}

	rewind(file1);

	for (i = 0; i < nl + 2; i++)
	{
		fgets(string, 50, file1);
		if (string[0] != 0)
		{
			for (k = 0; k < 50; k++)
			{
				if (string[k] == 'i' && string[k + 1] == 'f' && (string[k + 2] == ' ' || string[k + 2] == '('))
				{
					string[k] = string[k + 1] = string[k + 2] = ' ';
				}
				else if (string[k] == 'w' && string[k + 1] == 'h' && string[k + 2] == 'i' && string[k + 3] == 'l' && string[k + 4] == 'e' && (string[k + 5] == ' ' || string[k + 5] == '('))
				{
					string[k] = string[k + 1] = string[k + 2] = string[k + 3] = string[k + 4] = string[k + 5] = ' ';
				}
				else if (string[k] == 'f' && string[k + 1] == 'o' && string[k + 2] == 'r' && (string[k + 3] == ' ' || string[k + 3] == '('))
				{
					string[k] = string[k + 1] = string[k + 2] = string[k + 3] = ' ';
				}
			}
		}
		fputs(string, file2);
	}

	fclose(file1);
	fclose(file2);
}

