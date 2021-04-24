#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QDebug>
#include <adapters/qt.h>
#include <hiredis.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

signals:

private slots:
    void on_connRedisBtn_clicked();

private:
    Ui::MainWidget *ui;

    RedisQtAdapter m_adapter;
    redisAsyncContext* m_ctx;

    void appendMsg_slot(redisReply *reply);

public:
    friend void getCallback(redisAsyncContext *, void *, void *);
};

#endif // MAINWIDGET_H
