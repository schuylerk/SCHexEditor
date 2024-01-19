#ifndef USERDEFAULTS_H
#define USERDEFAULTS_H

#include <QString>
#include <QVector>
#include <QJsonObject>
#include <QMap>

class UserDefaults
{
protected:
    UserDefaults();

public:
    UserDefaults(const UserDefaults &) = delete;
    UserDefaults &operator=(const UserDefaults &) = delete;

    static UserDefaults &shared() {
        static UserDefaults userDefaults;
        return userDefaults;
    }

private:
    QString filePath;

    struct UserDefaultsError
    {
        enum ErrorType
        {
            NoError = 0,
            OpenError,
            ParseError
        };

        ErrorType type = NoError;
    };

private:
    QJsonObject readData(UserDefaultsError *error = nullptr); // 读取文件数据并转化为QJsonObject
    void writeData(QJsonObject &jsonObject, UserDefaultsError *error = nullptr); // 将QJsonObject对象写到文件中，写的方式是覆盖
    void set(QJsonValue &value, QString key); // 添加键值对
    QJsonValue get(QString key); // 获取指定键的值，返回QJsonValue对象

public:
    void setStringArray(QVector<QString> &value, QString key);
    QVector<QString> getStringArray(QString key);

    void setString(QString value, QString key);
    QString getString(QString key);

    void setBool(bool value, QString key);
    bool getBool(QString key);

    void setInt(int value, QString key);
    int getInt(QString key);

    void setDouble(double value, QString key);
    double getDouble(QString key);


};

#endif // USERDEFAULTS_H
