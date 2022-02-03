/*
     - Numtrans - Trò chơi ghép số
     - Đề bài:  
     * Cho n số nguyên dương a1,a2,...,an. Hãy ghép các số lại với nhau sao cho được số nguyên dương lớn nhất

     - Input: dòng đâu là số nguyên n, dòng thứ 2 chứa n số nguyên dương, hai số liên tiếp
     cách nhau bởi dấu cách.
     - Output: số lớn nhất có thể ghép được từ n số nguyên.

     - Ví dụ:
     * Với 3 số 12, 907, 91 ta có 6 cách ghép được 6 số là: 1290791, 1291907, 9071291,
     9079112, 9112907, 9190712.
     * Trong đó số lớn nhất là 9190712.

     - Bài toán này nhìn có vẻ khá phức tạp, và việc đầu tiên mình nghĩ đến là hoán vị
     tất cả các phân tử sau đó tìm phần tử lớn nhất nhưng việc đó là quá phức tạp.

     - Ý tưởng để giải quyết bài toán một cách đơn giản và dễ hiễu như sau:

     * Giả sử mảng chỉ cho các phần tử từ 1 đến 9, ví dụ như cho mảng: {8,9,7,4,5,3}. Thì để
     ghép được số lớn nhất từ các phần tử trên thì ta chỉ cần sắp xếp giảm dần các phần tử
     là ta sẽ có được số lớn nhất -> {9,8,7,5,4,3} số lớn nhất là 987543.

     * Xét với một ví dụ cụ thể khác: cho 3 số {12, 907, 91}, nếu ta sắp xếp dãy giảm dần một
     cách cơ bản thì ta có được dãy như sau: {907,91,12} nếu lúc này ta kết luận số lớn nhất
     là 9079112 thì sẽ sai vì nếu để ý kĩ thì số lớn nhất phải là 9190712, tức là mảng lúc này
     phải là {91, 907, 12}.

     * Cho nên việc sắp xếp cơ bản cho bài toán này là không ổn, ta phải có cách sắp xếp khác
     để thỏa được yêu cầu đề bài. Nếu ta muốn so sánh hai số a,b với nhau để hoán đổi vị trí
     khi sắp xếp thì ta sẽ xét hai trường hợp là "ab" và "ba" nếu số "ab" mà lớn hơn "ba"
     thì không cần hoán đổi vị trí ngược lại thì hoán đổi. Hiểu đơn giản là ghép hai số lại
     rồi so sánh xem số ghép nào lớn hơn rồi đổi vị trí cho phù hợp.

     * Xét ví dụ trên: {12, 907, 91},
     Xét i = 0:
     Ta so sánh a[0] với a[1] thì thấy 12907 < 90712 nên ta đổi vị trí a[0] và a[1]
     -> {907, 12, 91}
     Tiếp tục so sánh a[0] với a[2] ta thấy 90791 < 91907 nên ta đổi vị trí a[0] với a[2]
     -> {91, 12, 907}
     Xét i = 1:
     Ta so sánh a[1] với a[2], ta thấy 12907 < 90712 nên ta đổi vị trí a[1] và a[2]
     -> {91, 907, 12}
     Đến đây ta đã hết cặp để so sánh nên ta kết luận số lớn nhất có thể ghép được từ 3 số
     trên là 9190712.
*/

// Task

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

// Hàm so sánh để dùng trong hàm sort()
bool cmp(const string &s1, const string &s2)
{
     // điều kiện để không swap(s1,s2) với s1 s2 là hai phần tử đang xét trong mảng
     return s1 + s2 > s2 + s1;
}

int main()
{
     int n;
     cin >> n;
     string s[n];
     for (int i = 0; i < n; i++)
     {
          cin >> s[i];
     }

     // Sắp xếp bằng hai vòng lặp.
     // for (int i = 0; i < n - 1; i++)
     // {
     //      for (int j = i + 1; j < n; j++)
     //      {
     //           /*
     //           Do là nhập theo kiểu string nên là việc ghép số lại ta dùng toán tử '+' để
     //           cộng chuỗi và dùng toán tử '>' để so sánh.
     //           */
     //           if (s[i] + s[j] < s[j] + s[i])
     //           {
     //                swap(s[i], s[j]);
     //           }
     //      }
     // }

     // Nếu không muốn sử dụng sort bằng vòng lặp thì ta có thể sử dụng hàm sort trong STL
     // Để sử dụng được hàm sort ta phải khai báo thư viện <algorithm>
     /*
          - Hàm sort() được sử dụng như sau: sort(a + i, a + j + 1, "điều kiện sắp xếp"), nếu
          không có điều kiện sắp xếp thì mặc định là sắp xếp dãy tăng dần từ vị trí i đến vị
          trí j (0<=i<j<=n-1).
          - Ví dụ: cho mảng a[5]={1,5,3,2,4}, ta dùng lệnh sort để sắp xếp cả dãy như sau:
          sort(a + 0, a + 4 + 1), vì mảng bắt đầu từ 0 và kết thúc ở n - 1 = 5 - 1 = 4. Ta
          viết gọn lại sẽ là sort(a, a + 5).
          -> {1,2,3,4,5}
          - Vậy nếu muốn sắp xếp mảng a có n phần tử thì ta sẽ dùng lệnh sort(a, a + n).
     */
     sort(s, s + n, cmp);

     for (int i = 0; i < n; i++)
     {
          cout << s[i];
     }

     return 0;
}
