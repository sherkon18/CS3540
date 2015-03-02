
/* Name : Dalibor Labudovic
   Course: CS3540 Sec. 1
   Prof. : J. Higgins
*/
//Instructions on how to compile this program
//Type the following command to compile: gcc -Wall -o assign3 assign3.c -lm
//Type the following command to run program: ./assign3

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

//function prototype

int* get_data(int num_grades); // function to get grades

//function to calculate average and display results
float calc_average(int num_grades, int* grades);
void display_average(float average);

//function to calculate median and display results
float calc_median(int num_grades, int* grades);
void display_median(float median);

//function to calculate standard deviation and display results
float calc_standard_deviation(int num_grades, int* grades);
void display_stdDev(float stdDev);


const int MAX_GRADE = 100;

int main(){
    int* grades;
    int num_grades;
    printf("Enter the number of grades: ");
    scanf("%d", &num_grades);
   
    //invoke get data function passing num_grades
        grades = get_data(num_grades);
   
   
        float average = calc_average(num_grades, grades);
        display_average(average);

        float median = calc_median(num_grades, grades);
        display_median(median);

        float stdDev = calc_standard_deviation(num_grades, grades);
        display_stdDev(stdDev);

        free(grades);
      return 0;
}

//function to get input data
//prepost conditions
//num_grades != NULL
//
//postconditions
//grades != NULL
int* get_data(int num_grades)
{    assert(num_grades != 0);
    assert(num_grades > 0);
    int* grades = malloc(num_grades * sizeof(int));
    int i;
        for (i = 0; i < num_grades; i++){
                printf("Enter grade: ");
        int grade;
                scanf("%d", &grade);
                while(grade < 0 && grade > MAX_GRADE)
                {
                        printf("Grades need to be >= 0 and <= 100: Try Again!\n");
                        printf("enter a grade: ");
                        scanf("%d", &grade);
                }
                grades[i] = grade;
        }
    assert(grades != NULL);
    return grades;
}
//function to calcuate the median grade
float calc_median(int num_grades, int* grades)
{
    //sort
    float temp;
        int i,j;
            for(i = 1;i <= num_grades; i++)

            for(j = 1; j <= num_grades - 1; j++)
            {
                if(grades[i] > grades[j])
                    {
                        temp = grades[j];
                        grades[j] = grades[j+1];
                        grades[j+1] = temp;
                    }
            }

            if( num_grades % 2 == 0)
                return (grades[num_grades/2] + grades[num_grades/2+1])/2;
            else
                return grades[num_grades/2 + 1];
}
void display_median(float median)
{
    printf("Median %.2f\n", median);
}
//function to calcuate the average grade
float calc_average(int num_grades, int* grades)
{
    int sum = 0;
    float average;
    if(num_grades == 0) printf("No grades to average\n");
    else{
        int i;
        for(i=0; i < num_grades; i++){
            sum +=grades[i];
        }
        average = (float) sum/num_grades;
    }
    return average;
}
void display_average(float average)
{
    printf("Average: %.2f\n", average);
}
//function to calculate the standard deviation
float calc_standard_deviation(int num_grades, int* grades)
{
//find the mean
    float mean = 0.0;
    float sum_deviation = 0.0;
    int i;
    for(i = 0; i < num_grades; i++)
    {
        mean += grades[i];
    }
    mean = mean/num_grades;

    for(i = 0; i < num_grades; i++)
    sum_deviation += (grades[i] - mean)* (grades[i] - mean);
    float stdDev = sqrt(sum_deviation/num_grades);
    return stdDev;
}
void display_stdDev(float stdDev)
{
    printf("Standard Deviation %.2f\n", stdDev);

}
