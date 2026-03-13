#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 10

typedef struct {
    int date;
    int month;
    int year;
} Date;

typedef struct {
    int prodID;
    char prodName[20];
    Date prodExp;
    float prodPrice;
    int prodQty;
} Product;

typedef struct {
    Product prods[MAX];
    int front;
    int rear;
} Queue;

typedef Product ProductStk[MAX];

void populateStack(ProductStk s);
Product createProduct(int id, char name[], Date dexp, float price, int qty);

int isLeap(int year);
int countDays(Date d);
int dateDifference(Date d1, Date d2);
void displayDate(Date d);

Queue createQueue();
bool enqueue(Queue *q, Product p);
Product dequeue(Queue *q);
Product front(Queue q);
bool isEmpty(Queue q);
bool isFull(Queue q);

void displayTravesal(Queue q);

int main() {
    Queue prodQ = createQueue();
    ProductStk prodStk;
    
    populateStack(prodStk);
    
    while(prodStk[0].prodID > 0) {
        printf("%s\n", prodStk[prodStk[0].prodID].prodName);
        prodStk[0].prodID -= 1;
    }
    
    
    
    
    return 0;
}


int isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int countDays(Date d) {
    static int monthDays[12] = {31, 28, 31, 30, 31, 30,
                                31, 31, 30, 31, 30, 31};
    int days = d.year * 365 + d.date;

    for (int i = 0; i < d.month - 1; i++)
        days += monthDays[i];

    days += d.year / 4 - d.year / 100 + d.year / 400;

    if (isLeap(d.year) && d.month > 2)
        days += 1;

    return days;
}

int dateDifference(Date d1, Date d2) {
    return countDays(d2) - countDays(d1);
}

void displayDate(Date d) {
    char monthName [12][5] = {"Jan", "Feb", "Mar",
        "Apr", "May", "Jun",
        "Jul", "Aug", "Sep",
        "Oct", "Nov", "Dec",
    };
    
    printf("%02d %s %d", d.date, monthName[d.month], d.year);
}

Queue createQueue() {
    Queue q;
    
    q.front = 0;
    q.rear = MAX - 1;
    
    return q;
}

bool enqueue(Queue *q, Product p) {
    if(isFull(*q)) {
        return false;
    }
    
    q->rear = (q->rear + 1) % MAX;
    q->prods[q->rear] = p;
    
    return true;
}

// we could not call this one if empty
Product dequeue(Queue *q) {
    Product p = q->prods[q->front];
    q->front = (q->front + 1) % MAX;
   
    return p;
}

// we could not call this one if empty
Product front(Queue q) {
    return q.prods[q.front];
}

bool isEmpty(Queue q) {
    return (q.rear + 1) % MAX == q.front;    
}

bool isFull(Queue q) {
    return (q.rear + 2) % MAX == q.front;    
}

void displayTravesal(Queue q) {
    // Product p;
    // printf("%10s | %10s | %11s | %10s | %s\n", "ID", "NAME", "DATE EXPIRY", "PRICE", "QTY");
    // for(int i = q.front; ?? ; ??) {
    //     p = q.prods[i];
    //     printf("%10d | %10s | ", p.prodID, p.prodName);
    //     displayDate(p.prodExp);
    //     printf(" | Php %6.2f | %d\n", p.prodPrice, p.prodQty);
    // }
    // printf("\n");
}

Date createDate(int date, int month, int year) {
    Date d;
    
    d.date = date;
    d.month = month;
    d.year = year;
    
    return d;
}

Product createProduct(int id, char name[], Date dexp, float price, int qty) {
    Product p;
    
    p.prodID = id;
    strcpy(p.prodName, name);
    p.prodExp = dexp;
    p.prodPrice = price;
    p.prodQty = qty;
    
    return p;
}

void populateStack(ProductStk s) {
    s[0] = createProduct(3, "", createDate(0, 0, 0), 0.0, 0);
    s[1] = createProduct(1005, "Binangkal", createDate(15, 6, 2026), 12.50, 40);
    s[2] = createProduct(1010, "Bingka", createDate(12, 7, 2027), 20.00, 5);
    s[3] = createProduct(1020, "Budbud", createDate(12, 7, 2027), 20.00, 5);
}
apps-fileview.texmex_20250904.00_p1
main (1).c
Displaying main (1).c.