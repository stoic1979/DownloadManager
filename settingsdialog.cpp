#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    setModal(true);
    setFixedSize(width(), height());
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}
