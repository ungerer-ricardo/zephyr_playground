#include  <zephyr/kernel.h>
#include <iostream>

int main(void) 
{ 
    while (1) 
    {
        std::cout << "hello c++" << std::endl;
        k_msleep(100U); // Sleep for 100 ms. 
    }
    return 0;
}
