#include <iostream>

template <typename T, typename U>
class Pair {
    private:
        T m_first {};
        U m_second {};

    public:
        Pair(T first, U second)
            :   m_first { first }, m_second { second }
        {

        }

        T getFirst() const {
            return m_first;
        }

        U getSecond() const {
            return m_second;
        }
};

template <typename T>
class StringValuePair : public Pair<std::string, T> {
    public:
        StringValuePair(std::string_view first, T second)
            :   Pair<std::string, T> { static_cast<std::string>(first), second }
        {

        }
};

int main() {
    StringValuePair<int> hello { "Hello", 10 };
    std::cout << "Pair: " << hello.getFirst() << ' ' << hello.getSecond() << '\n';
}