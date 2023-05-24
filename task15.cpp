#include "task15.h"

task15::task15()
{

}

int task15::Main(QApplication *app){
    QWidget window;
    window.setWindowTitle("Linked Queue");
    QVBoxLayout *layout = new QVBoxLayout(&window);

    QListWidget *listWidget = new QListWidget(&window);
    QStringList programLines;
    programLines << "#include <iostream>"
                 << "using namespace std;"
                 << ""
                 << "int main() {"
                 << "    cout << \"Hello, World!\" << endl;"
                 << "    return 0;"
                 << "}";
    listWidget->addItems(programLines);
    layout->addWidget(listWidget);

    QPushButton *rememberButton = new QPushButton("Remember", &window);
    layout->addWidget(rememberButton);

    QPushButton *swapButton = new QPushButton("Swap", &window);
    layout->addWidget(swapButton);

    QListWidgetItem *rememberedItem = nullptr;

    QObject::connect(rememberButton, &QPushButton::clicked, [&]() {
        QList<QListWidgetItem *> selectedItems = listWidget->selectedItems();
        if (!selectedItems.isEmpty()) {
            rememberedItem = selectedItems.first();
        }
    });


    QObject::connect(swapButton, &QPushButton::clicked, [&]() {

        QListWidgetItem *currentItem = listWidget->currentItem();
        if (rememberedItem && currentItem) {

            int rememberedRow = listWidget->row(rememberedItem);
            int currentRow = listWidget->row(currentItem);

            listWidget->takeItem(rememberedRow);
            listWidget->insertItem(rememberedRow, currentItem);

            listWidget->takeItem(currentRow);
            listWidget->insertItem(currentRow, rememberedItem);

            listWidget->setCurrentItem(rememberedItem);
            rememberedItem = nullptr;
        }
    });

    window.show();
    return app->exec();
}
