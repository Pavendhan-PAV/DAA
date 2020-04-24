#include <bits/stdc++.h>
using namespace std;
#define ll long long

int partition(int a[], int low, int high);
int kthsmaintest(int a[], int low, int high, int k);

int main()
{
    int a[1000000], n = 0;
    char temp;

    cout << "Enter elements of the array :" << endl;

    while (1)
    {
        scanf("%inti%c", &a[n], &temp);
        n++;
        if (temp == '\n')
            break;
    }

    cout << "Enter k :" << endl;
    int k;
    cin >> k;

    int x = kthsmaintest(a, 0, n - 1, k);

    for (int i = 0; i < n; i++)
    {
        if (a[i] <= x)
            cout << a[i] << " ";
    }

    return 0;
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);

    return i + 1;
}

ll kthsmallest(ll a[], ll low, ll high, ll k)
{
    ll p = partition(a, low, high);

    if (p == k - 1)
        return a[p];
    else if (p > k - 1)
    {
        return kthsmallest(a, low, p - 1, k);
    }
    else
    {
        return kthsmallest(a, p + 1, high, k);
    }
}
