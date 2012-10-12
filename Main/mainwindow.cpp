#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //set up the gui
    ui->setupUi(this);
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

    //set up the system tray icon
    m_trayIcon = new QSystemTrayIcon(QIcon(":/icon.png"));
    m_trayIcon->show();
    connect(m_trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(trayIconActivated(QSystemTrayIcon::ActivationReason)));

    //load the plugins
    loadPlugins();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_trayIcon;
}

void MainWindow::focusOutEvent(QFocusEvent * event)
{
    if( event->lostFocus() )
        this->hide();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawRect(0,0, this->width()-1, this->height()-1);

    QMainWindow::paintEvent(event);
}

void MainWindow::loadPlugins()
{
    QDir pluginsDir(QApplication::applicationDirPath());
    //if-condition for dev purposes:
    if (pluginsDir.dirName().toLower() == "debug" || pluginsDir.dirName().toLower() == "release")
    {
        pluginsDir.cdUp();
        pluginsDir.cdUp();
    }
    pluginsDir.cd("plugins");

    foreach( QString fileName, pluginsDir.entryList(QDir::Files) )
    {
        QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
        QObject *plugin = pluginLoader.instance();
        if (plugin)
        {
            PluginInterface* pluginInterface = qobject_cast<PluginInterface *>(plugin);
            if (pluginInterface)
            {
                m_plugins.append(pluginInterface);
                qDebug() << "Plugin loaded: " + fileName + " - " + pluginInterface->name();
            }
        }
    }
}

void MainWindow::trayIconActivated(QSystemTrayIcon::ActivationReason reason)
{
    qDebug() << "tray activated";
    int availableWidth = QApplication::desktop()->availableGeometry().width();
    int availableHeight = QApplication::desktop()->availableGeometry().height();
    this->show();
    this->activateWindow();
    this->move(availableWidth - this->width() - 3, availableHeight - this->height() - 3);
}

void MainWindow::on_brightnessSlider_valueChanged(int value)
{
    ui->brightnessSpinBox->setValue(value);
}

void MainWindow::on_brightnessSpinBox_valueChanged(int arg1)
{
    ui->brightnessSlider->setValue(arg1);
}

void MainWindow::on_btnClose_clicked()
{
    this->hide();
}

void MainWindow::on_btnExit_clicked()
{
    this->close();
}

void MainWindow::on_btnPluginSettings_clicked()
{
    SettingsDialog* d = new SettingsDialog(&m_plugins, this);
    d->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint | Qt::Dialog);
    QRect screen = QApplication::desktop()->screenGeometry();
    d->move( screen.center() - d->rect().center() );
    d->exec();
}
