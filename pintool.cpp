#include "pintool.h"

#include <QCloseEvent>
#include <QFile>
#include <QScrollBar>
#include <QStandardPaths>
#include <QString>
#include <QTextStream>
#include <QDebug>

namespace {
	const QString DESKTOP_PATH = QString("%1/pinLog.txt").arg(QStandardPaths::writableLocation(QStandardPaths::DesktopLocation));
    const int SCROLLBAR_HIDE_TIME = 500;
};

PinTool::PinTool(QWidget *parent) : QWidget(parent), m_file(new QFile(DESKTOP_PATH, this)) {
    ui.setupUi(this);
    init();   
}

PinTool::~PinTool() {
    
}

void PinTool::init() {
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    initEditContent();
}

// 读文件内容
void PinTool::initEditContent() {
	if (m_file->open(QIODevice::ReadOnly | QIODevice::Text)) {
		QTextStream textStream(m_file);
		ui.textEdit->setText(textStream.readAll());
        m_file->close();
	}
}

void PinTool::closeEvent(QCloseEvent* event) {
    // 保存至本地
    QString toSaveText = ui.textEdit->toPlainText();

    if (m_file->open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
        QTextStream textStream(m_file);
        textStream << toSaveText;
        m_file->close();
    }

    event->accept();
}
