#pragma once

#include <QObject>

class SystemHandler : public QObject
{
    Q_OBJECT

public:
    explicit SystemHandler(QObject *parent = nullptr);

public slots:
    bool isUnix();
    bool isMobileDevice();
    bool openUrl(const QString &url);

    QString desktopEnvironment();
    bool isApplicableType(const QString &installType);

#ifdef QTLIB_UNIX
    bool applyFile(const QString &path, const QString &installType);
#endif

private:
#ifdef QTLIB_UNIX
    bool applyWallpaper(const QString &path);
    bool applyIcon(const QString &path);
    bool applyCursor(const QString &path);
    bool applyWindowTheme(const QString &path);
#endif
};
