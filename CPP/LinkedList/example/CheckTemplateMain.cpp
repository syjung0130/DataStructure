
#include <iostream>
#include "CheckTemplateClass.h"

using namespace std;

// function template
template <typename T>
T GetMax (T a, T b) {
    T result;
    result = (a>b)? a : b;
    return (result);
}

template <typename T>
T GetMul (T a, T b)
{
    T result;
    result = a * b;
    return result;
}

int main () 
{
    int i=5, j=6, k;
    long l=10, m=5, n;
    cout << "==== Get Max Value ====" << endl;
    k=GetMax<int>(i,j);
    n=GetMax<long>(l,m);
    cout << k << endl;
    cout << n << endl;

    cout << "==== Get Mul Value =====" << endl;
    int iOp1 = 5, iOp2 = 5;
    int iResult = 0;
    double dOp1 = 5.0, dOp2 = 5.0;
    double dResult = 0.0;

    iResult = GetMul<int>(iOp1, iOp2);
    dResult = GetMul<double>(dOp1, dOp2);
    // dResult = 10.99999;
    cout.precision(5);
    cout << std::fixed << "int multiply result: " << iResult << endl
            << "double multiply result: " << dResult << endl;

    cout << "==== Check Template Class : Sum function ====" << endl;
    MyMath<int> iMath;
    iResult = iMath.sum(iOp1, iOp2);
    MyMath<double> dMath;
    dResult = dMath.sum(dOp1, dOp2);
    cout << std::fixed << "int sum() result: " << iResult << endl
        << "double sum() result: " << dResult << endl;

    cout << "==== Check Template Node, List ====" << endl;
    MyList<int> iList;
    iList.createNode();
    iList.createNode();
    MyList<double> dList;
    dList.createNode();

  return 0;
}