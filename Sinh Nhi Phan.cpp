#include <iostream>
using namespace std;
int n;
int a[1000001];

void out(int k)
{
     for (int i = 1; i <= k; i++)
     {
          cout << a[i];
     }
}
void Try(int i, int k)
{
     // a[i] ở đây tượng trưng cho x_i và mặc định là 0
     // Do là sinh nhị phân nên phần tử trong dãy chỉ có thể là 0 hoặc 1
     for (int j = 0; j <= 1; j++)
     {
          // Những giá trị này mặc nhiên được chấp thuận mà không cần đk gì
          // Gán các giá trị đang xét trong khoảng đó cho a[i]
          a[i] = j;

          // Nếu đã đi đến cấu hình cuối cùng của bài toán thì ta in ra màn hình
          if (i == k)
          {
               out(k);
               cout << endl;
          }
          // Nếu chưa thì xét tiếp khả năng tiếp theo cho cho trường hợp a[i]
          else
               Try(i + 1, k);
     }
}
int main()
{
     int k;
     cin >> n;
     for (int i = 1; i <= n; i++)
     {
          Try(1, i);
          cout << endl
               << endl;
     }
     cout << endl;
     return 0;
}