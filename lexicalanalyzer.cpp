#include "lexicalanalyzer.h"

#include <qregularexpression.h>

LexicalAnalyzer::LexicalAnalyzer()
{

}

QList<Token> LexicalAnalyzer::parse(QString program)
{
    QList<Token> result;
    result.append(Token(program, unparsed));
    result = parseCommentsAndString(result);
    result = deleteWhiteSpaces(result);
    result = parseToken(result, ";", semicolon);
    result = parseToken(result, "{", leftCurlyBrace);
    result = parseToken(result, "}", rightCurlyBrace);
    result = parseToken(result, "(", leftParenthesis);
    result = parseToken(result, ")", rightParenthesis);
    result = parseToken(result, ".", dot);

    return result;
}

QList<Token> LexicalAnalyzer::parseCommentsAndString(QList<Token> tokens)
{
    QList<Token> result;

    foreach (Token token, tokens) {
        if(token.getType() != unparsed)
        {
            result.append(token);
            continue;
        }

        QString data = token.getData();
        int stringStart = data.indexOf('"');
        int commentStart = data.indexOf("//");

        if(stringStart == -1 && commentStart == -1)
        {
            result.append(token);
        }
        else if(stringStart == -1 || (commentStart < stringStart && commentStart != -1))
        {
            //comment detected
            commentStart++;
            int commentEnd = data.indexOf("\n", commentStart+1);

            if(commentStart > 1)
            {
                QString beforeComment = data.mid(0, commentStart-1);
                result.append(Token(beforeComment, unparsed));
            }

            if(commentEnd != -1)
            {
                QString currentComment = data.mid(commentStart+1, commentEnd-commentStart-1);
                result.append(Token(currentComment, comment));
                QString afterComment = data.mid(commentEnd+1, data.length()-commentEnd-1);
                result.append(Token(afterComment, unparsed));
            }
            else
            {
                QString currentComment = data.mid(commentStart+1, data.length()-commentStart-1);
                result.append(Token(currentComment, comment));
            }

            result = parseCommentsAndString(result);
        }
        else if(commentStart == -1 || (stringStart < commentStart && stringStart != -1))
        {
            //string detected
            int stringEnd = data.indexOf('"', stringStart+1);
            if(stringStart>0)
            {
                QString beforeString = data.mid(0, stringStart-1);
                result.append(Token(beforeString, unparsed));
            }

            if(stringEnd != -1)
            {
                QString currentString = data.mid(stringStart+1, stringEnd-stringStart-1);
                result.append(Token(currentString, string));
                QString afterString = data.mid(stringEnd+1, data.length()-stringEnd-1);
                result.append(Token(afterString, unparsed));
            }
            else
            {
                QString currentString = data.mid(stringStart+1, data.length()-stringStart-1);
                result.append(Token(currentString, string));
            }

            result = parseCommentsAndString(result);

        }
    }

    return result;
}

QList<Token> LexicalAnalyzer::deleteWhiteSpaces(QList<Token> tokens)
{
    QList<Token> result;

    foreach (Token token, tokens) {
        if(token.getType() != unparsed)
        {
            result.append(token);
            continue;
        }

        QString data = token.getData();
        QStringList subData = data.split(QRegularExpression("\\s+"), QString::SkipEmptyParts);
        foreach(QString str, subData)
        {
            result.append(Token(str, unparsed));
        }
    }

    return result;
}

QList<Token> LexicalAnalyzer::parseToken(QList<Token> tokens, QString str, TokenType type)
{
    QList<Token> result;

    foreach (Token token, tokens) {
        if(token.getType() != unparsed)
        {
            result.append(token);
            continue;
        }

        QString data = token.getData();
        int semicolonIndex = data.indexOf(str);

        if(semicolonIndex == -1)
        {
            result.append(token);
        }
        else if(data.length() == 1)
        {
            result.append(Token(str, type));
        }
        else if(semicolonIndex == 0)
        {
            result.append(Token(str, type));
            QString endString = data.mid(1, data.length()-1);
            result.append(Token(endString, unparsed));
            result = parseToken(result, str, type);
        }
        else if(semicolonIndex == data.length()-1)
        {
            QString startString = data.mid(0, data.length()-1);
            result.append(Token(startString, unparsed));
            result.append(Token(str, type));
            result = parseToken(result, str, type);
        }
        else
        {
            QString startString = data.mid(0, semicolonIndex);
            QString endString = data.mid(semicolonIndex+1, data.length()-semicolonIndex-1);
            result.append(Token(startString, unparsed));
            result.append(Token(str, type));
            result.append(Token(endString, unparsed));
            result = parseToken(result, str, type);
        }

    }

    return result;
}

