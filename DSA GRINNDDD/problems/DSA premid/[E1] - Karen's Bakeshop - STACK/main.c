#include<stdio.h>
#include "header.h"


int main(){

	CAKE cake,fullcake,tempcake;
	int choice,temp;
    initStack(&cake);
    initStack(&fullcake);
    initStack(&tempcake);

    CakeLayer B1 = {7, "Chocolate"};
    CakeLayer B2 = {7, "Vanilla"};
    CakeLayer B3 = {7, "Mango"};
    CakeLayer B4 = {7, "Ube"};
    CakeLayer B5 = {7, "Yema"};
    CakeLayer S1 = {5, "Chocolate"};
    CakeLayer S2 = {5, "Vanilla"};
    CakeLayer S3 = {5, "Mango"};
    CakeLayer S4 = {5, "Ube"};
    CakeLayer S5 = {5, "Yema"};
    CakeLayer T1 = {3, "Chocolate"};
    CakeLayer T2 = {3, "Vanilla"};
    CakeLayer T3 = {3, "Mango"};
    CakeLayer T4 = {3, "Ube"};
    CakeLayer T5 = {3, "Yema"};



    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch(choice){
    	case 1: //push 1 layer

		    pushLayer(&cake, B2);

		    display(cake);

	   		break;
    	case 2: //push only base

		    pushLayer(&cake, B2);
		    pushLayer(&cake, B1);
		    pushLayer(&cake, B2);

		    display(cake);

	   		break;

    	case 3:	//push 2 tiers

		    pushLayer(&cake, B2);
		    pushLayer(&cake, B3);
		    pushLayer(&cake, B2);
		    pushLayer(&cake, S2);
		    pushLayer(&cake, S3);
		    pushLayer(&cake, S2);

		    display(cake);

	   		break;

    	case 4: //push 3 tiers

		    pushLayer(&cake, B4);
		    pushLayer(&cake, B1);
		    pushLayer(&cake, B4);
		    pushLayer(&cake, S4);
		    pushLayer(&cake, S1);
		    pushLayer(&cake, S4);
		    pushLayer(&cake, T4);
		    pushLayer(&cake, T1);
		    pushLayer(&cake, T4);

		    display(cake);
	   		break;

    	case 5: //push smaller tiers
		    pushLayer(&cake, S3);
		    pushLayer(&cake, S2);
		    pushLayer(&cake, S3);
		    pushLayer(&cake, T4);
		    pushLayer(&cake, T2);
		    pushLayer(&cake, T4);

		    display(cake);

	   		break;
	   	case 6: //push when full, should error

		    fullcake.top=MAX-1;
		    pushLayer(&fullcake, T2);

    		break;

    	case 7: // check countRadius
		    push(&tempcake, S2);
		    push(&tempcake, S2);
		    push(&tempcake, S2);

		    temp=countRadius(&tempcake, S3.radius);

		    printf("\n%d Layers have a radius of %d",temp,S3.radius);

    		break;

    	case 8: // push when 3 tiers are of same radius
		    push(&tempcake, B5);
		    push(&tempcake, B5);
		    push(&tempcake, B5);
		    pushLayer(&tempcake, B5);

		    display(tempcake);

    		break;


    	case 9: //push if larger than life
		    push(&tempcake, S2);
		    pushLayer(&tempcake, B2);

		    display(tempcake);

    		break;

    	default:
    		printf("\nNot a valid choice");
			break;

	}

    return 0;

}