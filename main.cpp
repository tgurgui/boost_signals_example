#include <iostream>
#include <boost/signals2/signal.hpp>
#include <boost/bind.hpp>

class Observable;

class Observer
{
public:
    Observer() {};
    ~Observer() {};

    void SomethingChanged() {
        std::cout << "The observable has changed!" << std::endl;
    }

    void SomethingChanged(int value) {
        std::cout << "The observable value " << value << " has changed!" << std::endl;
    }
};

class Observable
{
public:
    Observable() {
        m_value = 0;
    }
    ~Observable() {};

    void Increment() {
        ++m_value;
        std::cout << "Value has changed: " << std::to_string(m_value) << std::endl;
        m_signal();
        m_signal_with_int(m_value);

    }
    void AddObserver(const Observer& observer) {
        m_signal.connect(boost::bind(&Observer::SomethingChanged, observer));
        m_signal_with_int.connect(boost::bind(&Observer::SomethingChanged, observer, _1));
    }

private:
    int m_value;
    boost::signals2::signal<void ()>    m_signal;
    boost::signals2::signal<void (int)>    m_signal_with_int;
};

int main() {
    std::cout << "Hello, World!" << std::endl;


    Observable observable;
    {
        Observer observer;

        observable.Increment();

        observable.AddObserver(observer);
    }

    observable.Increment();
    return 0;
}
