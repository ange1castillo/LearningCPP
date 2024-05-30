#include <iostream>
#include <memory>
#include <utility>

class Node {
    public:
        int m_value {};
        std::unique_ptr<Node> m_next {};
        std::unique_ptr<Node> m_previous {};

        Node(int value = 0, Node* previous = nullptr, Node* next = nullptr)
            : m_value { value }, m_previous { previous }, m_next { next }
        {

        }
};

class LinkedList {
    private:
        std::unique_ptr<Node> head {};

    public:
        LinkedList() = default;

        void pushBack(int value) {
            if(!head) {
                auto newNode { std::make_unique<Node>(value) };
                head = std::move(newNode);
            }

            else {
                Node* current { head.get() };

                while(current->m_next) {
                    current = current->m_next.get();
                }
                auto newNode { std::make_unique<Node>(value, current) };
                current->m_next = std::move(newNode);
            }
        }

        void popBack() {
            
        }

        friend std::ostream& operator<<(std::ostream& out, const LinkedList& list) {
            Node* current { list.head.get() };

            while(current) {
                out << current->m_value << ' ';
                current = current->m_next.get();
            }

            return out;
        }
};


int main() {
    LinkedList list {};
    std::cout << list << '\n';

    list.pushBack(5);
    std::cout << list << '\n';

    list.pushBack(6);

    std::cout << list << '\n';
}