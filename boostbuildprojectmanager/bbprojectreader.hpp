#ifndef BBPROJECTTREELOADER_HPP
#define BBPROJECTTREELOADER_HPP

// Qt
#include <QFutureInterface>
#include <QFutureWatcher>
#include <QString>
#include <QStringList>

namespace BoostBuildProjectManager {
namespace Internal {

class ProjectReader : public QObject
{
    Q_OBJECT
public:
    ProjectReader(QString const& projectPath);

    void startReading();
    QStringList files() const;
    QStringList includePaths() const;

signals:
    void readingFinished();
    void readingProgress(QString const& fileName);

private slots:
    void handleReadingFinished();

private:
    void run(QFutureInterface<void>& future);

    void buildFilesList(QString const& baseDir
                      , QStringList const& suffixes
                      , QStringList const& headerFilters
                      , QFutureInterface<void>& future);

    QString projectPath_;
    QStringList files_;
    QStringList includePaths_;
    QFutureWatcher<void> futureWatcher_;
    int futureCount_;
};

} // namespace Internal
} // namespace BoostBuildProjectManager

#endif // BBPROJECTTREELOADER_HPP
