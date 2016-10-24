#include "LayerVideo.h"

LayerVideo::LayerVideo(QWidget *parent) : QWidget(parent)
{
    m_player = new QMediaPlayer;

    //  connect(m_player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    m_player->setMedia(QUrl::fromLocalFile(QDir::currentPath()+"/res/video/001.webm"));

    m_player->setVolume(50);

    m_wVideo = new QVideoWidget(this);

    m_player->setVideoOutput(m_wVideo);

    m_wVideo->show();

    m_player->play();
}

void LayerVideo::resizeEvent(QResizeEvent *)
{
    m_wVideo->resize(size());
}



void LayerVideo::showEvent(QShowEvent *)
{

    qDebug()<<"show";
    m_player->setPosition(0);

    m_player->play();

}

void LayerVideo::hideEvent(QHideEvent *)
{

    qDebug()<<"hide";

    m_player->pause();

}





#include <QtWidgets>
#include <qvideowidget.h>
#include <qvideosurfaceformat.h>

VideoPlayer::VideoPlayer(QWidget *parent)
    : QWidget(parent)
    , mediaPlayer(0, QMediaPlayer::VideoSurface)
    , playButton(0)
    , positionSlider(0)
    , errorLabel(0)
{
    QVideoWidget *m_wVideo = new QVideoWidget;

    QAbstractButton *openButton = new QPushButton(tr("Open..."));
    connect(openButton, &QAbstractButton::clicked, this, &VideoPlayer::openFile);

    playButton = new QPushButton;
    playButton->setEnabled(false);
    playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));

    connect(playButton, &QAbstractButton::clicked,
            this, &VideoPlayer::play);

    positionSlider = new QSlider(Qt::Horizontal);
    positionSlider->setRange(0, 0);

    connect(positionSlider, &QAbstractSlider::sliderMoved,
            this, &VideoPlayer::setPosition);

    errorLabel = new QLabel;
    errorLabel->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);

    QBoxLayout *controlLayout = new QHBoxLayout;
    controlLayout->setMargin(0);
    controlLayout->addWidget(openButton);
    controlLayout->addWidget(playButton);
    controlLayout->addWidget(positionSlider);

    QBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(m_wVideo);
    layout->addLayout(controlLayout);
    layout->addWidget(errorLabel);

    setLayout(layout);

    mediaPlayer.setVideoOutput(m_wVideo);
    connect(&mediaPlayer, &QMediaPlayer::stateChanged,
            this, &VideoPlayer::mediaStateChanged);
    connect(&mediaPlayer, &QMediaPlayer::positionChanged, this, &VideoPlayer::positionChanged);
    connect(&mediaPlayer, &QMediaPlayer::durationChanged, this, &VideoPlayer::durationChanged);
    typedef void (QMediaPlayer::*ErrorSignal)(QMediaPlayer::Error);
    connect(&mediaPlayer, static_cast<ErrorSignal>(&QMediaPlayer::error),
            this, &VideoPlayer::handleError);
}

VideoPlayer::~VideoPlayer()
{
}

void VideoPlayer::openFile()
{
    QFileDialog fileDialog(this);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setWindowTitle(tr("Open Movie"));
    QStringList supportedMimeTypes = mediaPlayer.supportedMimeTypes();
    if (!supportedMimeTypes.isEmpty())
        fileDialog.setMimeTypeFilters(supportedMimeTypes);
    fileDialog.setDirectory(QStandardPaths::standardLocations(QStandardPaths::MoviesLocation).value(0, QDir::homePath()));
    if (fileDialog.exec() == QDialog::Accepted)
        setUrl(fileDialog.selectedUrls().constFirst());
}

void VideoPlayer::setUrl(const QUrl &url)
{
    errorLabel->setText(QString());
    setWindowFilePath(url.isLocalFile() ? url.toLocalFile() : QString());
    mediaPlayer.setMedia(url);
    playButton->setEnabled(true);
}

void VideoPlayer::play()
{
    switch(mediaPlayer.state()) {
    case QMediaPlayer::PlayingState:
        mediaPlayer.pause();
        break;
    default:
        mediaPlayer.play();
        break;
    }
}

void VideoPlayer::mediaStateChanged(QMediaPlayer::State state)
{
    switch(state) {
    case QMediaPlayer::PlayingState:
        playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        break;
    default:
        playButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        break;
    }
}

void VideoPlayer::positionChanged(qint64 position)
{
    positionSlider->setValue(position);
}

void VideoPlayer::durationChanged(qint64 duration)
{
    positionSlider->setRange(0, duration);
}

void VideoPlayer::setPosition(int position)
{
    mediaPlayer.setPosition(position);
}

void VideoPlayer::handleError()
{
    playButton->setEnabled(false);
    const QString errorString = mediaPlayer.errorString();
    QString message = "Error: ";
    if (errorString.isEmpty())
        message += " #" + QString::number(int(mediaPlayer.error()));
    else
        message += errorString;
    errorLabel->setText(message);
}
