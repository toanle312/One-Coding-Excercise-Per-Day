/*
     - PTIT037 - Gameshow "Ai là triệu phú"
     - Đề bài:
     + Taii tham gia một trò chơi hách não. Để bắt đầu anh ta phải chọn được chính xác ô cửa
     bắt đầu của mình.
     Để chọn chính xác ô cửa bắt đầu, trọng tài phát cho mỗi người một mảnh giấy trong đó có
     ghi mật mã chính là số của ô cửa mà anh ta phải bắt đầu. Tuy nhiên, có vẻ ngay câu hỏi
     đầu của trò chơi khá khó với Taii do anh ta rất lú lẫn. Taii đã chọn quyền trợ giúp của
     người thân.

     + Bạn hãy giúp Taii vượt qua câu hỏi đầu tiên này để tiến tới các câu hỏi khác nhé <3.
     Nếu bạn giải ra được, mật mã của mảnh giấy chính là điểm xuất phát của bạn.
     + Luật lệ như sau: Bạn chỉ có thể chọn ra một số chữ cái của mật mã ghi trong mảnh giấy
     và ghép chúng lại, đó chính là số của ô cửa mà anh ta bắt đầu (Tuyệt đối không được đảo
     vị trí các chữ)

     + Mật mã là một trong các dãy: ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE.

     + Tuy nhiên, trong số các tờ giấy mà Taii nhận được có 1 tờ giấy mà bạn không thể tìm
     ra mật mã được. Và đó cũng chính là kết thúc của bạn, tức là ô cửa ra về!

     - Dữ liệu vào:
     Một dòng duy nhất: Mật mã trong mảnh giấy là một xâu kí tự S, |S|<=10^3.

     - Dữ liệu ra:
     Nếu không tìm ra mật mã thì in ra "CHIA BUON, PHAI VE ROI, HEN NAM SAU NHE!!"

     NOTE: Nếu có nhiều hơn một mật mã thì in ô cửa có có số nhỏ nhất.
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
     string s = "";
     getline(cin, s);

     // Đầu tiên ta tạo một mảng chứa các kí chuỗi số để tiện cho quá trình duyệt
     string num[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN"};
     /*

     Cách bình thường


     // Xét từng số trong mảng trên
     for (int i = 0; i < 10; i++)
     {
          // Do từng phần tử trong mảng là chuỗi nên ta xét từ vị trí 0
          int index = 0;

          // Xét từng phần tử trong chuỗi
          for (int j = 0; j < s.size(); j++)
          {
               // Nếu trùng với ký tự đầu tiên trong chuỗi thì tăng vị trí lên để xét tiếp cho những lần sau
               if (s[j] == num[i][index])
               {
                    index++;

                    // nếu index hiện tại trùng với độ dài số đang xét trừ 1 thì ta in số đó ra và ngừng chương trình
                    if (index == num[i].size())
                    {
                         cout << num[i] << endl;
                         return 0;
                    }
               }
          }
     }

     // Nếu sau các vòng lặp trên mà không tìm được số thì in ra chia buồn
     cout << "Chia buon" << endl;
     return 0;

     */

     // Cách tối ưu

     // Tạo hai mảng đánh dầu là cntS và temp_CntS để đánh dấu số lần xuất hiện của kí tự có trong chuỗi
     int cntS[26], temp_CntS[26] = {0};
     int index = 0;
     for (int i = 0; i < s.size(); i++)
     {
          index = s[i] - 'A';

          // Ta phải lưu vào mảng đánh dấu tạm để mỗi lần xét sẽ cập nhật lại
          temp_CntS[index]++;
     }

     for (int i = 0; i < 10; i++)
     {
          for (int k = 0; k < 26; k++)
          {
               // Sau mối lần xét đều cập nhật lại mảng đánh dấu các kí tự
               cntS[k] = temp_CntS[k];
          }

          // Tạo một mảng đánh dấu số lần xuất hiện của các kí tự có trong mảng num[]
          int cntNum[26] = {0};

          // Tạo một biến kiểm tra xem có thỏa mãn điều kiện để xét hay không
          bool check = true;

          for (int k = 0; k < num[i].size(); k++)
          {
               index = num[i][k] - 'A';
               cntNum[index]++;

               // Nếu số lần xuất hiện của kí tự đó trong xâu s ít hơn số lần xuất hiện trong mảng num[] thì ngắt vòng lặp và xét tiếp số kế tiếp
               if (cntS[index] < cntNum[index])
               {
                    // điều kiện để không chạy các dòng lệnh xét chuỗi con ở bên dưới
                    check = false;
                    break;
               }
               if (check == true)
               {
                    // Xét tương tự ở cách bên trên
                    int pos = 0;
                    for (int j = 0; j < s.size(); j++)
                    {
                         index = s[j] - 'A';
                         if (s[j] == num[i][pos])
                         {
                              pos++;
                              if (pos == num[i].size())
                              {
                                   cout << num[i] << endl;
                                   return 0;
                              }

                              // Sau khi xét thỏa thì giảm số lần xuất hiện của kí tự đó ở mảng num

                              cntNum[index]--;
                         }

                         // Nếu xét khong thỏa thì t vẫn phải giảm đi số lần xuất hiện của kí tự đó mảng s
                         cntS[index]--;

                         // Nếu số lần xuất hiện của kí tự đó trong xâu s ít hơn số lần xuất hiện trong mảng num[] thì ngắt vòng lặp và xét tiếp số kế tiếp
                         if (cntS[index] < cntNum[index])
                         {
                              break;
                         }
                    }
               }
          }
     }

     // Nếu sau các vòng lặp trên mà không tìm được số thì in ra chia buồn
     cout << "CHIA BUON, PHAI VE ROI, HEN NAM SAU NHE!!";
     return 0;
}