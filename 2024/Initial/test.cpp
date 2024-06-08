#include <iostream>
#include <stdint.h>  // Để sử dụng uintptr_t

int main() {
    int x = 42;    // Khai báo biến x
    int* ptr = &x; // Khai báo con trỏ trỏ đến x

    // In địa chỉ của x dưới dạng con trỏ
    std::cout << "Địa chỉ của x (dưới dạng con trỏ): " << ptr << std::endl;

    // Chuyển đổi con trỏ sang dạng số nguyên
    int64_t intAddress = reinterpret_cast<uintptr_t>(ptr);

    // In địa chỉ của x dưới dạng số nguyên
    std::cout << "Địa chỉ của x (dưới dạng số nguyên): " << intAddress << std::endl;

    return 0;
}
