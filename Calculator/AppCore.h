#ifndef APPCORE_H
#define APPCORE_H


#include <QObject>

class AppHandler : public QObject
{
    Q_OBJECT
public:
    explicit AppHandler(QObject *parent = nullptr);
    QString num1;
    QString num2;
    float result;

signals:
//    void signalSendBack(const QString& message);
       void signalSendBack(float result);
public slots:
//    void slotOperateMessage(const QString& message);
    void slotOperateMessage(QString num1, QString symbol, QString num2);
};

#endif // APPCORE_H
