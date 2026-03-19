#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a student record
typedef struct Student {
    char name[50];
    int studentID;
    float gpa;
    struct Student* next;
} Student;

// write your functions here

Student* createStudent(char name[], int studentID, float gpa){
    Student* newS = malloc(sizeof(Student));
    if(newS != NULL){
        strcpy(newS->name, name);
        newS->studentID = studentID;
        newS->gpa = gpa;
        newS->next = NULL;
    }
    return newS;
}
Student* insertStudent(Student* head, char name[], int StudentID, float gpa){
    Student *newS = createStudent(name, StudentID, gpa);
    if(newS != NULL){
        newS->next = head;   
        return newS;
    }
}
Student* deleteStudent(Student* head, int studentID){
    Student *trav;
    if(head == NULL){
        printf("nothing...");
        return head;
    } 
    
    if(head->studentID == studentID){
        Student *trav = head;
        head = head->next;
        free(trav);
        return head;
    }
    

    for(trav = head; trav->next != NULL && trav->next->studentID != studentID; trav = trav->next){}
    Student *temp = trav->next;
    trav->next = temp->next;
    free(temp);
    
    return head;
    
    
    
}
void displayStudents(Student* head){
    
    Student *trav;
    printf("Student List:\n");
    for(trav = head; trav != NULL; trav = trav->next){
        printf("Name: %s, ID: %d, GPA: %.2f\n", trav->name, trav->studentID, trav->gpa);
    }
    
}

void searchStudentByName(Student* head, char searchName[]){
    if(head == NULL){
        printf("Student not found!\n");
    } else {
        Student *trav;
        for(trav = head; trav != NULL && strcmp(trav->name, searchName) != 0; trav = trav->next){}
        if(trav != NULL){
            printf("Student found:\nName: %s, ID: %d, GPA: %.2f\n",trav->name, trav->studentID, trav->gpa);
        } else {
            printf("Student not found!\n");
        }
    }
}
void freeList(Student* head){
    while(head != NULL){
        free(head);
        head = head->next;
    }
}