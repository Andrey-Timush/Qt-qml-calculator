#include "AppCore.h"
#include <QCommandLineParser>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QFile>

AppHandler::AppHandler(QObject *parent) : QObject(parent)
{

}

//void AppHandler::slotOperateMessage(const QString &message)
//{
//    QString backMsg=message.toUpper();
//    emit signalSendBack(backMsg);
//}
void AppHandler::slotOperateMessage(QString num1, QString symbol, QString num2)
{

    QFile file( "../Calculator/out.json" );
    file.open( QIODevice::WriteOnly);

    QJsonArray data;
    int k = 0;


    float n1 = num1.toFloat();
    float n2 = num2.toFloat();
    if (symbol == '+'){
        result = n1 + n2;
        QJsonObject tmp;
        k++;
        tmp[ "exprnumber" ] = k;
        tmp[ "number1" ] = num1;
        tmp[ "number2" ] = num2;
        tmp[ "operation" ] = "+";
        tmp[ "result" ] = result;
        data.append( tmp );
    }else if (symbol == '-'){
        result = n1 - n2;
        QJsonObject tmp;
        k++;
        tmp[ "exprnumber" ] = k;
        tmp[ "number1" ] = num1;
        tmp[ "number2" ] = num2;
        tmp[ "operation" ] = "-";
        tmp[ "result" ] = result;
        data.append( tmp );
    }else if (symbol == '*'){
        result = n1 * n2;
        QJsonObject tmp;
        k++;
        tmp[ "exprnumber" ] = k;
        tmp[ "number1" ] = num1;
        tmp[ "number2" ] = num2;
        tmp[ "operation" ] = "x";
        tmp[ "result" ] = result;
        data.append( tmp );
    }else {
        result = n1 /n2;
        QJsonObject tmp;
        k++;
        tmp[ "exprnumber" ] = k;
        tmp[ "number1" ] = num1;
        tmp[ "number2" ] = num2;
        tmp[ "operation" ] = "/";
        tmp[ "result" ] = result;
        data.append( tmp );
    }
    QJsonObject obj;
    obj[ "Calculations" ] = data;

     QJsonDocument qdoc( obj );
     file.write( qdoc.toJson() );
//    char s[4] = {'+','-','*','/'};

//    switch (*s) {
//    case '+':{
//        result = n1 + n2;
//    }break;
//    case '-':{
//        result = n1 - n2;
//    }break;
//    case '*':{
//        result = n1 * n2;
//    }break;
//    case '/':{
//        result = n1 / n2;
//    }default: result = -100;
//    }


    emit signalSendBack(result);
}
