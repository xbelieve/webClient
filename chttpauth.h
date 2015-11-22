#ifndef CHTTPAUTH_H
#define CHTTPAUTH_H

#include <QWidget>
#include <QtNetwork>

namespace Ui {
    class CHttpAuth;
}

class CHttpAuth : public QWidget
{
    Q_OBJECT

public:
    explicit CHttpAuth(QWidget *parent = 0);
    ~CHttpAuth();
    void request();

public slots:
    void on_pushButton_clicked();

private slots:
            void requestFinishOperation(int requestId, bool error);
            void readData(const QHttpResponseHeader &);

private:
    Ui::CHttpAuth *ui;
    QByteArray readBuf;
    int httpGetId;
    QHttp* m_pHttp;
};

#endif // CHTTPAUTH_H
