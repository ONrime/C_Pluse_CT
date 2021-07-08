#include <iostream>

using namespace std;

long long solution21(int w, int h) {
    long long answer = 1;

    int gong = 1;
    long long ww = w;
    long long hh = h;
    while (true) {
        if (w % 3 == 0 && h % 3 == 0) {
            w /= 3;
            h /= 3;
            gong = gong * 3;
        }
        else if (w % 2 == 0 && h % 2 == 0) {
            w /= 2;
            h /= 2;
            gong = gong * 2;
        }
        else {
            break;
        }
    }
    answer = ww * hh - ((ww + hh) - (long long)gong);
    return answer;
}

long long solution22(int w, int h) {
    long long answer = 1;

    int gong = 0;
    long long sum = (long long)w + (long long)h;
    long long multi = (long long)w * (long long)h;
    int temp = 0;

    while (h != 0) {
        temp = w % h;
        w = h;
        h = temp;
    }
    gong = w;

    answer = multi - (sum - gong);
    return answer;
}

/*int main()
{
	cout << "answer: " << solution22(8, 12) << "\n"; // 80
	cout << "answer: " << solution22(3, 4) << "\n"; // 6
}*/
/*

멀쩡한 사각형

*/