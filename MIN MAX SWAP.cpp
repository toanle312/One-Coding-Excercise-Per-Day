/*
     - Đề bài:
     * Cho một số nguyên t là số lượng truy vấn của đề bài
     * t*3 dòng tiếp theo lần lượt là số lượng phần tử có trong  2 mảng và 2 mảng n phần tử
     * Ta có thể đổi (hoặc không cần đổi) vị trí a[i] và b[i] giữa hai mảng a,b
     * Tìm tích của hai phần tử lớn nhất của hai mảng sao cho tích hai phân tử đó là nhỏ nhất

     - Ví dụ:
     * Input:

     3 // t = 3
     6 // n = 6
     1 2 6 5 1 2
     3 4 3 2 2 5
     3 // n = 3
     3 3 3
     3 3 3
     2 // n = 2
     1 2
     2 1

     * Output:
     18
     9
     2


     - Để phân tích bài toán ta xét ví dụ đơn giản như sau:
     n = 6
     a = {1, 2, 6, 5, 1, 2}
     b = {3, 4, 3, 2, 2, 5}
     * Nếu nhu ta giữ nguyên và không đổi vị trí hai phần tử có cùng vị trí của hai mảng thì
     ta có sẽ có kết quả là 30 vì max của a là 6, max của b là 5 -> ab = 30, nhưng con số này
     chưa phải là nhỏ nhất. Nếu ta đổi vị trí a[1], b[1] và a[5], b[5] thì ta sẽ có được 2 mảng
     lúc này sẽ là
     a = {1, 4, 6, 5, 1, 5}
     b = {3, 2, 3, 2, 2, 2}
     -> max a = 6, max b = 3 => ab = 18 đây mới là phần tích nhỏ nhất thỏa yêu cầu đề bài

     * Như vậy nếu để ý kĩ ví dụ trên ta có thể thấy được mấu chốt vấn đề đó là ta sẽ dồn
     hết các phần tử lớn nhất tại các vị trí i tương ứng trong 2 mảng về hết một mảng (a hoặc
     b đều được, tùy chúng ta quy ước) và các phần tử nhỏ hơn dồn về mảng còn lại.

     * Phải làm như thế vì phần tử lớn nhất trong 2 mảng dù có hoán vị qua mảng nào thì khi
     tính tích cũng vẫn gặp nó (vì nó là lớn nhất trong cả 2 mảng) như ví dụ 1 thì phần tử
     6 là phần tử lớn nhất trong cả 2 mảng thì dù có hoán vị cho nó nằm ở mảng a hay b thì khi
     tính tích đều phải tính đến nó. Tuy nhiên các phần tử lớn còn lại nếu nó cũng nằm chung
     trong mảng đang chứa phần tử lớn nhất đó luôn thì nó sẽ bị triệt tiêu đi vì chỉ tính
     phần tử lớn nhất đó. Vì thế ta dồn hết tất cả phần tử lớn nhất tại mỗi cặp ứng với các vị trí
     i về hết trong cùng 1 mảng thì mảng còn lại chỉ chứa những thằng nhỏ nhất vì thế lúc này
     tích 2 phần tử lớn nhất của mỗi mảng sẽ được đảm bảo tích đó là nhỏ nhất có thể.

*/

// Task

#include <iostream>
#include <cmath>
using namespace std;

int findMax(int a[], int n)
{
     int max = -1;
     for (int i = 0; i < n; i++)
     {
          if (a[i] > max)
          {
               max = a[i];
          }
     }
     return max;
}

int main()
{
     // Cách làm thuần túy
     // int t;
     // cin >> t;
     // while (t--)
     // {
     //      int n;
     //      cin >> n;
     //      int a[n], b[n];
     //      for (int i = 0; i < n; i++)
     //      {
     //           cin >> a[i];
     //      }
     //      for (int i = 0; i < n; i++)
     //      {
     //           cin >> b[i];
     //           /* Sau khi nhập một phần tử thứ i của b vào thì ta xét luôn phần tử lớn nhất tại
     //            ví trí đó trong hai mảng để hoán vị hai phần tử đó luôn */
     //           if (a[i] < b[i])
     //           {
     //                swap(a[i], b[i]);
     //           }
     //      }
     //      // Tìm max của mảng a
     //      int maxa = findMax(a, n);
     //      // Tìm max của mảng b
     //      int maxb = findMax(b, n);

     //      cout << maxa * maxb << endl;
     // }

     // Cách tối ưu hơn
     // int t;
     // cin >> t;
     // while (t--)
     // {
     //      int n, maxA = -1, maxB = -1;
     //      cin >> n;
     //      int a[n], b[n];
     //      for (int i = 0; i < n; i++)
     //      {
     //           cin >> a[i];
     //      }
     //      for (int i = 0; i < n; i++)
     //      {
     //           cin >> b[i];
     //           /* Sau mỗi lần nhập phần tử thứ i của mảng b xong thì ta sẽ đi tìm phần tử
     //           lớn nhất tại vị trí đó trong hai mảng luôn mà không cần phải hoán vị tất cả
     //           rồi mới tìm sau. Với cách làm này thì ta có thể bỏ đi hai vòng lặp để tìm phần tủ lớn nhất
     //           trong hai mảng và cũng không cần hoán đổi 2 phần tử tại vị trí đang xét. */

     //           // tìm max của mảng a, là max của a[i] và b[i]
     //           maxA = max(maxA, max(a[i], b[i]));
     //           // tìm max của mảng b, là min của a[i] và b[i]
     //           maxB = max(maxB, min(a[i], b[i]));
     //      }
     //      cout << maxA * maxB << endl;
     // }

     /* Cách tối ưu hơn một tí nữa là không cần tạo mảng b vì mỗi lần đọc xong một phần tử
        ta xét hẳn nó với phần tử của mảng a nên là mỗi lần đọc chỉ cần đọc một số */

     int t;
     cin >> t;
     while (t--)
     {
          int n, maxA = -1, maxB = -1;
          cin >> n;
          int a[n];
          for (int i = 0; i < n; i++)
          {
               cin >> a[i];
          }
          for (int i = 0; i < n; i++)
          {
               int x;
               cin >> x;
               /* Sau mỗi lần nhập phần tử thứ i của mảng b xong thì ta sẽ đi tìm phần tử
               lớn nhất tại vị trí đó trong hai mảng luôn mà không cần phải hoán vị tất cả
               rồi mới tìm sau. Với cách làm này thì ta có thể bỏ đi hai vòng lặp để tìm phần tủ lớn nhất
               trong hai mảng và cũng không cần hoán đổi 2 phần tử tại vị trí đang xét. */

               // tìm max của mảng a, là max của a[i] và b[i]
               maxA = max(maxA, max(a[i], x));
               // tìm max của mảng b, là min của a[i] và b[i]
               maxB = max(maxB, min(a[i], x));
          }
          cout << maxA * maxB << endl;
     }
}
