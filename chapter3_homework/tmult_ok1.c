int tmult_ok1(long x, long y, long *dest) {
    long result = 0;
    *dest = x*y;
    asm("setae %al");
    return result;
}