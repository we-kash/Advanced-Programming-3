int c = 0;
long long toh(int n, int s, int d, int h)
{
    // Your code here if (n == 1) {
    c++;
    cout << "move disk " << n << " from rod " << s << " to rod " << d << endl;
    return c;
}
toh(n - 1, s, h, d);
c++;
cout << "move disk " << n << " from rod " << s << " to rod " << d << endl;
toh(n - 1, h, d, s);
return c;
}