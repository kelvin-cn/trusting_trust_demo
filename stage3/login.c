#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char *account[2][2] = {
		{"abc","123"},
		{"xyz","456"}
	};

	char username[100];
	char password[100];
	printf("Username:");
	scanf_s("%s", username);
	printf("Password:");
	scanf_s("%s", password);
	
	int login = 0;
	for(int i=0; i<2; i++){
		if(strcmp(username, account[i][0])==0 && strcmp(password, account[i][1])==0){
			login = 1;
			break;
		}
	}
	
	if(login){
		printf("Success");
	}else{
		printf("Fail");
	}
}