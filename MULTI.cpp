/*
     - MULTI - DẤU TRONG ĐOẠN

     - Đề bài: Misaki là một cô gái xinh đẹp, hiền lành, học giỏi. Lớp cô vừa được dạy
     về dấu của tích 2 số, cô rất hứng thú với bài học và tự hỏi nếu cho một dãy số
     nguyên thì dấu của tích các số trong đoạn [L..R] bất kì là gì. Do dãy số có thể
     rất lớn nên Misaki đã nhờ bạn - một cao thủ NTUcoder giải giúp bài toán này.

     - Dữ liệu đầu vào:
     + Dòng thứ nhất là 2 số nguyên N, M với N là số lượng phần tử và M là số truy vấn
     (1 ≤ N, M ≤ 105).
     + Dòng thứ hai chứa N số nguyên, số nguyên ai là phần tử thứ i trong dãy (|ai|≤109).
     + M dòng tiếp theo chứa 2 số L, R là đoạn cần trả lời (1 ≤ L ≤ R ≤ N).

     - Dữ liệu đầu ra: Gồm M dòng, mỗi dòng in ra câu trả lời cho mỗi truy vấn,
     cụ thể: in ra "+" nếu kết quả là dương, "-" nếu kết quả là âm, "0" nếu kết quả là 0.
     (Chú ý: các ouput phải lược bỏ dấu " ").

     - Ví dụ:
     + Input
          4 3
          0 1 2 -3
          1 2
          2 3
          3 4
     + Output
          0 (Từ vị trí 1 đến 2 tích các số 0x1=0)
          + (Từ vị trí 2 đến 3 tích các số 1x2=2, dương)
          - (Từ vị trí 3 đến 4 tích các số 2x(-3) =-6, âm)

     - Ý tưởng bài toán này như sau:
     + Nếu ta chạy vòng lặp từ left đến right để nhân cá số lại với nhau thì nguy cơ
     bị quá thời gian sẽ rất cao vì mối số đều <= 10^9.
     + Để giải quyết vấn đề đó thì ta có thể làm hai cách như sau:
          * C1: sử dụng một mảng để đánh dầu xem vị trí đó là số âm hay dương hay số 0
          nếu số âm thì lưu -1, dương lưu 1, và số 0 thì lưu 0. Khi xét đoạn từ left đến
          right thì chỉ cần xét tích của mảng đánh dấu là sẽ ra kết quả.

          * C2: cũng sử dụng mảng đánh dấu nhưng làm theo một cách khác, đó là đánh dấu
          cộng dồn. Ta sử dụng hai mảng đánh dấu, một mảng đánh dấu số âm, một mảng đánh
          dấu số 0. Ta sẽ đánh dâu cộng dồn xem là từ vị trí đầu đến vị trí i đã có bao
          nhiêu số 0 hoặc số âm. Khi đó ta xét trên đoạn từ left đến right mà có số 0
          thì tích đó là 0, nếu trên đoạn đó số lượng số âm là chẵn thì tổng dương, nếu
          là lẻ thì tổng âm.

*/

#include <iostream>
using namespace std;
int main()
{
     /* C1
     int n, k;
     cin >> n >> k;
     int a[n + 1];
     int check[n + 1];
     for (int i = 1; i <= n; i++)
     {
          cin >> a[i];
          // Nếu là số 0 thì đánh dấu là 0
          if (a[i] == 0)
          {
               check[i] = 0;
          }
          // Nếu là số dương thì đánh dấu là 1
          else if (a[i] > 0)
          {
               check[i] = 1;
          }
          // Nếu là số âm thì đánh dấu là -1
          else
               check[i] = -1;
     }
     while (k--)
     {
          int sum = 1;
          int l, r;
          cin >> l >> r;
          // Kiểm tra tích các số trong đoạn từ left đến right thông qua mảng đánh dấu
          while (l <= r)
          {
               sum *= check[l];
               l++;
          }
          if (sum == 0)
          {
               cout << 0 << endl;
          }
          else if (sum > 0)
          {
               cout << '+' << endl;
          }
          else
               cout << "-" << endl;
     }*/
     // C2
     int n, k;
     cin >> n >> k;
     int zero = 0;
     int negative = 0;
     int cntZero[n + 1] = {0};
     int cntNeg[n + 1] = {0};
     for (int i = 1; i <= n; i++)
     {
          int x;
          cin >> x;
          if (x == 0)
          {
               // Đếm số lượng số 0 từ đầu đến vị trí i
               zero++;
          }
          if (x < 0)
          {
               // Đếm số lượng số âm từ đầu đến vị trí i
               negative++;
          }
          // Cập nhật lại các sô khi qua từng vị trí

          // Tại vị trí i thì nó đã đi qua bao nhiêu số 0
          cntZero[i] = zero;
          // Tại vị trí i thì nó đã đi qua bao nhiêu số âm
          cntNeg[i] = negative;
     }
     while (k--)
     {
          int l, r;
          cin >> l >> r;
          // Xét các số 0 trong đoạn từ left đến right
          if (cntZero[r] - cntZero[l - 1] > 0)
          {
               cout << 0 << endl;
          }
          // Xét các số âm trong đoạn từ left đến right
          else if ((cntNeg[r] - cntNeg[l - 1]) % 2 != 0)
          {
               cout << "-" << endl;
          }
          else
               cout << "+" << endl;
     }
     return 0;
}