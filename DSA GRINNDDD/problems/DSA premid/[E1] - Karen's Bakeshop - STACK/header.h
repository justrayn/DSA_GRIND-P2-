#ifndef HEADER_H
#define HEADER_H

#define MAX 9
typedef char String[50];


typedef struct {
	int radius;
	String flavor;
}CakeLayer;

typedef struct {
	CakeLayer Cake[MAX];
	int top;
}CAKE;

void initStack(CAKE *C);
void push(CAKE *C, CakeLayer Layer);
void pop(CAKE *C);
CakeLayer top(CAKE C);
void display(CAKE C);
int isEmpty(CAKE C);
int isFull(CAKE C);


/* Function to implement */
void pushLayer(CAKE *C,CakeLayer Layer);
int countRadius(CAKE *C, int radius);

#endif