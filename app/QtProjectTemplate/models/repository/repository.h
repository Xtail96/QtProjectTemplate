#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <QObject>

#include "models/settings_manager/settings_manager.h"

class Router;

class Repository : public QObject
{
    Q_OBJECT
public:
    explicit Repository(QObject *parent = nullptr);

    QString helloString() const;
    void setHelloString(const QString &helloString);

private:
    QString m_helloString;

    friend class Router;

signals:

public slots:
};

#endif // REPOSITORY_H
