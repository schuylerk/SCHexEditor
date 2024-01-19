#include "userdefaults.h"
#include <QCoreApplication>
#include <QFile>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFileInfo>

UserDefaults::UserDefaults() {
    filePath = QCoreApplication::applicationDirPath() + "/../userdefaults.json";
    // 创建该文件并初始化为空对象
    if (!QFileInfo::exists(filePath))
    {
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly))
        {
            file.write("{}");
            file.close();
        }
    }
}

QJsonObject UserDefaults::readData(UserDefaultsError *error)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly))
    {
        file.close();
        if (error)
        {
            error->type = UserDefaultsError::OpenError;
        }
        return QJsonObject();
    }
    QByteArray data = file.readAll();
    file.close();
    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data, &parseError);
    if (parseError.error != QJsonParseError::NoError || !jsonDoc.isObject())
    {
        if (error)
        {
            error->type = UserDefaultsError::ParseError;
        }
        return QJsonObject();
    }
    if (error)
    {
        error->type = UserDefaultsError::NoError;
    }
    return jsonDoc.object();
}

void UserDefaults::writeData(QJsonObject &jsonObject, UserDefaultsError *error)
{

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly))
    {
        file.close();
        if (error)
        {
            error->type = UserDefaultsError::OpenError;
        }
        return;
    }
    QByteArray data = QJsonDocument(jsonObject).toJson(QJsonDocument::Compact);
    file.write(data);
    file.close();
    if (error)
    {
        error->type = UserDefaultsError::NoError;
    }
}

void UserDefaults::set(QJsonValue &value, QString key)
{
    UserDefaultsError error;
    QJsonObject jsonObject = readData(&error);
    if (error.type == UserDefaultsError::NoError)
    {
        jsonObject.insert(key, value);
        writeData(jsonObject);
    }
}

QJsonValue UserDefaults::get(QString key)
{
    UserDefaultsError error;
    QJsonObject jsonObject = readData(&error);
    if (error.type == UserDefaultsError::NoError)
    {
        QJsonValue jsonValue = jsonObject.value(key);
        return jsonValue;
    }
    return QJsonValue();
}

void UserDefaults::setString(QString value, QString key)
{
    QJsonValue jsonValue(value);
    set(jsonValue, key);
}

QString UserDefaults::getString(QString key)
{
    QJsonValue jsonValue = get(key);
    return jsonValue.isString() ? jsonValue.toString() : "";
}

void UserDefaults::setStringArray(QVector<QString> &value, QString key)
{
    QJsonArray jsonArray;
    int size = value.size();
    for (int i = 0; i < size; i++)
    {
        jsonArray.push_back(QJsonValue(value[i]));
    }
    QJsonValue jsonValue(jsonArray);
    set(jsonValue, key);
}

QVector<QString> UserDefaults::getStringArray(QString key)
{
    QVector<QString> array;
    QJsonValue jsonValue = get(key);
    if (!jsonValue.isArray())
    {
        return array;
    }
    QJsonArray jsonArray = jsonValue.toArray();
    int size = jsonArray.size();
    for (int i = 0; i < size; i++)
    {
        QJsonValue value = jsonArray.at(i);
        if (value.isString())
        {
            array.push_back(value.toString());
        }
    }
    return array;
}

void UserDefaults::setBool(bool value, QString key)
{
    QJsonValue jsonValue(value);
    set(jsonValue, key);
}

bool UserDefaults::getBool(QString key)
{
    QJsonValue jsonValue = get(key);
    return jsonValue.isBool() ? jsonValue.toBool() : false;
}

void UserDefaults::setInt(int value, QString key)
{
    QJsonValue jsonValue(value);
    set(jsonValue, key);
}

int UserDefaults::getInt(QString key)
{
    QJsonValue jsonValue = get(key);
    return jsonValue.toInt();
}

void UserDefaults::setDouble(double value, QString key)
{
    QJsonValue jsonValue(value);
    set(jsonValue, key);
}

double UserDefaults::getDouble(QString key)
{
    QJsonValue jsonValue = get(key);
    return jsonValue.isDouble() ? jsonValue.toDouble() : 0.0;
}

