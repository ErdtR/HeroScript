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

void Context::setVariable(QString name, QString val)
{
    if(_map.contains(name))
    {
        _map.insert(name, val);
    }
    qDebug() << _map.count();
}

