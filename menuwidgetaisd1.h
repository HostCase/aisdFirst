#ifndef MENUWIDGETAISD1_H
#define MENUWIDGETAISD1_H
#include "dataInterface.h"
#include "ui_menuwidgetaisd1.h"
#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QIntValidator>

QT_BEGIN_NAMESPACE
namespace Ui { class menuWidgetAISD1; }
QT_END_NAMESPACE

class menuWidgetAISD1 : public QMainWindow
{
    Q_OBJECT

public:
    menuWidgetAISD1(QWidget *parent = nullptr);
    ~menuWidgetAISD1();

private slots:
    void on_ListChooseButton_clicked();
    void on_ArrayChooseButton_clicked();
    void on_StackChooseButton_clicked();
    void on_textBrowser_3_windowTitleChanged(const QString &title);
    bool methodInputSelected();
    void removeWidget (int index);
    void on_PushBackButton_clicked();
    void on_PopBackButton_clicked();
    void removeAllWidgets();
    void refreshMenu();
    void on_GetSizeButton_clicked();
    void on_RefreshButton_clicked();
    void on_PushFrontButton_clicked();
    void on_SortButton_clicked();
    void on_EmptyCheckButton_clicked();
    void on_PushFrontLine_returnPressed();
    void on_PushBackLine_returnPressed();

    void on_polskaNotation_clicked();

    void on_InsertButton_clicked();

    void on_EraseButton_clicked();

    void on_PopFrontButton_clicked();

private:
    Ui::menuWidgetAISD1 *ui;
    QVBoxLayout *lay;
    void removeAllData();
    int methodInput = 0;
    void scrollGenerator();
    void addWidget(const QString& inputToWidget);
    dataInterface<QString>* dataInterfaceObj=nullptr;
    void Refresh();


};
#endif // MENUWIDGETAISD1_H
