#include <iostream>
using namespace std;
int n;
int a[1000001];
bool check[1000001];

void out(int k)
{
     for (int i = 1; i <= k; i++)
     {
          cout << a[i];
     }
}
void Try(int i, int k)
{
     // Mỗi phần tử trong dãy chỉnh hợp chạy từ 1 đến n
     for (int j = 1; j <= n; j++)
     {
          // Điều kiện để không bị lặp lại phần tử
          if (check[j] == 0)
          {
               // Đánh dấu là đã được gán
               check[j] = 1;
               // Những giá trị này mặc nhiên được chấp thuận mà không cần đk gì
               // Gán các giá trị đang xét trong khoảng đó cho a[i]
               a[i] = j;

               // Nếu đã đi đến cấu hình cuối cùng của bài toán thì ta in ra màn hình
               if (i == k)
               {
                    out(k);
                    cout << endl;
               }
               // Nếu chưa thì xét tiếp khả năng tiếp theo
               else
                    Try(i + 1, k);
               // Cập nhật lại là chưa được thăm để xét tiếp bộ chỉnh hợp khác
               check[j] = 0;
          }
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