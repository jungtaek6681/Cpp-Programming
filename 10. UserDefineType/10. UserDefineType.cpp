#include <iostream>

using namespace std;

/*****************************************************
 * 구조체 (Struct)
 *
 * 하나 이상의 변수를 그룹 지어서 새로운 자료형을 정의
 *****************************************************/

// <구조체 선언>
// struct 구조체이름 { 구조체내용 };
// 구조체 내용으로는 변수와 함수가 포함 가능
// 구조체에 포함한 변수를 멤버함수, 구조체에 포함한 함수를 멤버함수라고 함
struct Student
{
    string name;
    int math;
    int english;
    int science;

    float Average()
    {
        return (math + english + science) / 3.0f;
    }
};

void Main1()
{
    Student hong;           // 구조체선언
    hong.name = "홍길동";   // 멤버변수에 접근하기 위해 구조체 변수에 .을 사용
    hong.math = 60;
    hong.english = 10;
    hong.science = 100;

    Student* ptr = &hong;
    ptr->english = 80;      // 포인터 변수를 통한 멤버변수 접근은 ->을 사용
    ptr->science = 90;      // (*ptr).science 와 동일

    cout << "평균 점수는 " << hong.Average() << endl;     // 멤버함수를 호출하기 위해 구조체 변수에 .을 사용
}


// <구조체 생성자>
// 구조체를 변수를 생성과 동시에 멤버변수를 초기화해주는 멤버함수
// 반환형 없이 구조체의 이름의 함수를 구현하여 사용
struct Monster
{
    string name;
    int hp;
    int mp;

    Monster()
    {
        name = "몬스터";
        hp = 100;
        mp = 20;
    }

    Monster(string name, int hp, int mp)
    {
        this->name = name;      // this : 자기자신을 가리키는 포인터 변수
        this->hp = hp;
        this->mp = mp;
    }
};

void Main2()
{
    Monster monster = Monster();
    Monster dragon = Monster("드래곤", 250, 150);
    Monster slime = Monster("슬라임", 10, 3);
}


// <기본생성자>
// 매개변수가 없는 생성자
// 생성자를 정의하지 않는 경우 기본생성자는 자동으로 생성됨
// 만약 다른 생성자를 정의하는 경우 기본생성자는 자동으로 생성되지 않음
struct Vector3
{
    float x;
    float y;
    float z;

    /*
    Vector3() {}     // 기본생성자 : 생성자를 생략한 경우 자동 생성
    */
};

struct Point
{
    int x;
    int y;

    // 생성자를 정의하는 경우 기본생성자는 자동으로 생성되지 않음
    Point(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
};

void Main3()
{
    Vector3 vector = Vector3();     // 기본생성자를 생략한 경우에도 기본생성자가 정의됨

    // Point point = Point();       // error : 기본생성자가 정의되지 않음
    Point point = Point(3, 3);      // 정의한 생성자로만 생성이 가능
}



/*********************************************************
 * 열거형 (Enum)
 *
 * 일정 갯수의 여러멤버들을 이름으로 명명하여 정의하는 자료형
 *********************************************************/

// <열거형 선언>
// enum 열거형이름 { 멤버목록 }
// 열거형은 이름으로 표현하기에 가독성이 좋음
enum Direction { Up, Down, Left, Right };   // 열거형 정의 : 열거형이름과 멤버이름을 작성
void Main4()
{
    Direction key = Left;                   // 열거형 변수 : 열거형의 값을 가지는 변수
    switch (key)
    {
    case Up:                                // 다른자료형을 쓰는 것보다 가독성이 좋음
        cout << "위쪽으로 이동" << endl;
        break;
    case Down:
        cout << "아래쪽으로 이동" << endl;
        break;
    case Left:
        cout << "왼쪽으로 이동" << endl;
        break;
    case Right:
        cout << "오른쪽으로 이동" << endl;
        break;
    }
}


// <열거형 변환>
// 열거형은 이름으로 명명되지만 구현원리는 정수로 구현되어 있음
enum Season
{
    Spring,         // 0  => 정수를 직접설정하지 않는 경우 자동으로 0부터 할당됨
    Summer,         // 1
    Autumn = 10,    // 10 => 정수를 직접설정하는 경우 이후 값부터 할당한 값에 1씩 증가시킴
    Winter          // 11
};

void Main5()
{
    Season season = (Season)1;      // 정수형을 열거형으로 변환
    cout << season << endl;         // 출력은 1 정수형으로 진행
    int value = Autumn;             // 정수 10 대입
    season = (Season)5;             // 단순히 정수를 담는 방식이기 때문에 가능
}


// <열거형 클래스>
// C++ 11 부터 지원하는 열거형 클래스
// 기존의 열거형보다 강한 형식과 범위를 가짐
enum class Color { Red, Green, Blue };
void Main6()
{
    int value1 = Season::Spring;    // 묵시적 형변환 가능
    // int value2 = Color::Green;   // 묵시적 형변환 불가
    int value3 = (int)Color::Red;   // 명시적 형변환 가능

    Season season = Summer;         // 열거형 범위지정 없이 사용가능
    // Color color = Blue;          // 열거형 범위지정 없이 사용불가
}



/*********************************************************
 * 자료형 재정의
 *
 * 자료형의 별칭을 생성하고 실제 자료형 이름 대신 사용
 *********************************************************/

// <자료형 재정의>
// typedef 자료형 별칭
typedef int myInt_t;                    // 자료형 재정의는 _t 로 끝내는 것을 권장
typedef unsigned long long uint64_t;    // 복잡한 자료형의 간소화버전 생성

void Main7()
{
    myInt_t value1;
    uint64_t value2;
}

int main()
{
    
}
