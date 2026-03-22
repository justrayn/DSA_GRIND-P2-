//put your answers here

// [E1] - Mary Rose's Gym - LIST
// by Janie Lane Sabado

// Background
 

// Thinking about her health journey, Ms. Mary Rose has decided to open up a new gym. It is very famous, especially among gym instructors that Ms. Mary Rose is having trouble with many instructors wanting to teach in her gym. So she has asked Ms. Janie if she could create a Gym Sched AI Assistant that would help in scheduling the gym classes while Ms. Mary Rose focuses on the making the perfect gym environment. Ms. Janie was more than willing to help and so she decided to code this Gym Sched AI Assistant not just because Ms. Mary Rose is her friend but also because Ms. Mary Rose offered her a free membership plan.

 

// HOWEVER! Ms. Janie was suddenly whisked away to a surprise holiday getaway with her boyfriend! And so she had to leave immediately, the program left unfinished as Ms. Janie ponders if her boyfriend will propose on this trip. It is now up to you to help, finish the program not just to help Ms. Mary Rose in her gym but also to help relieve Ms. Janie as she feels bad for leaving the program unfinished.

 

// Objectives
 

// Create the insertClass function which will insert a new gymClass into the schedule based on the following rules:
// Day rule: The gymClass day must be a weekday, not a weekend
// the helper function getDay is used for this condition
// Capacity constraint: Each day can hold a maximum of 6 classes.
// Duplicate rule: A class with the same name cannot be inserted on the same day.
// Duration rule: A class cannot exceed 1 hour in duration.
// Instructor rule: The instructor field must not be empty.
// Minimum size rule: The class must meet the minimum size requirement.
 

// Function Definitions
 

// The function **insertClass** will do the following:
// Accept the parameters gymSchedule *G, gymClass newGC, and String Day.
// If the day is not part of the day of the week array, print:
// "Error: Invalid day.\n" and terminate the function.
// If the specified day already has 6 classes, print:
// "Error: Max classes reached for the day.\n" and terminate the function.
// If the instructor field is empty, print:
// "Error: Instructor cannot be empty.\n" and terminate the function.
// If the minimum size is less than MIN, print:
// "Error: Minimum size not enough.\n" and terminate the function.
// If the duration is more than 1 hour, print:
// "Error: Duration exceeds 1 hour.\n" and terminate the function.
// If a class with the same name already exists on that day, print:
// "Error: Duplicate class name on %s.\n" and terminate the function.
// If all conditions are satisfied, insert the new class into the day’s linked list at the end of the list.
// After successful insertion, increment the day’s count and the schedule’s total count, and print:
 

// Note:
// The getDay function will return -1 if the day provided is not a weekday

// Sample Output 1

// Enter your choice: 1

// Inserting new class Core on Saturday:
// Error: Invalid day.
// Sample Output 2

// Enter your choice: 2

// Inserting new class in gymsched J (full) :
// Error: Max classes reached for the day.
// Sample Output 3

// Enter your choice: 3

// Inserting new class without an instructor :
// Error: Instructor cannot be empty.


#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include"header.h"


/*
 * @brief Inserts a new gym class into the schedule for a given day
 * @param G pointer to the gym schedule
 * @param newGC the new gymClass to be inserted
 * @param Day string representing the day of the week
 *
 */

void insertClass(gymSchedule* G, gymClass newGC, String Day) {
    //Write your code here...

}