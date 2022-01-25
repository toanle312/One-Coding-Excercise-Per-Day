/*
     -> True Brack - Dãy ngoặc đúng
     -> Bài toán liên quan đến CTDL Stack
     * Đề bài:
     - Một dãy ngoặc đúng sẽ là một dãy ngoặc đúng về số lượng ngoặc đóng, mở,
     thứ tự ưu tiên ngoặc và tính đúng đắn của một cặp ngoặc đóng, mở.
     - Ví dụ:
          {[()]}là một dãy ngoặc đúng vì đảm bảo thứ tự ưu tiên{,[,(và đủ số cặp ngoặc.
          Hãy kiểm tra xem một dãy ngoặc cho trước là đúng hay sai.
     * Dữ liệu vào
     - Một dòng duy nhất gồm một xâu S, (1 <= |S| <=10^5), với |S| là độ dài của xâu S.
     - Chắc chắn rằng tất cả các chứ cái trong xâu SS chỉ gồm các dấu ngoặc nhọn, vuông, tròn.
     *Dữ liệu ra
     - Một dòng duy nhất, xuất ra "Yes" nếu SS là một dãy ngoặc đúng, ngược lại xuất ra "No".
*/
// Task

#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
     string s = "";
     // Nhập chuỗi kí tự các dấu ngoặc
     cin >> s;
     // stack dùng để lưu các kí tự mở ngoặc {,[,(
     stack<char> st;

     for (int i = 0; i < s.size(); i++)
     {
          // Nếu gặp các kí tự mở ngoặc thì lưu vào stack
          if (s[i] == '{' || s[i] == '[' || s[i] == '(')
          {
               st.push(s[i]);
          }
          else
          {
               // Nếu gặp kí tự đóng ngoặc mà stack rỗng thì không hợp lệ
               if (st.empty())
               {
                    cout << "No" << endl;
                    return 0;
               }

               // Lưu dấu mở ngoặc của đầu stack
               char c = st.top();
               st.pop();

               // Kiểm tra xem vị trí hiện tại ngoặc đóng có tương thích với ngoặc mở hay không
               if ((c == '{') && (s[i] != '}') || c == '[' && s[i] != ']' || c == '(' && s[i] != ')')
               {
                    cout << "No" << endl;
                    return 0;
               }
          }
     }

     // Nếu không còn phần tử trong stack thì hợp lệ
     if (st.empty())
     {
          cout << "Yes" << endl;
          return 0;
     }
     // Ngược lại thì không hợp lệ
     else
     {
          cout << "No" << endl;
          return 0;
     }
     return 0;
}

