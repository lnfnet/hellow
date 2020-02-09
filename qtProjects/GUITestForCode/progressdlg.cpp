#include "progressdlg.h"
#include <QFont>
#include <QProgressDialog>

ProgressDlg::ProgressDlg(QWidget *parent):QDialg(parent)
{
    QFont font("ZYSong18030",12);
    setFont(font);
    setWindowTitle(tr("progress"));

    FileNum = new QLabel;
    FileNum->settext(tr("文件数目"));

    FileNumLineEdit = new QLinEdit;
    FileNumLineEdit->setText(tr("10000"));

    ProgressType = new QLabel;
    ProgressType ->setText(tr("显示类型"));
    comboBox = new QComboBox;
    comboBox ->addItem(tr("progressBar"));
    comboBox ->addItem(tr("progressDialog"));

    progressBar =new QProgressBar;

    startBtn=new QPushButton();
    startBtn->setText(tr("开始"));

    mainLayout =new QGridLayout(this);
    mainLayout->addWidget(FileNum,0,0);
    mainLayout->addWidget(FileNumLineEdit,0,1);
    mainLayout->addWidget(ProgressType,1,0);
    mainLayout->addWidget(comboBox,1,1);
    mainLayout->addWidget(progressBar,2,0,1,2);
    mainLayout->addWidget(startBtn,3,1);
    mainLayout->setMargin(15);
    mainlayout->setSpacing(10);

    connect(startBtn,SIGNAL(clicked(bool)),this,SLOT(startProgress()));


}

void ProgressDlg::startProgress()
{
    bool ok;
    int num= FileNumLineEdit->text().toInt(&ok);

    if(comboBox->currentIndex()==0)
    {
        progressBar->setRange(0,num);
        for(int i=1;i<num+1;i++)
        {
            progressBar->setValue(i);
        }
    }
    else if(comboBox->currentIndex()==1)
    {
        QProgressDialog *progrssDialog =QProgressDialog(this);
    }

}
