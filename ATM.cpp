/*
     - Đề bài: Cho 2 số nguyên dương n số nguyên dương và một số s. Hãy tính xem trong
     n số đó có tổng các chữ số nào bằng s hay không, nếu có in ra các số đó nếu không
     in ra -1.

     - Cách làm dưới đây là cách vét cạn, nếu muốn cải tiến có thể dùng đệ quy để sinh
     các tập con của dãy n phần tử sau đó xét xem tập con nào có tổng các phần tử là s
     thì in ra tập con đó. Nhưng cách làm tối ưu nhất vẫn là cách quy hoạch động, có thể
     tra GG với từ khóa như sau "Tìm dãy con có tổng bằng s".

     - Ý tưởng của cách vét cạn là dùng cấu trúc hàng đợi để sinh các tập con của dãy và
     mỗi phần tử trong queue là một vector vì nó là các chuỗi con <= n phần tử.

*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
     int n, s;
     cin >> n >> s;
     int a[n + 1];
     queue<vector<int>> q;
     for (int i = 0; i < n; i++)
     {
          cin >> a[i];

          vector<int> temp;
          // đưa các vị trí vào trong vector
          temp.push_back(i);
          // đưa các vị trí cơ bản vào queue
          q.push(temp);
     }

     // Xét cho đến khi queue rỗng
     while (!q.empty())
     {
          // Lấy từng phần tử trong queue để xét
          vector<int> temp = q.front();
          // Do lấy ra để xét và thêm vào các chuỗi con mới nên phải xóa ra khỏi queue
          q.pop();
          int sum = 0;

          // Mỗi lần lấy chuỗi con là phải xét xem tổng các phần tử trong chuỗi con có bằng
          // s hay không
          for (int i = 0; i < temp.size(); i++)
          {
               sum += a[temp[i]];
          }

          // Nếu có thì ngưng vòng lặp, out chuỗi con đó ra và kết thúc chương trình
          if (sum == s)
          {
               for (int i = 0; i < (int)temp.size(); ++i)
               {
                    cout << a[temp[i]] << " ";
               }
               return 0;
          }

          // Lúc này tức là dãy con đang xét không thỏa có tổng các phần tử bằng s
          // Nên là phải xét thêm chuỗi con khác từ chuỗi con vừa xét

          // Xét phần tử cuỗi dãy con đó
          int x = temp[temp.size() - 1];

          // Nếu phần tử đó vẫn còn nhỏ hơn n thì ta thêm lần lượt các số lơn hơn x
          // nhưng nhỏ hơn n vào để tạo thành một dãy con mới và thêm vào queue
          while (x < n)
          {
               temp.push_back(++x);
               q.push(temp);
               // Để có thể thêm lần lượt thì sau khi đc thêm vào queue thì phải xóa phần
               // vừa thêm vào chuỗi con
               temp.pop_back();
          }
     }

     // Nếu không tìm đc chuỗi con nào thì in ra -1
     cout << -1;
     return 0;
}