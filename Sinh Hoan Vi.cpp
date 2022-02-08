#include <iostream>
using namespace std;
int a[1000001];
bool check[1000001];
void out(int n)
{
     for (int i = 1; i <= n; i++)
     {
          cout << a[i];
     }
}
void Try(int i, int n)
{
     // Các phần tử trong dãy hoán vị chạy từ 1 đến n
     for (int j = 1; j <= n; j++)
     {
          // Điều kiện để không bị lặp lại phần tử
          if (check[j] == 0)
          {
               // Đánh dấu là đã được gán
               check[j] = 1;
               a[i] = j;
               // Nếu đã đi đến cấu hình cuối cùng thì out ra
               if (i == n)
               {
                    out(n);
                    cout << endl;
               }
               // Nếu chưa thì thử tiếp trường hợp tiếp theo
               else
                    Try(i + 1, n);

               // Cập nhật lại là chưa được thăm để xét tiếp bộ hoán vị khác
               check[j] = 0;
          }
     }
}
int main()
{
     int n;
     cin >> n;
     Try(1, n);
     return 0;
}