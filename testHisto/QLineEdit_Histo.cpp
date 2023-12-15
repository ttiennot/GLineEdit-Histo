#include "QLineEdit_Histo.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QPlainTextEdit>
#include <QDebug>

QLineEdit_Histo::QLineEdit_Histo(QWidget* parent) : QLineEdit(parent)
{
    QVBoxLayout* layout = new QVBoxLayout(this);

    // Création dynamique du QLineEdit
    QLineEdit* dynamicLineEdit = new QLineEdit(this);
    dynamicLineEdit->setGeometry(15, 50, 100, 20); // Position et taille
    layout->addWidget(dynamicLineEdit);

    historyTextEdit = new QPlainTextEdit(this);
    historyTextEdit->setReadOnly(true);

    QPushButton* clearHistoryButton = new QPushButton("Supprimer historique", this);
    connect(clearHistoryButton, &QPushButton::clicked, this, &QLineEdit_Histo::supprimerHistorique);

    layout->addWidget(clearHistoryButton);
    layout->addWidget(historyTextEdit);

    connect(dynamicLineEdit, &QLineEdit::returnPressed, [=]() {
        ajoute(dynamicLineEdit);
        qDebug() << "returnPressed on dynamicLineEdit";
        });

}




void QLineEdit_Histo::ajoute(QObject* senderObj)
{
    QLineEdit* dynamicLineEdit = qobject_cast<QLineEdit*>(senderObj);
    if (dynamicLineEdit)
    {
        QString currentText = dynamicLineEdit->text();
        if (!currentText.isEmpty())
        {
            text_histo.prepend(currentText);

            // Limit the size of the history to 10 items (you can customize this)
            if (text_histo.size() > 10)
                text_histo.resize(10);

            // Ajoutez le texte à l'historique avant de le vider
            historyTextEdit->appendPlainText(currentText);
        }

        // Clear the current text after adding to history
        dynamicLineEdit->clear();
    }

}



QString QLineEdit_Histo::historique() const
{
    QStringList historyList;
    for (const QString& item : text_histo)
    {
        historyList.append(item);
    }

    return historyList.join("\n");
}

void QLineEdit_Histo::clear()
{
    text_histo.clear();
}

void QLineEdit_Histo::afficherHistorique()
{
    historyTextEdit->setPlainText(historique());
}

void QLineEdit_Histo::supprimerHistorique()
{
    clear();
    historyTextEdit->clear();
}
