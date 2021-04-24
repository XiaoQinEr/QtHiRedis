#include "mainwidget.h"
#include "ui_mainwidget.h"

//回调函数
void getCallback(redisAsyncContext *ctx, void *r, void *privdata)
{
    qDebug() << "getCallback called";

    redisReply *reply = static_cast<redisReply*>(r);
    MainWidget* mw = static_cast<MainWidget *>(privdata);

    //与界面进行数据交互
    mw->appendMsg_slot(reply);

    if(reply == nullptr || mw == nullptr){
        qDebug() << "The reply || mw is nullptr";
        return;
    }

    //打印遍历到的所有键名
    for(int i = 0; i < reply->elements; i++){
        qDebug() << "key: " << reply->element[i]->str;
    }
}

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    setWindowTitle("Qt连接Redis数据库Demo");
    setFixedSize(570, 454);

    ui->textEdit->setReadOnly(true);
    ui->textEdit->setTextColor(Qt::red);
    ui->textEdit->setFontFamily("Consolas");
    ui->textEdit->setFontPointSize(14);

    ui->addressLiEdit->setText("localhost");
    ui->portLiEdit->setText("6379");
}

MainWidget::~MainWidget()
{
    delete ui;

    m_adapter.disconnect();

    redisAsyncFree(m_ctx);
}

void MainWidget::on_connRedisBtn_clicked()
{
    //初始化hiredis上下文
    m_ctx = redisAsyncConnect(ui->addressLiEdit->text().toLatin1().data(), ui->portLiEdit->text().toInt());

    if(m_ctx->err){
        ui->textEdit->append("注意：Redis数据库连接失败！！！");
    }
    else{
        ui->textEdit->append("Redis数据库连接成功-_-");
    }

    m_adapter.setContext(m_ctx);

    redisAsyncCommand(m_ctx, NULL, NULL, "SET Author %s", "键名");
    redisAsyncCommand(m_ctx, getCallback, this, "KEYS *");
}

void MainWidget::appendMsg_slot(redisReply *reply)
{
    ui->textEdit->append("-----------打印数据库键名-----------");
    for(int i = 0; i < reply->elements; i++){
        ui->textEdit->append(reply->element[i]->str);
    }
}






