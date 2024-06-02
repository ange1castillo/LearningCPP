#include <initializer_list>
#include <iostream>
#include <memory>
#include <utility>

class Node {
    public:
        int m_value {};
        std::unique_ptr<Node> m_next {};
        Node* m_previous {};

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

        LinkedList(std::initializer_list<int> list) {
            for(const auto& element : list) {
                pushBack(element);
            }
        }

        ~LinkedList() {
            if(!isEmpty()) {
                clear();
            }
        }

        void pushBack(int value) {
            auto newNode { std::make_unique<Node>(value) };

            if(!head) {
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
            if(!head) {
                throw std::out_of_range("you are trying to pop empty list");
            }

            if(!head->m_next) {
                head = nullptr;
            }

            else {
                Node* current { head.get() };

                while(current->m_next) {
                    current = current->m_next.get();
                }

                current->m_previous->m_next = nullptr;
                current = nullptr;
            }
        }

        int getFirst() const {
            if(!head) {
                throw std::out_of_range("Tried accessing an empty list!");
            }

            return head->m_value;
        }

        int getLast() const {
            if(!head) {
                throw std::out_of_range("Tried accessing an empty list!");
            }

            Node* current { head.get() };

            while(current->m_next) {
                current = current->m_next.get();
            }

            return current->m_value;
        }

        bool isEmpty() const {
            return head == nullptr;
        }

        void clear() {
            while(head) {
                head = std::move(head->m_next);
            }
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
    LinkedList list {1, 2, 3, 4, 5, 6};

    std::cout << list << '\n';
  


    return 0;
}