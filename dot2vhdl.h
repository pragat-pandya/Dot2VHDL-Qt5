#ifndef DOT2VHDL_H
#define DOT2VHDL_H

#include <QDialog>
#include <QString>
#include <QProcess>
#include <QDebug>
#include <QMessageBox>
#include <QProgressDialog>
#include <QThread>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>

namespace Ui {
class Dot2VHDL;
}

class Dot2VHDL : public QDialog
{
    Q_OBJECT

public:
    explicit Dot2VHDL(QWidget *parent = nullptr);
    ~Dot2VHDL();
    void goBackToMainWindow();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dot2VHDL *ui;
};

class Dot2KissConverter{
    QString input;
    QString output;
    bool valid = false;
public:
    Dot2KissConverter(){}

    // Setter
    void setInput(QString s) {
        this->input = s;
    }

    void isDotSyntaxValid() {
        int openParentheses = 0;
        int closeParentheses = 0;
        int openBrackets = 0;
        int closeBrackets = 0;
        QProcess dotProcess;
        dotProcess.setProgram("dot");
        QStringList arguments;
        arguments << "-Tdot";  // Use -Tdot to check the syntax
        dotProcess.setArguments(arguments);

        dotProcess.start();

        // Write the DOT content to the process and close the write channel
        dotProcess.write(this->input.toUtf8());
        dotProcess.closeWriteChannel();

        dotProcess.waitForFinished();

        // Read the output from the process
        QByteArray output = dotProcess.readAll();

        for (const QChar ch : this->input.toUtf8()) {
                if (ch == '[') {
                    openParentheses++;
                } else if (ch == ']') {
                    closeParentheses++;
                } else if (ch == '{') {
                    openBrackets++;
                } else if (ch == '}') {
                    closeBrackets++;
                }
            }

        bool parenCheck = (openParentheses == closeParentheses) && (openBrackets == closeBrackets);

        // Check if the output contains any syntax errors
        if (!output.contains("syntax error") && parenCheck)
            this->valid = true;
        else
            this->valid = false;
    }

    QString convertDotToKISS2() {
        if (!isValid()) {
            output = "-1";
            return output;
        }
        QString kiss2Content;
            QStringList lines = input.split(QRegExp("[\r\n]"), Qt::SkipEmptyParts);

            // Define KISS2 header
            kiss2Content += ".i 2\n";
            kiss2Content += ".o 1\n";
            kiss2Content += ".p 11\n";
            kiss2Content += ".s 4\n";

            // Initialize state mapping
            QMap<QString, QString> stateMap;
            stateMap["st0"] = "st0";
            stateMap["st1"] = "st1";
            stateMap["st2"] = "st2";
            stateMap["st3"] = "st3";

            // Initialize state index mapping
            QMap<QString, int> stateIndex;
            stateIndex["st0"] = 0;
            stateIndex["st1"] = 1;
            stateIndex["st2"] = 2;
            stateIndex["st3"] = 3;

            // Iterate through lines of .dot content
            for (const QString &line : lines) {
                if (line.contains("->")) {
                    QString state1, label, state2;
                    if (line.contains("label")) {
                        QRegExp rx("\"([^\"]*)\"");
                        int pos = 0;
                        while ((pos = rx.indexIn(line, pos)) != -1) {
                            label = rx.cap(1);
                            pos += rx.matchedLength();
                        }

                        state1 = line.split("->").at(0).trimmed();
                        state2 = line.split("->").at(1).split("[").at(0).trimmed();

                        // Translate states and labels to KISS2 format
                        QString state1Name = stateMap[state1];
                        QString state2Name = stateMap[state2];

                        // Translate the label into KISS2 format
                        if (label.contains("/")) {
                            QString input = label.split("/").at(0);
                            QString output = label.split("/").at(1);
                            kiss2Content += input + " " + state1Name + " " + state2Name + " " + output + "\n";
                        } else {
                            kiss2Content += label.trimmed() + " " + state1Name + " " + state2Name + " -\n";
                        }
                    }
                }
            }

            return kiss2Content;
    }

    // Syntax Validity Getter
    bool isValid () {
        return this->valid;
    }
};

class KISS2VHDL {
    QString kiss2;
    QString VHDL;
public:
    QString Kiss2VHDLConverter() {
        QString vhdlContent;
            QStringList lines = kiss2.split(QRegExp("[\r\n]"), Qt::SkipEmptyParts);

            // VHDL entity declaration
            vhdlContent += "library IEEE;\n";
            vhdlContent += "use IEEE.STD_LOGIC_1164.ALL;\n";
            vhdlContent += "entity YourEntityName is\n";
            vhdlContent += "    Port (\n";
            vhdlContent += "        Input1 : in STD_LOGIC;\n";
            vhdlContent += "        Input2 : in STD_LOGIC;\n";
            vhdlContent += "        Output1 : out STD_LOGIC\n";
            vhdlContent += "    );\n";
            vhdlContent += "end YourEntityName;\n\n";

            // VHDL architecture
            vhdlContent += "architecture Behavioral of YourEntityName is\n";
            vhdlContent += "begin\n\n";

            // Process for state transitions
            vhdlContent += "    process (Input1, Input2)\n";
            vhdlContent += "    begin\n";
            vhdlContent += "        case (Input1 & Input2) is\n";

            for (const QString &line : lines) {
                QStringList parts = line.split(" ", QString::SkipEmptyParts);
                if (parts.length() == 4) {
                    QString input = parts[0];
                    QString state1 = parts[1];
                    QString state2 = parts[2];
                    QString output = parts[3];
                    vhdlContent += "            when \"" + input + "\" =>\n";
                    vhdlContent += "                Output1 <= \"" + output + "\";\n";
                }
            }

            vhdlContent += "            when others =>\n";
            vhdlContent += "                Output1 <= 'X';\n";
            vhdlContent += "        end case;\n";
            vhdlContent += "    end process;\n\n";

            vhdlContent += "end Behavioral;\n";
            this->VHDL = vhdlContent;
            return vhdlContent;
        }
    void setKiss2Content (QString s) {
        this->kiss2 = s;
    }
};

#endif // DOT2VHDL_H
