#include "newdownloaddialog.h"
#include "ui_newdownloaddialog.h"

NewDownloadDialog::NewDownloadDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewDownloadDialog)
{
    ui->setupUi(this);

    setModal(true);
    setFixedSize(width(), height());
}

NewDownloadDialog::~NewDownloadDialog()
{
    delete ui;
}
