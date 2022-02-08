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
     // Để ý thấy vị trí x_i luôn lớn hơn vị trí x_i-1 ít nhất là một đơn vị
     // và vị trí x_i tối đa có thể nhận được là n - k + i
     // Ví dụ như: k=3, n=5 thì số cuối cùng của tổ hợp là 345
     // và ta thấy x_1 tối đa là 5 - 3 + 1 = 3, tươn tự cho x_2 và x_3
     for (int j = a[i - 1] + 1; j <= n - k + i; j++)
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
          // Nếu chưa thì xét tiếp khả năng tiếp theo
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