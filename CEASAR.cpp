/*
     Phần 1:
     - Đề bài:
     Trước công nguyên, nhà quân sự người La Mã Julius Ceasar đã nghĩ ra phương pháp mã hóa
     một bản tin như sau: thay thế mỗi chữ trong bản tin bằng chữ đứng sau nó k vị trí trong
     bảng chữ cái. Giả sử chọn k = 3, ta có bảng chuyển đổi như sau:

     Chữ ban đầu : a b c d e f g h i j k l m n o p q r s t u v w x y z

     Chữ thay thế: d e f g h i j k l m n o p q r s t u v w x y z a b c

     Giả sử bản tin là: 'attack' thì sau khi mã hóa sẽ có bản mã 'dwwdfn' và Ceasar gửi bản
     mã cho cấp dưới.

     Nhận được bản mã và khóa, cấp dưới của Ceasar chưa biết giải mã làm sao.
     Bạn hãy giúp họ đi nào.

     - Dữ liệu vào:
     * Dòng đầu tiên là bản tin đã được mã hóa, chỉ gồm các chữ cái la tinh thường,
       chiều dài không quá 100 ký tự.
     * Dòng thứ 2 là số nguyên thể hiện khóa k (1 ≤ k ≤ 26)

     - Dữ liệu ra:
     * Bản tin ban đầu.

     - Ví dụ:
     * Input : s="wyvnyhttpun", k=7.
     * Output: programming.

     Phần 2
     Tương tự Phần 1, nhưng là thay vì đi giải mã thì ta đi mã hóa.

*/

#include <iostream>
using namespace std;
int main()
{

     // Phần 1

     // Trường hợp nếu k lớn hơn 25, tức là khi trừ đi k kí tự đã vượt quá một lần chiều
     // dài dãy chữ cái thì ta chỉ cần lấy k%25 là xong
     int k;
     string s = "";

     getline(cin, s);
     cin >> k;

     string key = "";
     for (int i = 0; i < s.size(); i++)
     {
          if (s[i] >= 'a' && s[i] <= 'z')
          {
               char temp = s[i] - k;
               if (temp >= 97)
               {
                    key += temp;
               }
               else
               {
                    key += temp + 26;
               }
          }
     }
     cout << key << endl;

     // Phần 2
     // Trường hợp nếu k1 lớn hơn 25, tức là khi trừ đi k1 kí tự đã vượt quá một lần chiều
     // dài dãy chữ cái thì ta chỉ cần lấy k%25 là xong

     /*
          int k1;
          string s1 = "";

          getline(cin, s1);
          cin >> k1;

          string key1 = "";
          for (int i = 0; i < s1.size(); i++)
          {
               if (s1[i] >= 'a' && s1[i] <= 'z')
               {
                    char temp1 = s1[i] + k1;
                    if (temp1 <= 122)
                    {
                         key1 += temp1;
                    }
                    else
                    {
                         key1 += temp1 - 26;
                    }
               }
          }
          cout << key1 << endl;
     */
     return 0;
}