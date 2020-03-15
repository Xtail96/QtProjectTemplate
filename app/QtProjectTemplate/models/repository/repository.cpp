#include "repository.h"

Repository::Repository(QObject *parent) : QObject(parent)
{
    SettingsManager s;
    m_helloString = s.get("Main", "HelloString").toString();
}

QString Repository::helloString() const
{
    return m_helloString;
}

void Repository::setHelloString(const QString &helloString)
{
    m_helloString = helloString;
}
