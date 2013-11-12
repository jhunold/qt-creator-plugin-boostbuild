#include "bbprojectnode.hpp"
#include "bbproject.hpp"
#include <coreplugin/idocument.h>
#include <projectexplorer/projectnodes.h>

namespace BoostBuildProjectManager {
namespace Internal {

ProjectNode::ProjectNode(Project* project, Core::IDocument* projectFile)
    : ProjectExplorer::ProjectNode(projectFile->filePath())
    , project_(project)
    , projectFile_(projectFile)
{
    // TODO: setDisplayName(QFileInfo(projectFile->filePath()).completeBaseName());
}

bool ProjectNode::hasBuildTargets() const
{
    return false;
}

QList<ProjectExplorer::ProjectNode::ProjectAction>
ProjectNode::supportedActions(Node* node) const
{
    Q_UNUSED(node);
    return QList<ProjectNode::ProjectAction>();
}

bool ProjectNode::canAddSubProject(QString const& filePath) const
{
    Q_UNUSED(filePath)
    return false;
}

bool ProjectNode::addSubProjects(QStringList const& filePaths)
{
    Q_UNUSED(filePaths)
    return false;
}

bool ProjectNode::removeSubProjects(QStringList const& filePath)
{
    Q_UNUSED(filePath)
    return false;
}

bool ProjectNode::addFiles(QStringList const& filePaths, QStringList* notAdded = 0)
{
    Q_UNUSED(filePaths);
    Q_UNUSED(notAdded);
    return false;
}

bool ProjectNode::removeFiles(QStringList const& filePaths, QStringList* notRemoved = 0)
{
    Q_UNUSED(filePaths);
    Q_UNUSED(notRemoved);
    return false;
}

bool ProjectNode::deleteFiles(QStringList const& filePaths)
{
    Q_UNUSED(filePaths);
    return false;
}

bool ProjectNode::renameFile(QString const& filePath, QString const& newFilePath)
{
    Q_UNUSED(filePath);
    Q_UNUSED(newFilePath);
    return false;
}

QList<ProjectExplorer::RunConfiguration*> ProjectNode::runConfigurationsFor(Node* node)
{
    Q_UNUSED(node);
    return QList<ProjectExplorer::RunConfiguration*>();
}

} // namespace Internal
} // namespace BoostBuildProjectManager
