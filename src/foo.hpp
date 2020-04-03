template <typename F>
class Foo {
public:
    Foo();
    F data() { return _data; };
    void mut_data(F data) { _data = data; };


private:
    F _data;
    F* _array;
};

Foo()
    : _data(F())
    , _array(nullptr)
{};
