#include <bits/stdc++.h>

using namespace std;

long long a[1010];
long long n, k;
long long buf[1010];

bool cmp(int a, int b) {
    cout << 1 << " " << a << " " << b << endl;
    string ans;
    cin >> ans;
    return (ans == "YES");
}

void merge1 (long long l1, long long r1, long long l2, long long r2)
 {
  long long x1 = l1;
  long long x2 = l2;
  for (long long i = 0; i < r2 - l1; i++)
   {
    if (r1 - x1 > 0)
      if (r2 - x2 > 0)
       {
        if (cmp(a[x2], a[x1]))
         {
          buf[i] = a[x2];
          x2++;
         }
        else
         {
          buf[i] = a[x1];
          x1++;
         }
       }
     else
      {
       buf[i] = a[x1];
       x1++;
      }
    else
     if (r2 - x2 > 0)
      {
       buf[i] = a[x2];
       x2++;
      }
   }
  for (long long i = 0; i < r2 - l1; i++)
    a[l1 + i] = buf[i];
 }

void sort1(long long l, long long r)
 {
  long long m = (r + l) / 2;
  if (m - l > 1)
    sort1 (l, m);
  if (r - m > 1)
    sort1 (m, r);
  merge1 (l, m, m, r);
 }


int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
      a[i] = i + 1;
    sort1(0, n);
    cout << "0 ";
    for (int i = 0; i < n; i++)
      printf ("%d ", a[i]);
    return 0;
}
