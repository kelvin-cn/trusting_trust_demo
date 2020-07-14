#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "strrpl.c"

int main(int argc, char *argv[])
{
	char target_name[100];
	char source_name[100];
	strcpy(target_name, argv[1]);
	strcpy(source_name, argv[2]);
	char buffer[2000];
	FILE *fp;
	FILE *fpw;
	errno_t err;
	errno_t errw;
	if ((err = fopen_s(&fp, source_name, "r")) == 0 && (errw = fopen_s(&fpw, "temp.c", "w")) == 0)
	{
		while (fgets(buffer, sizeof(buffer), fp))
		{
			//Process source code
			fputs(buffer, fpw);
		}
		fclose(fp);
		fclose(fpw);
	}
	else
	{
		printf("Cannot read file!");
		return 0;
	}

	char command[1000] = {" "};
	strcat(command, "clang -o ");
	strcat(command, target_name);
	strcat(command, " temp.c");
	system(command);
}