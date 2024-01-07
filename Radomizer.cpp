#include <iostream>
#include <random>
#include<time.h>

using namespace std;

int main() {
    double x = 0.0, y = 0.0;
    double stddev = 50.0; // 50 고정
    int num;
    double arrx[10001];
    double arry[10001];


    cout << "gateway의 x, y 좌표를 입력하세요. : ";
    cin >> x >> y;

    cout << "출력할 노드의 개수를 입력하세요. : ";
    cin >> num;

    //랜덤 상수 생성
    random_device rd;
    mt19937 gen(rd());

    //조건에 맞는 좌표 생성 (현재 : Gateway 중심 65m 안에 있는 노드들만 생성하게 설정)
    for (int i = 0; i < num; ++i) {
        normal_distribution<double> distributionx(x, stddev);
        double m = distributionx(gen);
        normal_distribution<double> distributiony(y, stddev);
        double n = distributiony(gen);
        if (65 < sqrt((x - m) * (x - m) + (y - n) * (y - n))) {
            i--;
            continue;
        }
        arrx[i] = m;
        arry[i] = n;
    }

    ////표준편차에 맞게 중심 좌표들 생성
    //normal_distribution<double> distributionx(x, stddev);
    //for (int i = 0; i < num; ++i) {
    //    double x = distributionx(gen);
    //    arrx[i] = x;
    //}

    //normal_distribution<double> distributiony(y, stddev);
    //for (int i = 0; i < num; ++i) {
    //    double y = distributiony(gen);
    //    arry[i] = y;
    //}



    //출력
    for (int i = 0; i < num; i++) {
        cout << "**.loRaNodes[" << i << "].**.initialX = " << arrx[i] << "m\n";
        cout << "**.loRaNodes[" << i << "].**.initialY = " << arry[i] << "m\n";
    }

    srand((unsigned)time(NULL));
    int k = 12;

    //SF 균등하게 분포
    for (int i = 0; i < num; i++) {
        cout << "**.loRaNodes[" << i << "].**initialLoRaSF = " << k-- << '\n';
        cout << "**.loRaNodes[" << i << "].**initialLoRaTP = " << rand() % 11 + 2 << "dBm\n";
        if (k == 6) k = 12;
    }

    ////SF 12로 고정
    //for (int i = 0; i < num; i++) {
    //    cout << "**.loRaNodes[" << i << "].**initialLoRaSF = " << 12 << '\n';
    //    cout << "**.loRaNodes[" << i << "].**initialLoRaTP = " << rand() % 11 + 2 << "dBm\n";
    //}

    cout << "\n/////////////////////////////////////////////////\n";
    //networkseverapp.cc ninitialx값과 y값 변경하는 코드 추가
    for (int i = 0; i < num; i++) {
        cout << "NinitialX[" << i << "] = " << arrx[i] << ";\n";
        cout << "NinitialY[" << i << "] = " << arry[i] << ";\n";
    }
    return 0;
}