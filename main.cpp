#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Vector {
private:
    T* data;
    int sz;
    int cap;

public:
    Vector() {
        data = nullptr;
        sz = 0;
        cap = 0;
    }

    explicit Vector(int n) {
        sz = n;
        cap = n;
        data = new T[cap];
        for (int i = 0; i < sz; i++) {
            data[i] = T();
        }
    }

    ~Vector() {
        delete[] data;
    }

    void push_back(const T& value) {
        if (sz >= cap) {
            int newCap = (cap == 0) ? 1 : cap * 2;
            T* newData = new T[newCap];
            for (int i = 0; i < sz; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            cap = newCap;
        }
        data[sz] = value;
        sz++;
    }

    void pop_back() {
        if (sz > 0) {
            sz--;
        }
    }

    void resize(int newSize) {
        if (newSize < sz) {
            sz = newSize;
        }
        else if (newSize > sz) {
            if (newSize > cap) {
                T* newData = new T[newSize];
                for (int i = 0; i < sz; i++) {
                    newData[i] = data[i];
                }
                delete[] data;
                data = newData;
                cap = newSize;
            }
            for (int i = sz; i < newSize; i++) {
                data[i] = T();
            }
            sz = newSize;
        }
    }

    int size() const {
        return sz;
    }

    int capacity() const {
        return cap;
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    cout << "1. Вектор по умолчанию:" << endl;
    Vector<int> v1;
    cout << "Размер: " << v1.size() << ", Емкость: " << v1.capacity() << endl;

    cout << "\n2. Добавление элементов (push_back):" << endl;
    for (int i = 1; i <= 5; i++) {
        v1.push_back(i * 10);
        cout << "Добавлено: " << i * 10 << ", Размер: " << v1.size() << ", Емкость: " << v1.capacity() << endl;
    }

    cout << "\n3. Удаление последнего элемента (pop_back):" << endl;
    v1.pop_back();
    cout << "После удаления: Размер: " << v1.size() << ", Емкость: " << v1.capacity() << endl;

    cout << "\n4. Изменение размера (resize):" << endl;
    v1.resize(8);
    cout << "После resize(8): Размер: " << v1.size() << ", Емкость: " << v1.capacity() << endl;

    v1.resize(2);
    cout << "После resize(2): Размер: " << v1.size() << ", Емкость: " << v1.capacity() << endl;

    cout << "\n5. Вектор с параметром (размер):" << endl;
    Vector<double> v2(3);
    cout << "Размер: " << v2.size() << ", Емкость: " << v2.capacity() << endl;

    return 0;
}
