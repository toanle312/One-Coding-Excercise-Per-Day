/*
     - Đề bài:
     + Hãy tìm tất các số nguyên tố hoàn hảo có n chữ số
     + Biết số nguyên tố hoàn hảo là số mà:
          * Số đó là một số nguyên tố
          * Tất cả các số thuộc số đó đều là số nguyên tố
          * Sau khi đảo ngược lại vẫn là số đó và vẫn là số nguyên tố

     - Input : Nhập vào N
     - Output: In ra số lượng các số nguyên tố hoàn hảo có n chữ số

     - Ví dụ: N = 1, thì sẽ có tổng cộng là 4 số nguyên tố hoàn hảo có 1 chữ số, bao gồm:
     2, 3, 5, 7.

*/

#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
bool isPrime(long long num)
{
     if (num < 2)
          return false;
     for (long long i = 2; i <= sqrt(num); i++)
     {
          if (num % i == 0)
          {
               return false;
          }
     }
     return true;
}
bool isPerfectNum(long long num)
{
     int revNum = 0;
     long long temp = num;
     while (num != 0)
     {
          revNum = revNum * 10 + num % 10;
          num = num / 10;
     }
     return revNum == temp;
}

bool isPerfectPrime(int x)
{
     if (isPrime(x) && isPerfectNum(x))
     {
          while (x != 0)
          {
               if (!isPrime(x % 10))
                    return false;
               x /= 10;
          }
          return true;
     }
     return false;
}

long POW(int x, int n)
{
     if (n == 0)
     {
          return 1;
     }
     if (n == 1)
     {
          return x;
     }
     long res = 1;
     for (int i = 0; i < n; i++)
     {
          res *= x;
     }
     return res;
}
int main()
{
     /* Nếu làm theo cách này thì khi N chỉ cần lớn hơn >= 9 thì thời gian chạy sẽ vượt quá thời gian chạy quy định
          long long n;
          cin >> n;
          int c = 0;
          for (long long i = POW(10, n - 1); i <= POW(10, n) - 1; i++)
          {
               if (isPerfectPrime(i))
               {
                    c++;
               }
          }
          cout << c << endl;
     */

     /*
          Cách tối ưu, ta có thể dùng đệ quy nhưng do chưa vững kiến thức đệ quy nên ta sẽ sử dụng Queue

          - Việc cần làm là ta sẽ đi sắp xếp các số 2 3 5 7 thành số hoàn hảo có n chữ số
          - Ta có thể nhẩm thấy:
          N = 1 -> có 4 số (2 3 5 7)
          N = 2 -> có 4 số (22 33 55 77)
          N = 3 -> có 16 số (222, 323, 525, 727, ...)
          N = 4 -> có 16 số
          N = 5 -> có 64 số
          N = 6 -> có 64 số
          N = 7 -> có 256 số
          N = 8 -> có 256 số
          ...

          -> Ta có được công thức tổng quát như sau: N = 1,N = 2 thì có 4 số, N>=3 thì sẽ có
          4*(số lượng số của trường hợp N - 2)
          -> Ta dùng queue để có thể hiểu được một cách tổng quát nhất

          - Ta luôn ưu tiên kẹp một số gì đó ở giữa các chữ số 2_2, 3_3, 5_5, 7_7
          - Ví dụ: 3 chữ số thì ta sẽ ghép các số của trường hợp một chữ số vào giữa,
          5 chữ số ta sẽ ghép các số của trường hợp ba chữ số vào giữa, số n chữ số ta sẽ
          ghép các chữ số của trường hợp n-2 chữ số vào giữa, và ta có thể làm bắt đầu từ 1
          và 2 với bước nhảy là 2.


          - Chạy tay thử, ví dụ đề cho N = 3 đi ha. Thì ban đầu xét thấy N là số lẻ nên ta khởi tạo i = 1 và hàng đợi mang 4 giá trị chuỗi lần lượt từ đầu hàng đợi trở xuống là:
          2
          3
          5
          7
          - Xét i = 1 khác N = 3 nên thoả vào vòng lặp
          - Lúc này đây lấy giá trị 2 ra khỏi hàng đợi, hàng đợi lúc này còn:
          3
          5
          7
          - Với giá trị 2 lấy ra, ta thấy độ dài của nó là 1 đang khác N = 3 nên ta sẽ đi sinh ra 4 số tiếp theo để đưa vào hàng đợi, 4 số được sinh ra là: 222, 323, 525, 727 và đưa 4 số này vào hàng đợi, lúc này đây các giá trị hàng đợi đang chứa xét từ đầu đến cuối là:
          3
          5
          7
          222
          323
          525
          727
          - Lúc này đây lấy giá trị 2 ra khỏi hàng đợi, hàng đợi lúc này còn:
          3
          5
          7
          - Tiếp tục lấy giá trị đầu hàng đợi, lúc này là 3, ta thấy độ dài của nó là 1 đang khác N = 3 nên ta sẽ đi sinh ra 4 số tiếp theo để đưa vào hàng đợi, 4 số được sinh ra là: 232, 333, 535, 737 và đưa 4 số này vào hàng đợi, lúc này đây các giá trị hàng đợi đang chứa xét từ đầu đến cuối là:
          5
          7
          222
          323
          525
          727
          232
          333
          535
          737
          - Tiếp tục lấy giá trị đầu hàng đợi, lúc này là 5, ta thấy độ dài của nó là 1 đang khác N = 3 nên ta sẽ đi sinh ra 4 số tiếp theo để đưa vào hàng đợi, 4 số được sinh ra là: 252, 353, 555, 757 và đưa 4 số này vào hàng đợi, lúc này đây các giá trị hàng đợi đang chứa xét từ đầu đến cuối là:
          7
          222
          323
          525
          727
          232
          333
          535
          737
          252
          353
          555
          757
          - Tiếp tục lấy giá trị đầu hàng đợi, lúc này là 7, ta thấy độ dài của nó là 1 đang khác N = 3 nên ta sẽ đi sinh ra 4 số tiếp theo để đưa vào hàng đợi, 4 số được sinh ra là: 272, 373, 575, 777 và đưa 4 số này vào hàng đợi, lúc này đây các giá trị hàng đợi đang chứa xét từ đầu đến cuối là:
          222
          323
          525
          727
          232
          333
          535
          737
          252
          353
          555
          757
          272
          373
          575
          777
          - Tiếp tục lấy giá trị đầu hàng đợi, lúc này là 222, ta thấy độ dài của nó là 3
          lúc này bằng với N = 3 nên ta sẽ dừng quy trình sinh số lại vì từ giờ trở đi trong
          hàng đợi chỉ đang chứa toàn giá trị các số có độ dài 3 nên không cần sinh nữa.

          - Kêt quả tham khảo:
          N = 1 : 4
          N = 2 : 0
          N = 3 : 4
          N = 4 : 0
          N = 5 : 11
          N = 6 : 0
          N = 7 : 18
          N = 8 : 0
          N = 9 : 77
          N = 10: 0
          N = 11: 218
          N = 12: 0
     */

     int n;
     queue<string> q;
     cin >> n;
     int i;
     if (n % 2 != 0)
     {
          // Quy ước cho trường hợp n = 1
          q.push("2");
          q.push("3");
          q.push("5");
          q.push("7");
          i = 1;
     }
     else
     {
          // Quy ước cho trường hợp n = 2
          q.push("22");
          q.push("33");
          q.push("55");
          q.push("77");
          i = 2;
     }

     // Nếu i vẫn khác n thì tiếp tục làm
     while (i != n)
     {
          // Làm cho đến khi queue rỗng
          while (!q.empty())
          {
               // Lấy phần tử đầu queue ra để thêm vào giữa các số nguyên tố
               string s = q.front();

               // Nếu như số lấy ra được khỏi queue có độ dài n thì tức là queue đã chứa các số hoàn hảo có độ dài n
               if (s.size() == n)
                    break;
               // Sau khi lấy thì pop ra
               q.pop();

               // Luôn luôn phải kẹp giữa các chữ số 2 2, 3 3, 5 5, 7 7
               q.push("2" + s + "2");
               q.push("3" + s + "3");
               q.push("5" + s + "5");
               q.push("7" + s + "7");
          }

          // Bước nhảy là 2
          i += 2;
     }

     int count = 0;
     while (!q.empty())
     {
          // Kiểm tra xem số hoàn hảo đó có phải là số nguyên tố hay không
          if (isPrime(stoll(q.front())))
          {
               // Nếu có thì tăng biến đếm lên
               count++;
          }
          // Số nào đã được kiểm tra xong thì pop ra khỏi queue
          q.pop();
     }
     cout << count << endl;
     return 0;
}