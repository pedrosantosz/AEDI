int mySqrt(int x) {
    unsigned long int i;
    for (i = 0; (i+1) * (i+1) <= x; i++);

    return i;
}