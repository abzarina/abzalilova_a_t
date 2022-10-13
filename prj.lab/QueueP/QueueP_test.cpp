#include <iostream>
#include "QueueP.h"

int main() {
QueueP A;
A.push(8);
A.push(100);
A.push(5);
A.push(10);
std::cout << A.pop() << A.pop() << A.pop() << A.pop();
}
