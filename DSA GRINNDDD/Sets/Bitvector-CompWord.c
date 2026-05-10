unsigned char arrayToWord(bool array[]) {
    unsigned char result = 0; // Start with all bits at 0 (00000000)
    for (int i = 0; i < MAX; i++) {
        if (array[i]) {
            // If the array at index i is true, set the bit at position i to 1
            result |= (1 << i);
        }
    }
    return result;
}