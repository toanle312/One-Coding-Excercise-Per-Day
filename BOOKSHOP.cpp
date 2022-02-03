/*
     - Book shop - Tiệm sách
     - Đề bài: 
     * Nhà sách đang có chương trình mua 3 tính tiền 2, và khách hàng có thể mua ít hơn
     hoặc nhiều hơn 3 quyển, nếu mua 3 quyển thì quyển ít tiền nhất sẽ được miễn phí.
     * Giả sử muốn mua 7 quyển sách có mệnh giá như sau: 2, 3, 4, 4, 6, 9, 10
     + Lượt 1 mua 3 quyển 10 3 2 thì quyển có giá tiền 2 sẽ được miễn phí.
     + Lượt 2 mua 3 quyển 6 4 4 thì quyển có giá tiền 4 sẽ được miễn phí.
     + Lượt 3 mua 1 quyển 9 thì không được giảm vì không mua đủ 3 quyển.
     - Yêu cầu: Tính số tiền nhỏ nhất phải trả cho n quyến sách.
     - Input : Dòng đầu là số nguyên n, n dòng sau là số tiền cho n quyển sách
     - Output: Yêu cầu của đề bài

     - Ý tưởng thuật toán: Về cơ bản thì ta chỉ cần sắp xếp giảm dần sau đó cứ xét lần lượt
     bộ 3 phần tử xem phần tử nào nhỏ nhất thì không tính vào số tiền, vốn dĩ ta xếp tăng dần
     vì khi xếp tăng dần ta đã dồn được những phần tử lớn lên đầu dãy khi đó số tiền được giảm
     là lớn nhất vì giá trị các quyển sách là lớn nhất do đó số tiền phải trả là ít nhất.
*/

// Task
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
     int n;
     cin >> n;
     int a[n];
     long long res = 0;
     for (int i = 0; i < n; i++)
     {
          cin >> a[i];
     }

     // Hàm sắp xếp giảm dần
     sort(a, a + n, greater<int>());
     for (int i = 0; i < n; i++)
     {

          /*
               - Thay vì xét phần tử nhỏ nhất của bộ 3 phần tử liên tiếp thì ta có thể làm
               một cách ngắn gọn và đơn giản như sau:
               + Do mảng đã được sắp xếp giảm dần nên phần tử nhỏ nhất trong bộ ba là phần
               tử tại vị trí mà khi vị trí đó cộng thêm 1 sẽ chia hết cho 3.
               + Do xét trên mảng và vị trí bắt đầu từ 0 nên ta phải cộng thêm 1.
               + Nếu xét bình thường thì ta chỉ cần xét tại những vị trí chia hết cho 3 là
               được.
               VD: cho dãy có 6 phần tử {6 5 5 5 5 4}, thì những vị trí không được tính vào
               tổng là vị trí thứ 3 (phần tử có giá trị là 5) và vị trí thứ 6 (phần tử có giá
               trị là 4).
          */

          if ((i + 1) % 3 != 0)
          {
               res += a[i];
          }

          /*
               Nếu vị trí i+1 mà chia hết cho 3 tức là đó là phần tử nhỏ nhất trong bộ 3 nên
               ta không tính vào tổng số tiền phải trả.
          */
     }
     cout << res;
     return 0;
}
