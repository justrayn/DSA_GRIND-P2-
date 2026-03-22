#ifndef HEADER_H
#define HEADER_H

#define MAX 6
#define MIN 10
typedef char String[50];

typedef struct{
    String name;  //name of gym class
    int duration; //in hours
    String instructor;
    int minSize;
} gymClass;

typedef struct node{
    gymClass C;
    struct node* link;
} nodeType, *nodePtr;

typedef struct{
    nodePtr N;
    String Day;
    int count;
} gymDay;

typedef struct{
    gymDay dayOf[5];
    int count;
} gymSchedule;

int getDay(String Day);
void initialize(gymSchedule*);
void display(gymSchedule);
void loadDummyNodes(gymSchedule*);
nodePtr createNode(const char* name, int duration, const char* instructor, int minSize);


/* Function to implement */
void insertClass(gymSchedule*, gymClass, String);

#endif