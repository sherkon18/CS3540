  GNU nano 2.0.9                                   File: assign3.c                                                                              


/* Name : Dalibor Labudovic
   Course: CS3540 Sec. 1
   Prof. : J. Higgins
*/
//Instructions on how to compile this program
//Type the following command to compile: gcc -Wall -o assign3 assign3.c -lm
//Type the following command to	run program: ./assign3

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
                                                              [ Wrote 151 lines ]
^G Get Help             ^O WriteOut             ^R Read File            ^Y Prev Page            ^K Cut Text             ^C Cur Pos
^X Exit                 ^J Justify              ^W Where Is             ^V Next Page            ^U UnCut Text           ^T To Spell
