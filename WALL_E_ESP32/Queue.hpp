#ifndef Queue_hpp
#define Queue_hpp

template<typename T>
class Queue {
  private:
    T* _data;
    int _capacity;
    int _front;
    int _rear;
    int _count;
    bool _allocError;

  public:
    Queue(int capacity, T* buffer) {
      _capacity = capacity;
      _data = buffer;
      _front = 0;
      _rear = 0;
      _count = 0;
      _allocError = (_data == nullptr);
    }

    inline bool errors() {
      return _allocError;
    }

    inline bool push(const T &item) {
      if (_count >= _capacity) return false;
      _data[_rear] = item;
      _rear = (_rear + 1) % _capacity;
      _count++;
      return true;
    }

    inline T pop() {
      if (_count <= 0) return T();
      T result = _data[_front];
      _front = (_front + 1) % _capacity;
      _count--;
      return result;
    }

    inline void clear() {
      _front = 0;
      _rear = 0;
      _count = 0;
    }

    inline int size() {
      return _count;
    }

    inline bool empty() {
      return _count == 0;
    }
};

#endif
