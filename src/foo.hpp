template <typename T>
class Foo {
public:
    Foo();
    T data() { return _data; };
    void mut_data(int data) { _data = data; };
private:
    T _data;
};

Foo(): _data(T()) {};
