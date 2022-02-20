/*
     - Đề bài:
     Cho một dãy số a_1, a_2,...,a_n; ban đầu a_i=0 ∀i=1..n và m truy vấn dạng Q(u,v,k)
     tương ứng tăng các giá trị a_u,a_{u+1},…,a_v lên một lượng bằng k.

     - Ví dụ: Cho dãy a=[0,0,0] sau truy vấn: Q(2,3,30) thì dãy a trở trành a=[0,30,30].

     - Yêu cầu: Sau m truy vẫn, hãy tìm giá trị lớn nhất của dãy a.


     - Dữ liệu vào
     Dòng đầu ghi hai số nguyên dương n,m
     m dòng tiếp theo, dòng thứ i ghi truy vấn i gồm ba số nguyên không âm u,v,k

     - Dữ liệu ra
     Ghi ra một số nguyên duy nhất là giá trị lớn nhất của dãy A sau m truy vấn.

     - Chúng ta có thể giải quyết một cách bình thường theo yêu cầu của đề, nhưng để tối
     ưu hơn ta phải giải quyết theo kỹ thuật Prefix Sum (mảng cộng dồn).

     - Bài toán này là một dạng bài điển hình của kỹ thuật Prefix Sum, ta làm theo các
     bước như sau:
     B1: Khởi tạo mảng B có n phần tử và các phần tử đều bằng 0.
     B2: Với mỗi truy vấn L,R ta sẽ tăng giá trị a[L] lên k và giảm a[R++] xuống k đơn vị,
     sở dĩ làm thế là vì bản chất khi gán B[Left] += K là xác định điểm đầu mút bắt đầu,
     và bước xử lý khi cộng dồn các phần tử của mảng B lên là cách để sau cùng các phần tử
     trong đoạn bắt đầu từ Left trở đi sẽ tăng đúng K đơn vị, còn việc gán
     B[Right + 1] -= K như là bước đặt đầu mút kết thúc cho đầu mút bắt đầu tương ứng,
     để khi bước cộng dồn cộng lên vị trí B[Right] rồi tiếp theo là vị trí B[Right + 1]
     được cộng dồn lên thì nó bù lại cho phần đã bị trừ đi trước đó nên nó trở về lại tình
     trạng như ban đầu, và rồi từ đó B[Right + 1] sẽ được lấy cộng dồn tiếp cho
     B[Right + 2] nó sẽ không làm thay đổi kết quả của B[Right + 2].
     B3: Sau khi hoàn thành các bước trên thì ta sẽ tiền hành cộng dồn mảng B băng cách,
     B[N]+=b[N-1].
     B4: Ta cập nhật mảng A theo nguyên tắc A[i]+=B[i], sau đó tìm phần tử lớn nhất như
     bình thường.
*/

// Task
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
     /*
     int n, m;
     cin >> n >> m;
     long long a[n + 1] = {0};
     for (int i = 0; i < m; i++)
     {
          long long u, v, k;
          cin >> u >> v >> k;
          while (u <= v)
          {
               a[u++] += k;
          }
     }
     long long res = -1;
     for (int i = 1; i <= n; i++)
     {
          res = max(res, a[i]);
     }
     cout << res << endl;*/

     // Cách tối ưu

     int n, m;
     cin >> n >> m;
     // mảng chạy từ 0->n-1, nên n và n+1 sẽ không được gán là 0 nên phải khởi tạo thêm 2 ô
     long long a[n + 2] = {0};
     for (int i = 0; i < m; i++)
     {
          long long u, v, k;
          cin >> u >> v >> k;
          a[u] += k;
          a[v + 1] -= k;
     }
     long long res = -1;
     for (int i = 1; i <= n; i++)
     {
          a[i] += a[i - 1];
          res = max(res, a[i]);
     }
     cout << res << endl;

     return 0;
}