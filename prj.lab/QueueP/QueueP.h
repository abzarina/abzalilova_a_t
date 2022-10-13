#ifndef QUEUEP_LIBRARY_H
#define QUEUEP_LIBRARY_H

#include <iostream>

class QueueP {
    class Node {
    public:
        Node() = default;
        Node(int data_, std::unique_ptr<Node> next_) {
            data = data_;
            next = std::move(next_);
        }
        explicit Node(int data):data(data) {
            next = move(next);
        }

        ~Node() = default;
        std::unique_ptr<Node> next;
        int data = 0;

    };

private:
    std::unique_ptr<Node> head;

public:
    QueueP() = default;
    ~QueueP() {
        while (head)
            head = std::move(head->next);
    }
    void push(int data);
    int pop();
    bool empty() {
        return !head;
    }
};

#endif //QUEUEP_LIBRARY_H
