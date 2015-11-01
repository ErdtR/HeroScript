#ifndef CONTEXT_H
#define CONTEXT_H
#include <QtCore>

class Context
{
private:
    QMap<QString, QString> _map;
public:
    Context();
    void addVariable(QString name, QString val);
    QString getVariable(QString name);
    void setVariable(QString name, QString val);

signals:

public slots:
};

#endif // CONTEXT_H
