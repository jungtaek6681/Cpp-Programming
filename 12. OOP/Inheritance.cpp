#include <iostream>

using namespace std;

/**********************************************************************************
 * ��� (Inheritance)
 *
 * �θ�Ŭ������ ��� ����� ������ �ڽ�Ŭ������ �����ϴ� ���
 * is-a ���� : �θ�Ŭ������ �ڽ�Ŭ������ �����ϴ� ���������� ��� ��Ӱ��谡 ������
 **********************************************************************************/

 // <���>
 // �θ�Ŭ������ ����ϴ� �ڽ�Ŭ�������� �θ�Ŭ������ ��� ����� �ο�
 // class �ڽ�Ŭ���� : public �θ�Ŭ����

class Monster
{
protected:
    string name;
    int hp;

public:
    void TakeHit(int damage)
    {
        hp -= damage;
        cout << name << "��/�� " << damage << "�� �޾� ü���� " << hp << " �� �Ǿ����ϴ�." << endl;
    }
};

class Slime : public Monster
{
public:
    Slime()
    {
        name = "������";
        hp = 100;
    }

    void Split()
    {
        cout << name << "��/�� �п��մϴ�." << endl;
    }
};

class Dragon : public Monster
{
public:
    Dragon()
    {
        name = "�巡��";
        hp = 300;
    }

    void Breath()
    {
        cout << name << "��/�� �극���� �ս��ϴ�." << endl;
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

    // �θ�Ŭ���� Monster�� ����� �ڽ�Ŭ������ ��� �θ�Ŭ������ ����� ������ ����
    slime.TakeHit(10);
    dragon.TakeHit(10);


    // �ڽ�Ŭ������ �θ�Ŭ������ ��ɿ� �ڽĸ��� ����� ���� �߰��Ͽ� ���� ����
    slime.Split();
    dragon.Breath();


    // ��ĳ���� : �ڽ�Ŭ������ �θ�Ŭ���� �ڷ������� ����ȯ ����
    Hero hero;
    hero.Attack(slime);
    hero.Attack(dragon);

    Monster monster = Dragon();
    hero.Attack(monster);
}


// <��� ����ǹ� 1>
// ����� �����ϴ� ��� �ڽ�Ŭ�������� �θ�Ŭ������ ����� ��� ������ �ʿ���� �����

class Fruit
{
    // �θ�Ŭ�������� �����ϴ� ����
};

class Apple : public Fruit
{
    // �θ�Ŭ�������� ������ ������ ��� �ڽ�Ŭ�������� ������ �����
};


// <��� ����ǹ� 2>
// ��ĳ������ ���� �ڽ�Ŭ������ �θ�Ŭ������ ����ȯ�� ������
// �ڽ�Ŭ������ �θ�Ŭ������ �䱸�ϴ� ������ ������ ����� ������ �� ����

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