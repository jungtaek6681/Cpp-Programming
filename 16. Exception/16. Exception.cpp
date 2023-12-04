#include <iostream>
#include <string>
#include <cassert>

using namespace std;

/****************************************************************
 * 예외처리 (Exception Handling)
 *
 * 프로그램 동작 도중 발생하는 의도하지 않은 상황을 처리하는 방법
 ****************************************************************/

 // <조건문을 통한 예외처리>
 // 프로그램이 중단될 수 있을만한 처리를 조건문을 통해 진행할 수 없도록 제한
 // 가장 좋은 예외처리 방법은 처음부터 예외가 발생할 수 없도록 설계하는 것

void Main1()
{
    cout << "두 수를 입력하세요 : ";
    int value1;
    int value2;
    cin >> value1 >> value2;

    // 만약 value2가 0인 경우 예외처리를 진행하지 않으면 프로그램이 중단됨
    // 아래의 조건문을 통해 프로그램이 중단되는 상황에 대한 예외처리를 진행
    if (value2 != 0)
    {
        cout << "결과는 " << value1 / value2 << endl;
    }
    else
    {
        cout << "0 으로 나눌 수 없습니다." << endl;
    }
}


// <try catch 예외처리>
// C++ 에서 구조적으로 예외를 처리할 수 있는 구문
// try : 예외발생에 대한 검사의 범위를 지정하는 블록
// catch : 발생한 예외를 처리하는 블록
// throw : 발생한 예외에 대한 정보를 전달하는 구문

void Main2()
{
    cout << "수를 입력하세요 : ";
    int value;
    cin >> value;
    try
    {
        if (value < 0)
            throw 5;
        else if (value < 10)
            throw "AAA";

        cout << "예외처리 없이 도달함" << endl;
    }
    catch (int ex)
    {
        // throw 5 를 catch
        cout << "throw " << ex << " 를 catch";
    }
    catch (const char* ex)
    {
        // throw AAA 를 catch
        cout << "throw " << ex << " 를 catch";
    }
}


// <스택 풀기>
// 함수에서 예외가 발생한 경우 catch 문들 발견할 때까지 호출된 스택을 풀어냄

void Func3() { cout << "3전"; throw 0; cout << "3후"; }
void Func2() { cout << "2전"; Func3(); cout << "2후"; }
void Func1() { cout << "1전"; Func2(); cout << "1후"; }

void Main3()
{
    try
    {
        Func1();
    }
    catch (int ex)
    {
        cout << "예외처리" << endl;
    }
}


// <exception 클래스>
// C++ 에서 여러 예외를 처리하기 위해 제공하는 클래스

void Main4()
{
    try
    {
        int value = stoi("abc");
    }
    catch (const exception& ex)
    {
        cout << "예외처리 : " << ex.what() << endl;
    }
}


// <exception 생성>
// exception 클래스는 예외 메시지를 생성하여 전달 가능

void Main5()
{
    try
    {
        throw exception("예외처리 메시지");
    }
    catch (const exception& ex)
    {
        cout << "예외처리 : " << ex.what() << endl;
    }
}


// <assert 함수>
// 프로그램에서 치명적일 수 있는 문제에서 프로그램을 중단하고 오류를 표시
// 프로그램을 중단시키고 오류를 표시하기 때문에 개발자의 디버깅에 용이함
// assert는 false인 경우 오류를 처리하며 && 후 메시지를 입력하여 확인하는 것이 일반적

void Main6()
{
    cout << "배열의 크기를 입력하세요 : ";
    int size;
    cin >> size;

    assert(!(size <= 0) && "배열은 0개 이하로 생성할 수 없습니다.");

    int* array = new int[size];
    delete[] array;
}


int main()
{

}
