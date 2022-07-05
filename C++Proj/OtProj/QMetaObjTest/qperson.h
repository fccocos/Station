#ifndef QPERSON_H
#define QPERSON_H

#include <QObject>
#include <QString>
class QPerson:public QObject
{
    /*使用MOC*/
    Q_OBJECT
    /*定义类的附加信息*/
    Q_CLASSINFO("author","gunfire")
    Q_CLASSINFO("email", "gunfirefc70@163.com")
    Q_CLASSINFO("version", "1.0.0")
    /*定义属性*/
    Q_PROPERTY(int age READ getAge WRITE setAge NOTIFY ageChanged)
    Q_PROPERTY(QString name MEMBER m_name)
    Q_PROPERTY(int score MEMBER m_score)
public:
    explicit QPerson(QString fName, QObject *parent=nullptr);
    int getAge();
    void setAge(int value);
    void incAge();
private:
    int m_age = 10;
    QString m_name;
    int m_score = 90;
signals:
    void ageChanged(int value);
public slots:

};

#endif // QPERSON_H
