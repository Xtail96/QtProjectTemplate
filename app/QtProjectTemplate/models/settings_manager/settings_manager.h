#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <QCoreApplication>
#include <QFileInfo>
#include <QSettings>
#include <QString>
#include <QDateTime>
#include <QMessageBox>
#include <memory>

#define DEFAULT_SETTINGS_DIR ""
#define DEFAULT_SETTINGS_FILE "QtProjectTemplateSettings.ini"

/**
 * @brief Класс для работы с настройками станка
 *
 * Данный класс отвечает за:
 * - считывание настрока станка по заданному пути, либо пути по умолчанию
 * - генерацию настроек станка по умолчанию
 * - экспорт настроек по произвольному пути
 * - поиск и изменение значения по паре группа-ключ
 * - сохранение настроек
 */
class SettingsManager
{
protected:
    /// Класс, непосредственно отвечающий за хранение "группа-ключ-значение"
    std::shared_ptr<QSettings> settings;

public:
    /**
     * @brief Импортирует настройки из файла, находящегося в директории по умолчанию
     */
    SettingsManager();
     /**
     * @brief Импортирует настройки из заданного файла
     * @param settingsPath путь к файлу с настройками
     */
    SettingsManager(QString settingsFile);

    ~SettingsManager();

    /**
     * @brief Сохраняет настройки в текущий файл
     */
    void saveSettings();

    /**
     * @brief Экспортирует настройки по заданному пути
     * @param path путь, куда будут экспортированы настройки
     */
    void exportSettings(QString path);

    /**
     * @brief Импортирует настройки из заданного файла и сохраняет их в файл по умолчанию
     * @param settingsPath путь к файлу с настройками
     */
    void importSettings(QString settingsPath);

    /**
     * @brief Позволяет получить значение по заданным группе и ключу
     * @param group имя группы
     * @param key ключ
     * @return полученное по группе и ключу значение
     * \warning Если по заданному ключу не содержится никакое значение, выбрасывает исключение invalid_argument
     */
    QVariant get(QString group, QString key) const;

    /**
     * @brief Позволяет установить значение по заданным группе и ключу
     * @param group имя группы
     * @param key ключ
     * @param value значение, которое следует установить
     */
    void set(QString group, QString key, QVariant value);

    /**
     * @brief Генерирует настройки станка по умолчанию
     */
    void generateDefaultSettings();

    /**
     * @brief Возвращает все ключи файла настроек
     * @return Все ключи файла настроек
     */
    QStringList settingsKeys();
};

#endif // SETTINGSMANAGER_H
