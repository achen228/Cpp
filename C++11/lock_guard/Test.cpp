//lock_guard
template<class _Mutex>
class lock_guard
{
public:
    // 在构造lock_gard时，_Mtx还没有被上锁
    explicit lock_guard(_Mutex& _Mtx)
        : _MyMutex(_Mtx)
    {
        _MyMutex.lock();
    }

    // 在构造lock_gard时，_Mtx已经被上锁，此处不需要再上锁
    lock_guard(_Mutex& _Mtx, adopt_lock_t)
        : _MyMutex(_Mtx)
    {}

    ~lock_guard() _NOEXCEPT
    {
        _MyMutex.unlock();
    }

    lock_guard(const lock_guard&) = delete;
    lock_guard& operator=(const lock_guard&) = delete;
private:
    _Mutex& _MyMutex;
};
