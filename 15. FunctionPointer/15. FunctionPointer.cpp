#include <iostream>

using namespace std;

/****************************************************************
 * 함수 포인터 (Fucntion Pointer)
 *
 * 함수의 주소를 저장하는 변수
 ****************************************************************/

 // <함수 포인터>
 // 반환형 (*함수포인터변수이름)(매개변수목록);
 // 함수 포인터 변수는 함수의 주소를 저장할 수 있는 변수
 // 함수 포인터 변수에 저장하는 함수는 반드시 반환형과 매개변수가 일치해야함

int Add(int left, int right) { return left + right; }
int Sub(int left, int right) { return left - right; }
void Print(string str) { cout << str << endl; }

void Main1()
{
    int (*funcPtr)(int left, int right);

    funcPtr = Add;
    cout << (*funcPtr)(10, 20) << endl;

    funcPtr = Sub;
    cout << (*funcPtr)(20, 10) << endl;

    // funcPtr = Print;     // error : 매개변수와 반환형이 일치하는 함수만 담을 수 있음
}


// <함수 포인터 자료형 정의>
// 함수 포인터 변수의 선언을 typedef 하여 일반 변수사용처럼 가독성을 높임

typedef int (*CalcFunc)(int, int);

void Main2()
{
    CalcFunc funcPtr;
    funcPtr = Add;
    cout << funcPtr(10, 20) << endl;

    funcPtr = Sub;
    cout << funcPtr(20, 10) << endl;
}


// <콜백 함수>
// 함수 포인터 변수를 이용하여 특정조건에서 반응하는 함수를 구현
// 함수의 호출방식이 아닌 역으로 호출받는방식

typedef void (*Action)();

void Menu() { cout << "메뉴창을 엽니다." << endl; }
void Setting() { cout << "설정창을 엽니다." << endl; }
void ShutDown() { cout << "종료합니다." << endl; }

class Button
{
    Action action;

public:
    Button(Action action)
    {
        this->action = action;
    }

    void Click()
    {
        if (action == nullptr)
            return;

        action();
    }
};

void Main3()
{
    Button menuButton = Button(Menu);
    Button settingButton = Button(Setting);
    Button exitButton = Button(ShutDown);

    menuButton.Click();
    settingButton.Click();
    exitButton.Click();
}


int main()
{

}
