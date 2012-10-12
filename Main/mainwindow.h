#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QFocusEvent>
#include <QDesktopWidget>
#include <QPainter>
#include <QDir>
#include <QPluginLoader>
#include <QDebug>

#include "plugininterface.h"
#include "settingsdialog.h"
#include "blinksequence.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSystemTrayIcon* m_trayIcon;
    QList<PluginInterface*> m_plugins;

    void focusOutEvent(QFocusEvent *event);
    void paintEvent(QPaintEvent *event);

    void loadPlugins();

private slots:
    void trayIconActivated(QSystemTrayIcon::ActivationReason reason);
    void on_brightnessSlider_valueChanged(int value);
    void on_brightnessSpinBox_valueChanged(int arg1);
    void on_btnClose_clicked();
    void on_btnExit_clicked();
    void on_btnPluginSettings_clicked();
};

#endif // MAINWINDOW_H
