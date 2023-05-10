void merge(int a[], int l, int r, int m)
{
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = a[m + 1 + i];
    int li = 0, ri = 0, mi = l;
    while (li < n1 and ri < n2)
    {
        if (L[li] <= R[ri])
        {
            a[mi] = L[li];
            li++;
        }
        else
        {
            a[mi] = R[ri];
            ri++;
        }
        mi++;
    }
    while (li < n1)
    {
        a[mi] = L[li];
        li++;
        mi++;
    }
    while (ri < n2)
    {
        a[mi] = R[ri];
        ri++;
        mi++;
    }
}

void mergeSort(int a[], int l, int r)
{
    int mid = (l + r) / 2;
    if (l == r)
        return;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    merge(a, l, r, mid);
}