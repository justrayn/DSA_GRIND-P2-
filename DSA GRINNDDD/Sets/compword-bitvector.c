void wordToArray(unsigned char word, bool array[]) {
    for (int i = 0; i < MAX; i++) {
        // Shift 1 to position i and check if that bit exists in 'word'
        if ((word & (1 << i)) != 0) {
            array[i] = true;
        } else {
            array[i] = false;
        }
    }
}