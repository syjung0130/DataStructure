#ifndef __CHECKTEMPLATECLASS_H__
#define __CHECKTEMPLATECLASS_H__

template<typename T>
class MyMath
{
public:
    MyMath(){};
    T sum(T op1, T op2);
};

template<typename T>
T MyMath<T>::sum(T op1, T op2)
{
    return op1+op2;
}


#endif