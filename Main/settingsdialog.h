#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QFormLayout>
#include <QLineEdit>
#include <QCheckBox>
#include <QLabel>
#include <QDebug>
#include <QPainter>
#include "plugininterface.h"

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SettingsDialog(QList<PluginInterface*>* plugins, QWidget *parent = 0);
    ~SettingsDialog();
    
private:
    Ui::SettingsDialog *ui;
    QList<PluginInterface*>* m_plugins;

    void paintEvent(QPaintEvent *e);

private slots:
    void textSettingChanged();
    void checkBoxSettingChanged(bool toggled);
    void pageChange();
    void on_btnDone_clicked();
};

#endif // SETTINGSDIALOG_H
