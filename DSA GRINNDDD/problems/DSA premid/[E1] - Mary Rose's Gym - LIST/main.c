#include<stdio.h>
#include "header.h"


int main(){
	int choice;

	gymSchedule G; initialize(&G); loadDummyNodes(&G);
	gymSchedule J;
	J.dayOf[0].count=6;
	String Day = "Monday";
	String otherDay = "Tuesday";
	String wrongDay = "Saturday";

    gymClass newGC = {"Core",1,"Menchavez",11};
    gymClass wrong1 = {"Core",1,"0",13};
    gymClass wrong2 = {"Core",2,"Menchavez",11};
    gymClass wrong3 = {"Core",1,"Menchavez",9};

    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch(choice){
    	case 1: //WrongDay
			printf("\nInserting new class Core on Saturday:\n");

		    insertClass(&G, newGC, wrongDay);


	   		break;

    	case 2: //MaxCount for the day

			printf("\nInserting new class in gymsched J (full) :\n");

		    insertClass(&J, newGC, Day);


	   		break;

    	case 3: //no Instructor

			printf("\nInserting new class without an instructor :\n");

		    insertClass(&G, wrong1, Day);


	   		break;

    	case 4: //duration more than 1 hour

			printf("\nInserting new class that is more than an hour :\n");

		    insertClass(&G, wrong2, Day);


	   		break;

    	case 5: //size of minsize

			printf("\nInserting new class that doesn't reach minimum size:\n");

		    insertClass(&G, wrong3, Day);


	   		break;

    	case 6: //duplicateClass on the day

			printf("\nInserting new class Core that is already in Tuesday:\n");

		    insertClass(&G, newGC, otherDay);


	   		break;



    	case 7: //insert


		    insertClass(&G, newGC, Day);

		    display(G);

	   		break;

    	default:
    		printf("\nNot a valid choice");
			break;

	}

    return 0;

}