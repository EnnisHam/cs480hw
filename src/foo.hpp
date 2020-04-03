template <typename F>
class Foo {
public:
    Foo();
    Foo(Foo &&rval);
    F data() { return _data; };
    void mut_data(F data) { _data = data; };

    F* array() { return _array; };
    void change_ptr(F *const array) { _array = array; };


private:
    F _data;
    F* _array;
};

Foo()
    : _data(F())
    , _array(nullptr)
{};
