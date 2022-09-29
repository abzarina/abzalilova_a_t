#ifndef QUEUEP_LIBRARY_H
#define QUEUEP_LIBRARY_H

/*QueueP(QueueP& example) {
    count = example.count;
}*/

#include <iostream>

class QueueP {
    class Node {
    public:
        Node() = default;
        Node(std::unique_ptr<Node> next, int data):data(data), next(std::move(next)) {}
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
};

#endif //QUEUEP_LIBRARY_H
