// Yêu cầu:
// 1. tạo lớp Time
// 2. tạo hàm nextSecond() để cộng thêm 1 giây vào thời gian hiện tại
// 3. tạo hàm previousSecond() để trừ đi 1 giây vào thời gian hiện tại

#include <iostream>
#include <string>
using namespace std;

// tạo lớp Time
class Time{
    private:
        int hour;           // giờ
        int minute;         // phút
        int second;         // giây

    public:
        // hàm khởi tạo không tham số
        Time(){
            hour = 0;
            minute = 0;
            second = 0;
        }

        // hàm khởi tạo có tham số
        Time(int h, int m, int s){
            hour = h;
            minute = m;
            second = s;
        }

        // hàm hủy
        ~Time(){
            cout << "Huy doi tuong\n";
        }

        // hàm getHour, getMinute, getSecond
        int getHour(){
            return hour;
        }
        int getMinute(){
            return minute;
        }
        int getSecond(){
            return second;
        }

        // hàm setHour, setMinute, setSecond
        void setHour(int h){
            hour = h;
        }
        int setMinute(int m){
            minute = m;
        }
        int setSecond(int s){
            second = s;
        }

        // hàm setTime
        void setTime(int h, int m, int s){
            hour = h;
            minute = m;
            second = s;
        }

        //hàm print
        void print(){
            string data_hour = to_string(hour);
            string data_minute = to_string(minute);
            string data_second = to_string(second);

            if (hour < 10)
            {
                data_hour = "0" + data_hour;
            }
            
            if (minute < 10)
            {
                data_minute = "0" + data_minute;
            }

            if (second < 10)
            {
                data_second = "0" + data_second;
            }
            
            cout << data_hour + ":" + data_minute + ":" + data_second + "\n";
        }

        // hàm nextSecond
        void nextSecond(){
            // trường hợp 1 là khác giây thứ 59
            if (second != 59)
            {
                // thì chỉ cần cộng 1
                second = second + 1;
            }

            // trường hợp 2 là giây thứ 59
            else if (second == 59)
            {
                // thì gán giây bằng 0
                second = 0;

                if (minute != 59)
                {
                    minute = minute + 1;
                }
                else if (minute == 59)
                {
                    minute = 0;

                    if (hour != 23)
                    {
                        hour = hour + 1;
                    }
                    else if (hour == 23)
                    {
                        hour = 0;
                    }
                }
            }
        }

        // hàm previousSecond()
        void previousSecond(){
            // trường hợp 1 là khác giây thứ 0
            if (second != 0)
            {
                // thì chỉ cần cộng 1
                second = second - 1;
            }

            // trường hợp 2 là giây thứ 0
            else if (second == 0)
            {
                // thì gán giây bằng 59
                second = 59;

                if (minute != 0)
                {
                    minute = minute - 1;
                }
                else if (minute == 0)
                {
                    minute = 59;

                    if (hour != 0)
                    {
                        hour = hour - 1;
                    }
                    else if (hour == 0)
                    {
                        hour = 23;
                    }
                }             
            }
        }
};

int main(){
    // tạo đối tượng dt1
    Time dt1 = Time(1, 1, 0);

    // gọi phương thức print()
    dt1.print();

    // gọi phương thức nextSecond()
    dt1.nextSecond();
    dt1.print();

    cout << "\n";

    // tạo đối tượng dt2
    Time dt2 = Time(7, 50, 50);

    // gọi phương thức print()
    dt2.print();

    // gọi phương thức nextSecond()
    dt2.previousSecond();
    dt2.print();

    return 0;
}