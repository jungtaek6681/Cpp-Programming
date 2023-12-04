#include <iostream>

using namespace std;

/****************************************************************
 * 클래스 (class)
 *
 * 객체지향 프로그래밍에 객체를 만들기 위한 형식
 * 클래스는 객체를 만들기 위한 설계도이며, 만들어진 객체는 인스턴스라 함
 ****************************************************************/

 // <클래스 선언>
 // class 클래스이름 { 클래스내용 };
 // 클래스 내용으로는 변수와 함수가 포함 가능
 // 클래스에 포함한 변수를 멤버변수, 클래스에 포함한 함수를 멤버함수라고 함

class Student
{
public: // public 접근제한자
    string name;
    int math;
    int english;
    int science;

    float Average()
    {
        return (math + english + science) / 3.0f;
    }
};


// <구조체와 클래스의 차이>
// C++에서 클래스와 구조체는 본질적으로 같음
// 차이점은 클래스의 기본접근제한자는 private, 구조체의 기본접근제한자는 public

class DataClass
{
    int value;
};

struct DataStruct
{
    int value;
};

void Class_Main1()
{
    DataClass dataClass;
    // dataClass.value;      // 기본접근제한자 public 외부사용불가

    DataStruct dataStruct;
    dataStruct.value;        // 기본접근제한자 private 외부사용가능
}


// <생성자>
// 반환형이 없는 클래스 이름의 함수를 생성자라 하며 클래스의 인스턴스를 만들 때 호출되는 역할로 사용

class Constructor
{
    int value1;
    int value2;
    int value3;

public:
    // <기본생성자>
    // 매개변수를 포함하지 않는 생성자로 다른 생성자가 없는 경우 자동으로 생성됨
    Constructor()
    {
        // <this 포인터>
        // 인스턴스를 가리키는 포인터 변수
        // 클래스 내부에 기능을 사용할 때 인스턴스를 가리키는 변수
        this->value1 = 0;
        this->value2 = 0;
        this->value3 = 0;
    }

    // <매개변수를 가지는 생성자>
    // 인스턴스를 만들 때 필요한 자료를 매개변수로 입력하여 생성하는 함수
    Constructor(int value1)
    {
        this->value1 = value1;
        this->value2 = 0;
        this->value3 = 0;
    }


    // <생성자 위임>
    // 생성자를 구현할 때 이전의 구현한 생성자를 이용하여 중복코드를 줄이는 방법
    Constructor(int value1, int value2, int value3) : Constructor(value1)
    {
        this->value2 = value2;
        this->value3 = value3;
    }
};


// <소멸자>
// 인스턴스가 메모리에서 삭제되기 직전 호출되는 함수
// 인스턴스가 삭제되기 전에 마무리해야하는 작업을 진행할 것을 권장함
// 인스턴스가 동적할당 받은 메모리를 반납하는 작업을 소멸자에 작성할 것을 권장함
// 자식클래스의 소멸자 호출이 가능하도록 소멸자는 가상함수로 작성할 것을 권장함

class Destructor
{
    int* ptr;

public:
    Destructor()
    {
        ptr = new int;
    }

    virtual ~Destructor()
    {
        delete ptr;
    }
};


// <복사생성자>
// 다른 인스턴스의 데이터를 복사하여 새로운 인스턴스를 생성하는 생성자
// 복사생성자를 구현하지 않는 경우 자동으로 생성되며, 자동으로 생성된 복사생성자는 얕은복사를 진행

class CopyConstructor
{
public:
    int* shallowPtr;        // 얕은복사가 적합한 포인터변수
    int* deepPtr;           // 깊은복사가 적합한 포인터변수

    CopyConstructor()
    {
        shallowPtr = nullptr;
        deepPtr = new int;
    }

    virtual ~CopyConstructor()
    {
        delete deepPtr;
    }

    CopyConstructor(const CopyConstructor& other)
    {
        // <얕은복사 깊은복사>
        // 얕은복사 : 변수에 저장되어 있는 값을 복사하는 것으로 포인터변수인 경우 같은 대상을 가리키게 함
        // 깊은복사 : 변수에 저장되어 있는 값이 아닌 원본의 데이터를 복사하는 것으로 새로운 대상을 생성하여 가리키게 함
        shallowPtr = other.shallowPtr;      // 얕은 복사

        deepPtr = new int;
        *deepPtr = *(other.deepPtr);        // 깊은 복사
    }
};


void Class_Main2()
{
    CopyConstructor cc1 = CopyConstructor();

    int target = 0;
    cc1.shallowPtr = &target;
    *(cc1.deepPtr) = 0;

    CopyConstructor cc2 = cc1;                  // 복사생성자를 통한 복사
    *(cc2.shallowPtr) = 1;
    *(cc2.deepPtr) = 2;

    cout << "얕은복사 원본 값 : " << *(cc1.shallowPtr) << endl;
    cout << "얕은복사 원본 주소 : " << cc1.shallowPtr << endl;
    cout << "얕은복사 복사 값 : " << *(cc2.shallowPtr) << endl;
    cout << "얕은복사 복사 주소 : " << cc2.shallowPtr << endl;

    cout << "깊은복사 원본 값 : " << *(cc1.deepPtr) << endl;
    cout << "깊은복사 원본 주소 : " << cc1.deepPtr << endl;
    cout << "깊은복사 복사 값 : " << *(cc2.deepPtr) << endl;
    cout << "깊은복사 복사 주소 : " << cc2.deepPtr << endl;
}


// <정적멤버>
class StaticClass
{
public:
    // <정적멤버변수>
    // static 키워드가 붙은 클래스의 멤버변수
    // 데이터 영역에 저장되며 모든 클래스가 하나의 변수를 공유하여 사용
    // 정적 멤버 변수는 생성자에서 초기화되지 않으며, 객체 초기화에 종속되지 않아 명시적으로 클래스 외부에서 값을 할당
    static int s_value;
    int m_value;


    // <정적멤버함수>
    // static 키워드가 붙은 클래스의 멤버함수
    // 인스턴스 없이 함수를 호출할 수 있는 특징이 있음
    static void S_Function()
    {
        s_value = 0;                // 정적멤버함수에서 정적멤버변수 사용가능
        // m_value = 0;             // 정적멤버함수에서 멤버변수 사용불가
    }
    void M_Function()
    {
        s_value = 0;                // 멤버함수에서 정적멤버변수 사용가능
        m_value = 0;                // 멤버함수에서 멤버변수 사용가능
    }
};
int StaticClass::s_value = 0;       // 정적멤버변수는 클래스 선언시 할당 할 수 없으므로 외부에서 할당을 진행해야함

void Class_Main3()
{
    StaticClass::s_value = 0;       // 정적멤버변수는 인스턴스 없이 사용가능
    // StaticClass::m_value = 0;    // error : 멤버변수는 인스턴스가 필요

    StaticClass::S_Function();      // 정적멤버함수는 인스턴스 없이 사용가능
    // StaticClass::M_Function();   // error : 멤버함수는 인스턴스가 필요

    StaticClass instance1 = StaticClass();
    StaticClass instance2 = StaticClass();

    // 정적멤버변수는 모든 인스턴스가 공유하여 사용
    instance1.s_value = 1;
    instance2.s_value = 2;
    cout << instance1.s_value << endl;      // 2
    cout << instance2.s_value << endl;      // 2
    cout << StaticClass::s_value << endl;   // 2

    // 멤버변수는 모든 인스턴스가 따로 소유
    instance1.m_value = 1;
    instance2.m_value = 2;
    cout << instance1.m_value << endl;      // 1
    cout << instance2.m_value << endl;      // 2
}


int main()
{

}