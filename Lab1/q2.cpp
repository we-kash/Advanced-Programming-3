void solve(string &s, vector<string> &st, int k)
{
    if (k == s.size())
    {
        st.push_back(s);
        return;
    }
    string s1 = s;
    for (int i = k; i < s.size(); i++)
    {
        swap(s1[k], s1[i]);
        solve(s1, st, k + 1);
    }
}
vector<string> find_permutation(string S)
{
    vector<string> st;
    solve(S, st, 0);
    set<string> ans;
    for (auto i : st)
        ans.insert(i);
    st = {};
    for (auto i : ans)
        st.push_back(i);
    return st;
}