#include <iostream>

using namespace std;

/**********************************************************************************
 * 상속 (Inheritance)
 *
 * 부모클래스의 모든 기능을 가지는 자식클래스를 설계하는 방법
 * is-a 관계 : 부모클래스가 자식클래스를 포함하는 상위개념일 경우 상속관계가 적합함
 **********************************************************************************/

 // <상속>
 // 부모클래스를 상속하는 자식클래스에게 부모클래스의 모든 기능을 부여
 // class 자식클래스 : public 부모클래스

class Monster
{
protected:
    string name;
    int hp;

public:
    void TakeHit(int damage)
    {
        hp -= damage;
        cout << name << "이/가 " << damage << "를 받아 체력이 " << hp << " 이 되었습니다." << endl;
    }
};

class Slime : public Monster
{
public:
    Slime()
    {
        name = "슬라임";
        hp = 100;
    }

    void Split()
    {
        cout << name << "이/가 분열합니다." << endl;
    }
};

class Dragon : public Monster
{
public:
    Dragon()
    {
        name = "드래곤";
        hp = 300;
    }

    void Breath()
    {
        cout << name << "이/가 브레스를 뿜습니다." << endl;
    }
};

class Hero
{
    int damage;
public:
    void Attack(Monster& monster)
    {
        monster.TakeHit(damage);
    }
};

void Inheritance_Main1()
{
    Slime slime;
    Dragon dragon;

    // 부모클래스 Monster을 상속한 자식클래스는 모두 부모클래스의 기능을 가지고 있음
    slime.TakeHit(10);
    dragon.TakeHit(10);


    // 자식클래스는 부모클래스의 기능에 자식만의 기능을 더욱 추가하여 구현 가능
    slime.Split();
    dragon.Breath();


    // 업캐스팅 : 자식클래스는 부모클래스 자료형으로 형변환 가능
    Hero hero;
    hero.Attack(slime);
    hero.Attack(dragon);

    Monster monster = Dragon();
    hero.Attack(monster);
}


// <상속 사용의미 1>
// 상속을 진행하는 경우 자식클래스에서 부모클래스의 기능을 모두 구현할 필요없이 적용됨

class Fruit
{
    // 부모클래스에서 구현하는 내용
};

class Apple : public Fruit
{
    // 부모클래스에서 구현을 진행할 경우 자식클래스에서 구현이 적용됨
};


// <상속 사용의미 2>
// 업캐스팅을 통해 자식클래스는 부모클래스로 형변환이 가능함
// 자식클래스는 부모클래스를 요구하는 곳에서 동일한 기능을 수행할 수 있음

class Parent {};
class Child1 : public Parent {};
class Child2 : public Parent {};
class Child3 : public Parent {};

void UseParent(Parent& parent) {}

void Inheritance_Main2()
{
    Child1 child1 = Child1();
    Child2 child2 = Child2();
    Child3 child3 = Child3();

    UseParent(child1);
    UseParent(child2);
    UseParent(child3);
}