//display the bits of the given SET; number of bits to display = 
//number of bytes of the data type * number of bits each byte
void displayBits(SET s) {
    int ctr;
    SET mask = 1 << (sizeof(SET) * 8 - 1);
    for (ctr = 1; mask > 0; mask >>= 1, ++ctr) {
        printf("%u", ((s & mask) != 0) ? 1 : 0);
        if (ctr % 8 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

//insert at the greatest bit value
void insertFront(SET *s) {
    SET mask = 1 << (sizeof(SET) * 8 - 1);
    *s = (*s) | mask;
}

//insert at the least bit value
void insertRear(SET *s) {
    SET mask = 1;
    *s = (*s) | mask;
}

//least bit value is == 0, insert at pos-1
void insertAt(SET *s, int pos) {
    SET mask = 1 << (pos - 1);
    *s = (*s) | mask;
}

//negate the mask and & into the set
void deleteFront(SET *s) {
    SET mask = 1 << (sizeof(SET) * 8 - 1);
    *s = (*s) & (~mask);
}

//negate the mask of value 1 and & into the set
void deleteRear(SET *s) {
    SET mask = 1;
    *s = (*s) & (~mask);
}

//negate the mask of value at pos-1 and & into the set
void deleteAt(SET *s, int pos) {
    SET mask = 1 << (pos - 1);
    *s = (*s) & (~mask);
}

//All elements of both sets to produce another subset
SET myUnion(SET a, SET b) {
    SET c = a | b;
    return c;
}

//common between the sets
SET myIntersection(SET a, SET b) {
    SET c = a & b;
    return c;
}

//a-b == unique elements in a that are not in b == NAND
SET myDifference(SET a, SET b) {
    SET c = a & (~b);
    return c;
}