#include <iostream>
#include <string>

using namespace std;

/****************************************************************
 * 템플릿 (Template)
 *
 * 사용자가 지정한 자료형의 함수, 클래스를 컴파일 시간에 생성하는 구문
 ****************************************************************/

 // <함수 템플릿>
 // 함수에 필요한 자료형을 선언하고 함수의 호출시 자료형을 지정해주어 사용
 // 템플릿으로 작성한 함수를 호출하는 때에 자료형에 맞는 함수를 생성하여 사용
template <typename T>
void Swap(T& left, T& right)
{
    T temp = left;
    left = right;
    right = temp;
}

void Main1()
{
    int iLeft = 10;
    int iRight = 20;
    Swap<int>(iLeft, iRight);
    cout << iLeft << ", " << iRight << endl;

    double dLeft = 2.3;
    double dRight = 3.2;
    Swap(dLeft, dRight);        // 매개변수로 템플릿 자료형을 추측가능한 경우 생략가능
    cout << dLeft << ", " << dRight << endl;
}

template <typename T>
T Multi(T left, T right) { return left * right; }

void Main2()
{
    int number = Multi(10, 20);
    // string str = Multi("ABC", "DEF");    // error : 컴파일 당시 에러
}


// <클래스 템플릿>
// 클래스에 필요한 자료형을 선언하고 클래스 자료형을 지정해주어 사용
// 템플릿으로 작성한 클래스를 호출하는 때에 자료형에 맞는 클래스를 생성하여 사용

template <typename T>
class SafeArray
{
    T* arrayPtr;
    int size;

public:
    SafeArray(int size)
    {
        this->size = size;
        arrayPtr = new T[size];
    }

    virtual ~SafeArray()
    {
        delete[] arrayPtr;
    }

    void Set(int index, T value)
    {
        if (index < 0 || index >= size)
            return;

        arrayPtr[index] = value;
    }

    T Get(int index)
    {
        return arrayPtr[index];
    }
};

void Main3()
{
    SafeArray<int> intArray = SafeArray<int>(10);
    intArray.Set(0, 20);
    cout << intArray.Get(0) << endl;

    SafeArray<double> strArray = SafeArray<double>(5);
    strArray.Set(1, 2.5);
    cout << strArray.Get(1) << endl;
}


// <함수 템플릿의 명시적 특수화>
// 템플릿의 특정 형식에 대한 특별한 동작을 별개로 정의

template <typename T>
string ToString(T value)
{
    return to_string(value);
}

template <>
string ToString(char c)
{
    return string(1, c);
}

template <>
string ToString(bool value)
{
    return value ? "true" : "false";
}

void Main4()
{
    cout << ToString(1) << endl;
    cout << ToString('a') << endl;
    cout << ToString(false) << endl;
}


int main()
{

}