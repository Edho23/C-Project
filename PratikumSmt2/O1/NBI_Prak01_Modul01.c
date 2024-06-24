#define START_VAL 0

int accum = START_VAL;

int sum(int x, int y) {
    int t = x + y;
    accum += t;
    return t;
}
