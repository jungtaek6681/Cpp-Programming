#include <iostream>

using namespace std;

/***************************************************************************
 * 다형성 (Polymorphism)
 *
 * 객체의 속성이나 기능이 상황에 따라 여러가지 형태를 가질 수 있는 성질
 ****************************************************************************/

 // <다형성>
 // 부모클래스의 함수를 자식클래스에서 재정의하여 자식클래스의 서로 다른 반응을 구현

class Car
{
protected:
    string name;
    int speed;

public:
    void Move()
    {
        cout << name << " 이/가" << speed << "의 속도로 이동합니다." << endl;
    }
};

class SportsCar : public Car
{
public:
    SportsCar()
    {
        name = "스포츠카";
        speed = 100;
    }
};

class Truck : public Car
{
public:
    Truck()
    {
        name = "트럭";
        speed = 30;
    }
};

void Polymorphism_Main1()
{
    SportsCar sportCar = SportsCar();
    Truck truck = Truck();

    sportCar.Move();    // 스포츠카 이/가 100의 속도로 이동합니다.
    truck.Move();       // 트럭 이/가 30의 속도로 이동합니다.
}


// <가상함수와 오버라이딩>
// 가상함수   : 부모클래스의 함수 중 자식클래스에 의해 재정의 할 수 있는 함수를 지정
// 오버라이딩 : 부모클래스의 함수를 같은 함수이름과 같은 매개변수로 재정의

class Skill
{
public:
    virtual void Execute()
    {
        cout << "스킬 재사용 대기시간을 진행시킴" << endl;
    }
};

class FireBall : public Skill
{
public:
    void Execute() override
    {
        Skill::Execute();
        cout << "파이어볼 스킬을 사용함" << endl;
    }
};

class Rush : public Skill
{
public:
    void Execute() override
    {
        cout << "돌진 스킬을 사용함" << endl;
    }
};


void Polymorphism_Main2()
{
    // <정적바인딩>
    // 컴파일 당시에 호출될 함수가 결정
    // 변수의 자료형을 기반으로 호출할 함수를 결정
    Skill sValue = Skill();
    Skill fValue = FireBall();
    Rush rValue = Rush();

    // 자료형을 기준으로 함수를 호출함
    sValue.Execute();           // Skill::Execute() 가 호출됨
    fValue.Execute();           // Skill::Execute() 가 호출됨
    rValue.Execute();           // Rush::Execute() 가 호출됨


    // <동적바인딩>
    // 런타임 당시에 호출될 함수가 결정
    // virtual 함수를 포함하는 객체는 가상함수테이블을 포함함
    // 가상함수를 재정의하는 경우 가상함수테이블의 주소값을 재정의한 함수의 주소로 변경
    // 호출시 가상함수테이블에 있는 함수 주소를 읽어 함수를 진행
    Skill* sPtr = new Skill();
    Skill* fPtr = new FireBall();
    Rush* rPtr = new Rush();

    // 가상함수테이블에 연결된 함수를 호출함 : 인스턴스가 재정의한 함수가 호출됨
    sPtr->Execute();            // Skill::Execute() 가 호출됨
    fPtr->Execute();            // FireBall::Execute() 가 호출됨
    rPtr->Execute();            // Rush::Execute() 가 호출됨

    delete sPtr;
    delete fPtr;
    delete rPtr;
}

// <다형성 사용의미 1>
// 새로운 클래스를 추가하거나 확장할 때 기존 코드에 영향을 최소화함

class Heal : public Skill       // 새로운 클래스를 만들 때 기존의 소스를 수정하지 않아도 됨
{
public:
    void Execute() override
    {
        Skill::Execute();
        cout << "치유 스킬을 사용함" << endl;
    }
};


// <다형성 사용의미 2>
// 클래스 간의 의존성을 줄여 확장성은 높이고 결합도는 낮춤

class RapidShot : public Skill
{
public:
    void Execute() override     // 재정의를 통해 확장성을 확보하며, 다른 클래스에 영향을 미치지 않음
    {
        cout << "연속사격 스킬을 사용함" << endl;
    }
};