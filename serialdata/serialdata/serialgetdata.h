#ifndef SERIALGETDATA_H
#define SERIALGETDATA_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDateTime>
#include "TOOL/myexcption.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SerialGetData; }
QT_END_NAMESPACE

class SerialGetData : public QMainWindow
{
    Q_OBJECT

public:
    SerialGetData(QWidget *parent = nullptr);
    ~SerialGetData();

    QByteArray serial_recv_Data() throw(MyExcption);

    bool serial_sendData(QString data);

    int getNumsFromStr(QString data);//获取字符串中数字部分

private slots:
    void on_scanSerialBtn_clicked();

    void Serial_read();

    void on_openSerialBtn_clicked();

    void on_eConnectBtn_clicked();

    void on_eDisconnectBtn_clicked();

    void timerEvent(QTimerEvent *event)override;

private:
    Ui::SerialGetData *ui;

    QSerialPort *serialport;

    int timerid;

    int serialflag;

    QDateTime dateTime;
};
#endif // SERIALGETDATA_H
