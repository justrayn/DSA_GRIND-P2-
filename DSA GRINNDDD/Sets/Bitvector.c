/* SET IMPLEMENTED IN BIT VECTOR

The size of your set in bit-vector will be the largest element in
the given set of numbers +1

ex. given a set {32, 12, 49, 55, 2}, the size of my bit-vector set
will be 55+1 = 56
*/

typedef enum { FALSE, TRUE } Boolean;

/* assume the declaration is main; determining the max element */
int setA[] = {4, 7, 8, 9, 10};
int x, maxElem = setA[0];
for (x = 1; x < 5; x++) {
    if (setA[x] > maxElem)
        maxElem = setA[x];
}

/* create a bit vector out of an array of integers where size in the
parameters is the largest element in the set */
Boolean makeBitVector(int setArr[], int size) {
    Boolean *arr = calloc(size + 1, sizeof(Boolean));
    if (arr != NULL) {
        int x;
        for (x = 0; x < 5; x++) {
            arr[setArr[x]] = TRUE;
        }
    }
    return arr;
}

/* display the bit vector array and make sure you iterate
size times! – literal */
void displayBV(Boolean SET[], int size) {
    int x;
    printf("\nBit-Vector = { ");
    for (x = 0; x < size + 1; x++) {
        printf("%d", SET[x]);
        if (x < size - 1)
            printf(", ");
    }
    printf(" }\n\n");
}

/* return TRUE for a presence of a 1 at elem as the position to check */
Boolean isMember(Boolean SET[], int size, int elem) {
    return (SET[elem] == TRUE) ? TRUE : FALSE;
}

/* make the presence at index elem to 0 */
void deleteElem(Boolean arr[], int size, int elem) {
    arr[elem] = 0;
}

/* setUnion is assumed to be the largest element in the universal set; 
   return a new bit vector set of UNION bit vectors a and b */
Boolean *unionSet(Boolean setA[], Boolean setB[], int size) {
    Boolean *unionSet = calloc(size + 1, sizeof(Boolean));
    if (unionSet != NULL) {
        int x;
        for (x = 0; x < size + 1; x++) {
            if (setA[x] == TRUE || setB[x] == TRUE) {
                unionSet[x] = TRUE;
            }
        }
    }
    return unionSet;
}

/* setIntersection is assumed to be the largest element in the universal set; 
   return a new bit vector set of INTERSECTION bit vectors a and b */
Boolean *intersectionSet(Boolean setA[], Boolean setB[], int size) {
    Boolean *intersectionSet = calloc(size + 1, sizeof(Boolean));
    if (intersectionSet != NULL) {
        int x;
        for (x = 0; x < size + 1; x++) {
            if (setA[x] == TRUE && setB[x] == TRUE) {
                intersectionSet[x] = TRUE;
            }
        }
    }
    return intersectionSet;
}

/* setDifference is assumed to be the largest element in the universal set; 
   return a new bit vector set of DIFFERENCE bit vectors a and b */
Boolean *differenceSet(Boolean setA[], Boolean setB[], int size) {
    Boolean *differenceSet = calloc(size + 1, sizeof(Boolean));
    if (differenceSet != NULL) {
        int x;
        for (x = 0; x < size + 1; x++) {
            if (setA[x] == TRUE && setB[x] == FALSE) {
                differenceSet[x] = TRUE;
            }
        }
    }
    return differenceSet;
}