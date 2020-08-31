#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct grades {
	char RollNo[10];
	char courseId[9];
	char grade[6];
};

struct grades grade[12];

void mergesort(low,high) {
	if(low<high) {
		
		mergesort
	}
}
int main() {
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
	return 0;
}


//printf("Openening the records for %s.........\n",courseId);
			//printf("Roll no		Names		Grades\n");
//			for(i = 0; i<no_grades; i++) {
//				if(!strcmp(grade[i].courseId,courseId)) {
//					for(k=0;k<no_students;k++) {
//						if(!strcmp(grade[i].RollNo,s[k].RollNo)) {
//							printf("%s-%s-%s\n",s[k].RollNo,s[k].name,grade[k].grade);
//						}
//					}
//				}
//			}	



//struct students {
//	char RollNo[10];
//	char name[20];
//};
//
//struct students s[10];
//int main() {
//	char ch;
//	int isName = 0;
//	FILE *fp;
//	fp = fopen("csestudents.txt","r");
//	char name[15];
//	char rollNo[9];
//	int i,j,k;
//	int flag = 1;
//	
//	i = 0;
//	while(flag) {
//		j = 0;
//		k = 0;
//		isName = 0;
//		while(1) {
//			ch = fgetc(fp);
//
//			if(ch == '\n') {
//				break;
//			}
//			if(ch == EOF) {
//				flag = 0;
//				break;
//			}
//			if(ch == ' ' ||  ch == '\t') {
//				continue;
//			}
//			if(ch == ',') {
//				isName = 1;
//				continue;
//			}
//
//			if(isName) {
//				s[i].name[j] = ch;
//				j++;		
//			} else {
//				s[i].RollNo[k] = ch;
//				k++;
//			}	
//			
//		}
//	
//		i++;
//			
//	}
//
//	for(i=0;i<6;i++) {
//		printf("%s-%s\n",s[i].name,s[i].RollNo);
//	}
//	fclose(fp);
//}
