#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define no_students 5
#define no_courses 5
#define no_grades 16


//structures

struct students {
	char RollNo[10];
	char name[20];
};

struct students s[10];

struct courses {
	char CourseId[9];
	char Coursename[15];
};

struct courses course[10];

struct grades {
	char RollNo[10];
	char courseId[9];
	char grade[6];
};

struct grades grade[16];


int populateStudents();
int populateCourses();
int populateGrades();

void menu();

void displayStudents();
void displayCourses();
void displayGrades();

int show(char *str, int j);
void cleanConsole();
int check(char *str, int length);
int main() {
	char str[30];
	int length;
	int i;
	int flag;
	char cmd_1[5], filename[10], cmd_2[4], columnname[10], value[15];
	char sample[6];
	
	populateStudents();
	populateCourses();
	populateGrades();

	menu();
	
	while(1) {
		printf(">>>");
		gets(str);
		length = strlen(str);
		check(str,length);	
	}
	
}


int populateStudents() {
	char ch;
	int isName = 0;
	FILE *fp;
	fp = fopen("csestudents.txt","r");
	int i,j,k;
	int flag = 1;
	int x = 1;
	i = 0;
	while(flag) {
		j = 0;
		k = 0;
//		s[i].isFilled = 1;
		isName = 0;
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
				isName = 1;
				continue;
			}

			if(isName) {
				s[i].name[j] = ch;
				j++;		
			} else {
				s[i].RollNo[k] = ch;
				k++;
			}	
			
		}
	
		i++;
			
	}
	fclose(fp);
	return 0;
}

int populateCourses() {
	char ch;
	int isName = 0;
	FILE *fp;
	fp = fopen("courses.txt","r");
	int i,j,k;
	int flag = 1;
	int x = 1;
	i = 0;
	while(flag) {
		j = 0;
		k = 0;
		isName = 0;
//		s[i].isFilled = 1;
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
				isName = 1;
				continue;
			}

			if(isName) {
				course[i].Coursename[j] = ch;
				//printf("%c",course[i].Coursename[j]);
				j++;		
			} else {
				course[i].CourseId[k] = ch;
				//printf("%c",course[i].Coursename[j]);
				k++;
			}	
			
		}
	
		i++;
			
	}
	
	fclose(fp);
	return 0;
}

int populateGrades() {
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


void menu() {
	printf("Use the commands as shown in the following syntax. All the commands are Case-sensitive\n");
	printf("Menu\n");
	printf("-----\n");
	printf("1. To see all the contents of a particular file: SHOW <filename>;\n");
	printf("2. To see all the contents of a particular file in a sorted order w.r.t the data of a particular column: SHOW <filename> SORTBY <columnname>;\n");
	printf("3. To see all the fields where selected records: SHOW <filename> WHERE <columnname = value>;\n");
	printf("4. To see all the student roll numbers, their names, and grades in a particular subject: SHOW CourseID=<courseId>;\n");	
	printf("5. To clear the console: CLEAR;\n");
	printf("6. To exit the program: QUIT;\n");
	printf("7. To see the syntax for different commands: MENU\n");
	return;
	
}


int check(char *str, int length) {
	char cmd_1[4];
	int i,j;
	
	//Checks whether the statement ends with ';'
	if(str[length - 1] != ';') {
		puts("ERR : Check the syntax properly!");
		return;
	}
	
	i=0;
	while(str[i] == ' ') {
		i++;
	}
	
	//Extracts the first 4 letters of the command entered
	for(j=i;j<i+4;j++) {
		cmd_1[j-i] = str[j];
	}
	
	//Checks if the first command is SHOW/QUIT/CLEAR/MENU and acts accordingly
	if(!strcmp(cmd_1, "SHOW")) {
		printf("----------SHOW--\n");
		show(str,j);
	} else if(!strcmp(cmd_1,"QUIT")) {
		printf("Quitting...\n");
		return -1;
	} else if(!strcmp(cmd_1,"CLEA") && str[j] == 'R') {
		cleanConsole();
	} else if(!strcmp(cmd_1,"MENU")) {
		menu();
	}
	
	return 0;
}

void cleanConsole() {
	//Checks whether the OS being used is windows or linux and operates the appropriate command.
	#ifdef _WIN32
		system("cls");
	#elif __linux__
		system("clear");
	#endif
}

int show(char *str, int j) {
	int k,l,i;
	char filename[15];
	char courseId[8];
	char cmd_2[7];
	char columnname[10];
	while(1) {
		if(str[j] == ' ')
			j++;
		else
			break;
	}
	k = 0;
	while(str[j] != ' ') {
		if(str[j] == ';') {
			break;
		}
		filename[k] = str[j];
		j++;
		k++;
	}
	filename[k] = '\0';

//	printf("%s",filename);
	if(!(!strcmp(filename,"csestudents") || !strcmp(filename,"courses") || !strcmp(filename,"grades") || !strcmp(filename,"courseId"))) {
		puts("ERR: Enter a valid file name...\n");
		return;
	} 
	while(1) {
		if(str[j] == ' ') {
			j++;
			continue;
		} else {
			break;
		}
	}
//	printf("%d",j);
	if(!strcmp(filename,"courseId")) {
		if(str[j] == '=') {
			j++;
			while(1) {
				if(str[j] == ' ') {
				j++;
				continue;
				} else {
					break;
				}
			
			}
//			printf("------%d----",j);
			l = 0;
			while(str[j] != ' ' && str[j] != ';') {
				courseId[l] = str[j];
				printf("%c",courseId[l]);
				l++;
				j++;	
			}
			courseId[l] = '\0';
			printf("Openening the records for %s.........\n",courseId);
			printf("Roll no		Names		Grades\n");
			for(i = 0; i<no_grades; i++) {
				if(!strcmp(grade[i].courseId,courseId)) {
					for(k=0;k<no_students;k++) {
						if(!strcmp(grade[i].RollNo,s[k].RollNo)) {
							printf("%s-%s-%s\n",s[k].RollNo,s[k].name,grade[k].grade);
						}
					}
				}
			}
	return;	
		}
	}	
	if(str[j] == ';') {
		printf("opening %s file...........\n",filename);
		if(filename[1] == 's') {
			printf("--World\n");
			displayStudents();
		} else if(filename[1] == 'o') {
			displayCourses();
		} else if(filename[1] == 'r') {
			displayGrades();
		}
	}
	i = 0;
	while(1) {
		if(str[j] != ' ') {
			cmd_2[i] = str[j];
			i++;
			j++;
		} else {
			cmd_2[i] = '\0';
			break;
		}
	}
	
	while(1) {
		if(str[j] == ' ') {
			j++;
			continue;
		} else {
			break;
		}
	}
	
	i = 0;
	while(1) {
		if(str[i] != ' ') {
			columnname[i] = str[j];
			i++;
			j++;
		} else {
			columnname[i] = '\0';
			break;
		}		
	}
//	printf("%s\n",columnname);
//	printf("%s\n",cmd_2);
}


void displayStudents() {
	int i;
	i = 0;
	while(i < 6) {
		printf("%s-%s\n",s[i].RollNo,s[i].name);
		i++;
	}
	
	//return;	
}

void displayCourses() {
	int i;
	i = 0;
	while(i < no_courses) {
		printf("%s-%s\n",course[i].CourseId,course[i].Coursename);
		i++;
	}
	return;	
}

void displayGrades() {
	int i;
	i = 0;
	while(i < no_grades) {
		printf("%s-%s-%s\n",grade[i].RollNo,grade[i].courseId,grade[i].grade);
		i++;
	}
	return;	
}

