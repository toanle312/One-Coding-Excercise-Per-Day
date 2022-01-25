/*
     - Đề bài: Tính tổng các số trong chuỗi
     - Ví dụ:
     * Input: abcD12hd3rer4
     * Output: 12+3+4 = 19
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
     string s;
     getline(cin, s);

     long long sum = 0;

     // Khởi tạo một chuỗi tạm để lưu các số
     string temp = "";

     for (int i = 0; i <= s.size(); i++)
     {

          // Nếu là các kí tự số thì sẽ thêm vào mảng tạm
          if (s[i] >= '0' && s[i] <= '9')
          {
               temp += s[i];
          }
          // Nếu là các kí tự khác
          else
          {
               // Nếu chuỗi tạm khác rỗng tức là mảng có phần tử số trong đó thì cộng vào tổng
               if (temp != "")
               {
                    sum += stoll(temp);
                    // Gán chuỗi tạm lại bằng 0
                    temp = "";
               }
          }
     }
     cout << sum << endl;
     return 0;
}