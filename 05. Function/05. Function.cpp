#include <iostream>

using namespace std;

/****************************************************************
 * 함수 (Function)
 *
 * 미리 정해진 동작을 수행하는 코드 묶음
 * 어떤 처리를 미리 함수로 만들어 두면 다시 반복적으로 사용 가능
 ****************************************************************/

// <함수 구성>
// 반환형 함수이름(매개변수목록) { 함수내용 }
int Add(int left, int right) { return left + right; }
void Func1() {}     // 매개변수가 없는 경우 빈괄호


// <함수 사용>
// 작성한 함수의 이름에 괄호를 붙이며, 괄호안에 매개변수들을 넣어 사용
void Main1()
{
    int ret = Add(1, 2);
    Func1();
}


// <반환형 (Return Type)>
// 함수의 결과(출력) 데이터의 자료형
// 함수의 결과 데이터가 없는 경우 반환형은 void
// <return>
// 함수가 끝나기 전까지 반드시 return으로 반환형에 맞는 데이터를 return 해야함
// 함수 진행 중 return을 만났을 경우 그 결과 데이터를 반환하고 함수를 탈출함
// void 반환형 함수의 return은 생략 가능
int IntReturnFunc2()
{
    cout << "return 전" << endl;
    return 10;                      // return 을 통해 10 값을 가지고 함수가 완료됨
    cout << "return 후" << endl;     // return 에서 함수가 완료되므로 실행되지 않음
}

void VoidReturnFunc2()
{
    cout << "return 전" << endl;
    // void 반환형은 함수 내용 중 return 을 생략 가능하나 함수를 종료하고 싶을때도 사용가능
    return;                         // void 반환형은 return 데이터가 없음
    cout << "return 후" << endl;
}

void Main2()
{
    int value = IntReturnFunc2();       // IntReturnFunc2 함수가 10 값을 반환하므로 value는 10이 됨
    VoidReturnFunc2();                  // 반환값이 없는 void 함수는 일반적으로 함수내에서 행동이 의미 있음
    // int value = VoidReturnFunc2();   // error : VoidReturnFunc2 함수가 void 반환형이므로 반환데이터가 없음
}


// <매개변수 (Parameter)>
// 함수에 추가(입력)할 데이터의 자료형과 변수명
// 같은 함수에서도 매개변수 입력이 다름에 따라 다른 처리가 가능
int Sub(int left, int right)
{
    // 함수의 입력으로 넣어준 매개변수 left, right 에 따라 함수가 동작
    return left - right;
}

void Main3()
{
    int value1 = Sub(20, 10);       // 매개변수 20, 10이 들어간 Sub 함수의 반환은 10
    int value2 = Sub(30, 10);       // 매개변수 30, 10이 들어간 Sub 함수의 반환은 20
}


// <함수 호출 순서>
// 함수는 호출되었을 때 해당 함수블록으로 제어가 전송되며 완료되었을 때 원위치로 전송됨
void Func4_2()
{                           // 1
    cout << "End" << endl;  // 2
}                           // 3

void Func4_1()
{                           // 4
    Func4_2();              // 5
}                           // 6

void Main4()
{                           // 7
    Func4_1();              // 8
}                           // 9
// 함수 호출 순서 : 7 -> 8 -> 4 -> 5 -> 1 -> 2 -> 3 -> 6 -> 9


// <함수 오버로딩>
// 같은 이름의 함수를 매개변수를 달리하여 다른 함수로 재정의하는 기술
int Multi(int left, int right) { return left * right; }
float Multi(float left, float right) { return left * right; }
double Multi(double left, double right) { return left * right; }

void Main5()
{
    cout << Multi(5, 3) << endl;        // Multi(int, int) 가 호출됨
    cout << Multi(5.1f, 3.2f) << endl;  // Multi(float, float) 가 호출됨
    cout << Multi(3.1, 3.2) << endl;    // Multi(double, double) 가 호출됨
}


// <함수 전방선언>
// 함수를 구현하기 전에 함수의 선언만 우선 진행하는 기법
// 컴파일시 함수의 호출은 함수의 구현을 필요로 하며 구현이 없는 경우 사용불가
// 전방선언을 진행하는 경우 함수의 구현을 호출 이후에 진행하도록 구현 가능
void Func6_1();
void Func6_3(); 

void Main6()
{
    Func6_1();      // 전방선언을 이용한 함수의 호출
    // Func6_2();   // error : 컴파일 에러 - 함수의 호출이 함수의 구현보다 먼저 진행되는 경우 발생
    // Func6_3();   // error : 링크 에러 - 전방선언이 있지만 함수의 구현이 없는 경우 발생
}

void Func6_1() {}
void Func6_2() {}


// <기본 매개변수>
// 매개변수에 기본값을 지정하여 함수 호출시 매개변수를 전달하지 않는 경우 기본값으로 처리
void Func7(int param1, int param2 = 2, int param3 = 3) {}
// void Func7(int param1, int param2 = 2, int param3) {}    // error : 기본 매개변수는 뒤에서부터 지정해야 함

void Main7()
{
    Func7(5, 6, 7);     // Func7(5, 6, 7);
    Func7(5, 6);        // Func7(5, 6, 3);
    Func7(5);           // Func7(5, 2, 3);
}


// <인라인 함수>
// 함수의 호출과정에서 발생하는 오버헤드를 줄이기 위해 함수의 모든 코드를 호출된 자리에 바로 삽입하는 방식의 함수
// 이는 반복적인 호출에서 걸리는 시간을 절약할 수 있으나, 함수 호출 과정으로 생기는 이점을 포기하게 됨
// 따라서 코드가 매우 간단하며 잦은 호출이 있는 함수만을 인라인 함수로 선언하는 것이 좋음
// 참고 : 인라인 함수를 알고 있어야 하지만 최신 컴파일러는 함수를 적절하게 인라인화 하므로 대부분 inline 키워드를 사용할 필요는 없다.
inline int Bigger(int left, int right) { return left > right ? left : right; }

int main()
{
    
}
