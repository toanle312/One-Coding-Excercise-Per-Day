/*
     - GAGI - Gấp Giấy.
     - Cho số nguyên a là độ dày của tờ giấy, sau lần gấp đầu tiền thì độ dài tờ giấy là
     2a, sau lần gấp thứ 2 độ dày tờ giấy là 4a,...-> từ đây ta có thể suy ra ta chỉ cần
     giải hệ a*2^n <= b với n là số lần gấp giấy => n = log2(b/a), n nguyên dương.
     - b là khoảng gập ghềnh của của bàn.
     - Đề bài yêu cầu phải gấp tờ giấy bao nhiêu lần để có thể chêm vào chân bàn để bàn
     không bị gập ghềnh nữa, sao cho đồ dày của tờ giấy sau các lần gấp không được lớn hơn
     khoảng gập ghềnh.
     - Ví dụ : a=1, b=4 => cần gấp n=2 lần
               a=2, b=5 => cần gấp n=1 lần
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
     int a, b;
     cin >> a >> b;
     // Ta có thể sử dụng công thức trực tiếp như này để tính
     cout << int(log2((b * 1.0) / a)) << endl;

     // Hoặc có thể làm đơn giản theo đúng luật và yêu cầu của đề bài đưa ra
     int count = 0;

     while (a * 2 <= b)
     {
          a *= 2;
          count++;
     }

     cout << count << endl;

     return 0;
}