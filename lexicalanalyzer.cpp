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
    result = parseToken(result, "==", logicEqual);
    result = parseToken(result, "<", logicLess);
    result = parseToken(result, ">", logicMore);
    result = parseToken(result, "!=", logicNotEqual);
    result = parseToken(result, "=", assigment);
    result = parseToken(result, "+", plus);
    result = parseToken(result, "-", minus);
    result = parseToken(result, "/", division);
    result = parseToken(result, "*", multiplication);
    result = parseKeyWord(result, "var", var);
    result = parseKeyWord(result, "if", ifToken);
    result = parseKeyWord(result, "else", elseToken);
    result = parseKeyWord(result, "while", whileToken);
    result = parseKeyWord(result, "Hero", heroObject);
    result = parseKeyWord(result, "go", goMethod);
    result = parseKeyWord(result, "turnLeft", turnLeftMethod);
    result = parseKeyWord(result, "turnRight", turnRightMethod);
    result = parseKeyWord(result, "collectGem", collectGemMethod);
    result = parseKeyWord(result, "say", sayMethod);
    result = parseKeyWord(result, "stoped", stopedEvent);
    result = parseKeyWord(result, "gemCollectedEvent", gemCollectedEvent);

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
                QString beforeString = data.mid(0, stringStart);
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
        int startIndex = data.indexOf(str);

        if(startIndex == -1)
        {
            result.append(token);
        }
        else if(data.length() == str.length())
        {
            result.append(Token(str, type));
        }
        else if(startIndex == 0)
        {
            result.append(Token(str, type));
            QString endString = data.mid(str.length(), data.length()-str.length());
            result.append(Token(endString, unparsed));
            result = parseToken(result, str, type);
        }
        else if(startIndex == data.length()-str.length())
        {
            QString startString = data.mid(0, data.length()-str.length());
            result.append(Token(startString, unparsed));
            result.append(Token(str, type));
            result = parseToken(result, str, type);
        }
        else
        {
            QString startString = data.mid(0, startIndex);
            QString endString = data.mid(startIndex+str.length(), data.length()-startIndex-str.length());
            result.append(Token(startString, unparsed));
            result.append(Token(str, type));
            result.append(Token(endString, unparsed));
            result = parseToken(result, str, type);
        }

    }

    return result;
}

QList<Token> LexicalAnalyzer::parseKeyWord(QList<Token> tokens, QString str, TokenType type)
{
    QList<Token> result;

    foreach (Token token, tokens) {
        if(token.getType() != unparsed)
        {
            result.append(token);
            continue;
        }

        QString data = token.getData();
        int startIndex = data.indexOf(str);

        if(startIndex==0 && (data.length()==str.length()))
        {
            result.append(Token(str, type));
        }
        else
        {
            result.append(token);
        }
    }

    return result;
}
