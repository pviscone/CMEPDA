#include "action.hh"

MyActionInitialization::MyActionInitialization()
{
}

MyActionInitialization::~MyActionInitialization()
{
}

void MyActionInitialization::Build() const
{
    MyPrimaryGenerator* primaryGenerator = new MyPrimaryGenerator();
    SetUserAction(primaryGenerator);
}