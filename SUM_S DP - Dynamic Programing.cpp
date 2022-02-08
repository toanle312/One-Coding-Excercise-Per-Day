/*
     - Bài toán quy hoạch động cơ bản
     - Tìm chuỗi con có tổng bằng s
*/

#include <iostream>
using namespace std;
int main()
{
     int a[1001], n, s;
     // Gọi dp[i,j]=1 nếu tồn tại chuỗi con từ a[1] đến a[i] sao cho tổng bằng s
     // Nếu không tồn tại thì gán bằng 0
     int dp[40005] = {0};
     cin >> n >> s;
     for (int i = 1; i <= n; i++)
     {
          cin >> a[i];
     }

     dp[0] = 1; // Luôn bằng 1 vì tập con có tổng bằng 0 là tập rỗng

     // Do nhập mản từ 1 nên bắt đầu từ 1
     for (int i = 1; i <= n; i++)
     {
          // Đối với mỗi a[i] nó sẽ bổ sung được vào một cái tổng và mỗi cái tổng đó ít
          // nhất phải lớn hơn a[i]

          // Ta sẽ bổ sung a[i] vào từng cái tổng có thể có sao cho <= s
          for (int j = s; j >= a[i]; j--)
          {
               // Nếu như dp tại j - a[i] = 1 tức là khi thêm a[i] thì sẽ tồn tại tổng
               // đó

               // Đây là công thức truy hồi hay đệ quy cho bài toán này
               // Nếu xét mà có tồn tại dãy con có tổng là j - a[i] thì khi thêm a[i]
               // vào chắc chắn sẽ tồn tại

               // Ta cứ cập nhật từ từ để tìm ra được kết quả cuối cùng là dp[s]
               if (dp[j] == 0 && dp[j - a[i]] == 1)
               {
                    dp[j] = 1;
               }
          }
     }
     if (dp[s] == 1)
     {
          cout << "OK" << endl;
     }
     return 0;
}
