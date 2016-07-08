int getSum(int a, int b) {
    if(!b) return a;
    int sum = a^b, carry = (a&b)<<1;
    return getSum(sum, carry);
}