#include "chttpauth.h"
#include "ui_chttpauth.h"
#include <QtGui>
#include <QHttpRequestHeader>
#include <QUrl>

CHttpAuth::CHttpAuth(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CHttpAuth)
{
    //m_pHttp = NULL;
    

    ui->setupUi(this);
    ui->lineEdit_ip->setText("192.168.3.211");
    ui->lineEdit_port->setText("5251");
    ui->comboBox_method->setCurrentIndex(1);
    ui->lineEdit_url->setText("/");
    ui->lineEdit_username->setText("admin");
    ui->lineEdit_pass->setText("admin");
}

CHttpAuth::~CHttpAuth()
{
    delete ui;
}

void CHttpAuth::on_pushButton_clicked()
{
    readBuf = "";
    request();
}

void CHttpAuth::request()
{
    QString ip = ui->lineEdit_ip->text();
    int port = ui->lineEdit_port->text().toInt();
    QHttp::State httpState = QHttp::Unconnected;
    
    m_pHttp =  new QHttp(this);
    connect(m_pHttp, SIGNAL(readyRead ( const QHttpResponseHeader &)), this,  SLOT(readData(const QHttpResponseHeader &)) );
    connect(m_pHttp, SIGNAL(requestFinished ( int, bool )), this,  SLOT(requestFinishOperation(int, bool )) );

    m_pHttp->setHost(ip, port);
//     QString urlLink = "http://192.168.3.105";
// 
//     QUrl url(urlLink);
    QString method = ui->comboBox_method->currentText();
    QString url = ui->lineEdit_url->text();
    QHttpRequestHeader header(method, url);
    header.setValue("Host", ip );
    header.setValue("User-Agent", "gSOAP/2.7" );
    //header.setValue("User-Agent", " Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 5.1; Trident/4.0; .NET CLR 2.0.50727)");
    //header.setValue("eferer", "http://192.168.1.232/moduser.php" );
    QString name = ui->lineEdit_username->text();
    QString pass = ui->lineEdit_pass->text();

//    QByteArray namePassword = "user1:pass1";
    QByteArray namePassword = name.toUtf8()+":"+pass.toUtf8();
    header.setValue("Authorization", "Basic "+namePassword.toBase64());
    header.setValue("Connection", "Keep-Alive");
    //header.setValue("SOAPAction", "");


//     QByteArray postData = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
//         "<SOAP-ENV:Envelope xmlns:SOAP-ENV=\"http://www.w3.org/2003/05/soap-envelope\" "
//         "xmlns:SOAP-ENC=\"http://www.w3.org/2003/05/soap-encoding\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" "
//         "xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\" xmlns:np=\"http://tempuri.org/np.xsd\">"
//         "<SOAP-ENV:Header></SOAP-ENV:Header><SOAP-ENV:Body><np:subscribeEvent></np:subscribeEvent></SOAP-ENV:Body></SOAP-ENV:Envelope>";
    //header.setContentType("text/xml; charset=utf-8");
    QString postData = ui->textEdit_request->toPlainText();
    if (method == "POST")
    {
        postData += "\r\n\r\n";
        httpGetId = m_pHttp->request( header, postData.toUtf8());
    }
    else if (method == "GET")
    {
        httpGetId = m_pHttp->request( header, NULL);
    }
    

    //     QString command = "/cgi-bin/cgi_main?cmd=modify&xml=1";
    //     httpGetId = m_pHttp->get(command );
}

void CHttpAuth::readData(const QHttpResponseHeader &resp)
{
    QString recString;
    recString = resp.toString();

    if (m_pHttp != NULL)
    {
        readBuf += (m_pHttp->readAll());
        ui->textEdit_response->setPlainText(readBuf);
    }
}

void CHttpAuth::requestFinishOperation(int requestId, bool error)
{
    if (requestId != httpGetId)
        return;

    if (m_pHttp != NULL)
    {
        readBuf += (m_pHttp->readAll());
        ui->textEdit_response->setPlainText(readBuf);
    }
    if (error) {
//         QMessageBox::information(this, tr("HTTP"),
//             tr("Requset failed: %1.")
//             .arg(m_pHttp->errorString()));
        ui->textEdit_response->setPlainText(m_pHttp->errorString());
    } else {
        //ui.statusLabel->setText(tr("Request success."));
        QMessageBox::information(this, tr("HTTP"),
            tr("Requset success: %1.")
            .arg(readBuf.data()));
    }
}
