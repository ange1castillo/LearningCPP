#ifndef _INTARRAY_H_
#define _INTARRAY_H_

#include <algorithm>

class IntArray {
    private:
        int m_length {};
        int* m_data {};

    public:
        IntArray() = default;

        IntArray(int length)
            : m_length { length }
        {
            if(length > 0){
                m_data = new int[length] {};
            }
        }

        ~IntArray(){
            delete[] m_data;
        }

        void erase(){
            delete[] m_data;
            m_data = nullptr;
            m_length = 0;
        }

        int& operator[](int index){
            return m_data[index];
        }

        int getLength() const {
            return m_length;
        }

        void reallocate(int newLength){
            erase();

            if(newLength <= 0){
                return;
            }

            m_data = new int[length] {};
            m_length = newLength;
        }

        void resize(int newLength){
            if(newLength == m_length){
                return;
            }

            if(newLength <= 0){
                erase();
                return;
            }

            int* data { new int[newLength] };

            int elementsToCopy { (newLength > m_length) ? m_length : newLength };

            std::copy(m_data, elementsToCopy, data);

            delete[] m_data;

            m_data = data;
            m_length = newLength;

            delete[] data;

        }
};

#endif