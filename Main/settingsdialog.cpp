#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QList<PluginInterface*>* plugins, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    m_plugins = plugins;

    //build the gui
    if( m_plugins->size() > 0 )
    {
        QVBoxLayout* layout = new QVBoxLayout();
        layout->setContentsMargins(0, 9, 0, 9);
        layout->setSpacing(0);

        QLabel *frameTitleLabel = new QLabel(this);
        frameTitleLabel->setText("Plugin settings");
        frameTitleLabel->setStyleSheet("font: 20pt \"Segoe UI\"; padding: 6px; padding-bottom: 30px;");
        layout->addWidget(frameTitleLabel);

        for( int i = 0; i < m_plugins->size(); ++i )
        {
            QPushButton* newButton = new QPushButton(this);
            newButton->setProperty("pageIndex", i);
            newButton->setText(m_plugins->at(i)->name());
            newButton->setCheckable(true);
            newButton->setAutoExclusive(true);
            if( i == 0 )
                newButton->setChecked(true);
            connect(newButton, SIGNAL(clicked()), this, SLOT(pageChange()));
            layout->addWidget(newButton);

            QWidget* newPage = new QWidget(ui->stackedWidget);
            QFormLayout* pageLayout = new QFormLayout();

            QLabel* newTitleLabel = new QLabel(this);
            newTitleLabel->setText(m_plugins->at(i)->name());
            newTitleLabel->setStyleSheet("font: 20pt \"Segoe UI\"; padding: 6px; padding-bottom: 30px;");
            pageLayout->addRow(newTitleLabel);

            QList<PluginInterface::Setting> settings = m_plugins->at(i)->settings();
            for(int j = 0; j < settings.size(); ++j)
            {
                if( settings.at(j).type == PluginInterface::TEXT || settings.at(j).type == PluginInterface::PASSWORD)
                {
                    QLineEdit* newLineEdit = new QLineEdit(ui->stackedWidget);
                    newLineEdit->setProperty("pluginIndex", i);
                    newLineEdit->setProperty("settingName", settings.at(j).name);
                    newLineEdit->setText(settings.at(j).value.toString());
                    if( settings.at(j).type == PluginInterface::PASSWORD )
                        newLineEdit->setEchoMode(QLineEdit::Password);
                    connect(newLineEdit, SIGNAL(editingFinished()), SLOT(textSettingChanged()));
                    pageLayout->addRow(settings.at(j).name, newLineEdit);
                }
                else if( settings.at(j).type == PluginInterface::CHECKBOX)
                {
                    QCheckBox* newCheckBox = new QCheckBox(ui->stackedWidget);
                    newCheckBox->setProperty("pluginIndex", i);
                    newCheckBox->setProperty("settingName", settings.at(j).name);
                    newCheckBox->setChecked(settings.at(j).value.toBool());
                    connect(newCheckBox, SIGNAL(toggled(bool)), this, SLOT(checkBoxSettingChanged(bool)));
                    pageLayout->addRow(newCheckBox, new QLabel(settings.at(j).name, ui->stackedWidget));
                }
            }
            newPage->setLayout(pageLayout);
            ui->stackedWidget->addWidget(newPage);
        }
        layout->addStretch();
        ui->frame->setLayout(layout);
    }
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawRect(0,0, this->width()-1, this->height()-1);

    QDialog::paintEvent(e);
}

void SettingsDialog::textSettingChanged()
{
    QLineEdit* lineEdit = qobject_cast<QLineEdit*>(QObject::sender());
    int pluginIndex = lineEdit->property("pluginIndex").toInt();
    QString settingName = lineEdit->property("settingName").toString();

    m_plugins->at(pluginIndex)->updateSetting(settingName, lineEdit->text());
}

void SettingsDialog::checkBoxSettingChanged(bool toggled)
{
    QCheckBox* checkBox = qobject_cast<QCheckBox*>(QObject::sender());
    int pluginIndex = checkBox->property("pluginIndex").toInt();
    QString settingName = checkBox->property("settingName").toString();

    m_plugins->at(pluginIndex)->updateSetting(settingName, toggled);
}

void SettingsDialog::pageChange()
{
    int pageIndex = QObject::sender()->property("pageIndex").toInt();
    ui->stackedWidget->setCurrentIndex(pageIndex);
}

void SettingsDialog::on_btnDone_clicked()
{
    this->accept();
}
