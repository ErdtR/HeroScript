#include "context.h"

Context::Context()
{

}

void Context::addVariable(QString name, QString val)
{
    _map.insert(name, val);
    qDebug()<<name + " = " + val + " added";
}

QString Context::getVariable(QString name)
{
    if(_map.contains(name))
    {
        return _map[name];
    }
    else
    {
        return "";
    }
}

