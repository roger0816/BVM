#ifndef LAYERVIDEO_H
#define LAYERVIDEO_H

#include <QWidget>
#include <QMediaPlayer>
#include <qvideowidget.h>
#include <QDir>
#include <QResizeEvent>
#include <QShowEvent>
#include <QHideEvent>
class LayerVideo : public QWidget
{
    Q_OBJECT
public:
    explicit LayerVideo(QWidget *parent = 0);

private:

    QMediaPlayer *m_player;

    QVideoWidget *m_wVideo ;

    void resizeEvent(QResizeEvent *);

    void showEvent(QShowEvent *);

    void hideEvent(QHideEvent *);

signals:
    void singalClicked();

public slots:
};





#include <qmediaplayer.h>

#include <QtGui/QMovie>
#include <QtWidgets/QWidget>

class QAbstractButton;
class QSlider;
class QLabel;
class QUrl;

class VideoPlayer : public QWidget
{
    Q_OBJECT
public:
    VideoPlayer(QWidget *parent = 0);
    ~VideoPlayer();

    void setUrl(const QUrl &url);

public slots:
    void openFile();
    void play();

private slots:
    void mediaStateChanged(QMediaPlayer::State state);
    void positionChanged(qint64 position);
    void durationChanged(qint64 duration);
    void setPosition(int position);
    void handleError();

private:
    QMediaPlayer mediaPlayer;
    QAbstractButton *playButton;
    QSlider *positionSlider;
    QLabel *errorLabel;
};



#endif // LAYERVIDEO_H
