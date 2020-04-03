class Foo {
public:
    Foo();
    int data() { return _data; };
    void mut_data(int data) { _data = data; };
private:
    int _data;
};

Foo(): _data(0) {};
