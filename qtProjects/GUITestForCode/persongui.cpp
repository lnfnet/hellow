#include "persongui.h"

personGui::personGui(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("UserInfo for QMainWindows"));
    UserNameLabel = new QLabel(tr("用户名："));
    NameLabel= new QLabel(tr("姓名："));
    SexLabel= new QLabel(tr("性别："));
    DepartmentLabel= new QLabel(tr("部门："));
    AgeLabel= new QLabel(tr("年龄："));
    OtherLabel= new QLabel(tr("其它："));
    OtherLabel->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    UserNameLinEdit = new QLineEdit();
    NameLineEdit=new QLineEdit();
    SexCoBox = new QComboBox;
    SexCoBox->addItem(tr("女"));
    SexCoBox->addItem(tr("男"));

    DepartmentTextEdit = new QTextEdit;
    AgeLineEdit = new QLineEdit;
//布局左
    leftLayout = new QGridLayout();
    leftLayout ->addWidget(UserNameLabel,0,0);
    leftLayout ->addWidget(UserNameLinEdit,0,1);
    leftLayout ->addWidget(NameLabel,1,0);
    leftLayout ->addWidget(NameLineEdit,1,1);
    leftLayout ->addWidget(SexLabel,2,0);
    leftLayout ->addWidget(SexCoBox,2,1);
    leftLayout ->addWidget(DepartmentLabel,3,0);
    leftLayout ->addWidget(DepartmentTextEdit,3,1);
    leftLayout ->addWidget(AgeLabel,4,0);
    leftLayout ->addWidget(AgeLineEdit,4,1);
    leftLayout ->addWidget(OtherLabel,5,0,1,2);

    leftLayout ->setColumnStretch(0,1);
    leftLayout ->setColumnStretch(1,3);

//布局右
    HeadLabel =new QLabel(tr("头像"));
    HeadIconLabel = new QLabel;
    QPixmap icon("312.png");
    HeadIconLabel ->setPixmap(icon);
    HeadIconLabel ->resize(icon.width(),icon.height());
    UpdateHeadBtn = new QPushButton(tr("更新"));
    
    TopRightLayout = new QHBoxLayout();
    TopRightLayout ->setSpacing(20);
    TopRightLayout ->addWidget(HeadLabel);
    TopRightLayout ->addWidget(HeadIconLabel);
    TopRightLayout ->addWidget(UpdateHeadBtn);
    
//布局右下
    IntroductionLabel = new QLabel(tr("个人说明"));
    IntroductionTextEdit =new QTextEdit();
    
    RightLayout = new QVBoxLayout();
    RightLayout -> setMargin(10);
    RightLayout ->addLayout(TopRightLayout);
    RightLayout -> addWidget(IntroductionLabel);
    RightLayout -> addWidget(IntroductionTextEdit);
    
//布局底部
    okBtn = new QPushButton(tr("确实"));
    CancelBtn = new QPushButton(tr("取消"));

    ButtomLayout = new QHBoxLayout();
    ButtomLayout ->addStretch();
    ButtomLayout ->addWidget(okBtn);
    ButtomLayout ->addWidget(CancelBtn);

//主布局
    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout  ->setMargin(15);
    mainLayout  ->setSpacing(10);
    mainLayout  ->addLayout(leftLayout,0,0);
    mainLayout  ->addLayout(RightLayout,0,1);
    mainLayout  ->addLayout(ButtomLayout,1,0,1,2);
    mainLayout  ->setSizeConstraint(QLayout::SetFixedSize); //最大化及最小化失效

}
