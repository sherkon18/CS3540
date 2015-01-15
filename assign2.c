//Name: Dalibor Labudovic
//Prof: Prof. J. Higgins
//Course: CS3540
//Assignment: Assignment 2 : modify the grades program to ask the user for the number of grades before entering grades
#include <stdio.h>
int main(){
	int grade;
	int num_grades;
		printf("Enter the number of grades: ");
		scanf("%d", &num_grades);
			int i;
			for(i = 0; i < num_grades; i++){
				printf("Enter grade ");
				scanf("%d", &grade);
			}
			//check to see if grade is between 0 and 100
			if (grade < 0 || grade > 100) printf("Error: Grade should be between 0 and 100");

		if (num_grades == 0)
			printf("No grades to average\n");
		else {
		int sum = 0;
		int j;
		for (j = 0; j < num_grades; j++)
			sum += grade;
			float ave = (float)sum/num_grades;
			printf("average: %f\n",ave);
		}
	return 0;
}
