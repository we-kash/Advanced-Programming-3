void generate(int i, string s, vector<string> &arr)
{
    if (i == s.size())
    {
        arr.push_back(s);
        return;
    }
    s[i] = '0';
    generate(i + 1, s, arr);
    s[i] = '1';

    generate(i + 1, s, arr);
}