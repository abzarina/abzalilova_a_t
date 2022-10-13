#include "QueueP.h"
#include <iostream>
#include <memory>

void QueueP::push(int data) {
    if (empty() || data < head->data) {
        head = std::unique_ptr<Node>(new Node(data, std::move(head)));
        return;
    }
    else {
        Node* current = head.get();
        while (current->next && current->next->data <= data) {
            current = current->next.get();
        }

        current->next = std::unique_ptr<Node>(new Node(data, move(current->next)));
    }


}

int QueueP::pop() {
    if (empty()) {
        return -1;
    }
    int r = head->data;
    std::unique_ptr<Node> prev(move(head));
    head = move(prev->next);
    return r;
}
