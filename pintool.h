#pragma once

#include <QtWidgets/QWidget>
#include "ui_pintool.h"

class QFile;

class PinTool : public QWidget
{
    Q_OBJECT

public:
    PinTool(QWidget *parent = Q_NULLPTR);
    ~PinTool();

protected:
    void init();
    void initEditContent();

    void closeEvent(QCloseEvent* event) override;

private:
	Ui::PinToolClass ui;
    QFile* m_file = nullptr;
};
