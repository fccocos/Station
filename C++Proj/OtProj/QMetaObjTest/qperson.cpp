#include "qperson.h"

 QPerson::QPerson(QString fName, QObject *parent):QObject(parent)
 {
     m_name = fName;
 }
int QPerson::getAge()
{
    return this->m_age;
}
void QPerson::setAge(int value)
{
    this->m_age = value;
    emit ageChanged(this->m_age); // 发射信号
}
void QPerson::incAge()
{
    this->m_age++;
    emit ageChanged(this->m_age);
}
