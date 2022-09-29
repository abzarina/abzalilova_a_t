#include "QueueP.h"
#include <iostream>

void QueueP::push(int data) {
    if (data > head->data) {
        if (nullptr != next) {next = ->next_;}
    }
}

int QueueP::pop() {
    int r = head->data;
    head = std::move(head);
    return r;
}
