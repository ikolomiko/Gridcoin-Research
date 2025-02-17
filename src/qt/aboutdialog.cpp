#include "aboutdialog.h"
#include "qt/decoration.h"
#include "ui_aboutdialog.h"
#include "clientmodel.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    ui->copyrightLabel->setText("Copyright 2009-2023 The Bitcoin/Peercoin/Black-Coin/Gridcoin developers");

    resize(GRC::ScaleSize(this, width(), height()));
}

void AboutDialog::setModel(ClientModel *model)
{
    if(model)
    {
        ui->versionLabel->setText(model->formatFullVersion());
    }
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::on_buttonBox_accepted()
{
    close();
}
