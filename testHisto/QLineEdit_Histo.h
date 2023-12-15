#ifndef QLINEEDIT_HISTO_H
#define QLINEEDIT_HISTO_H

#include <QLineEdit>
#include <QVector>
#include <QPlainTextEdit>

class QLineEdit_Histo : public QLineEdit
{
    Q_OBJECT

public:
    QLineEdit_Histo(QWidget* parent = nullptr);

private slots:
    void afficherHistorique();
    void supprimerHistorique();
    void ajoute(QObject* senderObj);
    QString historique() const;
    void clear(); // Rename efface to clear

private:
    QVector<QString> text_histo;
    QPlainTextEdit* historyTextEdit;
};

#endif // QLINEEDIT_HISTO_H
