template <typename F>
class Foo {
public:
    Foo();
    F data() { return _data; };
    void mut_data(F data) { _data = data; };
private:
    F _data;
};

Foo(): _data(F()) {};
