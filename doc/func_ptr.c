#include <stdio.h>

void funcA() {
    printf("Hàm A đang chạy\n");
}

void funcB() {
    printf("Hàm B đang chạy\n");
}

void funcC() {
    printf("Hàm C đang chạy\n");
}

int main() {
//========================================================    
    // Khai báo kiểu con trỏ hàm
    void (*funcList[])() = { funcA, funcB, funcC };

    int size = sizeof(funcList) / sizeof(funcList[0]);

    // Chạy qua vòng for
    for (int i = 0; i < size; i++) {
        funcList[i]();   // gọi hàm
        


    }
//========================================================
    return 0;
}
