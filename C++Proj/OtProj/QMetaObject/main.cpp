#include <QCoreApplication>
#include <iostream>
#include <QMetaObject>
#include <QObject>
#include <QDebug>
#include <QTimer>

class QTestMetaObj:public QObject{
#ifndef Q_OBJECT
#define Q_OBJECT
#endif
private:
private slots:
public:
    QTestMetaObj(){};
    ~QTestMetaObj(){};
};
class QTestMetaObjSub: public QTestMetaObj{
#ifndef Q_OBJECT
#define Q_OBJECT
#endif
public:
    QTestMetaObjSub(){qDebug()<<"QTestMetaObjSub::Constructor";}
    ~QTestMetaObjSub(){qDebug()<<"QTestMetaObjSub::Destructor";}

};

class QTestMetaObjOth: public QObject{
#ifndef Q_OBJECT
#define Q_OBJECT
#endif
public:
    QTestMetaObjOth(){
      qDebug() << "QTestMetaObjOth::Constructor";
    }
    ~QTestMetaObjOth(){
        qDebug() << "QTestMetaObjOth::Destructor";
      }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /*metaObject函数测试*/
    QObject *obj = new QTestMetaObj; //向上转型
    qDebug()<<"className:"<<obj->metaObject()->className();// 打印值 className:QObject

    /*inherits函数测试*/
    QTimer *time = new QTimer;
    qDebug()<<"QTimer:"<<time->inherits("QTimer");
    qDebug() << "QObject: "<<time->inherits("QObject");
    qDebug() << "QTestMetaObj:" << time->inherits("QTestMetaObj");
    /*
     * QTimer: true
     * QObject:  true
     * QTestMetaObj: false
    */

    /*测试qobject函数*/
    QObject *objt = new QTestMetaObjSub;
    qDebug() <<"objt:"<<objt->metaObject()->className();
    QTestMetaObj *qtmobj = qobject_cast<QTestMetaObj* >(obj);
    qDebug() << "qtmobj:"<<qtmobj->metaObject()->className();
    QTestMetaObjOth *othobj = qobject_cast<QTestMetaObjOth*>(obj);
    qDebug() << "othobj:"<<othobj->metaObject()->className();

    return a.exec();
}
