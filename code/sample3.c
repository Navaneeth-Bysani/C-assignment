#include<stdio.h>
#include<conio.h>
#include<string.h>

struct grades {
	char RollNo[10];
	char courseId[9];
	char grade[6];
};

struct grades grade[4];

void readFile() {
	FILE *fp;
	fp = fopen("grades.txt","r");
	char ch;
	int i,j,k,l;
	int flag = 1;
	int x = 1;
	int counter;
	i = 0;
	
	while(flag) {
		j = 0;
		k = 0;
		l = 0;
		counter = 0;
		while(1) {
			ch = fgetc(fp);

			if(ch == '\n') {
				break;
			}
			if(ch == EOF) {
				flag = 0;
				break;
			}
			if(ch == ' ' ||  ch == '\t') {
				continue;
			}
			if(ch == ',') {
				counter++;
				continue;
			}

			if(counter == 0) {
				grade[i].RollNo[j] = ch;
				
				j++;		
			} else if(counter == 1) {
				grade[i].courseId[k] = ch;
				
				k++;
			}	else if(counter == 2) {
				grade[i].grade[l] = ch;
				
				l++;
			}
			
		}
		
		i++;	
	}		
	fclose(fp);
	return ;
}
void mergeSort(char a[][10], int low, int high) {
	int mid;
	if(low<high) {
		mid = (high+low)/2;
		mergeSort(a,low,mid);
	}

	
	return;
}

int main() {
	int b[3];
	char c[5] = "Grade";
	char arr[4][10];
	int i,j;
	int low,high;
	readFile();

	for(i=0;i<4;i++) {
//		printf("%s	",grade[i].RollNo);
		strcpy(arr[i], grade[i].RollNo);
//		printf("%s	",grade[i].RollNo);
		//printf("	%s\n",arr[i]);
	}
	
	low = 1;
	high = 3;
	mergeSort(arr[],low,high);

	return 0;	
}
