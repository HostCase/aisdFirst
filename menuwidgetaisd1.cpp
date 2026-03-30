#include "menuwidgetaisd1.h"
#include "./ui_menuwidgetaisd1.h"
#include "list.h"
#include "array.h"
#include "stack.h"

menuWidgetAISD1::menuWidgetAISD1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::menuWidgetAISD1)
{
    ui->setupUi(this);


    lay = new QVBoxLayout(ui->scrollContens);
    lay->setSpacing(2);
    ui->scrollContens->setLayout(lay);
    ui->scrollArea_2->hide();
    ui->RefreshButton->hide();
    ui->scrollArea->hide();
    ui->SortButton->hide();
    ui->polskaWidget->hide();
    ui->InsertPosition->setPlaceholderText("Position");
    ui->InsertValue->setPlaceholderText("String");


    QIntValidator *validator = new QIntValidator(this);
    ui->InsertPosition->setValidator(validator);
}

menuWidgetAISD1::~menuWidgetAISD1()
{
    delete ui;
    QLayoutItem *item;
    while ((item = lay->takeAt(0)) != 0) {
        delete item->widget();
        delete item;
    }
    delete lay;
}




void menuWidgetAISD1::on_ListChooseButton_clicked()
{
    removeAllData();
    methodInput = 1;
    QString title = "List";
    this->on_textBrowser_3_windowTitleChanged(title);
    dataInterfaceObj= new list<QString>();
    ui->scrollArea_2->show();
    ui->scrollArea->show();
    ui->RefreshButton->show();
    ui->PopFrontButton->show();
    ui->widget_6->show();
    ui->polskaWidget->hide();
    ui->widget_2->show();
    ui->widget_3->show();

}


void menuWidgetAISD1::on_ArrayChooseButton_clicked()
{
    removeAllData();
    methodInput = 2;
    QString title = "Array";
    this->on_textBrowser_3_windowTitleChanged(title);
    dataInterfaceObj= new Array<QString>();
    ui->scrollArea_2->show();
    ui->RefreshButton->show();
    ui->scrollArea->show();
    ui->SortButton->show();
    ui->PopFrontButton->show();
    ui->widget_6->show();
    ui->polskaWidget->hide();
    ui->widget_2->show();
    ui->widget_3->show();
}


void menuWidgetAISD1::on_StackChooseButton_clicked()
{
    removeAllData();
    methodInput = 3;
    QString title = "Stack";
    this->on_textBrowser_3_windowTitleChanged(title);
    dataInterfaceObj= new stack<QString>();
    ui->scrollArea_2->show();
    ui->scrollArea->show();
    ui->PopFrontButton->hide();
    ui->widget_6->hide();
    ui->SortButton->hide();
    ui->polskaWidget->show();
    ui->widget_2->hide();
    ui->widget_3->hide();
}

void menuWidgetAISD1::on_textBrowser_3_windowTitleChanged(const QString &title)
{
    this->setWindowTitle(title);
}



bool menuWidgetAISD1::methodInputSelected(){
    if(methodInput){
        return 1;
    }
    else{
    QMessageBox::critical(nullptr, "Error", "Choose method");
        return 0;
    }
}



void menuWidgetAISD1::addWidget(const QString& inputToWidget) {
    QLabel* newLabel = new QLabel(inputToWidget, ui->scrollContens);
    newLabel->setFixedSize(150, 30);
    lay->addWidget(newLabel);
}




void menuWidgetAISD1::removeWidget(int index) {
    QList<QLabel*> labels = ui->scrollContens->findChildren<QLabel*>();

    if (index >= 0 && index < labels.size()) {
        QLabel* labelToRemove = labels.at(index);
        lay->removeWidget(labelToRemove);
        delete labelToRemove;
    } else {
        QMessageBox::warning(nullptr, "Error", "Invalid index. No widget found at the specified index.");
    }
}


void menuWidgetAISD1::removeAllWidgets() {
    while (QLayoutItem* item = lay->takeAt(0)) {
        if (QWidget* widget = item->widget()) {
            lay->removeWidget(widget);
            delete widget;
        }
        delete item;
    }
}

void menuWidgetAISD1::removeAllData() {
    ui->scrollArea_2->hide();
    ui->RefreshButton->hide();
    ui->scrollArea->hide();
    if(!(dataInterfaceObj==nullptr)){
        delete dataInterfaceObj;
        removeAllWidgets();
    }
    else return;
}




void menuWidgetAISD1::on_PushBackButton_clicked()
{
    if((methodInputSelected())){
        QString value = ui->PushBackLine->text();
        if(!(value.isEmpty())){
            dataInterfaceObj->push_back(value);
            addWidget(value);
        }
    }
    ui->PushBackLine->clear();
}


void menuWidgetAISD1::on_PopBackButton_clicked()
{
    if (methodInputSelected()) {

        if (!dataInterfaceObj->empty()) {
            removeWidget(dataInterfaceObj->getSize()-1);
            dataInterfaceObj->pop_back();
        } else {
            QMessageBox::warning(nullptr, "Error", "The structure is empty");
        }
    }
}

void menuWidgetAISD1::refreshMenu(){
    if(methodInputSelected()){
        removeAllWidgets();
        for(int i=0;i<dataInterfaceObj->getSize();i++){
            QString value = dataInterfaceObj->getElement(i);
            addWidget(value);
        }
    }
        else{
        QMessageBox::information(nullptr, "Warning", "Only for array ");
    }

}


void menuWidgetAISD1::on_GetSizeButton_clicked()
{   if(methodInputSelected()){
    int size = dataInterfaceObj->getSize();
    QMessageBox::information(nullptr, "Size", "Size is " + QString::number(size));
    }
}


void menuWidgetAISD1::on_RefreshButton_clicked()
{
    if(methodInputSelected()){
        refreshMenu();
    }
    else{
        QMessageBox::information(nullptr, "Warning", "Structure not selected");
    }
}


void menuWidgetAISD1::on_PushFrontButton_clicked()
{
    if((methodInputSelected())){
        QString value = ui->PushFrontLine->text();
        if(!(value.isEmpty())){
            dataInterfaceObj->push_front(value);
        }
    }
    refreshMenu();
    ui->PushFrontLine->clear();
}


void menuWidgetAISD1::on_SortButton_clicked()
{
    if(methodInput==2){
        dataInterfaceObj->sort();
        refreshMenu();
    }
    else{
        QMessageBox::information(nullptr, "Warning", "It`s only for array");
    }
}


void menuWidgetAISD1::on_EmptyCheckButton_clicked()
{
    if(dataInterfaceObj->empty()){
        QMessageBox::information(nullptr, "Information", "Empty");
    }
    else{
        QMessageBox::information(nullptr, "Information", "Not empty");
    }
}


void menuWidgetAISD1::on_PushFrontLine_returnPressed()
{
    on_PushFrontButton_clicked();
}




void menuWidgetAISD1::on_PushBackLine_returnPressed()
{
    on_PushBackButton_clicked();
}



void menuWidgetAISD1::on_polskaNotation_clicked() {
    QString input = ui->polskaInput->text();
    ui->polskaInput->clear();


    QStringList tokens = input.split(" ", Qt::SkipEmptyParts);


    stack<QString> operators;
    QStringList output;

    QMap<QString, int> precedence;
    precedence["+"] = 1;
    precedence["-"] = 1;
    precedence["*"] = 2;
    precedence["/"] = 2;
    precedence["^"] = 3;
    precedence["sin"] = 4;
    precedence["cos"] = 4;

    QMap<QString, bool> rightOperBool;
    rightOperBool["+"] = false;
    rightOperBool["-"] = false;
    rightOperBool["*"] = false;
    rightOperBool["/"] = false;
    rightOperBool["^"] = true;

    for (const QString& token : tokens) {
        bool isNumber;
        token.toDouble(&isNumber);

        if (isNumber) {

            output.append(token);
        } else if (precedence.contains(token)) {

            while (!operators.empty() &&
                   ((rightOperBool[token] && precedence[operators.back()] > precedence[token]) ||
                    (!rightOperBool[token] && precedence[operators.back()] >= precedence[token]))) {
                output.append(operators.back());
                operators.pop_back();
            }
            operators.push_back(token);
        } else if (token == "(") {
            operators.push_back(token);
        } else if (token == ")") {
            while (!operators.empty() && operators.back() != "(") {
                output.append(operators.back());
                operators.pop_back();
            }
            if (!operators.empty()) {
                operators.pop_back();
            }

            if (!operators.empty() && (operators.back() == "sin" || operators.back() == "cos")) {
                output.append(operators.back());
                operators.pop_back();
            }
        }
    }


    while (!operators.empty()) {
        output.append(operators.back());
        operators.pop_back();
    }


    QString result = output.join(" ");
    QMessageBox::information(nullptr, "Polish Notation", result);
}

void menuWidgetAISD1::on_InsertButton_clicked()
{
    QString value = ui->InsertValue->text();
    QString getPos = ui->InsertPosition->text();
    int pos=getPos.toInt();
    if((methodInputSelected())&&(pos<=(dataInterfaceObj->getSize()))){

    dataInterfaceObj->insert(pos, value);
    ui->InsertPosition->clear();
    ui->InsertValue->clear();
    refreshMenu();

    }
    else{
            QMessageBox::information(nullptr, "Error ","Invalid index");
        ui->InsertPosition->clear();
    }


}

void menuWidgetAISD1::on_EraseButton_clicked()
{

    QString getPos = ui->EraseLine->text();
    int pos=getPos.toInt();
    if((methodInputSelected())&&(pos<=(dataInterfaceObj->getSize()-1))){

        dataInterfaceObj->erase(pos);
        ui->InsertPosition->clear();
        ui->InsertValue->clear();
        refreshMenu();

    }
    else{
        QMessageBox::information(nullptr, "Error ","Invalid index");
        ui->InsertPosition->clear();
    }
    ui->InsertPosition->clear();

}



void menuWidgetAISD1::on_PopFrontButton_clicked()
{
    if (methodInputSelected()) {

        if (!dataInterfaceObj->empty()) {
            dataInterfaceObj->pop_front();
        } else {
            QMessageBox::warning(nullptr, "Error", "The structure is empty");
        }
        refreshMenu();
    }
}
